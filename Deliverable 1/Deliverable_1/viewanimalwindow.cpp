#include "viewanimalwindow.h"
#include "ui_viewanimalwindow.h"

ViewAnimalWindow::ViewAnimalWindow(QWidget *parent) :
//    QMainWindow(parent),
    cuACSViewWindow(parent),    // Related to cuACSViewWindow Inheritance
    ui(new Ui::ViewAnimalWindow)
{
    qDebug() << "ViewAnimalWindow()";
    ui->setupUi(this);
    centerScreen();
}

ViewAnimalWindow::ViewAnimalWindow(QWidget *parent, QList<QList<QString>> _selectedAnimalInfo, StorageDatabase *_db) :
//    QMainWindow(parent),
    cuACSViewWindow(parent),    // Related to cuACSViewWindow Inheritance
    ui(new Ui::ViewAnimalWindow)
{
    qDebug() << "ViewAnimalWindow()";
    ui->setupUi(this);
    selectedAnimalInfo = convertFromInput(_selectedAnimalInfo);
    db = _db;
//    status = _status;
    centerScreen();
//    handlePermissions();
//    viewAnimal();
}

ViewAnimalWindow::~ViewAnimalWindow()
{
    qDebug() << "~ViewAnimalWindow()";
    delete ui;
}


void ViewAnimalWindow::centerScreen(){
    int screenWidth = QGuiApplication::primaryScreen()->geometry().width();
    int screenHeight = QGuiApplication::primaryScreen()->geometry().height();
    int width = this->geometry().width();
    int height = this->geometry().height();
    this->setGeometry((screenWidth/2) - (width/2), (screenHeight/2) - (height/2), width, height);
}

void ViewAnimalWindow::handlePermissions(int status){
    if (status == 1) { // Staff
        qDebug() << "Staff detected";
        ui->editAnimalButton->setEnabled(true);
    } else {
        qDebug() << "Client detected";
        // Restricting everything on the screen from being changed
        ui->editAnimalButton->setEnabled(false);
        // Restricting the animal ID and name form being changed
        ui->lineEdit->setReadOnly(true);
        ui->lineEdit_2->setReadOnly(true);

        // Restricting all the animal Physical Attributes from being changed
        ui->comboBox_2->setEnabled(false);
        ui->comboBox_3->setEnabled(false);
        ui->lineEdit_3->setReadOnly(true);
        ui->comboBox_4->setEnabled(false);
        ui->lineEdit_5->setReadOnly(true);
        ui->lineEdit_6->setReadOnly(true);
        ui->lineEdit_7->setReadOnly(true);
        ui->lineEdit_8->setReadOnly(true);
        ui->lineEdit_9->setReadOnly(true);

        // Restricting all the animal Non-Physical Attributes form being changed
        ui->CBox1->setEnabled(false);
        ui->CBox2->setEnabled(false);
        ui->CBox3->setEnabled(false);
        ui->CBox4->setEnabled(false);
        ui->CBox5->setEnabled(false);
        ui->CBox6->setEnabled(false);
        ui->CBox1_2->setEnabled(false);
        ui->CBox2_2->setEnabled(false);
        ui->CBox3_2->setEnabled(false);
        ui->CBox4_2->setEnabled(false);
        ui->CBox5_2->setEnabled(false);
        ui->CBox6_2->setEnabled(false);
        ui->CBox1_5->setEnabled(false);
        ui->CBox2_5->setEnabled(false);
        ui->CBox3_5->setEnabled(false);
        ui->CBox4_5->setEnabled(false);
        ui->CBox5_5->setEnabled(false);
        ui->CBox6_5->setEnabled(false);
        ui->CBox1_6->setEnabled(false);
        ui->CBox2_6->setEnabled(false);
        ui->CBox3_6->setEnabled(false);
        ui->CBox4_6->setEnabled(false);
        ui->CBox5_6->setEnabled(false);
    //    ui->CBox6_6->setEnabled(false);
        ui->CBox1_7->setEnabled(false);
        ui->CBox2_7->setEnabled(false);
        ui->CBox3_7->setEnabled(false);
        ui->CBox4_7->setEnabled(false);
        ui->CBox5_7->setEnabled(false);
        ui->CBox6_7->setEnabled(false);
    }
}

QVector<QString> ViewAnimalWindow::convertFromInput(QList<QList<QString>> animalInfo){
    qDebug() << "Converting animal Data from QList<QList> to QVector";
    QVector<QString> results;
    for (int i = 0; i < animalInfo.size(); i++){
        for (int j = 0; j < animalInfo[i].size(); j++){
            results.append(animalInfo[i].value(j));
        }
    }
    qDebug() << "Results: " << results;
    return results;
}


void ViewAnimalWindow::closeEvent(QCloseEvent *event){
    this->parentWidget()->show();
    delete this;
    event->accept();
}



