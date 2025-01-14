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
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
    QLineEdit *zadaneLabel;
    QLineEdit *wyjscieLabel;
    QLabel *label_13;
    QLabel *label_14;
    QGraphicsView *graphicsView_2;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *kpLabel;
    QLabel *label_3;
    QLineEdit *tdLabel;
    QLabel *label_5;
    QLineEdit *vecbLabel;
    QLabel *label_7;
    QLineEdit *zakloceniaLabel;
    QLabel *label_10;
    QLineEdit *okresLabel;
    QLabel *label_8;
    QComboBox *sygnalcomboBox;
    QPushButton *aktualizujButton;
    QPushButton *startButton;
    QPushButton *stopButton;
    QLabel *label_2;
    QLineEdit *tiLabel;
    QLabel *label_4;
    QLineEdit *vecaLabel;
    QLabel *label_6;
    QLineEdit *delayLabel;
    QLabel *label_9;
    QLineEdit *amplitudaLabel;
    QLabel *label_11;
    QLineEdit *cyklLabel;
    QLabel *label_12;
    QLineEdit *aktywacjaLabel;
    QPushButton *resetButton;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1386, 636);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(1386, 636));
        MainWindow->setMaximumSize(QSize(1386, 636));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(110, 10, 1000, 250));
        zadaneLabel = new QLineEdit(centralwidget);
        zadaneLabel->setObjectName(QString::fromUtf8("zadaneLabel"));
        zadaneLabel->setGeometry(QRect(1250, 100, 121, 71));
        wyjscieLabel = new QLineEdit(centralwidget);
        wyjscieLabel->setObjectName(QString::fromUtf8("wyjscieLabel"));
        wyjscieLabel->setGeometry(QRect(1250, 260, 121, 71));
        label_13 = new QLabel(centralwidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(1290, 80, 49, 16));
        label_14 = new QLabel(centralwidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(1290, 240, 49, 16));
        graphicsView_2 = new QGraphicsView(centralwidget);
        graphicsView_2->setObjectName(QString::fromUtf8("graphicsView_2"));
        graphicsView_2->setGeometry(QRect(110, 260, 1000, 250));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(40, 560, 1271, 58));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        kpLabel = new QLineEdit(widget);
        kpLabel->setObjectName(QString::fromUtf8("kpLabel"));

        gridLayout->addWidget(kpLabel, 0, 1, 1, 1);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 0, 2, 1, 1);

        tdLabel = new QLineEdit(widget);
        tdLabel->setObjectName(QString::fromUtf8("tdLabel"));

        gridLayout->addWidget(tdLabel, 0, 3, 1, 1);

        label_5 = new QLabel(widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 0, 4, 1, 1);

        vecbLabel = new QLineEdit(widget);
        vecbLabel->setObjectName(QString::fromUtf8("vecbLabel"));

        gridLayout->addWidget(vecbLabel, 0, 5, 1, 1);

        label_7 = new QLabel(widget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 0, 6, 1, 1);

        zakloceniaLabel = new QLineEdit(widget);
        zakloceniaLabel->setObjectName(QString::fromUtf8("zakloceniaLabel"));

        gridLayout->addWidget(zakloceniaLabel, 0, 7, 1, 1);

        label_10 = new QLabel(widget);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout->addWidget(label_10, 0, 8, 1, 1);

        okresLabel = new QLineEdit(widget);
        okresLabel->setObjectName(QString::fromUtf8("okresLabel"));

        gridLayout->addWidget(okresLabel, 0, 9, 1, 1);

        label_8 = new QLabel(widget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 0, 10, 1, 1);

        sygnalcomboBox = new QComboBox(widget);
        sygnalcomboBox->setObjectName(QString::fromUtf8("sygnalcomboBox"));

        gridLayout->addWidget(sygnalcomboBox, 0, 11, 1, 1);

        aktualizujButton = new QPushButton(widget);
        aktualizujButton->setObjectName(QString::fromUtf8("aktualizujButton"));

        gridLayout->addWidget(aktualizujButton, 0, 12, 2, 1);

        startButton = new QPushButton(widget);
        startButton->setObjectName(QString::fromUtf8("startButton"));

        gridLayout->addWidget(startButton, 0, 13, 2, 1);

        stopButton = new QPushButton(widget);
        stopButton->setObjectName(QString::fromUtf8("stopButton"));

        gridLayout->addWidget(stopButton, 0, 14, 2, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        tiLabel = new QLineEdit(widget);
        tiLabel->setObjectName(QString::fromUtf8("tiLabel"));

        gridLayout->addWidget(tiLabel, 1, 1, 1, 1);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 1, 2, 1, 1);

        vecaLabel = new QLineEdit(widget);
        vecaLabel->setObjectName(QString::fromUtf8("vecaLabel"));

        gridLayout->addWidget(vecaLabel, 1, 3, 1, 1);

        label_6 = new QLabel(widget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 1, 4, 1, 1);

        delayLabel = new QLineEdit(widget);
        delayLabel->setObjectName(QString::fromUtf8("delayLabel"));

        gridLayout->addWidget(delayLabel, 1, 5, 1, 1);

        label_9 = new QLabel(widget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout->addWidget(label_9, 1, 6, 1, 1);

        amplitudaLabel = new QLineEdit(widget);
        amplitudaLabel->setObjectName(QString::fromUtf8("amplitudaLabel"));

        gridLayout->addWidget(amplitudaLabel, 1, 7, 1, 1);

        label_11 = new QLabel(widget);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout->addWidget(label_11, 1, 8, 1, 1);

        cyklLabel = new QLineEdit(widget);
        cyklLabel->setObjectName(QString::fromUtf8("cyklLabel"));

        gridLayout->addWidget(cyklLabel, 1, 9, 1, 1);

        label_12 = new QLabel(widget);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout->addWidget(label_12, 1, 10, 1, 1);

        aktywacjaLabel = new QLineEdit(widget);
        aktywacjaLabel->setObjectName(QString::fromUtf8("aktywacjaLabel"));

        gridLayout->addWidget(aktywacjaLabel, 1, 11, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        resetButton = new QPushButton(widget);
        resetButton->setObjectName(QString::fromUtf8("resetButton"));

        gridLayout_2->addWidget(resetButton, 0, 1, 1, 1);

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
        label_13->setText(QCoreApplication::translate("MainWindow", "Wej\305\233cie", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Wyj\305\233cie", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "kp", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "td", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "B", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "zaklocenia", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "okres", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "typ sygnalu", nullptr));
        aktualizujButton->setText(QCoreApplication::translate("MainWindow", "AKTUALIZUJ", nullptr));
        startButton->setText(QCoreApplication::translate("MainWindow", "START", nullptr));
        stopButton->setText(QCoreApplication::translate("MainWindow", "STOP", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "ti", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "A", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "delay", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "amplituda", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "cykl", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "czas aktywacji", nullptr));
        resetButton->setText(QCoreApplication::translate("MainWindow", "RESET", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
