#include "mainwindowclient.h"
#include "ui_mainwindowclient.h"

MainWindowClient::MainWindowClient(QWidget *parent) :
//    QMainWindow(parent),
    cuACSMainWindow(parent),    // Related to cuACSMainWindow Inheritance
    ui(new Ui::MainWindowClient)
{
    ui->setupUi(this);
    db.loadDatabase();  // Connects to database and loads data into this object
    createAllAnimalsFromDatabase();
}

MainWindowClient::~MainWindowClient()
{
    qDebug() << "~MainWindowClient()";
    delete ui;
    db.closeDatabase(); // Closes database (maybe move to class destructor)
}

/** When pushButton is clicked, run the query in the textEdit field,
  * save the results to a QList "results", and output those results
  * to textField_2.
  * NOTE: This is used to test the database. Not needed for assignment **/
void MainWindowClient::on_pushButton_clicked()
{
    QString queryText = ui->textEdit->toPlainText();    // Gets query

    QSqlQuery query;
    query.prepare(queryText);   // Inputs text in query object
    query.exec();   // Runs query

    // Goes through and saves all the query results to "results"
    QList<QList<QString>> results;
    while (query.next()) {
        int i = 0;
        QList<QString> row;
        while(query.value(i).isValid()){
            row.append(query.value(i++).toString());
        }
        results.append(row);
    }


    // Outputs query text to textEdit_2 one word at a time, and moves
    // cursor to the end of the text field before writing each word.
    qDebug() << "\nOutputting Query results for \'" << queryText <<"\'";
    ui->textEdit_2->clear();    // Clears text field
    for (int i = 0; i < results.size(); i++){
        ui->textEdit_2->moveCursor(QTextCursor::End);
        ui->textEdit_2->insertPlainText("(");

        for (int j = 0; j < results[i].size(); j++){
            QString word = results[i][j];
            if (j != 0) word = ", " + word;
            ui->textEdit_2->moveCursor(QTextCursor::End);
            ui->textEdit_2->insertPlainText(word);
        }

        ui->textEdit_2->moveCursor(QTextCursor::End);
        ui->textEdit_2->insertPlainText(")\n");
    }
}


/** Creates and Initializes all the Animal objects from the data in the
  * database upon loading up the application. **/
void MainWindowClient::createAllAnimalsFromDatabase(){
    qDebug() << "\nCreating animal objects...";
    for (int i = 0; i < db.getCompleteAnimalList().size(); i++){
        QList<QList<QString>> animalInfo = db.getSpecificAnimal(i);
        Animal *tempAnimal = new Animal(&animalInfo);
        animalsCollection.append(tempAnimal);
    }
    qDebug() << "...Finished creating animals";
}


void MainWindowClient::on_queryPageSwitchButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindowClient::on_viewAnimalPageSwitchButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);

    // Get all animal info from database in the form of a QSqlQueryModel
//    ui->tableView_viewAnimals->setModel(db.getQueryModel(db.getSelectAllAnimalProfiles()));

    // Runs parent function to load animal list from db to QTableView object
    viewAnimalList(ui->tableView_viewAnimals, &db);
}

void MainWindowClient::on_homePageSwitchButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

/* NOTE: Shouldn't be a client functionality */
//void MainWindowClient::on_viewClientPageSwitchButton_clicked()
//{
//    ui->stackedWidget->setCurrentIndex(4);

//    // Get all client info from database in the form of a QSqlQueryModel
//    ui->tableView_viewClients->setModel(db.getQueryModel(db.getSelectAllClientProfiles()));
//}


void MainWindowClient::on_viewSelectedAnimal_clicked()
{
    popUpWindow = new ViewAnimalWindow(this);
    viewAnimal(this, (QMainWindow*)popUpWindow);
}

void MainWindowClient::closeEvent(QCloseEvent *event){
    this->parentWidget()->show();
//    this->~MainWindowClient();
    delete this;
    event->accept();
}

void MainWindowClient::on_logoutButton_clicked()
{
    qDebug() << "\nLogging out of " << this;
    close();
}



