 #include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QGraphicsTextItem>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), m_timer(new QTimer(this)),  m_time(0), m_prevSetpoint(0.0), m_prevOutput(0.0) {

    ui->setupUi(this);

    sterowaniePlot = ui->sterowanie;
    uchybPlot = ui->uchyb;
    zadanaPlot = ui->zadana;
    ui->sygnalcomboBox->addItem("Skok");
    ui->sygnalcomboBox->addItem("Sinusoida");
    ui->sygnalcomboBox->addItem("Prostokątny");

    connect(ui->startButton, &QPushButton::clicked, this, &MainWindow::startSimulation);
    connect(ui->stopButton, &QPushButton::clicked, this, &MainWindow::stopSimulation);
    connect(ui->resetButton, &QPushButton::clicked, this, &MainWindow::resetSimulation);
    connect(ui->aktualizujButton, &QPushButton::clicked, this, &MainWindow::updateAllParams);

    connect(m_timer, &QTimer::timeout, this, &MainWindow::updateSimulation);


}

MainWindow::~MainWindow() {
    delete ui;
}

auto MainWindow::updateARXParams()
{
    QStringList a_values = ui->vecaLabel->text().split(",");
    QStringList b_values = ui->vecbLabel->text().split(",");
    std::vector<double> vec_a, vec_b;
    for (const auto& val : a_values) vec_a.push_back(val.toDouble());
    for (const auto& val : b_values) vec_b.push_back(val.toDouble());

    int delay = ui->delayLabel->text().toInt();
    double zaklocenia = ui->zakloceniaLabel->text().toDouble();
    auto arx = std::make_unique<ARX>(vec_a, vec_b, delay, zaklocenia);
    return arx;
}
auto MainWindow::updatePIDParams()
{
    double kp = ui->kpLabel->text().toDouble();
    double ti = ui->tiLabel->text().toDouble();
    double td = ui->tdLabel->text().toDouble();
    auto pid = std::make_unique<PID>(kp, ti, td);
    return pid;
}

auto MainWindow::updateSignalParams()
{
    auto wartoscZadana = std::make_unique<WartoscZadana>();
    double amplitude = ui->amplitudaLabel->text().toDouble();
    double period = ui->okresLabel->text().toDouble();
    double dutyCycle = ui->cyklLabel->text().toDouble();
    int activationTime = ui->aktywacjaLabel->text().toInt();
    TypSygnalu type = static_cast<TypSygnalu>(ui->sygnalcomboBox->currentIndex());

    switch (type) {
    case skok:
        wartoscZadana->ustawskok(amplitude, activationTime);
        break;
    case sinusoida:
        wartoscZadana->ustawsinusoide(amplitude, period);
        break;
    case prostokatny:
        wartoscZadana->ustawprostokatny(amplitude, period, dutyCycle);
        break;
    default:
        throw std::invalid_argument("Nieznany typ sygnału.");
    }
    return wartoscZadana;
}

