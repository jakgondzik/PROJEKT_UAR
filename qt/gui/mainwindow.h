#pragma once

#include <QMainWindow>
#include <QTimer>
#include <memory>
#include <QGraphicsScene>
#include "klasy.h"
#include "qcustomplot.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void startSimulation();
    void stopSimulation();
    void resetSimulation();
    void updateSimulation();
    void updateAllParams();

private:
    Ui::MainWindow *ui;

    std::unique_ptr<Symulacja> m_symulacja;

    QTimer *m_timer;

    QCustomPlot * sterowaniePlot;
    QCustomPlot * uchybPlot;
    QCustomPlot * zadanaPlot;
    QMessageBox msg;
    double m_x = 1;
    double m_yZ = 3;
    double m_yPID = 1;
    double m_yU = 1;
    bool wasreseted = false;
    void zoom(bool);
    void setupPlots();
    int m_time;
    double m_prevSetpoint;
    double m_prevOutput;
    bool isAllSet();
    void initSimulation();
    auto updateSignalParams();
    auto updateARXParams();
    auto updatePIDParams();
};
