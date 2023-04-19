#ifndef LOGINPAGE_H
#define LOGINPAGE_H

#include <QMainWindow>
#include <QMessageBox>
#include <QScreen>
#include "mainwindow.h"
#include "mainwindowclient.h"

namespace Ui {
class LoginPage;
}

class LoginPage : public QMainWindow
{
    Q_OBJECT

public:
    static LoginPage* getInstance(QWidget *parent = 0);    // Static Access Method (Singleton)
//    explicit LoginPage(QWidget *parent = 0);
    ~LoginPage();


private slots:
    void on_pushButton_Login_clicked();

    void on_lineEdit_username_returnPressed();

    void on_lineEdit_password_returnPressed();

private:
    explicit LoginPage(QWidget *parent = 0);    // Private Constructor (Singleton)
    static LoginPage* instance;
    Ui::LoginPage *ui;
    MainWindow *mainWindow;
    StorageDatabase db;
//    QList<QList<QString>> * loginInfo;
//    MainWindowClient *mainWindowClient;
    QList<QList<QString>> *loginInfo;
//    QList<QList<QString>> loginInfo =
//        {{"-1", "Client", "client123"},
//         {"0", "Staff", "admin123"},
//         {"1", "MGonz", "Max25"},
//         {"2", "KFort", "Kyleigh31"},
//         {"3", "JJone", "James1"},
//         {"4", "AMarc", "Aleksandr1"},
//         {"5", "JMath", "Jordan24"},
//         {"6", "EKing", "Elissa23"},
//         {"7", "JPant", "Jordan1"},
//         {"8", "OAllm", "Olivia24"},
//         {"9", "JLund", "Jordan11"},
//         {"10", "JWils", "James1"},
//         {"11", "LHenf", "Liam24"},
//         {"12", "JFort", "Johnathon7"},
//         {"13", "MOlso", "Mikayla21"},
//         {"14", "JKabo", "Jim13"},
//         {"15", "HKano", "Hoda8"},
//         {"16", "GJane", "Gilbert6"},
//         {"17", "JChri", "Jesus11"},
//         {"18", "LZulu", "Lima12"},
//         {"19", "SPie", "Scorpio4"},
//         {"20", "HDing", "Hahvok17"}};
    void authenticate();
    void launchMainWindow(int status, int id);
    void centerScreen();
    void closeEvent(QCloseEvent *event);
};

#endif // LOGINPAGE_H
