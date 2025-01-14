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
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
<<<<<<< Updated upstream
<<<<<<< Updated upstream
=======
    QPushButton *resetButton;
    QGraphicsView *graphicsView1;
    QLineEdit *zadaneLabel;
    QLineEdit *wyjscieLabel;
    QLabel *label_13;
    QLabel *label_14;
    QWidget *layoutWidget;
=======
    QGraphicsView *graphicsView1;
    QGraphicsView *graphicsView2;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_2;
>>>>>>> Stashed changes
    QGridLayout *gridLayout;
    QLabel *label;
>>>>>>> Stashed changes
    QLineEdit *kpLabel;
    QLineEdit *tiLabel;
    QLineEdit *tdLabel;
    QLineEdit *vecaLabel;
    QLineEdit *vecbLabel;
    QLineEdit *delayLabel;
    QLineEdit *zakloceniaLabel;
    QComboBox *sygnalcomboBox;
    QPushButton *startButton;
    QPushButton *stopButton;
    QPushButton *resetButton;
    QGraphicsView *graphicsView;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *zadaneLabel;
    QLineEdit *wyjscieLabel;
    QLineEdit *amplitudaLabel;
    QLineEdit *okresLabel;
    QLineEdit *cyklLabel;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLineEdit *aktywacjaLabel;
<<<<<<< Updated upstream
<<<<<<< Updated upstream
    QPushButton *aktualizujButton;
    QLabel *label_13;
    QLabel *label_14;
    QMenuBar *menubar;
    QMenu *menuUAR;
=======
    QGraphicsView *graphicsView2;
>>>>>>> Stashed changes
=======
    QPushButton *resetButton;
    QSplitter *splitter;
    QLabel *label_13;
    QLineEdit *zadaneLabel;
    QLabel *label_14;
    QLineEdit *wyjscieLabel;
>>>>>>> Stashed changes
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1386, 636);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
<<<<<<< Updated upstream
        kpLabel = new QLineEdit(centralwidget);
        kpLabel->setObjectName(QString::fromUtf8("kpLabel"));
        kpLabel->setGeometry(QRect(60, 510, 71, 24));
        tiLabel = new QLineEdit(centralwidget);
        tiLabel->setObjectName(QString::fromUtf8("tiLabel"));
        tiLabel->setGeometry(QRect(60, 550, 71, 24));
        tdLabel = new QLineEdit(centralwidget);
        tdLabel->setObjectName(QString::fromUtf8("tdLabel"));
        tdLabel->setGeometry(QRect(190, 510, 71, 24));
        vecaLabel = new QLineEdit(centralwidget);
        vecaLabel->setObjectName(QString::fromUtf8("vecaLabel"));
        vecaLabel->setGeometry(QRect(190, 550, 71, 24));
        vecbLabel = new QLineEdit(centralwidget);
        vecbLabel->setObjectName(QString::fromUtf8("vecbLabel"));
        vecbLabel->setGeometry(QRect(330, 510, 61, 24));
        delayLabel = new QLineEdit(centralwidget);
        delayLabel->setObjectName(QString::fromUtf8("delayLabel"));
        delayLabel->setGeometry(QRect(330, 550, 61, 24));
        zakloceniaLabel = new QLineEdit(centralwidget);
        zakloceniaLabel->setObjectName(QString::fromUtf8("zakloceniaLabel"));
        zakloceniaLabel->setGeometry(QRect(480, 510, 71, 24));
        sygnalcomboBox = new QComboBox(centralwidget);
        sygnalcomboBox->setObjectName(QString::fromUtf8("sygnalcomboBox"));
        sygnalcomboBox->setGeometry(QRect(780, 510, 65, 24));
        startButton = new QPushButton(centralwidget);
        startButton->setObjectName(QString::fromUtf8("startButton"));
        startButton->setGeometry(QRect(1040, 520, 101, 51));
        stopButton = new QPushButton(centralwidget);
        stopButton->setObjectName(QString::fromUtf8("stopButton"));
        stopButton->setGeometry(QRect(1160, 520, 91, 51));
        resetButton = new QPushButton(centralwidget);
        resetButton->setObjectName(QString::fromUtf8("resetButton"));
        resetButton->setGeometry(QRect(1270, 520, 91, 51));
<<<<<<< Updated upstream
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(10, 0, 1221, 491));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 510, 21, 16));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 550, 16, 16));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(170, 510, 21, 16));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(170, 550, 21, 16));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(310, 510, 21, 16));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(290, 550, 31, 16));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(420, 510, 61, 16));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(700, 510, 71, 16));
=======
        graphicsView1 = new QGraphicsView(centralwidget);
        graphicsView1->setObjectName(QString::fromUtf8("graphicsView1"));
        graphicsView1->setGeometry(QRect(10, 10, 1221, 231));
