#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QGraphicsTextItem>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), m_timer(new QTimer(this)), m_scene1(new QGraphicsScene(this)), m_scene2(new QGraphicsScene(this)), m_scene3(new QGraphicsScene(this)), m_time(0), m_prevSetpoint(0.0), m_prevOutput(0.0) {

    ui->setupUi(this);

    // Podłączenie scen do QGraphicsView
    ui->graphicsView1->setScene(m_scene1);
    ui->graphicsView2->setScene(m_scene2);
    ui->graphicsView3->setScene(m_scene3);

    ui->sygnalcomboBox->addItem("Skok");
    ui->sygnalcomboBox->addItem("Sinusoida");
    ui->sygnalcomboBox->addItem("Prostokątny");

    // Podłączenie przycisków
    connect(ui->startButton, &QPushButton::clicked, this, &MainWindow::startSimulation);
    connect(ui->stopButton, &QPushButton::clicked, this, &MainWindow::stopSimulation);
    connect(ui->resetButton, &QPushButton::clicked, this, &MainWindow::resetSimulation);
    connect(ui->aktualizujButton, &QPushButton::clicked, this, &MainWindow::updateAllParams);

    // Timer do aktualizacji symulacji
    connect(m_timer, &QTimer::timeout, this, &MainWindow::updateSimulation);

    // Inicjalizacja symulacji
    initSimulation();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::initSimulation() {
    // Inicjalizacja ARX
    std::vector<double> A = { -0.4 };   // Współczynniki A
    std::vector<double> B = { 0.6 };    // Współczynniki B
    int delay = 1;                      // Opóźnienie
    double zaklocenia = 0.01;           // Zakłócenia
    auto arx = std::make_unique<ARX>(A, B, delay, zaklocenia);

    // Inicjalizacja PID
    double kp = 0.5, ti = 10.0, td = 0.1;
    auto pid = std::make_unique<PID>(kp, ti, td);

    // Inicjalizacja klasy WartoscZadana
    m_wartoscZadana = std::make_unique<WartoscZadana>();

    // Inicjalizacja klasy Symulacja
    m_symulacja = std::make_unique<Symulacja>(std::move(arx), std::move(pid), std::move(m_wartoscZadana));

    // Wyczyszczenie scen
    m_time = 0;
    m_prevSetpoint = 0.0;
    m_prevOutput = 0.0;
    m_scene1->clear();
    m_scene2->clear();
    m_scene3->clear();
    drawAxes(m_scene1, 600, 50); // Osie dla sceny 1
    drawAxes(m_scene2, 600, 50); // Osie dla sceny 2
    drawAxes(m_scene3, 600, 50);
}

void MainWindow::startSimulation() {
    try {
        if (!m_symulacja) {
            throw std::logic_error("Symulacja nie została poprawnie zainicjalizowana.");
        }

        // Wyświetlanie aktualnych wartości w polach tekstowych
        auto arx = m_symulacja->getARX();
        auto pid = m_symulacja->getPID();
        if (arx) {
            auto [vec_a, vec_b] = arx->getVektory();
            ui->vecaLabel->setText(QString::fromStdString(std::to_string(vec_a[0])));
            ui->vecbLabel->setText(QString::fromStdString(std::to_string(vec_b[0])));
            ui->delayLabel->setText(QString::number(arx->getDelay()));
            ui->zakloceniaLabel->setText(QString::number(arx->getZaklocenia()));
        }
        if (pid) {
            ui->kpLabel->setText(QString::number(pid->getKp()));
            ui->tiLabel->setText(QString::number(pid->getTi()));
            ui->tdLabel->setText(QString::number(pid->getTd()));
        }

        m_timer->start(100); // Start symulacji z interwałem 100 ms
    } catch (const std::exception& ex) {
        QMessageBox::critical(this, "Błąd", ex.what());
    }
}

void MainWindow::stopSimulation() {
    m_timer->stop();
}

void MainWindow::resetSimulation() {
    initSimulation();
    ui->zadaneLabel->setText("0.00");
    ui->wyjscieLabel->setText("0.00");
}

