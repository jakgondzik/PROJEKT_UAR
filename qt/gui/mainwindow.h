#pragma once

#include <QMainWindow>
#include <QTimer>
#include <QGraphicsScene>
#include <memory>
#include "klasy.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void startSimulation();   // Rozpoczyna symulację
    void stopSimulation();    // Zatrzymuje symulację
    void resetSimulation();   // Resetuje symulację
    void updateSimulation();  // Aktualizuje dane symulacji i wykresy
    void updateAllParams();   // Aktualizuje wszystkie parametry symulacji

private:
    Ui::MainWindow *ui;

    // Symulacja
    std::unique_ptr<Symulacja> m_symulacja;
    std::unique_ptr<WartoscZadana> m_wartoscZadana;

    // Timer do symulacji
    QTimer *m_timer;

    // Wykresy
    QGraphicsScene *m_scene1; // Scena dla zadane, zmierzone, sterowanie
    QGraphicsScene *m_scene2; // Scena dla uchybu

    int m_time;               // Aktualny czas symulacji
    double m_prevSetpoint;    // Poprzednia wartość zadana
    double m_prevOutput;      // Poprzednia wartość wyjściowa

    // Funkcje pomocnicze
    void initSimulation();    // Inicjalizuje symulację
    void updateSignalParams();// Pobiera parametry sygnału z GUI i ustawia w WartoscZadana
    void updateARXParams();   // Aktualizuje parametry ARX
    void updatePIDParams();   // Aktualizuje parametry PID
    void drawAxes(QGraphicsScene* scene, int xAxisLength, int yAxisRange); // Rysuje osie na scenie
};