void MainWindow::initSimulation() {

    auto arx = this->updateARXParams();

    auto pid = this->updatePIDParams();

    auto wartoscZadana = this->updateSignalParams();

    m_symulacja = std::make_unique<Symulacja>(std::move(arx), std::move(pid), std::move(wartoscZadana));
    m_time = 0;
    m_prevSetpoint = 0.0;
    m_prevOutput = 0.0;
    setupPlots();

}
void MainWindow::setupPlots()
{
    sterowaniePlot->xAxis->setLabel("t [s]");
    sterowaniePlot->yAxis->setLabel("y");
    //sterowaniePlot->xAxis->setRange(m_x-1, m_x);
  //  sterowaniePlot->yAxis->setRange(m_yPID-2, m_yPID);

    // Uchyb
    uchybPlot->xAxis->setLabel("t [s]");
    uchybPlot->yAxis->setLabel("y");
  //  uchybPlot->xAxis->setRange(m_x-1, m_x);
   // uchybPlot->yAxis->setRange(m_yU-2, m_yU);

    // Zadana
    zadanaPlot->xAxis->setLabel("t [s]");
    zadanaPlot->yAxis->setLabel("y");
    zadanaPlot->xAxis->setRange(m_x-1, m_x);
    zadanaPlot->yAxis->setRange(m_yZ-6, m_yZ);
    // Dodanie danych do każdego wykresu
    sterowaniePlot->addGraph();
    sterowaniePlot->addGraph();
    sterowaniePlot->addGraph();
    sterowaniePlot->graph(0)->setPen(QPen(Qt::red));
    sterowaniePlot->graph(1)->setPen(QPen(Qt::blue));
    sterowaniePlot->graph(2)->setPen(QPen(Qt::green));

    uchybPlot->addGraph();
    uchybPlot->graph(0)->setPen(QPen(Qt::green));
    if(!wasreseted)
    {
    zadanaPlot->plotLayout()->insertRow(0);
    zadanaPlot->plotLayout()->addElement(0, 0, new QCPTextElement(zadanaPlot, "Wartość zadana", QFont("Arial", 12, QFont::Bold)));
    sterowaniePlot->plotLayout()->insertRow(0);
    sterowaniePlot->plotLayout()->addElement(0, 0, new QCPTextElement(sterowaniePlot, "PID", QFont("Arial", 12, QFont::Bold)));
    uchybPlot->plotLayout()->insertRow(0);
    uchybPlot->plotLayout()->addElement(0, 0, new QCPTextElement(uchybPlot, "Uchyb", QFont("Arial", 12, QFont::Bold)));
    }
    zadanaPlot->addGraph();
    zadanaPlot->addGraph();
    zadanaPlot->graph(0)->setPen(QPen(Qt::red));
    zadanaPlot->graph(1)->setPen(QPen(Qt::blue));

    sterowaniePlot->legend->setVisible(true);
    uchybPlot->legend->setVisible(true);
    zadanaPlot->legend->setVisible(true);
    uchybPlot->graph(0)->setName("Uchyb");

    zadanaPlot->graph(0)->setName("Wyjście");
    zadanaPlot->graph(1)->setName("Zmierzona");

    sterowaniePlot->graph(0)->setName("Składowa P");
    sterowaniePlot->graph(1)->setName("Składowa I");
    sterowaniePlot->graph(2)->setName("Składowa D");

    zoom(true);

    sterowaniePlot->replot();
    uchybPlot->replot();
    zadanaPlot->replot();
}

void MainWindow::startSimulation() {
    if(m_time > 0)
    {
        return;
    }
initSimulation();
    try {
        if (!m_symulacja) {
            throw std::logic_error("Symulacja nie została poprawnie zainicjalizowana.");
        }

        zoom(false);
        m_timer->start(100);
    } catch (const std::exception& ex) {
        QMessageBox::critical(this, "Błąd", ex.what());
    }

}

void MainWindow::stopSimulation() {
    m_timer->stop();
    zoom(true);

}

void MainWindow::resetSimulation() {

    ui->zadaneLabel->setText("0.00");
    ui->wyjscieLabel->setText("0.00");
    sterowaniePlot->clearGraphs();
    zadanaPlot->clearGraphs();
    uchybPlot->clearGraphs();
    wasreseted = true;
   // initSimulation();
}

void MainWindow::updateAllParams() {
    if(m_time == 0)
    {
        msg.setText("Najpierw zacznij symulacje!");
        msg.exec();
        return;
    }
    try {
        auto arx = this->updateARXParams();

        auto pid = this->updatePIDParams();

        auto wartoscZadana = this->updateSignalParams();

        m_symulacja = std::make_unique<Symulacja>(std::move(arx), std::move(pid), std::move(wartoscZadana));

        QMessageBox::information(this, "Sukces", "Parametry zostały pomyślnie zaktualizowane.");
    } catch (const std::exception& ex) {
        QMessageBox::critical(this, "Błąd aktualizacji", ex.what());
    }
}



