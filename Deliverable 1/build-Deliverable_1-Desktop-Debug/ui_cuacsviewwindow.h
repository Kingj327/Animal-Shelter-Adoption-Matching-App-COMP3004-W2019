/********************************************************************************
** Form generated from reading UI file 'cuacsviewwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUACSVIEWWINDOW_H
#define UI_CUACSVIEWWINDOW_H

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

class Ui_cuACSViewWindow
{
public:
    QMenuBar *menubar;
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *cuACSViewWindow)
    {
        if (cuACSViewWindow->objectName().isEmpty())
            cuACSViewWindow->setObjectName(QStringLiteral("cuACSViewWindow"));
        cuACSViewWindow->resize(800, 600);
        menubar = new QMenuBar(cuACSViewWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        cuACSViewWindow->setMenuBar(menubar);
        centralwidget = new QWidget(cuACSViewWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        cuACSViewWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(cuACSViewWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        cuACSViewWindow->setStatusBar(statusbar);

        retranslateUi(cuACSViewWindow);

        QMetaObject::connectSlotsByName(cuACSViewWindow);
    } // setupUi

    void retranslateUi(QMainWindow *cuACSViewWindow)
    {
        cuACSViewWindow->setWindowTitle(QApplication::translate("cuACSViewWindow", "MainWindow", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class cuACSViewWindow: public Ui_cuACSViewWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUACSVIEWWINDOW_H
