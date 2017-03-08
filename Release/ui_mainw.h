/********************************************************************************
** Form generated from reading UI file 'mainw.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINW_H
#define UI_MAINW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainw
{
public:
    QWidget *centralWidget;
    QPushButton *speedtestbutton;
    QLabel *label;
    QComboBox *comboBox;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *mainw)
    {
        if (mainw->objectName().isEmpty())
            mainw->setObjectName(QStringLiteral("mainw"));
        mainw->resize(403, 222);
        centralWidget = new QWidget(mainw);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        speedtestbutton = new QPushButton(centralWidget);
        speedtestbutton->setObjectName(QStringLiteral("speedtestbutton"));
        speedtestbutton->setGeometry(QRect(150, 130, 111, 27));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 50, 351, 51));
        label->setFrameShape(QFrame::NoFrame);
        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(10, 0, 381, 31));
        mainw->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(mainw);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 403, 25));
        mainw->setMenuBar(menuBar);
        mainToolBar = new QToolBar(mainw);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainw->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(mainw);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        mainw->setStatusBar(statusBar);

        retranslateUi(mainw);

        QMetaObject::connectSlotsByName(mainw);
    } // setupUi

    void retranslateUi(QMainWindow *mainw)
    {
        mainw->setWindowTitle(QApplication::translate("mainw", "mainw", 0));
        speedtestbutton->setText(QApplication::translate("mainw", "Test the speed", 0));
        label->setText(QApplication::translate("mainw", "<html><head/><body><p>You should select a USB-drive and push the button<br />The settings are: 4M blocks, count = 1024<br />(4096 MB of data)</p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class mainw: public Ui_mainw {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINW_H