void MainWindow::updateSimulation() {
    try {
        double setpoint = m_symulacja->getWartoscZadana()->generuj();
        double measured = m_prevOutput;
        double error = setpoint - measured;

        double kp = m_symulacja->getPID()->getKp();
        double ti = m_symulacja->getPID()->getTi();
        double td = m_symulacja->getPID()->getTd();
        double pComponent = kp * error;
        double iComponent = (ti == 0.0) ? 0.0 : (kp / ti * error * m_time);
        double dComponent = td * kp * (error - (m_prevSetpoint - measured));
        double controlSignal = pComponent + iComponent + dComponent;

        m_symulacja->setZadane(setpoint);
        double output = m_symulacja->krok();

        ui->zadaneLabel->setText(QString::number(setpoint, 'f', 2));
        ui->wyjscieLabel->setText(QString::number(output, 'f', 2));



        if (m_time > 0) {
       /*     if(setpoint > m_yZ || measured > m_yZ)
            {
//Brakuje skalowania w dół
                m_yZ+=1;
            }
            if(pComponent > m_yPID || iComponent > m_yPID || dComponent > m_yPID)
            {
                m_yPID+=1;
            }
            if(setpoint > m_yZ)
            {
                m_yZ+=1;
            }*/
            zadanaPlot->graph(0)->addData(m_time-1,setpoint);
            zadanaPlot->graph(1)->addData(m_time-1,measured);
            sterowaniePlot->graph(0)->addData(m_time-1,pComponent);
            sterowaniePlot->graph(1)->addData(m_time-1,iComponent);
            sterowaniePlot->graph(2)->addData(m_time-1,dComponent);
            uchybPlot->graph(0)->addData(m_time-1, error);
           /* zadanaPlot->xAxis->setRange(m_x-1, m_x);
            sterowaniePlot->xAxis->setRange(m_x-1, m_x);
            uchybPlot->xAxis->setRange(m_x-1, m_x);*/
            //Wstępnie zostawiam rescale Axes, musimy przemyśleć czy wolimy moje skalowanie czy przy użyciu tego
            sterowaniePlot->rescaleAxes();
            zadanaPlot->rescaleAxes();
            uchybPlot->rescaleAxes();
            zadanaPlot->replot();
            sterowaniePlot->replot();
            uchybPlot->replot();
            m_x+=0.2;

        }
        m_time++;
        m_prevOutput = output;
        m_prevSetpoint = setpoint;
    } catch (const std::exception& ex) {
        QMessageBox::critical(this, "Błąd symulacji", ex.what());
        stopSimulation();
    }
}
bool MainWindow::isAllSet()
{
    QString error = "";\
    bool isset = true;
    if(ui->kpLabel->text() == "")
    {
        error+= "kp;";
        isset = false;
    }
    if(ui->tdLabel->text() == "")
    {
        error+= "td;";
        isset = false;
    }
    if(ui->tiLabel->text() == "")
    {
        error+= "ti;";
        isset = false;
    }
    if(ui->vecaLabel->text() == "")
    {
        error+= "Współczynnik A;";
        isset = false;
    }
    if(ui->vecbLabel->text() == "")
    {
        error+= "Współczynnik B;";
        isset = false;
    }
    if(ui->delayLabel->text() == "")
    {
        error+= "delay;";
        isset = false;
    }
    if(ui->zakloceniaLabel->text() == "")
    {
        error+= "zaklocenia;";
        isset = false;
    }
    msg.setText("Nie ustawiłeś współczynników: " + error + " symulacja wstrzymana.");
    msg.exec();
    return isset;
}
void MainWindow::zoom(bool stan)
{
    sterowaniePlot->setInteraction(QCP::iRangeZoom, stan);
    sterowaniePlot->setInteraction(QCP::iRangeDrag, stan);
    zadanaPlot->setInteraction(QCP::iRangeZoom, stan);
    zadanaPlot->setInteraction(QCP::iRangeDrag, stan);
    uchybPlot->setInteraction(QCP::iRangeZoom, stan);
    uchybPlot->setInteraction(QCP::iRangeDrag, stan);
}


