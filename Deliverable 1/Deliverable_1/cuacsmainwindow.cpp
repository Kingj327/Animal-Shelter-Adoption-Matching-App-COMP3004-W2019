#include "cuacsmainwindow.h"
#include "ui_cuacsmainwindow.h"

//cuACSMainWindow::cuACSMainWindow(QWidget *parent) :
//    QMainWindow(parent),
//    ui(new Ui::cuACSMainWindow)
//{
//    ui->setupUi(this);
//}

//cuACSMainWindow::~cuACSMainWindow()
//{
//    delete ui;
//}


cuACSMainWindow::cuACSMainWindow(QWidget *parent) :
    QMainWindow(parent)
{

}

cuACSMainWindow::~cuACSMainWindow()
{

}


void cuACSMainWindow::viewAnimalList(QTableView *table, StorageDatabase *db){
    qDebug() << "\n**Running cuACSMainWindow function viewAnimalList()**";
    table->setModel(db->getQueryModel(db->getSelectAllAnimalProfiles()));
    qDebug() << "**cuACSMainWindow function viewAnimalList() Complete**";
}

void cuACSMainWindow::viewAnimal(QMainWindow *parent, QMainWindow *popUpWindow){
    qDebug() << "\ncuACSMainWindow viewAnimal(). "
                "\nHiding " << parent << ", showing "<< popUpWindow;
    parent->hide();
    popUpWindow->show();
}
