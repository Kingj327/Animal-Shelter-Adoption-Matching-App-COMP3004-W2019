#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include "storagedatabase.h"


/*************************************************************************************************
                                    Functions used for initalization
**************************************************************************************************/


/** Constructor **/
MainWindow::MainWindow(QWidget *parent, StorageDatabase *_db) :
//    QMainWindow(parent),
    cuACSMainWindow(parent),    // Related to cuACSMainWindow Inheritance
    ui(new Ui::MainWindow)
{
    qDebug() << "MainWindow(QWidget)";
    ui->setupUi(this);
    ui->refreshLabelClient->setVisible(false);
    ui->refreshLabelAnimal->setVisible(false);
    centerScreen();
    status = -1;
    handleUserPermissions();
    db = _db;
//    db.loadDatabase();  // Connects to database and loads data into this object
    createAllAnimalsFromDatabase();
}

MainWindow::MainWindow(QWidget *parent, StorageDatabase *_db, int _status, int _id) :
//    QMainWindow(parent),
    cuACSMainWindow(parent),    // Related to cuACSMainWindow Inheritance
    ui(new Ui::MainWindow)
{
    qDebug() << "MainWindow(QWidget, int)";
    ui->setupUi(this);
    ui->refreshLabelClient->setVisible(false);
    ui->refreshLabelAnimal->setVisible(false);
    centerScreen();
    status = _status;
    id = _id;
    qDebug() << "Status = " << status << ", ID is = " << id;
    handleUserPermissions();
    db = _db;
//    db.loadDatabase();  // Connects to database and loads data into this object
    createAllAnimalsFromDatabase();
}


/** Desctuctor **/
MainWindow::~MainWindow()
{
    qDebug() << "~MainWindow()";
    delete ui;
//    db.closeDatabase(); // Closes database (maybe move to class destructor)
}



void MainWindow::centerScreen(){
    int screenWidth = QGuiApplication::primaryScreen()->geometry().width();
    int screenHeight = QGuiApplication::primaryScreen()->geometry().height();
    int width = this->geometry().width();
    int height = this->geometry().height();
    this->setGeometry((screenWidth/2) - (width/2), (screenHeight/2) - (height/2), width, height);
}


/** Creates and Initializes all the Animal objects from the data in the
  * database upon loading up the application. **/
void MainWindow::createAllAnimalsFromDatabase(){
    qDebug() << "\nCreating animal objects...";
    for (int i = 0; i < db->getCompleteAnimalList().size(); i++){
        QList<QList<QString>> animalInfo = db->getSpecificAnimal(i);
        Animal *tempAnimal = new Animal(&animalInfo);
        animalsCollection.append(tempAnimal);
    }
    qDebug() << "...Finished creating animals";
}



void MainWindow::handleUserPermissions(){
    if (status == 1){ // Staff
        ui->homePageSwitchButton->setEnabled(true);
        ui->queryPageSwitchButton->setEnabled(true);
        ui->addAnimalPageSwitchButton->setEnabled(true);
        ui->addClientPageSwitchButton->setEnabled(true);
        ui->viewAnimalPageSwitchButton->setEnabled(true);
        ui->viewClientPageSwitchButton->setEnabled(true);
        ui->runACMAlgorithmButton->setEnabled(true);
    } else { // Ignoring Error cases and such, we'll say if you're not a staff, you're a client.
        ui->homePageSwitchButton->setEnabled(true);
        ui->queryPageSwitchButton->setEnabled(false);
        ui->addAnimalPageSwitchButton->setEnabled(false);
        ui->addClientPageSwitchButton->setEnabled(false);
        ui->viewAnimalPageSwitchButton->setEnabled(true);
        ui->viewClientPageSwitchButton->setEnabled(true);
        ui->runACMAlgorithmButton->setEnabled(false);
    }
}


/*************************************************************************************************
                                    Page Switch Buttons
**************************************************************************************************/


void MainWindow::on_homePageSwitchButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_queryPageSwitchButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_addAnimalPageSwitchButton_clicked()
{
    
    ui->stackedWidget->setCurrentIndex(2);

    // Setting ANIMALID field
//    qDebug() << "AnimalID = "<< QString::number(db->getMaxAnimalID());
//    qDebug() << "AnimalID = "<< db->getMaxAnimalID();
    ui->lineEdit->setText(QString::number(db->getMaxAnimalID()));
}

