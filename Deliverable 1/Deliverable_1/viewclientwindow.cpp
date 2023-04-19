#include "viewclientwindow.h"
#include "ui_viewclientwindow.h"

ViewClientWindow::ViewClientWindow(QWidget *parent) :
//    QMainWindow(parent),
    cuACSViewWindow(parent),    // Related to cuACSMainWindow Inheritance
    ui(new Ui::ViewClientWindow)
{
    qDebug() << "ViewClientWindow()";
    ui->setupUi(this);
    centerScreen();
}

ViewClientWindow::ViewClientWindow(QWidget *parent, QList<QList<QString>> _selectedClientInfo, StorageDatabase *_db) :
//    QMainWindow(parent),
    cuACSViewWindow(parent),    // Related to cuACSMainWindow Inheritance
    ui(new Ui::ViewClientWindow)
{
    qDebug() << "ViewClientWindow()";
    ui->setupUi(this);
    selectedClientInfo = convertFromInput(_selectedClientInfo);
    db = _db;
//    status = _status;
    centerScreen();
//    handlePermissions();
//    viewClient();
}

ViewClientWindow::~ViewClientWindow()
{
    qDebug() << "~ViewClientWindow()";
    delete ui;
}


void ViewClientWindow::centerScreen(){
    int screenWidth = QGuiApplication::primaryScreen()->geometry().width();
    int screenHeight = QGuiApplication::primaryScreen()->geometry().height();
    int width = this->geometry().width();
    int height = this->geometry().height();
    this->setGeometry((screenWidth/2) - (width/2), (screenHeight/2) - (height/2), width, height);
}

void ViewClientWindow::handlePermissions(int status){
    if (status == 1) { // Staff
        ui->editClientButton->setEnabled(true);
    } else {
        ui->editClientButton->setEnabled(true);
    }
}

QVector<QString> ViewClientWindow::convertFromInput(QList<QList<QString>> clientInfo){
    qDebug() << "Converting Client Data from QList<QList> to QVector";
    QVector<QString> results;
    for (int i = 0; i < clientInfo.size(); i++){
        for (int j = 0; j < clientInfo[i].size(); j++){
            results.append(clientInfo[i].value(j));
        }
    }
    qDebug() << "Results: " << results;
    return results;
}


void ViewClientWindow::closeEvent(QCloseEvent *event){
    this->parentWidget()->show();
    delete this;
    event->accept();
}



/*************************************************************************************************
                                    Functions for Edit Client Functionality
**************************************************************************************************/


void ViewClientWindow::on_editClientButton_clicked()
{
    editClient();
}