/*************************************************************************************************
                                    Functions for Edit Animal Functionality
**************************************************************************************************/


void ViewAnimalWindow::on_editAnimalButton_clicked()
{
    editAnimal();
}


// Should handle loading data to the UI
void ViewAnimalWindow::viewData(){
    // Setting the Animal name and ID.
    ui->lineEdit->setText(selectedAnimalInfo[0]);
    ui->lineEdit_2->setText(selectedAnimalInfo[1].trimmed());

    // Setting all the animal Physical Attributes
    ui->comboBox_2->setCurrentIndex(ui->comboBox_2->findText(selectedAnimalInfo[2]));
    ui->comboBox_3->setCurrentIndex(ui->comboBox_3->findText(selectedAnimalInfo[3]));
    ui->lineEdit_3->setText(selectedAnimalInfo[4].trimmed());
    ui->comboBox_4->setCurrentIndex(ui->comboBox_4->findText(selectedAnimalInfo[5]));
    ui->lineEdit_5->setText(selectedAnimalInfo[6].trimmed());
    ui->lineEdit_6->setText(selectedAnimalInfo[7].trimmed());
    ui->lineEdit_7->setText(selectedAnimalInfo[8].trimmed());
    ui->lineEdit_8->setText(selectedAnimalInfo[9].trimmed());
    ui->lineEdit_9->setText(selectedAnimalInfo[10].trimmed());

    // Setting all the animal Non-Physical Attributes
    ui->CBox1->setCurrentIndex(1+selectedAnimalInfo[11].toInt());
    ui->CBox2->setCurrentIndex(1+selectedAnimalInfo[12].toInt());
    ui->CBox3->setCurrentIndex(1+selectedAnimalInfo[13].toInt());
    ui->CBox4->setCurrentIndex(1+selectedAnimalInfo[14].toInt());
    ui->CBox5->setCurrentIndex(1+selectedAnimalInfo[15].toInt());
    ui->CBox6->setCurrentIndex(1+selectedAnimalInfo[16].toInt());
    ui->CBox1_2->setCurrentIndex(1+selectedAnimalInfo[17].toInt());
    ui->CBox2_2->setCurrentIndex(1+selectedAnimalInfo[18].toInt());
    ui->CBox3_2->setCurrentIndex(1+selectedAnimalInfo[19].toInt());
    ui->CBox4_2->setCurrentIndex(1+selectedAnimalInfo[20].toInt());
    ui->CBox5_2->setCurrentIndex(1+selectedAnimalInfo[21].toInt());
    ui->CBox6_2->setCurrentIndex(1+selectedAnimalInfo[22].toInt());
    ui->CBox1_5->setCurrentIndex(1+selectedAnimalInfo[23].toInt());
    ui->CBox2_5->setCurrentIndex(1+selectedAnimalInfo[24].toInt());
    ui->CBox3_5->setCurrentIndex(1+selectedAnimalInfo[25].toInt());
    ui->CBox4_5->setCurrentIndex(1+selectedAnimalInfo[26].toInt());
    ui->CBox5_5->setCurrentIndex(1+selectedAnimalInfo[27].toInt());
    ui->CBox6_5->setCurrentIndex(1+selectedAnimalInfo[28].toInt());
    ui->CBox1_6->setCurrentIndex(1+selectedAnimalInfo[29].toInt());
    ui->CBox2_6->setCurrentIndex(1+selectedAnimalInfo[30].toInt());
    ui->CBox3_6->setCurrentIndex(1+selectedAnimalInfo[31].toInt());
    ui->CBox4_6->setCurrentIndex(1+selectedAnimalInfo[32].toInt());
    ui->CBox5_6->setCurrentIndex(1+selectedAnimalInfo[33].toInt());
//    ui->CBox6_6->setCurrentIndex(1+selectedAnimalInfo[34].toInt());
    ui->CBox1_7->setCurrentIndex(1+selectedAnimalInfo[34].toInt());
    ui->CBox2_7->setCurrentIndex(1+selectedAnimalInfo[35].toInt());
    ui->CBox3_7->setCurrentIndex(1+selectedAnimalInfo[36].toInt());
    ui->CBox4_7->setCurrentIndex(1+selectedAnimalInfo[37].toInt());
    ui->CBox5_7->setCurrentIndex(1+selectedAnimalInfo[38].toInt());
    ui->CBox6_7->setCurrentIndex(1+selectedAnimalInfo[39].toInt());
}