>>>>>>> Stashed changes
        zadaneLabel = new QLineEdit(centralwidget);
        zadaneLabel->setObjectName(QString::fromUtf8("zadaneLabel"));
        zadaneLabel->setGeometry(QRect(1250, 100, 121, 71));
        wyjscieLabel = new QLineEdit(centralwidget);
        wyjscieLabel->setObjectName(QString::fromUtf8("wyjscieLabel"));
        wyjscieLabel->setGeometry(QRect(1250, 260, 121, 71));
        amplitudaLabel = new QLineEdit(centralwidget);
        amplitudaLabel->setObjectName(QString::fromUtf8("amplitudaLabel"));
        amplitudaLabel->setGeometry(QRect(480, 550, 71, 24));
        okresLabel = new QLineEdit(centralwidget);
        okresLabel->setObjectName(QString::fromUtf8("okresLabel"));
        okresLabel->setGeometry(QRect(610, 510, 71, 24));
        cyklLabel = new QLineEdit(centralwidget);
        cyklLabel->setObjectName(QString::fromUtf8("cyklLabel"));
        cyklLabel->setGeometry(QRect(610, 550, 71, 24));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(420, 550, 61, 16));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(570, 510, 31, 16));
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(570, 550, 31, 16));
        label_12 = new QLabel(centralwidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(690, 550, 81, 20));
        aktywacjaLabel = new QLineEdit(centralwidget);
        aktywacjaLabel->setObjectName(QString::fromUtf8("aktywacjaLabel"));
        aktywacjaLabel->setGeometry(QRect(780, 550, 71, 24));
        aktualizujButton = new QPushButton(centralwidget);
        aktualizujButton->setObjectName(QString::fromUtf8("aktualizujButton"));
        aktualizujButton->setGeometry(QRect(920, 520, 101, 51));
        label_13 = new QLabel(centralwidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(1290, 80, 49, 16));
        label_14 = new QLabel(centralwidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(1290, 240, 49, 16));