// Should handle loading data to the UI
void ViewClientWindow::viewData(){
    // Setting the Client info.
    ui->clientIDEdit->setText(selectedClientInfo[0].trimmed());
    ui->clientNameEdit->setText(selectedClientInfo[1].trimmed());
    ui->cComboBox1->setCurrentIndex(ui->cComboBox1->findText(selectedClientInfo[2]));
    ui->cComboBox2->setCurrentIndex(ui->cComboBox2->findText(selectedClientInfo[3]));
    ui->cComboBox3->setCurrentIndex(ui->cComboBox3->findText(selectedClientInfo[4]));
    ui->cEmailEdit->setText(selectedClientInfo[5].trimmed());
    ui->cPhoneEdit1->setText(selectedClientInfo[6].trimmed());
    ui->cPhoneEdit2->setText(selectedClientInfo[7].trimmed());
    ui->cPhoneEdit3->setText(selectedClientInfo[8].trimmed());

    // Setting all the client Physical Attributes preferences
    ui->comboBox_2->setCurrentIndex(ui->comboBox_2->findText(selectedClientInfo[9]));
    ui->comboBox_3->setCurrentIndex(ui->comboBox_3->findText(selectedClientInfo[10]));
    ui->lineEdit_3->setText(selectedClientInfo[11].trimmed());
    ui->comboBox_4->setCurrentIndex(ui->comboBox_4->findText(selectedClientInfo[12]));
    ui->lineEdit_5->setText(selectedClientInfo[13].trimmed());
    ui->lineEdit_6->setText(selectedClientInfo[14].trimmed());
    ui->lineEdit_7->setText(selectedClientInfo[15].trimmed());
    ui->lineEdit_8->setText(selectedClientInfo[16].trimmed());
    ui->lineEdit_9->setText(selectedClientInfo[17].trimmed());

    // Setting all the client Non-Physical Attributes preferences
    ui->CBox1->setCurrentIndex(1+selectedClientInfo[18].toInt());
    ui->CBox2->setCurrentIndex(1+selectedClientInfo[19].toInt());
    ui->CBox3->setCurrentIndex(1+selectedClientInfo[20].toInt());
    ui->CBox4->setCurrentIndex(1+selectedClientInfo[21].toInt());
    ui->CBox5->setCurrentIndex(1+selectedClientInfo[22].toInt());
    ui->CBox6->setCurrentIndex(1+selectedClientInfo[23].toInt());
    ui->CBox1_2->setCurrentIndex(1+selectedClientInfo[24].toInt());
    ui->CBox2_2->setCurrentIndex(1+selectedClientInfo[25].toInt());
    ui->CBox3_2->setCurrentIndex(1+selectedClientInfo[26].toInt());
    ui->CBox4_2->setCurrentIndex(1+selectedClientInfo[27].toInt());
    ui->CBox5_2->setCurrentIndex(1+selectedClientInfo[28].toInt());
    ui->CBox6_2->setCurrentIndex(1+selectedClientInfo[29].toInt());
    ui->CBox1_5->setCurrentIndex(1+selectedClientInfo[30].toInt());
    ui->CBox2_5->setCurrentIndex(1+selectedClientInfo[31].toInt());
    ui->CBox3_5->setCurrentIndex(1+selectedClientInfo[32].toInt());
    ui->CBox4_5->setCurrentIndex(1+selectedClientInfo[33].toInt());
    ui->CBox5_5->setCurrentIndex(1+selectedClientInfo[34].toInt());
    ui->CBox6_5->setCurrentIndex(1+selectedClientInfo[35].toInt());
    ui->CBox1_6->setCurrentIndex(1+selectedClientInfo[36].toInt());
    ui->CBox2_6->setCurrentIndex(1+selectedClientInfo[37].toInt());
    ui->CBox3_6->setCurrentIndex(1+selectedClientInfo[38].toInt());
    ui->CBox4_6->setCurrentIndex(1+selectedClientInfo[39].toInt());
    ui->CBox5_6->setCurrentIndex(1+selectedClientInfo[40].toInt());
//    ui->CBox6_6->setCurrentIndex(1+selectedClientInfo[41].toInt());
    ui->CBox1_7->setCurrentIndex(1+selectedClientInfo[41].toInt());
    ui->CBox2_7->setCurrentIndex(1+selectedClientInfo[42].toInt());
    ui->CBox3_7->setCurrentIndex(1+selectedClientInfo[43].toInt());
    ui->CBox4_7->setCurrentIndex(1+selectedClientInfo[44].toInt());
    ui->CBox5_7->setCurrentIndex(1+selectedClientInfo[45].toInt());
    ui->CBox6_7->setCurrentIndex(1+selectedClientInfo[46].toInt());
}

