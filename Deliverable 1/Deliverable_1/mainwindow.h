#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "cuacsmainwindow.h"    // Related to cuACSMainWindow Inheritance

#include <QMainWindow>
#include <QSqlQueryModel>
#include <QMessageBox>
#include "storagedatabase.h"
#include "animal.h"
#include "viewanimalwindow.h"
#include "viewclientwindow.h"
#include "cuacsmatchingalgorithm.h"

#include <QKeyEvent>
#include <QScreen>
#include <QStandardItemModel>
#include <QStandardItem>

namespace Ui {
class MainWindow;
}

//class MainWindow : public QMainWindow
class MainWindow: public cuACSMainWindow    // Related to cuACSMainWindow Inheritance
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0, StorageDatabase *_db = 0);
    explicit MainWindow(QWidget *parent, StorageDatabase *_db, int _status, int _id = -1);
    ~MainWindow();
    void centerScreen();

private slots:


    // Page Switch Buttons.
    void on_homePageSwitchButton_clicked();
    void on_queryPageSwitchButton_clicked();
    void on_addAnimalPageSwitchButton_clicked();
    void on_addClientPageSwitchButton_clicked();
    void on_viewAnimalPageSwitchButton_clicked();
    void on_viewClientPageSwitchButton_clicked();

    // Additional buttons
    void handleViewWindow();
    void on_runQueryButton_clicked();
    void on_addAnimalButton_clicked();
    void on_addClientButton_clicked();
    void on_viewSelectedAnimalButton_clicked();
    void on_viewSelectedClientButton_clicked();
    void on_logoutButton_clicked();


    void on_runACMAlgorithmButton_clicked();

private:
    Ui::MainWindow *ui;
    ViewAnimalWindow *animalWindow;
    ViewClientWindow *clientWindow;
    cuACSViewWindow *viewWindow = 0;
    QAbstractItemModel *model;
    StorageDatabase *db; // Database
    cuACSMatchingAlgorithm *alg;
    QList<Animal*> animalsCollection;   // Collection of all our animals
    int status = 0; // -1 = error, 0 = default, 1 = staff, 2 = client
    int id = -1; // Client specific id from db
    void createAllAnimalsFromDatabase();    // Initializes all animals
    void handleUserPermissions();
    void addNewAnimal();
    void addNewClient();

    void closeEvent(QCloseEvent *event);
};

#endif // MAINWINDOW_H
