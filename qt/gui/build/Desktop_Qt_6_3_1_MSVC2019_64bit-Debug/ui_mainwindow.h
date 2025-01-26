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
#include <QtWidgets/QFormLayout>
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
    QFormLayout *formLayout_2;
    QLabel *label_4;
    QLineEdit *vecaLabel;
    QLineEdit *vecbLabel;
    QLabel *label_5;
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
    QCustomPlot *uchyb;
    QCustomPlot *sterowanie;
    QCustomPlot *zadana;
    QFormLayout *formLayout_3;
    QLineEdit *delayLabel;
    QLabel *label_6;
    QLabel *label_7;
    QLineEdit *zakloceniaLabel;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *kpLabel;
    QLabel *label_2;
    QLineEdit *tiLabel;
    QLineEdit *tdLabel;
    QLabel *label_3;
    QFormLayout *formLayout_6;
    QLabel *label_8;
    QComboBox *sygnalcomboBox;
    QLabel *label_15;
    QSpinBox *interwalSpinBox;
    QFormLayout *formLayout_5;
    QLabel *label_11;
    QLineEdit *cyklLabel;
    QLabel *label_12;
    QLineEdit *aktywacjaLabel;
    QFormLayout *formLayout_4;
    QLabel *label_10;
    QLineEdit *okresLabel;
    QLabel *label_9;
    QLineEdit *amplitudaLabel;
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
        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setFormAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_4);

        vecaLabel = new QLineEdit(centralwidget);
        vecaLabel->setObjectName(QString::fromUtf8("vecaLabel"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, vecaLabel);

        vecbLabel = new QLineEdit(centralwidget);
        vecbLabel->setObjectName(QString::fromUtf8("vecbLabel"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, vecbLabel);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_5);


        gridLayout->addLayout(formLayout_2, 2, 3, 1, 1);

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

        uchyb = new QCustomPlot(centralwidget);
        uchyb->setObjectName(QString::fromUtf8("uchyb"));

        gridLayout->addWidget(uchyb, 1, 14, 1, 3);

        sterowanie = new QCustomPlot(centralwidget);
        sterowanie->setObjectName(QString::fromUtf8("sterowanie"));

        gridLayout->addWidget(sterowanie, 0, 14, 1, 3);

        zadana = new QCustomPlot(centralwidget);
        zadana->setObjectName(QString::fromUtf8("zadana"));

        gridLayout->addWidget(zadana, 0, 0, 2, 14);

        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        formLayout_3->setFormAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);
        delayLabel = new QLineEdit(centralwidget);
        delayLabel->setObjectName(QString::fromUtf8("delayLabel"));

        formLayout_3->setWidget(0, QFormLayout::FieldRole, delayLabel);

        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_6);

        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        formLayout_3->setWidget(1, QFormLayout::LabelRole, label_7);

        zakloceniaLabel = new QLineEdit(centralwidget);
        zakloceniaLabel->setObjectName(QString::fromUtf8("zakloceniaLabel"));

        formLayout_3->setWidget(1, QFormLayout::FieldRole, zakloceniaLabel);


        gridLayout->addLayout(formLayout_3, 2, 4, 1, 1);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setSizeConstraint(QLayout::SetMinimumSize);
        formLayout->setFormAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        kpLabel = new QLineEdit(centralwidget);
        kpLabel->setObjectName(QString::fromUtf8("kpLabel"));

        formLayout->setWidget(0, QFormLayout::FieldRole, kpLabel);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        tiLabel = new QLineEdit(centralwidget);
        tiLabel->setObjectName(QString::fromUtf8("tiLabel"));

        formLayout->setWidget(1, QFormLayout::FieldRole, tiLabel);

        tdLabel = new QLineEdit(centralwidget);
        tdLabel->setObjectName(QString::fromUtf8("tdLabel"));

        formLayout->setWidget(2, QFormLayout::FieldRole, tdLabel);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);


        gridLayout->addLayout(formLayout, 2, 1, 1, 1);

        formLayout_6 = new QFormLayout();
        formLayout_6->setObjectName(QString::fromUtf8("formLayout_6"));
        formLayout_6->setFormAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        formLayout_6->setWidget(0, QFormLayout::LabelRole, label_8);

        sygnalcomboBox = new QComboBox(centralwidget);
        sygnalcomboBox->setObjectName(QString::fromUtf8("sygnalcomboBox"));

        formLayout_6->setWidget(0, QFormLayout::FieldRole, sygnalcomboBox);

        label_15 = new QLabel(centralwidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        formLayout_6->setWidget(1, QFormLayout::LabelRole, label_15);

        interwalSpinBox = new QSpinBox(centralwidget);
        interwalSpinBox->setObjectName(QString::fromUtf8("interwalSpinBox"));
        interwalSpinBox->setMinimum(100);
        interwalSpinBox->setMaximum(1000000);
        interwalSpinBox->setSingleStep(100);

        formLayout_6->setWidget(1, QFormLayout::FieldRole, interwalSpinBox);


        gridLayout->addLayout(formLayout_6, 2, 16, 1, 1);

        formLayout_5 = new QFormLayout();
        formLayout_5->setObjectName(QString::fromUtf8("formLayout_5"));
        formLayout_5->setFormAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        formLayout_5->setWidget(0, QFormLayout::LabelRole, label_11);

        cyklLabel = new QLineEdit(centralwidget);
        cyklLabel->setObjectName(QString::fromUtf8("cyklLabel"));

        formLayout_5->setWidget(0, QFormLayout::FieldRole, cyklLabel);

        label_12 = new QLabel(centralwidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        formLayout_5->setWidget(1, QFormLayout::LabelRole, label_12);

        aktywacjaLabel = new QLineEdit(centralwidget);
        aktywacjaLabel->setObjectName(QString::fromUtf8("aktywacjaLabel"));

        formLayout_5->setWidget(1, QFormLayout::FieldRole, aktywacjaLabel);


        gridLayout->addLayout(formLayout_5, 2, 15, 1, 1);

        formLayout_4 = new QFormLayout();
        formLayout_4->setObjectName(QString::fromUtf8("formLayout_4"));
        formLayout_4->setFormAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        formLayout_4->setWidget(0, QFormLayout::LabelRole, label_10);

        okresLabel = new QLineEdit(centralwidget);
        okresLabel->setObjectName(QString::fromUtf8("okresLabel"));

        formLayout_4->setWidget(0, QFormLayout::FieldRole, okresLabel);

        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        formLayout_4->setWidget(1, QFormLayout::LabelRole, label_9);

        amplitudaLabel = new QLineEdit(centralwidget);
        amplitudaLabel->setObjectName(QString::fromUtf8("amplitudaLabel"));

        formLayout_4->setWidget(1, QFormLayout::FieldRole, amplitudaLabel);


        gridLayout->addLayout(formLayout_4, 2, 9, 1, 1);

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
        label_4->setText(QCoreApplication::translate("MainWindow", "A", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "B", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Wej\305\233cie", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Wyj\305\233cie", nullptr));
        aktualizujButton->setText(QCoreApplication::translate("MainWindow", "AKTUALIZUJ", nullptr));
        startButton->setText(QCoreApplication::translate("MainWindow", "START", nullptr));
        resetButton->setText(QCoreApplication::translate("MainWindow", "RESET", nullptr));
        stopButton->setText(QCoreApplication::translate("MainWindow", "STOP", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "delay", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "zaklocenia", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "kp", nullptr));
        kpLabel->setText(QString());
        label_2->setText(QCoreApplication::translate("MainWindow", "ti", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "td", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "typ sygnalu", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "cykl", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "czas aktywacji", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "okres", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "amplituda", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