// Should get the info from the UI and save it
void ViewClientWindow::editClient(){
    qDebug() << "\neditClient()";
    QList<QString> clientInfo;
    QList<QString> clientPhysAttrPref;
    QList<int> clientNonPhysAttrPref;

    // Getting the client basic info
//    clientInfo.append(ui->clientIDEdit->text());  // required at end for updates
    clientInfo.append(ui->clientNameEdit->text().trimmed());
    clientInfo.append(ui->cComboBox1->currentText());
    clientInfo.append(ui->cComboBox2->currentText());
    clientInfo.append(ui->cComboBox3->currentText());
    clientInfo.append(ui->cEmailEdit->text().trimmed());
    clientInfo.append(ui->cPhoneEdit1->text().trimmed());
    clientInfo.append(ui->cPhoneEdit2->text().trimmed());
    clientInfo.append(ui->cPhoneEdit3->text().trimmed());

    // Getting all the client Physical Attributes preferences
    clientPhysAttrPref.append(ui->comboBox_2->currentText());
    clientPhysAttrPref.append(ui->comboBox_3->currentText());
    clientPhysAttrPref.append(ui->lineEdit_3->text().trimmed());
    clientPhysAttrPref.append(ui->comboBox_4->currentText());
    clientPhysAttrPref.append(ui->lineEdit_5->text().trimmed());
    clientPhysAttrPref.append(ui->lineEdit_6->text().trimmed());
    clientPhysAttrPref.append(ui->lineEdit_7->text().trimmed());
    clientPhysAttrPref.append(ui->lineEdit_8->text().trimmed());
    clientPhysAttrPref.append(ui->lineEdit_9->text().trimmed());

    // Getting all the client Non-Physical Attributes preferences
    // Category 1: Conscientiousness
    clientNonPhysAttrPref.append(ui->CBox1->currentIndex() - 1);
    clientNonPhysAttrPref.append(ui->CBox2->currentIndex() - 1);
    clientNonPhysAttrPref.append(ui->CBox3->currentIndex() - 1);
    clientNonPhysAttrPref.append(ui->CBox4->currentIndex() - 1);
    clientNonPhysAttrPref.append(ui->CBox5->currentIndex() - 1);
    clientNonPhysAttrPref.append(ui->CBox6->currentIndex() - 1);
    // Category 2: Sociable
    clientNonPhysAttrPref.append(ui->CBox1_2->currentIndex() - 1);
    clientNonPhysAttrPref.append(ui->CBox2_2->currentIndex() - 1);
    clientNonPhysAttrPref.append(ui->CBox3_2->currentIndex() - 1);
    clientNonPhysAttrPref.append(ui->CBox4_2->currentIndex() - 1);
    clientNonPhysAttrPref.append(ui->CBox5_2->currentIndex() - 1);
    clientNonPhysAttrPref.append(ui->CBox6_2->currentIndex() - 1);
    // Category 3: Temperament/Nature
    clientNonPhysAttrPref.append(ui->CBox1_5->currentIndex() - 1);
    clientNonPhysAttrPref.append(ui->CBox2_5->currentIndex() - 1);
    clientNonPhysAttrPref.append(ui->CBox3_5->currentIndex() - 1);
    clientNonPhysAttrPref.append(ui->CBox4_5->currentIndex() - 1);
    clientNonPhysAttrPref.append(ui->CBox5_5->currentIndex() - 1);
    clientNonPhysAttrPref.append(ui->CBox6_5->currentIndex() - 1);
    // Category 4: Action
    clientNonPhysAttrPref.append(ui->CBox1_6->currentIndex() - 1);
    clientNonPhysAttrPref.append(ui->CBox2_6->currentIndex() - 1);
    clientNonPhysAttrPref.append(ui->CBox3_6->currentIndex() - 1);
    clientNonPhysAttrPref.append(ui->CBox4_6->currentIndex() - 1);
    clientNonPhysAttrPref.append(ui->CBox5_6->currentIndex() - 1);
//    clientNonPhysAttrPref.append(ui->CBox6_6->currentIndex());
    // Category 5: Health/Maintenance
    clientNonPhysAttrPref.append(ui->CBox1_7->currentIndex() - 1);
    clientNonPhysAttrPref.append(ui->CBox2_7->currentIndex() - 1);
    clientNonPhysAttrPref.append(ui->CBox3_7->currentIndex() - 1);
    clientNonPhysAttrPref.append(ui->CBox4_7->currentIndex() - 1);
    clientNonPhysAttrPref.append(ui->CBox5_7->currentIndex() - 1);
    clientNonPhysAttrPref.append(ui->CBox6_7->currentIndex() - 1);

    // Appending ID to the end of the lists (since update statements have a "WHERE"
    // clause at the end requiring the id).
    clientInfo.append(ui->clientIDEdit->text());
    clientPhysAttrPref.append(ui->clientIDEdit->text());
    clientNonPhysAttrPref.append(ui->clientIDEdit->text().toInt());

//    qDebug() << "editClient() = " << clientInfo << clientPhysAttrPref << clientNonPhysAttrPref;

    db->startTransaction();
    try {
        if (!db->updateData(db->getClientInfoUpdateQuery(), &clientInfo)){
            throw "Error 1: Client info couldn't be updated.";
        }
        if (!db->updateData(db->getClientPhysAttrUpdateQuery(), &clientPhysAttrPref)){
            throw "Error 2: Client physical attribute preferences couldn't be updated.";
        }
        if (!db->updateData(db->getClientNonPhysAttrUpdateQuery(), &clientNonPhysAttrPref)){
            throw "Error 3: Client non-physical attribute preferences couldn't be updated.";
        }

        // Prepending ID to list to get proper format to update. (NOTE: no id needed for the
        // phys and non-phys list, since when merged from the database, the id is only found at
        // the beginning of the list).
        clientInfo.removeLast();
        clientPhysAttrPref.removeLast();
        clientNonPhysAttrPref.removeLast();
        clientInfo.prepend(ui->clientIDEdit->text());
//        clientPhysAttrPref.prepend(ui->clientIDEdit->text());
//        clientNonPhysAttrPref.prepend(ui->clientIDEdit->text().toInt());

        if (!db->updateLocalClient(&clientInfo, &clientPhysAttrPref, &clientNonPhysAttrPref)){
            throw "Error 4: Couldn't update local client database variable.";
        }
        db->commit();
        QMessageBox::critical(this, tr("Added"), tr("Client info and preferences has been successfully updated."));

    } catch (const char* err){
        qDebug() << err;
        QMessageBox::critical(this, tr("Error"), err);
        db->rollback();
    }
}
