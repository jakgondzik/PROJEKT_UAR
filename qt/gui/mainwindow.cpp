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

    this->ui->kpLabel->setText("0.5");
    this->ui->tiLabel->setText("10");
    this->ui->tdLabel->setText("0.1");
    this->ui->vecaLabel->setText("-0.4");
    this->ui->vecbLabel->setText("0.6");
    this->ui->zakloceniaLabel->setText("0.01");
    this->ui->delayLabel->setText("1");
    this->ui->amplitudaLabel->setText("1");
    this->ui->okresLabel->setText("40");
    this->ui->cyklLabel->setText("0.5");
    this->ui->aktywacjaLabel->setText("1");

}

MainWindow::~MainWindow() {
    delete ui;
}



std::unique_ptr<ARX> MainWindow::updateARXParams()
{
    QStringList a_values = ui->vecaLabel->text().split(",");
    QStringList b_values = ui->vecbLabel->text().split(",");
    std::vector<double> vec_a, vec_b;

    for (const auto& val : a_values) {
        bool ok;
        double number = val.toDouble(&ok);
        if (ok) {
            vec_a.push_back(number);
        } else {
            QMessageBox::warning(this, "Błąd danych", "Nieprawidłowa wartość w polu vecA: " + val);
            return nullptr;
        }
    }
    for (const auto& val : b_values) {
        bool ok;
        double number = val.toDouble(&ok);
        if (ok) {
            vec_b.push_back(number);
        } else {
            QMessageBox::warning(this, "Błąd danych", "Nieprawidłowa wartość w polu vecB: " + val);
            return nullptr;
        }
    }

    bool delayOk;
    int delay = ui->delayLabel->text().toInt(&delayOk);
    if (!delayOk) {
        QMessageBox::warning(this, "Błąd danych", "Nieprawidłowa wartość opóźnienia (delay).");
        return nullptr;
    }


    bool zakloceniaOk;
    double zaklocenia = ui->zakloceniaLabel->text().toDouble(&zakloceniaOk);
    if (!zakloceniaOk) {
        QMessageBox::warning(this, "Błąd danych", "Nieprawidłowa wartość zakłócenia.");
        return nullptr;
    }

    auto arx = std::make_unique<ARX>(vec_a, vec_b, delay, zaklocenia);
    return arx;
}


std::unique_ptr<PID> MainWindow::updatePIDParams()
{
    bool kpOk, tiOk, tdOk;

    double kp = ui->kpLabel->text().toDouble(&kpOk);
    if (!kpOk) {
        QMessageBox::warning(this, "Błąd danych", "Nieprawidłowa wartość Kp.");
        return nullptr;
    }

    double ti = ui->tiLabel->text().toDouble(&tiOk);
    if (!tiOk) {
        QMessageBox::warning(this, "Błąd danych", "Nieprawidłowa wartość Ti.");
        return nullptr;
    }

    double td = ui->tdLabel->text().toDouble(&tdOk);
    if (!tdOk) {
        QMessageBox::warning(this, "Błąd danych", "Nieprawidłowa wartość Td.");
        return nullptr;
    }

    return std::make_unique<PID>(kp, ti, td);
}


std::unique_ptr<WartoscZadana> MainWindow::updateSignalParams()
{
    auto wartoscZadana = std::make_unique<WartoscZadana>();

    bool amplitudeOk, periodOk, dutyCycleOk, activationTimeOk;

    double amplitude = ui->amplitudaLabel->text().toDouble(&amplitudeOk);
    if (!amplitudeOk) {
        QMessageBox::warning(this, "Błąd danych", "Nieprawidłowa wartość amplitudy.");
        return nullptr;
    }

    double period = ui->okresLabel->text().toDouble(&periodOk);
    if (!periodOk) {
        QMessageBox::warning(this, "Błąd danych", "Nieprawidłowa wartość okresu.");
        return nullptr;
    }

    double dutyCycle = ui->cyklLabel->text().toDouble(&dutyCycleOk);
    if (!dutyCycleOk) {
        QMessageBox::warning(this, "Błąd danych", "Nieprawidłowa wartość współczynnika wypełnienia (duty cycle).");
        return nullptr;
    }

    int activationTime = ui->aktywacjaLabel->text().toInt(&activationTimeOk);
    if (!activationTimeOk) {
        QMessageBox::warning(this, "Błąd danych", "Nieprawidłowa wartość czasu aktywacji.");
        return nullptr;
    }

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
        QMessageBox::warning(this, "Błąd danych", "Nieznany typ sygnału.");
        return nullptr;
    }

    return wartoscZadana;
}


