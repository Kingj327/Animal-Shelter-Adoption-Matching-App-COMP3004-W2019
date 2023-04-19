#ifndef MAINWINDOWCLIENT_H
#define MAINWINDOWCLIENT_H

#include "cuacsmainwindow.h"    // Related to cuACSMainWindow Inhetitance

//#include <QMainWindow>
#include <QSqlQueryModel>
#include <QMessageBox>
#include "storagedatabase.h"
#include "animal.h"

#include "viewanimalwindow.h"

namespace Ui {
class MainWindowClient;
}

//class MainWindowClient : public QMainWindow
class MainWindowClient : public cuACSMainWindow     // Related to cuACSMainWindow Inheritance
{
    Q_OBJECT

public:
    explicit MainWindowClient(QWidget *parent = 0);
    ~MainWindowClient();

private slots:
    void on_pushButton_clicked();   // for pushButton

    void on_queryPageSwitchButton_clicked();

    void on_viewAnimalPageSwitchButton_clicked();

    void on_homePageSwitchButton_clicked();

    /* NOTE: Shouldn't be a client functionality */
//    void on_viewClientPageSwitchButton_clicked();

    void on_logoutButton_clicked();

    void on_viewSelectedAnimal_clicked();

private:
    Ui::MainWindowClient *ui;
    ViewAnimalWindow *popUpWindow;
    StorageDatabase db; // Database
    QList<Animal*> animalsCollection;   // Collection of all our animals
    void createAllAnimalsFromDatabase();    // Initializes all animals
    void addNewAnimal();

    void closeEvent(QCloseEvent *event);
};

#endif // MAINWINDOWCLIENT_H