void MainWindow::on_addClientPageSwitchButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);

    // Setting CLIENTID field
    ui->clientIDEdit->setText(QString::number(db->getMaxClientID()));
}

void MainWindow::on_viewAnimalPageSwitchButton_clicked()
{
    ui->refreshLabelAnimal->setVisible(false);
    ui->stackedWidget->setCurrentIndex(4);

    // Get all animal info from database in the form of a QSqlQueryModel
    model = db->getQueryModel(db->getSelectAllAnimalProfiles());
    ui->tableView_viewAnimals->setModel(model);

    // Runs parent function to load animal list from db to QTableView object
//    viewAnimalList(ui->tableView_viewAnimals, &db);
}

void MainWindow::on_viewClientPageSwitchButton_clicked()
{
    if (status == 1){
        ui->refreshLabelClient->setVisible(false);
        ui->stackedWidget->setCurrentIndex(5);

        // Get all client info from database in the form of a QSqlQueryModel
        model = db->getQueryModel(db->getSelectAllClientProfiles());
        ui->tableView_viewClients->setModel(model);
    } else if (status == 2 && id != -1){
        ui->refreshLabelClient->setVisible(false);
//        ui->stackedWidget->setCurrentIndex(5);

        // Get all client info from database in the form of a QSqlQueryModel
        QList<QList<QString>> selectedClientInfo = db->getSpecificClientByID(id);
        qDebug() << selectedClientInfo;
        if (selectedClientInfo.isEmpty()) {
            QMessageBox::warning(this, "Client ID Error",
                                 "Couldn't find a client with that ID in our database."
                                 "\n\nIs it possible that you didn't select (click on/highlight) a client that you'd like to view?");
        } else {
//            if (viewWindow != 0) { delete viewWindow; }
            viewWindow = new ViewClientWindow(this, selectedClientInfo, db);    // Bridge pattern
            handleViewWindow();
            if (status == 1) ui->refreshLabelClient->setVisible(true);  // ie. if staff
        }
    } else {
        qDebug() << "Non-Staff trying to see client list. Show them their own details."
                    "    NOTE: For now its just a random user.";

    }
}


// Implements the bridge pattern for pop-up view windows.
void MainWindow::handleViewWindow(){
//        if (viewWindow != 0) { delete viewWindow; }
        viewWindow->handlePermissions(status);
        viewWindow->viewData();
        qDebug() << "\nHiding " << this << ", showing "<< animalWindow;
        hide();
        viewWindow->show();
}

/*************************************************************************************************
                                    Additional Buttons
**************************************************************************************************/


/** When pushButton is clicked, run the query in the textEdit field,
  * save the results to a QList "results", and output those results
  * to textField_2.
  * NOTE: This is used to test the database. Not needed for assignment **/
void MainWindow::on_runQueryButton_clicked()
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


void MainWindow::on_addAnimalButton_clicked()
{
    // Check if the inputted ID is too large. If so, complain.
    if (ui->lineEdit->text().toInt() > (5 * db->getCompleteAnimalList().length())){
        QString err = "Error: Animal ID must be less than the number of animals in the system "
                "multiplied by 5. \n\nMake sure the ID is less than " +
                QString::fromStdString(std::to_string(5 * db->getCompleteAnimalList().length()));
        qDebug() << err;
        QMessageBox::critical(this, tr("Error"), err);
    } else {
        addNewAnimal();
    }
}


void MainWindow::on_addClientButton_clicked()
{
    // Check if the inputted ID is too large. If so, complain.
    if (ui->clientIDEdit->text().toInt() > (5 * db->getCompleteClientList().length())){
        QString err = "Error: Client ID must be less than the number of clients in the system "
                "multiplied by 5. \n\nMake sure the ID is less than " +
                QString::fromStdString(std::to_string(5 * db->getCompleteClientList().length()));
        qDebug() << err;
        QMessageBox::critical(this, tr("Error"), err);
    } else {
        addNewClient();
    }
}


