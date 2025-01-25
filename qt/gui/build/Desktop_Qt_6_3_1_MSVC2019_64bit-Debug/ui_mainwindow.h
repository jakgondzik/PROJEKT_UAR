/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QCustomPlot *zadana;
    QCustomPlot *uchyb;
    QLineEdit *amplitudaLabel;
    QLabel *label;
    QLabel *label_9;
    QLabel *label_3;
    QLineEdit *delayLabel;
    QLineEdit *okresLabel;
    QLineEdit *zakloceniaLabel;
    QLineEdit *cyklLabel;
    QLabel *label_4;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *vecbLabel;
    QLabel *label_11;
    QLabel *label_6;
    QLabel *label_5;
    QLineEdit *tdLabel;
    QLabel *label_2;
    QLineEdit *tiLabel;
    QLineEdit *kpLabel;
    QLineEdit *vecaLabel;
    QLabel *label_12;
    QLabel *label_10;
    QComboBox *sygnalcomboBox;
    QLineEdit *aktywacjaLabel;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QSplitter *splitter;
    QLabel *label_13;
    QLineEdit *zadaneLabel;
    QLabel *label_14;
    QLineEdit *wyjscieLabel;
    QPushButton *aktualizujButton;
    QPushButton *startButton;
    QPushButton *resetButton;
    QPushButton *stopButton;
    QCustomPlot *sterowanie;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1386, 836);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(1386, 836));
        MainWindow->setMaximumSize(QSize(1386, 836));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        zadana = new QCustomPlot(centralwidget);
        zadana->setObjectName(QString::fromUtf8("zadana"));
        zadana->setGeometry(QRect(30, 30, 781, 701));
        uchyb = new QCustomPlot(centralwidget);
        uchyb->setObjectName(QString::fromUtf8("uchyb"));
        uchyb->setGeometry(QRect(810, 380, 451, 351));
        amplitudaLabel = new QLineEdit(centralwidget);
        amplitudaLabel->setObjectName(QString::fromUtf8("amplitudaLabel"));
        amplitudaLabel->setGeometry(QRect(668, 780, 108, 24));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(195, 750, 16, 16));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(607, 780, 54, 16));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(328, 750, 16, 16));
        delayLabel = new QLineEdit(centralwidget);
        delayLabel->setObjectName(QString::fromUtf8("delayLabel"));
        delayLabel->setGeometry(QRect(493, 780, 108, 24));
        okresLabel = new QLineEdit(centralwidget);
        okresLabel->setObjectName(QString::fromUtf8("okresLabel"));
        okresLabel->setGeometry(QRect(816, 750, 108, 24));
        zakloceniaLabel = new QLineEdit(centralwidget);
        zakloceniaLabel->setObjectName(QString::fromUtf8("zakloceniaLabel"));
        zakloceniaLabel->setGeometry(QRect(668, 750, 108, 24));
        cyklLabel = new QLineEdit(centralwidget);
        cyklLabel->setObjectName(QString::fromUtf8("cyklLabel"));
        cyklLabel->setGeometry(QRect(816, 780, 108, 24));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(328, 780, 16, 16));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(607, 750, 55, 16));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(930, 750, 61, 16));
        vecbLabel = new QLineEdit(centralwidget);
        vecbLabel->setObjectName(QString::fromUtf8("vecbLabel"));
        vecbLabel->setGeometry(QRect(493, 750, 108, 24));
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(782, 780, 21, 16));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(459, 780, 28, 16));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(459, 750, 16, 16));
        tdLabel = new QLineEdit(centralwidget);
        tdLabel->setObjectName(QString::fromUtf8("tdLabel"));
        tdLabel->setGeometry(QRect(345, 750, 108, 24));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(195, 780, 16, 16));
        tiLabel = new QLineEdit(centralwidget);
        tiLabel->setObjectName(QString::fromUtf8("tiLabel"));
        tiLabel->setGeometry(QRect(214, 780, 108, 24));
        kpLabel = new QLineEdit(centralwidget);
        kpLabel->setObjectName(QString::fromUtf8("kpLabel"));
        kpLabel->setGeometry(QRect(214, 750, 108, 24));
        vecaLabel = new QLineEdit(centralwidget);
        vecaLabel->setObjectName(QString::fromUtf8("vecaLabel"));
        vecaLabel->setGeometry(QRect(345, 780, 108, 24));
        label_12 = new QLabel(centralwidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(930, 780, 74, 16));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(782, 750, 28, 16));
        sygnalcomboBox = new QComboBox(centralwidget);
        sygnalcomboBox->setObjectName(QString::fromUtf8("sygnalcomboBox"));
        sygnalcomboBox->setGeometry(QRect(1010, 750, 111, 24));
        aktywacjaLabel = new QLineEdit(centralwidget);
        aktywacjaLabel->setObjectName(QString::fromUtf8("aktywacjaLabel"));
        aktywacjaLabel->setGeometry(QRect(1010, 780, 111, 24));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(1270, 270, 110, 214));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        splitter = new QSplitter(layoutWidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Vertical);
        label_13 = new QLabel(splitter);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        splitter->addWidget(label_13);
        zadaneLabel = new QLineEdit(splitter);
        zadaneLabel->setObjectName(QString::fromUtf8("zadaneLabel"));
        zadaneLabel->setReadOnly(true);
        splitter->addWidget(zadaneLabel);
        label_14 = new QLabel(splitter);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        splitter->addWidget(label_14);
        wyjscieLabel = new QLineEdit(splitter);
        wyjscieLabel->setObjectName(QString::fromUtf8("wyjscieLabel"));
        wyjscieLabel->setReadOnly(true);
        splitter->addWidget(wyjscieLabel);
        aktualizujButton = new QPushButton(splitter);
        aktualizujButton->setObjectName(QString::fromUtf8("aktualizujButton"));
        splitter->addWidget(aktualizujButton);

        verticalLayout->addWidget(splitter);

        startButton = new QPushButton(layoutWidget);
        startButton->setObjectName(QString::fromUtf8("startButton"));

        verticalLayout->addWidget(startButton);

        resetButton = new QPushButton(layoutWidget);
        resetButton->setObjectName(QString::fromUtf8("resetButton"));

        verticalLayout->addWidget(resetButton);

        stopButton = new QPushButton(layoutWidget);
        stopButton->setObjectName(QString::fromUtf8("stopButton"));

        verticalLayout->addWidget(stopButton);

        sterowanie = new QCustomPlot(centralwidget);
        sterowanie->setObjectName(QString::fromUtf8("sterowanie"));
        sterowanie->setGeometry(QRect(810, 30, 451, 351));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "UAR", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "kp", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "amplituda", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "td", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "A", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "zaklocenia", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "typ sygnalu", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "cykl", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "delay", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "B", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "ti", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "czas aktywacji", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "okres", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Wej\305\233cie", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Wyj\305\233cie", nullptr));
        aktualizujButton->setText(QCoreApplication::translate("MainWindow", "AKTUALIZUJ", nullptr));
        startButton->setText(QCoreApplication::translate("MainWindow", "START", nullptr));
        resetButton->setText(QCoreApplication::translate("MainWindow", "RESET", nullptr));
        stopButton->setText(QCoreApplication::translate("MainWindow", "STOP", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
