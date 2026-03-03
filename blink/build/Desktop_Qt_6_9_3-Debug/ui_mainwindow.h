/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *image;
    QLabel *led0;
    QLabel *led1;
    QLabel *led2;
    QLabel *led3;
    QLabel *led4;
    QLabel *led5;
    QLabel *led6;
    QPushButton *update_color_value;
    QTextEdit *color_value;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        image = new QLabel(centralwidget);
        image->setObjectName("image");
        image->setGeometry(QRect(230, 90, 361, 331));
        led0 = new QLabel(centralwidget);
        led0->setObjectName("led0");
        led0->setGeometry(QRect(310, 140, 81, 81));
        led0->setStyleSheet(QString::fromUtf8("border-radius: 35px;\n"
" background-color: white;"));
        led1 = new QLabel(centralwidget);
        led1->setObjectName("led1");
        led1->setGeometry(QRect(400, 140, 81, 81));
        led1->setStyleSheet(QString::fromUtf8("border-radius: 35px;\n"
"background-color: white;"));
        led2 = new QLabel(centralwidget);
        led2->setObjectName("led2");
        led2->setGeometry(QRect(260, 220, 81, 91));
        led2->setStyleSheet(QString::fromUtf8("border-radius: 35px;\n"
"background-color: white;"));
        led3 = new QLabel(centralwidget);
        led3->setObjectName("led3");
        led3->setGeometry(QRect(350, 220, 81, 91));
        led3->setStyleSheet(QString::fromUtf8("border-radius: 35px;\n"
"background-color: white;"));
        led4 = new QLabel(centralwidget);
        led4->setObjectName("led4");
        led4->setGeometry(QRect(440, 220, 81, 91));
        led4->setStyleSheet(QString::fromUtf8("border-radius: 35px;\n"
"background-color: white;"));
        led5 = new QLabel(centralwidget);
        led5->setObjectName("led5");
        led5->setGeometry(QRect(310, 290, 81, 81));
        led5->setStyleSheet(QString::fromUtf8("border-radius: 35px;\n"
"background-color: white;"));
        led6 = new QLabel(centralwidget);
        led6->setObjectName("led6");
        led6->setGeometry(QRect(400, 290, 81, 81));
        led6->setStyleSheet(QString::fromUtf8("border-radius: 35px;\n"
"background-color: white;"));
        update_color_value = new QPushButton(centralwidget);
        update_color_value->setObjectName("update_color_value");
        update_color_value->setGeometry(QRect(490, 430, 96, 31));
        color_value = new QTextEdit(centralwidget);
        color_value->setObjectName("color_value");
        color_value->setGeometry(QRect(240, 430, 241, 31));
        MainWindow->setCentralWidget(centralwidget);
        led1->raise();
        led2->raise();
        led0->raise();
        led4->raise();
        led3->raise();
        led6->raise();
        led5->raise();
        image->raise();
        update_color_value->raise();
        color_value->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        image->setText(QString());
        led0->setText(QString());
        led1->setText(QString());
        led2->setText(QString());
        led3->setText(QString());
        led4->setText(QString());
        led5->setText(QString());
        led6->setText(QString());
        update_color_value->setText(QCoreApplication::translate("MainWindow", "SET", nullptr));
        color_value->setPlaceholderText(QCoreApplication::translate("MainWindow", "RRR,GGG,BBB", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
