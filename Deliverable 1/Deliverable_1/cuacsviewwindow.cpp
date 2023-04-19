#include "cuacsviewwindow.h"
#include "ui_cuacsviewwindow.h"

//cuACSViewWindow::cuACSViewWindow(QWidget *parent) :
//    QMainWindow(parent),
//    ui(new Ui::cuACSViewWindow)
//{
//    ui->setupUi(this);
//}

//cuACSViewWindow::~cuACSViewWindow()
//{
//    delete ui;
//}


cuACSViewWindow::cuACSViewWindow(QWidget *parent) :
    QMainWindow(parent)
{
    qDebug() << "cuACSViewWindow()";
}

cuACSViewWindow::~cuACSViewWindow()
{
    qDebug() << "~cuACSViewWindow()";
}