// Should get the info from the UI and save it
void ViewAnimalWindow::editAnimal(){
    qDebug() << "\neditAnimal()";
    QList<QString> animalID;
    QList<QString> animalPhysAttr;
    QList<int> animalNonPhysAttr;

    /// Getting the Animal name and ID.
//    animalID.append(ui->lineEdit->text()); // required at end for updates
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
    animalNonPhysAttr.append(ui->CBox1->currentIndex() - 1);
    animalNonPhysAttr.append(ui->CBox2->currentIndex() - 1);
    animalNonPhysAttr.append(ui->CBox3->currentIndex() - 1);
    animalNonPhysAttr.append(ui->CBox4->currentIndex() - 1);
    animalNonPhysAttr.append(ui->CBox5->currentIndex() - 1);
    animalNonPhysAttr.append(ui->CBox6->currentIndex() - 1);
    // Category 2: Sociable
    animalNonPhysAttr.append(ui->CBox1_2->currentIndex() - 1);
    animalNonPhysAttr.append(ui->CBox2_2->currentIndex() - 1);
    animalNonPhysAttr.append(ui->CBox3_2->currentIndex() - 1);
    animalNonPhysAttr.append(ui->CBox4_2->currentIndex() - 1);
    animalNonPhysAttr.append(ui->CBox5_2->currentIndex() - 1);
    animalNonPhysAttr.append(ui->CBox6_2->currentIndex() - 1);
    // Category 3: Temperament/Nature
    animalNonPhysAttr.append(ui->CBox1_5->currentIndex() - 1);
    animalNonPhysAttr.append(ui->CBox2_5->currentIndex() - 1);
    animalNonPhysAttr.append(ui->CBox3_5->currentIndex() - 1);
    animalNonPhysAttr.append(ui->CBox4_5->currentIndex() - 1);
    animalNonPhysAttr.append(ui->CBox5_5->currentIndex() - 1);
    animalNonPhysAttr.append(ui->CBox6_5->currentIndex() - 1);
    // Category 4: Action
    animalNonPhysAttr.append(ui->CBox1_6->currentIndex() - 1);
    animalNonPhysAttr.append(ui->CBox2_6->currentIndex() - 1);
    animalNonPhysAttr.append(ui->CBox3_6->currentIndex() - 1);
    animalNonPhysAttr.append(ui->CBox4_6->currentIndex() - 1);
    animalNonPhysAttr.append(ui->CBox5_6->currentIndex() - 1);
//    animalNonPhysAttr.append(ui->CBox6_6->currentIndex());
    // Category 5: Health/Maintenance
    animalNonPhysAttr.append(ui->CBox1_7->currentIndex() - 1);
    animalNonPhysAttr.append(ui->CBox2_7->currentIndex() - 1);
    animalNonPhysAttr.append(ui->CBox3_7->currentIndex() - 1);
    animalNonPhysAttr.append(ui->CBox4_7->currentIndex() - 1);
    animalNonPhysAttr.append(ui->CBox5_7->currentIndex() - 1);
    animalNonPhysAttr.append(ui->CBox6_7->currentIndex() - 1);

    // Appending ID to the end of the lists (since update statements have a "WHERE"
    // clause at the end requiring the id).
    animalID.append(ui->lineEdit->text());
    animalPhysAttr.append(ui->lineEdit->text());
    animalNonPhysAttr.append(ui->lineEdit->text().toInt());

//    qDebug() << "editAnimal() = " << animalID << animalPhysAttr << animalNonPhysAttr;

    db->startTransaction();
    try {
        if (!db->updateData(db->getAnimalIDUpdateQuery(), &animalID)){
            throw "Error 1: Animal ID and name couldn't be updated.";
        }
        if (!db->updateData(db->getAnimalPhysAttrUpdateQuery(), &animalPhysAttr)){
            throw "Error 2: Animal physical attribute couldn't be updated.";
        }
        if (!db->updateData(db->getAnimalNonPhysAttrUpdateQuery(), &animalNonPhysAttr)){
            throw "Error 3: Animal non-physical attribute couldn't be updated.";
        }

        // Prepending ID to list to get proper format to update. (NOTE: no id needed for the
        // phys and non-phys list, since when merged from the database, the id is only found at
        // the beginning of the list).
        animalID.removeLast();
        animalPhysAttr.removeLast();
        animalNonPhysAttr.removeLast();
        animalID.prepend(ui->lineEdit->text());
//        animalPhysAttr.prepend(ui->lineEdit->text());
//        animalNonPhysAttr.prepend(ui->lineEdit->text().toInt());

//        qDebug() << "editAnimal2() = " << animalID << animalPhysAttr << animalNonPhysAttr;

        if (!db->updateLocalAnimal(&animalID, &animalPhysAttr, &animalNonPhysAttr)){
            throw "Error 4: Couldn't update local animal database variable.";
        }
        db->commit();
        QMessageBox::critical(this, tr("Added"), tr("Animal attributes and info has been successfully updated."));

    } catch (const char* err){
        qDebug() << err;
        QMessageBox::critical(this, tr("Error"), err);
        db->rollback();
    }
}

