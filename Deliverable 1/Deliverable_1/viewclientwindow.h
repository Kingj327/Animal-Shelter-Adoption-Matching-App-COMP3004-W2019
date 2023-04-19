#ifndef VIEWCLIENTWINDOW_H
#define VIEWCLIENTWINDOW_H

#include "cuacsviewwindow.h"    // Related to cuACSViewWindow Inheritance

#include <QMainWindow>
#include <QDebug>
#include <QKeyEvent>
#include <QScreen>
#include <QMessageBox>
#include "storagedatabase.h"

namespace Ui {
class ViewClientWindow;
}

//class ViewClientWindow : public QMainWindow
class ViewClientWindow : public cuACSViewWindow     // Related to cuACSViewWindow Inheritance
{
    Q_OBJECT

public:
    explicit ViewClientWindow(QWidget *parent = 0);
    explicit ViewClientWindow(QWidget *parent, QList<QList<QString>> _selectedClientInfo, StorageDatabase *_db);
    ~ViewClientWindow();
    void centerScreen();
    void viewData();
    void handlePermissions(int status);

private slots:
    void on_editClientButton_clicked();

private:
    Ui::ViewClientWindow *ui;
    StorageDatabase *db;
//    int status = -1;
//    void handlePermissions();
    QVector<QString> selectedClientInfo;
    QVector<QString> convertFromInput(QList<QList<QString>> clientInfo);
//    void viewClient();
    void editClient();
    void closeEvent(QCloseEvent *event);
};

#endif // VIEWCLIENTWINDOW_H