void MainWindow::on_viewSelectedAnimalButton_clicked()
{
    int rowIndex = ui->tableView_viewAnimals->selectionModel()->currentIndex().row();
    int id = model->index(rowIndex, 0).data().toInt();
//    for (int i = 0; i < model->columnCount(); i++){
//        selectedAnimalInfo->append(&(model->index(rowIndex,i).data().toString()));
//    }
    QList<QList<QString>> selectedAnimalInfo = db->getSpecificAnimalByID(id);
    qDebug() << selectedAnimalInfo;
    if (selectedAnimalInfo.isEmpty()) {
        QMessageBox::warning(this, "Animal ID Error",
                             "Couldn't find an animal with that ID in our database."
                             "\n\nIs it possible that you didn't select (click on/highlight) an animal that you'd like to view?");
    } else {
        viewWindow = new ViewAnimalWindow(this, selectedAnimalInfo, db);    // Bridge pattern
        handleViewWindow();
        if (status == 1) ui->refreshLabelAnimal->setVisible(true);  // ie. if staff
    }
}


void MainWindow::on_viewSelectedClientButton_clicked()
{
    int rowIndex = ui->tableView_viewClients->selectionModel()->currentIndex().row();
    int id = model->index(rowIndex, 0).data().toInt();
    QList<QList<QString>> selectedClientInfo = db->getSpecificClientByID(id);
    qDebug() << selectedClientInfo;
    if (selectedClientInfo.isEmpty()) {
        QMessageBox::warning(this, "Client ID Error",
                             "Couldn't find a client with that ID in our database."
                             "\n\nIs it possible that you didn't select (click on/highlight) a client that you'd like to view?");
    } else {
//        if (viewWindow != 0) { delete viewWindow; }
        viewWindow = new ViewClientWindow(this, selectedClientInfo, db);    // Bridge pattern
        handleViewWindow();
        if (status == 1) ui->refreshLabelClient->setVisible(true);  // ie. if staff
    }
}


void MainWindow::on_logoutButton_clicked()
{
    qDebug() << "\nLogging out of " << this;
    close();
}



/*************************************************************************************************
                                    Other Functions (typically private)
**************************************************************************************************/