void MainWindow::updateAllParams() {
    try {
        // Tworzenie nowych obiektów na podstawie parametrów z GUI
        QStringList a_values = ui->vecaLabel->text().split(",");
        QStringList b_values = ui->vecbLabel->text().split(",");
        std::vector<double> vec_a, vec_b;
        for (const auto& val : a_values) vec_a.push_back(val.toDouble());
        for (const auto& val : b_values) vec_b.push_back(val.toDouble());

        int delay = ui->delayLabel->text().toInt();
        double zaklocenia = ui->zakloceniaLabel->text().toDouble();
        auto arx = std::make_unique<ARX>(vec_a, vec_b, delay, zaklocenia);

        double kp = ui->kpLabel->text().toDouble();
        double ti = ui->tiLabel->text().toDouble();
        double td = ui->tdLabel->text().toDouble();
        auto pid = std::make_unique<PID>(kp, ti, td);

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

        // Zastąpienie starych obiektów nowymi
        m_symulacja = std::make_unique<Symulacja>(std::move(arx), std::move(pid), std::move(wartoscZadana));

        QMessageBox::information(this, "Sukces", "Parametry zostały pomyślnie zaktualizowane.");
    } catch (const std::exception& ex) {
        QMessageBox::critical(this, "Błąd aktualizacji", ex.what());
    }
}

void MainWindow::drawAxes(QGraphicsScene* scene, int xAxisLength, int yAxisRange) {
    scene->addLine(0, 0, xAxisLength, 0, QPen(Qt::black));
    for (int i = 0; i <= xAxisLength; i += 100) {
        QGraphicsTextItem* label = scene->addText(QString::number(i));
        label->setPos(i, 5);
    }

    scene->addLine(0, -yAxisRange, 0, yAxisRange, QPen(Qt::black));
    for (int i = -yAxisRange; i <= yAxisRange; i += 10) {
        QGraphicsTextItem* label = scene->addText(QString::number(i / 5.0));
        label->setPos(-25, -i);
    }
}

void MainWindow::updateSimulation() {
    try {
        double setpoint = m_symulacja->getWartoscZadana()->generuj();
        double measured = m_prevOutput; // Ostatnia zmierzona wartość
        double error = setpoint - measured;

        // Pobranie składowych P, I, D sterowania
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

        // Przesuwanie wykresów w lewo, aby najstarszy widoczny moment to 60 sekund wstecz
        int windowWidth = 600; // Odpowiada 60 sekundom przy 100 ms interwale
        int xStart = std::max(0, m_time - windowWidth);
        m_scene1->setSceneRect(xStart, -100, windowWidth, 200); // Scena 1 zakres
        m_scene2->setSceneRect(xStart, -100, windowWidth, 200); // Scena 2 zakres
        m_scene3->setSceneRect(xStart, -100, windowWidth, 200);

        // Skalowanie wartości wyświetlanych na wykresach
        double scaledSetpoint = setpoint * 5; // Skalowanie na potrzeby wykresu
        double scaledOutput = output * 5;
        double scaledError = error * 5;
        double scaledP = pComponent * 5;
        double scaledI = iComponent * 5;
        double scaledD = dComponent * 5;
        double scaledControlSignal = controlSignal * 5;

        if (m_time > 0) {
            // Wykres wartości zadanej, wyjściowej i sterowania na scenie 1
            m_scene1->addLine(m_time - 1, -m_prevSetpoint * 5, m_time, -scaledSetpoint, QPen(Qt::blue));
            m_scene1->addLine(m_time - 1, -m_prevOutput * 5, m_time, -scaledOutput, QPen(Qt::red));


            // Wykres uchybu na scenie 2
            m_scene2->addLine(m_time - 1, 0, m_time, -scaledError, QPen(Qt::green));

            m_scene3->addLine(m_time - 1, 0, m_time, -scaledControlSignal, QPen(Qt::yellow));
            m_scene3->addLine(m_time - 1, 0, m_time, -scaledP, QPen(Qt::cyan));       // Składowa P
            m_scene3->addLine(m_time - 1, 0, m_time, -scaledI, QPen(Qt::magenta));    // Składowa I
            m_scene3->addLine(m_time - 1, 0, m_time, -scaledD, QPen(Qt::darkRed));  // Składowa D
        }

        m_prevSetpoint = setpoint;
        m_prevOutput = output;
        m_time++;
    } catch (const std::exception& ex) {
        QMessageBox::critical(this, "Błąd symulacji", ex.what());
        stopSimulation();
    }
}
