#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QGraphicsTextItem>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), m_timer(new QTimer(this)), m_scene(new QGraphicsScene(this)), m_time(0), m_prevSetpoint(0.0), m_prevOutput(0.0) {

    ui->setupUi(this);

    // Podłączenie sceny do QGraphicsView
    ui->graphicsView->setScene(m_scene);
    // Dodanie opcji do listy rozwijanej
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

    // Wyczyszczenie sceny
    m_time = 0;
    m_prevSetpoint = 0.0;
    m_prevOutput = 0.0;
    m_scene->clear();
    drawAxes();
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
        ui->graphicsView->fitInView(m_scene->sceneRect(), Qt::KeepAspectRatio);



        m_timer->start(100);  // Interwał 100 ms
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

void MainWindow::updateSimulation() {
    try {
        double setpoint = m_symulacja->getWartoscZadana()->generuj();
        m_symulacja->setZadane(setpoint);
        double output = m_symulacja->krok();

        ui->zadaneLabel->setText(QString::number(setpoint, 'f', 2));
        ui->wyjscieLabel->setText(QString::number(output, 'f', 2));


        // Przesuwanie wykresu w lewo, aby najstarszy widoczny moment to 60 sekund wstecz
        int windowWidth = 600; // Odpowiada 60 sekundom przy 100 ms interwale
        int xStart = std::max(0, m_time - windowWidth);
        m_scene->setSceneRect(xStart, -100, windowWidth, 200); // Zwiększony zakres Y

        // Skalowanie wartości wyświetlanych na wykresie
        double scaledSetpoint = setpoint * 10; // Skalowanie na potrzeby wykresu
        double scaledOutput = output * 10;

        if (m_time > 0) {
            m_scene->addLine(m_time - 1, -m_prevSetpoint * 10, m_time, -scaledSetpoint, QPen(Qt::blue));
            m_scene->addLine(m_time - 1, -m_prevOutput * 10, m_time, -scaledOutput, QPen(Qt::red));

        }

        m_prevSetpoint = setpoint;
        m_prevOutput = output;
        m_time++;
    } catch (const std::exception& ex) {
        QMessageBox::critical(this, "Błąd symulacji", ex.what());
        stopSimulation();
    }
}

void MainWindow::drawAxes() {
    int xAxisLength = 600; // Długość osi X odpowiada 60 sekundom
    m_scene->addLine(0, 0, xAxisLength, 0, QPen(Qt::black));
    for (int i = 0; i <= xAxisLength; i += 100) {
        QGraphicsTextItem* label = m_scene->addText(QString::number(i / 10.0));
        label->setPos(i, 5);
    }

    m_scene->addLine(0, -100, 0, 100, QPen(Qt::black)); // Zwiększony zakres Y
    for (int i = -100; i <= 100; i += 20) { // Dostosowanie opisów osi
        QGraphicsTextItem* label = m_scene->addText(QString::number(i / 10.0)); // Etykiety w rzeczywistej skali
        label->setPos(-25, -i);
    }
   /* m_scene->addLine(0, 0, xAxisLength, 0, QPen(Qt::black));
    for (int i = 0; i <= xAxisLength; i += 100) {
        QGraphicsTextItem* label = m_scene_2->addText(QString::number(i / 10.0));
        label->setPos(i, 5);
    }

    m_scene->addLine(0, -100, 0, 100, QPen(Qt::black)); // Zwiększony zakres Y
    for (int i = -100; i <= 100; i += 20) { // Dostosowanie opisów osi
        QGraphicsTextItem* label = m_scene_2->addText(QString::number(i / 10.0)); // Etykiety w rzeczywistej skali
        label->setPos(-25, -i);
    }*/
}
