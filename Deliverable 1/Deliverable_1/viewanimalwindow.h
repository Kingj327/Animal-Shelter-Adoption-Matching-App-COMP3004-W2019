#ifndef VIEWANIMALWINDOW_H
#define VIEWANIMALWINDOW_H

#include "cuacsviewwindow.h"    // Related to cuACSViewWindow Inheritance

#include <QMainWindow>
#include <QDebug>
#include <QKeyEvent>
#include <QScreen>
#include <QMessageBox>
#include "storagedatabase.h"

namespace Ui {
class ViewAnimalWindow;
}

//class ViewAnimalWindow : public QMainWindow
class ViewAnimalWindow : public cuACSViewWindow     // Related to cuACSViewWindow Inheritance
{
    Q_OBJECT

public:
    explicit ViewAnimalWindow(QWidget *parent = 0);
    explicit ViewAnimalWindow(QWidget *parent, QList<QList<QString>> _selectedAnimalInfo, StorageDatabase *_db);
    ~ViewAnimalWindow();
    void centerScreen();
    void viewData();
    void handlePermissions(int status);

private slots:
    void on_editAnimalButton_clicked();

private:
    Ui::ViewAnimalWindow *ui;
    StorageDatabase *db;
//    int status = -1;
//    void handlePermissions();
    QVector<QString> selectedAnimalInfo;
    QVector<QString> convertFromInput(QList<QList<QString>> animalInfo);
//    void viewAnimal();
    void editAnimal();
    void closeEvent(QCloseEvent *event);
};

#endif // VIEWANIMALWINDOW_H