void MainWindow::addNewAnimal(){
    QList<QString> animalID;
    QList<QString> animalPhysAttr;
    QList<int> animalNonPhysAttr;

    // Getting the Animal name and ID.
    animalID.append(ui->lineEdit->text().trimmed());
    animalID.append(ui->lineEdit_2->text().trimmed());

    // Getting all the animal Physical Attributes
    animalPhysAttr.append(ui->comboBox_2->currentText());
    animalPhysAttr.append(ui->comboBox_3->currentText());
    animalPhysAttr.append(ui->lineEdit_3->text().trimmed());
    animalPhysAttr.append(ui->comboBox_4->currentText());
    animalPhysAttr.append(ui->lineEdit_5->text().trimmed());
    animalPhysAttr.append(ui->lineEdit_6->text().trimmed());
    animalPhysAttr.append(ui->lineEdit_7->text().trimmed());
    animalPhysAttr.append(ui->lineEdit_8->text().trimmed());
    animalPhysAttr.append(ui->lineEdit_9->text().trimmed());

    // Getting all the animal Non-Physical Attributes
    // Category 1: Conscientiousness
    animalNonPhysAttr.append(ui->CBox1->currentIndex());
    animalNonPhysAttr.append(ui->CBox2->currentIndex());
    animalNonPhysAttr.append(ui->CBox3->currentIndex());
    animalNonPhysAttr.append(ui->CBox4->currentIndex());
    animalNonPhysAttr.append(ui->CBox5->currentIndex());
    animalNonPhysAttr.append(ui->CBox6->currentIndex());
    // Category 2: Sociable
    animalNonPhysAttr.append(ui->CBox1_2->currentIndex());
    animalNonPhysAttr.append(ui->CBox2_2->currentIndex());
    animalNonPhysAttr.append(ui->CBox3_2->currentIndex());
    animalNonPhysAttr.append(ui->CBox4_2->currentIndex());
    animalNonPhysAttr.append(ui->CBox5_2->currentIndex());
    animalNonPhysAttr.append(ui->CBox6_2->currentIndex());
    // Category 3: Temperament/Nature
    animalNonPhysAttr.append(ui->CBox1_5->currentIndex());
    animalNonPhysAttr.append(ui->CBox2_5->currentIndex());
    animalNonPhysAttr.append(ui->CBox3_5->currentIndex());
    animalNonPhysAttr.append(ui->CBox4_5->currentIndex());
    animalNonPhysAttr.append(ui->CBox5_5->currentIndex());
    animalNonPhysAttr.append(ui->CBox6_5->currentIndex());
    // Category 4: Action
    animalNonPhysAttr.append(ui->CBox1_6->currentIndex());
    animalNonPhysAttr.append(ui->CBox2_6->currentIndex());
    animalNonPhysAttr.append(ui->CBox3_6->currentIndex());
    animalNonPhysAttr.append(ui->CBox4_6->currentIndex());
    animalNonPhysAttr.append(ui->CBox5_6->currentIndex());
//    animalNonPhysAttr.append(ui->CBox6_6->currentIndex());
    // Category 5: Health/Maintenance
    animalNonPhysAttr.append(ui->CBox1_7->currentIndex());
    animalNonPhysAttr.append(ui->CBox2_7->currentIndex());
    animalNonPhysAttr.append(ui->CBox3_7->currentIndex());
    animalNonPhysAttr.append(ui->CBox4_7->currentIndex());
    animalNonPhysAttr.append(ui->CBox5_7->currentIndex());
    animalNonPhysAttr.append(ui->CBox6_7->currentIndex());

    // Prepending the animalID to the respective lists
    animalPhysAttr.prepend(ui->lineEdit->text().trimmed());
    animalNonPhysAttr.prepend(ui->lineEdit->text().trimmed().toInt());

    // Setting animal information for Animal Class Object
    Animal *newAnimal = new Animal();
    animalsCollection.append(newAnimal);
    newAnimal->setID(ui->lineEdit->text().trimmed().toInt());
    newAnimal->setName(ui->lineEdit_2->text().trimmed());
    newAnimal->setPhysAttr(animalPhysAttr);
    newAnimal->setNonPhysAttr(animalNonPhysAttr);

    // Updating db with animal information (straight from lists used above)
    db->startTransaction();
    try {
        if (!db->addData(db->getAnimalIDInsertQuery(),&animalID)){
            throw "Error 1: Cannot add to animals table. Are you sure this Animal ID is a number "
                    "that hasn't been taken in the table yet (check in View Table tab)";
        }
        if (!db->addData(db->getAnimalPhysAttrInsertQuery(), &animalPhysAttr)){
            throw "Error 2: Cannot add to animal_phys_attr table. Are you sure this Animal ID is a number "
                    "that hasn't been taken in the table yet? (check in View Table tab)"
                    "\nCheck also that the age and weight fields are numbers only.";
        }
        if (!db->addData(db->getAnimalNonPhysAttrInsertQuery(), &animalNonPhysAttr)){
            throw "Error 3: Cannot add to animal_non_phys_table table. Are you sure this Animal ID is a number "
                    "that hasn't been taken in the table yet (check in View Table tab)";
        }
        db->commit();
        QMessageBox::critical(this, tr("Added"), tr("Animal has been successfully added."));

        // Resetting the Animal name and ID.
        db->incrementMaxAnimalID();
        ui->lineEdit->setText(QString::number(db->getMaxAnimalID()));
        ui->lineEdit_2->setText("");

        // Resetting all the animal Physical Attributes
        ui->comboBox_2->setCurrentIndex(0);
        ui->comboBox_3->setCurrentIndex(0);
        ui->lineEdit_3->setText("");
        ui->comboBox_4->setCurrentIndex(0);
        ui->lineEdit_5->setText("");
        ui->lineEdit_6->setText("");
        ui->lineEdit_7->setText("");
        ui->lineEdit_8->setText("");
        ui->lineEdit_9->setText("");

        // Resetting all the animal Non-Physical Attributes
        ui->CBox1->setCurrentIndex(0);
        ui->CBox2->setCurrentIndex(0);
        ui->CBox3->setCurrentIndex(0);
        ui->CBox4->setCurrentIndex(0);
        ui->CBox5->setCurrentIndex(0);
        ui->CBox6->setCurrentIndex(0);
        ui->CBox1_2->setCurrentIndex(0);
        ui->CBox2_2->setCurrentIndex(0);
        ui->CBox3_2->setCurrentIndex(0);
        ui->CBox4_2->setCurrentIndex(0);
        ui->CBox5_2->setCurrentIndex(0);
        ui->CBox6_2->setCurrentIndex(0);
        ui->CBox1_5->setCurrentIndex(0);
        ui->CBox2_5->setCurrentIndex(0);
        ui->CBox3_5->setCurrentIndex(0);
        ui->CBox4_5->setCurrentIndex(0);
        ui->CBox5_5->setCurrentIndex(0);
        ui->CBox6_5->setCurrentIndex(0);
        ui->CBox1_6->setCurrentIndex(0);
        ui->CBox2_6->setCurrentIndex(0);
        ui->CBox3_6->setCurrentIndex(0);
        ui->CBox4_6->setCurrentIndex(0);
        ui->CBox5_6->setCurrentIndex(0);
        ui->CBox6_6->setCurrentIndex(0);
        ui->CBox1_7->setCurrentIndex(0);
        ui->CBox2_7->setCurrentIndex(0);
        ui->CBox3_7->setCurrentIndex(0);
        ui->CBox4_7->setCurrentIndex(0);
        ui->CBox5_7->setCurrentIndex(0);
        ui->CBox6_7->setCurrentIndex(0);
    } catch (const char* err){
        qDebug() << err;
        QMessageBox::critical(this, tr("Error"), err);
        db->rollback();
    }



}


