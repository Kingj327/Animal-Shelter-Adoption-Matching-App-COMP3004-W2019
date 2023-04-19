/********************************************************************************
** Form generated from reading UI file 'cuacsmainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUACSMAINWINDOW_H
#define UI_CUACSMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_cuACSMainWindow
{
public:
    QMenuBar *menubar;
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *cuACSMainWindow)
    {
        if (cuACSMainWindow->objectName().isEmpty())
            cuACSMainWindow->setObjectName(QStringLiteral("cuACSMainWindow"));
        cuACSMainWindow->resize(800, 600);
        menubar = new QMenuBar(cuACSMainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        cuACSMainWindow->setMenuBar(menubar);
        centralwidget = new QWidget(cuACSMainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        cuACSMainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(cuACSMainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        cuACSMainWindow->setStatusBar(statusbar);

        retranslateUi(cuACSMainWindow);

        QMetaObject::connectSlotsByName(cuACSMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *cuACSMainWindow)
    {
        cuACSMainWindow->setWindowTitle(QApplication::translate("cuACSMainWindow", "MainWindow", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class cuACSMainWindow: public Ui_cuACSMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUACSMAINWINDOW_H
