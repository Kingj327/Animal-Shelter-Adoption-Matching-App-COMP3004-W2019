#ifndef CUACSMAINWINDOW_H
#define CUACSMAINWINDOW_H

#include <QMainWindow>
#include <QTableView>

#include "storagedatabase.h"

namespace Ui {
class cuACSMainWindow;
}

class cuACSMainWindow : public QMainWindow
{
//    Q_OBJECT

public:
    explicit cuACSMainWindow(QWidget *parent = 0);
    virtual ~cuACSMainWindow() = 0;     // Related to cuACSMainWindow Inheritance (Makes this
                                        // an abstract class by having a pure virtual function)

//    void home();
    void viewAnimalList(QTableView *table, StorageDatabase *db);
    void viewAnimal(QMainWindow *parent, QMainWindow *popUpWindow);
//    void editClient();

private:
//    Ui::cuACSMainWindow *ui;
};

#endif // CUACSMAINWINDOW_H