void MainWindow::addNewClient(){
    QList<QString> clientInfo;

    // Getting all client info
    clientInfo.append(ui->clientIDEdit->text().trimmed());
    clientInfo.append(ui->clientNameEdit->text().trimmed());
    clientInfo.append(ui->cComboBox1->currentText());
    clientInfo.append(ui->cComboBox2->currentText());
    clientInfo.append(ui->cComboBox3->currentText());
    clientInfo.append(ui->cEmailEdit->text().trimmed());
    clientInfo.append(ui->cPhoneEdit1->text().trimmed());
    clientInfo.append(ui->cPhoneEdit2->text().trimmed());
    clientInfo.append(ui->cPhoneEdit3->text().trimmed());

    // Updating db with client information (straight from the lists used above)
    db->startTransaction();
    try {
        if (!db->addData(db->getClientInfoInsertQuery(), &clientInfo)){
            throw "Error 1: Cannot add to clients table. \n\nAre you sure this Client ID is a number "
                    "that hasn't been taken in the table yet (check in View Client tab)";
        }
        db->commit();
        QMessageBox::critical(this, tr("Added"), tr("Client has been successfully added."));


        db->incrementMaxClientID();
        // Resetting the Client Info
        ui->clientIDEdit->setText(QString::number(db->getMaxClientID()));
        ui->clientNameEdit->setText("");
        ui->cComboBox1->setCurrentIndex(0);
        ui->cComboBox2->setCurrentIndex(0);
        ui->cComboBox3->setCurrentIndex(0);
        ui->cEmailEdit->setText("");
        ui->cPhoneEdit1->setText("");
        ui->cPhoneEdit2->setText("");
        ui->cPhoneEdit3->setText("");

    } catch (const char* err){
        qDebug() << err;
        QMessageBox::critical(this, tr("Error"), err);
        db->rollback();
    }
}


void MainWindow::closeEvent(QCloseEvent *event){
    this->parentWidget()->show();
//    this->~MainWindow();
    delete this;
    event->accept();
}


void MainWindow::on_runACMAlgorithmButton_clicked()
{
    qDebug() << "Run ACM Algorithm Button";
    alg = new cuACSMatchingAlgorithm(db->getCompleteAnimalListPtr(), db->getCompleteClientListPtr());

    ui->stackedWidget->setCurrentIndex(6);


    //matched = new QStandardItem(alg->getMatches().value(3));
    //standardItemModel = new QStandardItemModel(2,2);
    //standardItemModel->setItem(1, 1, matched);
    //model = alg->getMatches();

    QMap<int, int> *tempMap = alg->getMatches();
    QList<int> keys = tempMap->keys();

    QStandardItemModel * table_model = new QStandardItemModel(tempMap->size(), 2);
    for(int row = 0; row < tempMap->size(); ++row){

        QStandardItem *itemKey = new QStandardItem(QList<QString>(db->getCompleteClientListPtr()->value(keys[row]))[1]);
        table_model->setItem(row, 0, itemKey);

        QStandardItem *itemValue = new QStandardItem(QList<QString>(db->getCompleteAnimalListPtr()->value(tempMap->value(keys[row])))[1]);
        table_model->setItem(row, 1, itemValue);
    }

    ui->tableView_runAlgorithm->setModel(table_model);
}
