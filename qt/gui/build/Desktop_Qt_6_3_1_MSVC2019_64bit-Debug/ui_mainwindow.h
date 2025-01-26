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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
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
    QGridLayout *gridLayout;
    QLineEdit *amplitudaLabel;
    QLineEdit *aktywacjaLabel;
    QLabel *label_2;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *zakloceniaLabel;
    QLineEdit *cyklLabel;
    QLabel *label_15;
    QLabel *label_10;
    QLineEdit *kpLabel;
    QLabel *label_3;
    QSpinBox *interwalSpinBox;
    QLabel *label_6;
    QLabel *label;
    QLabel *label_4;
    QLabel *label_8;
    QLineEdit *vecaLabel;
    QCustomPlot *zadana;
    QLineEdit *delayLabel;
    QLabel *label_7;
    QLineEdit *okresLabel;
    QSpacerItem *horizontalSpacer;
    QLabel *label_9;
    QComboBox *sygnalcomboBox;
    QLineEdit *vecbLabel;
    QLineEdit *tdLabel;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QSplitter *splitter;
    QLabel *label_13;
    QLineEdit *zadaneLabel;
    QLabel *label_14;
    QLineEdit *wyjscieLabel;
    QPushButton *aktualizujButton;
    QPushButton *startButton;
    QPushButton *resetButton;
    QPushButton *stopButton;
    QSpacerItem *verticalSpacer_2;
    QLineEdit *tiLabel;
    QLabel *label_11;
    QLabel *label_12;
    QCustomPlot *uchyb;
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
        MainWindow->setMinimumSize(QSize(800, 600));
        MainWindow->setMaximumSize(QSize(16777215, 16777215));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        amplitudaLabel = new QLineEdit(centralwidget);
        amplitudaLabel->setObjectName(QString::fromUtf8("amplitudaLabel"));

        gridLayout->addWidget(amplitudaLabel, 3, 10, 1, 1);

        aktywacjaLabel = new QLineEdit(centralwidget);
        aktywacjaLabel->setObjectName(QString::fromUtf8("aktywacjaLabel"));

        gridLayout->addWidget(aktywacjaLabel, 3, 14, 1, 1);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 3, 0, 1, 1);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 3, 3, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 4, 8, 1, 1);

        zakloceniaLabel = new QLineEdit(centralwidget);
        zakloceniaLabel->setObjectName(QString::fromUtf8("zakloceniaLabel"));

        gridLayout->addWidget(zakloceniaLabel, 3, 7, 1, 1);

        cyklLabel = new QLineEdit(centralwidget);
        cyklLabel->setObjectName(QString::fromUtf8("cyklLabel"));

        gridLayout->addWidget(cyklLabel, 2, 14, 1, 1);

        label_15 = new QLabel(centralwidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout->addWidget(label_15, 3, 15, 1, 1);

        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout->addWidget(label_10, 2, 9, 1, 1);

        kpLabel = new QLineEdit(centralwidget);
        kpLabel->setObjectName(QString::fromUtf8("kpLabel"));

        gridLayout->addWidget(kpLabel, 2, 1, 1, 1);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 4, 0, 1, 1);

        interwalSpinBox = new QSpinBox(centralwidget);
        interwalSpinBox->setObjectName(QString::fromUtf8("interwalSpinBox"));
        interwalSpinBox->setMinimum(10);
        interwalSpinBox->setMaximum(1000);
        interwalSpinBox->setSingleStep(100);
        interwalSpinBox->setValue(100);

        gridLayout->addWidget(interwalSpinBox, 3, 16, 1, 1);

        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 2, 6, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 2, 0, 1, 1);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 2, 3, 1, 1);

        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 2, 15, 1, 1);

        vecaLabel = new QLineEdit(centralwidget);
        vecaLabel->setObjectName(QString::fromUtf8("vecaLabel"));

        gridLayout->addWidget(vecaLabel, 2, 4, 1, 1);

        zadana = new QCustomPlot(centralwidget);
        zadana->setObjectName(QString::fromUtf8("zadana"));
        zadana->setMinimumSize(QSize(0, 0));

        gridLayout->addWidget(zadana, 0, 0, 2, 12);

        delayLabel = new QLineEdit(centralwidget);
        delayLabel->setObjectName(QString::fromUtf8("delayLabel"));

        gridLayout->addWidget(delayLabel, 2, 7, 1, 1);

        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 3, 6, 1, 1);

        okresLabel = new QLineEdit(centralwidget);
        okresLabel->setObjectName(QString::fromUtf8("okresLabel"));

        gridLayout->addWidget(okresLabel, 2, 10, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 4, 2, 1, 1);

        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout->addWidget(label_9, 3, 9, 1, 1);

        sygnalcomboBox = new QComboBox(centralwidget);
        sygnalcomboBox->setObjectName(QString::fromUtf8("sygnalcomboBox"));

        gridLayout->addWidget(sygnalcomboBox, 2, 16, 1, 1);

        vecbLabel = new QLineEdit(centralwidget);
        vecbLabel->setObjectName(QString::fromUtf8("vecbLabel"));

        gridLayout->addWidget(vecbLabel, 3, 4, 1, 1);

        tdLabel = new QLineEdit(centralwidget);
        tdLabel->setObjectName(QString::fromUtf8("tdLabel"));

        gridLayout->addWidget(tdLabel, 4, 1, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        splitter = new QSplitter(centralwidget);
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

        startButton = new QPushButton(centralwidget);
        startButton->setObjectName(QString::fromUtf8("startButton"));

        verticalLayout->addWidget(startButton);

        resetButton = new QPushButton(centralwidget);
        resetButton->setObjectName(QString::fromUtf8("resetButton"));

        verticalLayout->addWidget(resetButton);

        stopButton = new QPushButton(centralwidget);
        stopButton->setObjectName(QString::fromUtf8("stopButton"));

        verticalLayout->addWidget(stopButton);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        gridLayout->addLayout(verticalLayout, 0, 17, 2, 1);

        tiLabel = new QLineEdit(centralwidget);
        tiLabel->setObjectName(QString::fromUtf8("tiLabel"));

        gridLayout->addWidget(tiLabel, 3, 1, 1, 1);

        label_11 = new QLabel(centralwidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout->addWidget(label_11, 2, 13, 1, 1);

        label_12 = new QLabel(centralwidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout->addWidget(label_12, 3, 13, 1, 1);

        uchyb = new QCustomPlot(centralwidget);
        uchyb->setObjectName(QString::fromUtf8("uchyb"));
        uchyb->setMinimumSize(QSize(0, 0));

        gridLayout->addWidget(uchyb, 1, 13, 1, 4);

        sterowanie = new QCustomPlot(centralwidget);
        sterowanie->setObjectName(QString::fromUtf8("sterowanie"));
        sterowanie->setMinimumSize(QSize(0, 0));

        gridLayout->addWidget(sterowanie, 0, 13, 1, 4);

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
        label_2->setText(QCoreApplication::translate("MainWindow", "ti", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "B", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "interwa\305\202", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "okres", nullptr));
        kpLabel->setText(QString());
        label_3->setText(QCoreApplication::translate("MainWindow", "td", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "delay", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "kp", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "A", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "typ sygnalu", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "zaklocenia", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "amplituda", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Wej\305\233cie", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Wyj\305\233cie", nullptr));
        aktualizujButton->setText(QCoreApplication::translate("MainWindow", "AKTUALIZUJ", nullptr));
        startButton->setText(QCoreApplication::translate("MainWindow", "START", nullptr));
        resetButton->setText(QCoreApplication::translate("MainWindow", "RESET", nullptr));
        stopButton->setText(QCoreApplication::translate("MainWindow", "STOP", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "cykl", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "czas aktywacji", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