void MainWindow::initSimulation() {

    auto arx = this->updateARXParams();

    auto pid = this->updatePIDParams();

    auto wartoscZadana = this->updateSignalParams();

    if (arx==nullptr||pid==nullptr||wartoscZadana==nullptr)
    {
        m_symulacja = nullptr;
    } else
    {
    m_symulacja = std::make_unique<Symulacja>(std::move(arx), std::move(pid), std::move(wartoscZadana));
    m_time = 0;
    m_prevSetpoint = 0.0;
    m_prevOutput = 0.0;
    if(resetclicked)
    {
        setupPlots();
        resetclicked = false;
    }
    }
}
void MainWindow::setupPlots()
{

    // Dodanie danych do każdego wykresu
    sterowaniePlot->addGraph();
    sterowaniePlot->addGraph();
    sterowaniePlot->addGraph();
    uchybPlot->addGraph();
    zadanaPlot->addGraph();
    zadanaPlot->addGraph();
    if(!wasreseted)
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
    zadanaPlot->plotLayout()->insertRow(0);
    zadanaPlot->plotLayout()->addElement(0, 0, new QCPTextElement(zadanaPlot, "Wartość zadana", QFont("Arial", 12, QFont::Bold)));
    sterowaniePlot->plotLayout()->insertRow(0);
    sterowaniePlot->plotLayout()->addElement(0, 0, new QCPTextElement(sterowaniePlot, "PID", QFont("Arial", 12, QFont::Bold)));
    uchybPlot->plotLayout()->insertRow(0);
    uchybPlot->plotLayout()->addElement(0, 0, new QCPTextElement(uchybPlot, "Uchyb", QFont("Arial", 12, QFont::Bold)));
    }
    sterowaniePlot->graph(0)->setPen(QPen(Qt::red));
    sterowaniePlot->graph(1)->setPen(QPen(Qt::blue));
    sterowaniePlot->graph(2)->setPen(QPen(Qt::green));


    uchybPlot->graph(0)->setPen(QPen(Qt::green));

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
        m_timer->start(1000);
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
    resetclicked = true;
    ui->zadaneLabel->setText("0.00");
    ui->wyjscieLabel->setText("0.00");
    sterowaniePlot->clearGraphs();
    zadanaPlot->clearGraphs();
    uchybPlot->clearGraphs();
    wasreseted = true;
    sterowaniePlot->replot();
    zadanaPlot->replot();
    uchybPlot->replot();
    initSimulation();
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
            zadanaPlot->graph(0)->addData(m_time-1,setpoint);
            zadanaPlot->graph(1)->addData(m_time-1,measured);
            sterowaniePlot->graph(0)->addData(m_time-1,pComponent);
            sterowaniePlot->graph(1)->addData(m_time-1,iComponent);
            sterowaniePlot->graph(2)->addData(m_time-1,dComponent);
            uchybPlot->graph(0)->addData(m_time-1, error);
            zadanaPlot->xAxis->setRange(0, m_x);
            sterowaniePlot->xAxis->setRange(0, m_x);
            uchybPlot->xAxis->setRange(0, m_x);
            //Wstępnie zostawiam rescale Axes, musimy przemyśleć czy wolimy moje skalowanie czy przy użyciu tego
            sterowaniePlot->yAxis->rescale();
            zadanaPlot->yAxis->rescale();
            uchybPlot->yAxis->rescale();
            zadanaPlot->replot();
            sterowaniePlot->replot();
            uchybPlot->replot();
            m_x+=1;

        }
        m_time++;
        m_prevOutput = output;
        m_prevSetpoint = setpoint;
    } catch (const std::exception& ex) {
        QMessageBox::critical(this, "Błąd symulacji", ex.what());
        stopSimulation();
    }
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