<<<<<<< Updated upstream
=======
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(40, 510, 1183, 56));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
=======
        graphicsView1 = new QGraphicsView(centralwidget);
        graphicsView1->setObjectName(QString::fromUtf8("graphicsView1"));
        graphicsView1->setGeometry(QRect(110, 10, 1000, 250));
        graphicsView2 = new QGraphicsView(centralwidget);
        graphicsView2->setObjectName(QString::fromUtf8("graphicsView2"));
        graphicsView2->setGeometry(QRect(110, 260, 1000, 250));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(40, 560, 1271, 58));
        gridLayout_2 = new QGridLayout(layoutWidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
>>>>>>> Stashed changes
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        kpLabel = new QLineEdit(layoutWidget);
        kpLabel->setObjectName(QString::fromUtf8("kpLabel"));

        gridLayout->addWidget(kpLabel, 0, 1, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 0, 2, 1, 1);

        tdLabel = new QLineEdit(layoutWidget);
        tdLabel->setObjectName(QString::fromUtf8("tdLabel"));

        gridLayout->addWidget(tdLabel, 0, 3, 1, 1);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 0, 4, 1, 1);

        vecbLabel = new QLineEdit(layoutWidget);
        vecbLabel->setObjectName(QString::fromUtf8("vecbLabel"));

        gridLayout->addWidget(vecbLabel, 0, 5, 1, 1);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 0, 6, 1, 1);

        zakloceniaLabel = new QLineEdit(layoutWidget);
        zakloceniaLabel->setObjectName(QString::fromUtf8("zakloceniaLabel"));

        gridLayout->addWidget(zakloceniaLabel, 0, 7, 1, 1);

        label_10 = new QLabel(layoutWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout->addWidget(label_10, 0, 8, 1, 1);

        okresLabel = new QLineEdit(layoutWidget);
        okresLabel->setObjectName(QString::fromUtf8("okresLabel"));

        gridLayout->addWidget(okresLabel, 0, 9, 1, 1);

        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 0, 10, 1, 1);

        sygnalcomboBox = new QComboBox(layoutWidget);
        sygnalcomboBox->setObjectName(QString::fromUtf8("sygnalcomboBox"));

        gridLayout->addWidget(sygnalcomboBox, 0, 11, 1, 1);

        aktualizujButton = new QPushButton(layoutWidget);
        aktualizujButton->setObjectName(QString::fromUtf8("aktualizujButton"));

        gridLayout->addWidget(aktualizujButton, 0, 12, 2, 1);

        startButton = new QPushButton(layoutWidget);
        startButton->setObjectName(QString::fromUtf8("startButton"));

        gridLayout->addWidget(startButton, 0, 13, 2, 1);

        stopButton = new QPushButton(layoutWidget);
        stopButton->setObjectName(QString::fromUtf8("stopButton"));

        gridLayout->addWidget(stopButton, 0, 14, 2, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        tiLabel = new QLineEdit(layoutWidget);
        tiLabel->setObjectName(QString::fromUtf8("tiLabel"));

        gridLayout->addWidget(tiLabel, 1, 1, 1, 1);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 1, 2, 1, 1);

        vecaLabel = new QLineEdit(layoutWidget);
        vecaLabel->setObjectName(QString::fromUtf8("vecaLabel"));

        gridLayout->addWidget(vecaLabel, 1, 3, 1, 1);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 1, 4, 1, 1);

        delayLabel = new QLineEdit(layoutWidget);
        delayLabel->setObjectName(QString::fromUtf8("delayLabel"));

        gridLayout->addWidget(delayLabel, 1, 5, 1, 1);

        label_9 = new QLabel(layoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout->addWidget(label_9, 1, 6, 1, 1);

        amplitudaLabel = new QLineEdit(layoutWidget);
        amplitudaLabel->setObjectName(QString::fromUtf8("amplitudaLabel"));

        gridLayout->addWidget(amplitudaLabel, 1, 7, 1, 1);

        label_11 = new QLabel(layoutWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout->addWidget(label_11, 1, 8, 1, 1);

        cyklLabel = new QLineEdit(layoutWidget);
        cyklLabel->setObjectName(QString::fromUtf8("cyklLabel"));

        gridLayout->addWidget(cyklLabel, 1, 9, 1, 1);

        label_12 = new QLabel(layoutWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout->addWidget(label_12, 1, 10, 1, 1);

        aktywacjaLabel = new QLineEdit(layoutWidget);
        aktywacjaLabel->setObjectName(QString::fromUtf8("aktywacjaLabel"));

        gridLayout->addWidget(aktywacjaLabel, 1, 11, 1, 1);

<<<<<<< Updated upstream
        graphicsView2 = new QGraphicsView(centralwidget);
        graphicsView2->setObjectName(QString::fromUtf8("graphicsView2"));
        graphicsView2->setGeometry(QRect(10, 240, 1221, 231));
>>>>>>> Stashed changes
=======

        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        resetButton = new QPushButton(layoutWidget);
        resetButton->setObjectName(QString::fromUtf8("resetButton"));

        gridLayout_2->addWidget(resetButton, 0, 1, 1, 1);

        splitter = new QSplitter(centralwidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setGeometry(QRect(1160, 140, 161, 171));
        splitter->setOrientation(Qt::Vertical);
        label_13 = new QLabel(splitter);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        splitter->addWidget(label_13);
        zadaneLabel = new QLineEdit(splitter);
        zadaneLabel->setObjectName(QString::fromUtf8("zadaneLabel"));
        splitter->addWidget(zadaneLabel);
        label_14 = new QLabel(splitter);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        splitter->addWidget(label_14);
        wyjscieLabel = new QLineEdit(splitter);
        wyjscieLabel->setObjectName(QString::fromUtf8("wyjscieLabel"));
        splitter->addWidget(wyjscieLabel);
>>>>>>> Stashed changes
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1386, 21));
        menuUAR = new QMenu(menubar);
        menuUAR->setObjectName(QString::fromUtf8("menuUAR"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuUAR->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
<<<<<<< Updated upstream
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
=======
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "UAR", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "kp", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "td", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "B", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "zaklocenia", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "okres", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "typ sygnalu", nullptr));
        aktualizujButton->setText(QCoreApplication::translate("MainWindow", "AKTUALIZUJ", nullptr));
>>>>>>> Stashed changes
        startButton->setText(QCoreApplication::translate("MainWindow", "START", nullptr));
        stopButton->setText(QCoreApplication::translate("MainWindow", "STOP", nullptr));
        resetButton->setText(QCoreApplication::translate("MainWindow", "RESET", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "kp", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "ti", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "td", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "A", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "B", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "delay", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "zaklocenia", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "typ sygnalu", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "amplituda", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "okres", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "cykl", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "czas aktywacji", nullptr));
<<<<<<< Updated upstream
        aktualizujButton->setText(QCoreApplication::translate("MainWindow", "AKTUALIZUJ", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Wej\305\233cie", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Wyj\305\233cie", nullptr));
        menuUAR->setTitle(QCoreApplication::translate("MainWindow", "UAR", nullptr));
=======
        resetButton->setText(QCoreApplication::translate("MainWindow", "RESET", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Wej\305\233cie", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Wyj\305\233cie", nullptr));
>>>>>>> Stashed changes
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
