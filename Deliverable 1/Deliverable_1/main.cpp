#include "mainwindow.h"
#include "loginpage.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setQuitOnLastWindowClosed(false);
    //MainWindow w;
//    LoginPage l;
//    l.show();
    LoginPage* l = LoginPage::getInstance();
    l->show();
    //w.show();

    a.exec();
    l->~LoginPage();

//    return a.exec();    // Runs the Application
}
