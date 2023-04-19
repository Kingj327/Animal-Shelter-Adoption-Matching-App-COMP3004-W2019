#include "storagedatabase.h"

using namespace std;

/** Constructor **/
StorageDatabase::StorageDatabase()
    : animalInfoList({}){
//    loadDatabase();
}



/** Constructor containing database name (file location) **/
StorageDatabase::StorageDatabase(string dbFileName)
    : animalInfoList({}){
//    loadDatabase();
}


/** Deconstructor **/
StorageDatabase::~StorageDatabase(){

}

void StorageDatabase::loadSimpleDatabase(){
    qDebug() << "\n****** Starting Simple Database Initialization ******";
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("MyDomain");
    db.setDatabaseName(dbName);
//    db.setUserName("");
//    db.setPassword("");

    if (db.open()){
        qDebug() << "Database Successfully Opened.";
    } else {
        qDebug() << "Database didn't load. Closing...\n" << "Error = " << db.lastError().text();
        exit(20);
    }
    qDebug() << "****** Finishing Simple Database Initialization ******";
}

/** Loads database in from file and sets host name.
  * Prints debugging/confirmation statements as it runs.
  *   NOTE: This could easily be called in the constructor. **/
void StorageDatabase::loadDatabase(){
    qDebug() << "\n****** Starting Database Initialization ******";
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("MyDomain");
    db.setDatabaseName(dbName);
//    db.setUserName("");
//    db.setPassword("");

    if (db.open()){
        qDebug() << "Database Successfully Opened.";
    } else {
        qDebug() << "Database didn't load. Closing...\n" << "Error = " << db.lastError().text();
        exit(20);
    }
    qDebug() << "Attempting to load Animal data to internal variables";

    queryAndSave(selectAllAnimalProfiles, &animalInfoList);
    if (!animalInfoList.isEmpty()){
        qDebug() << "Animal data successfully loaded.";
    } else {
        qDebug() << "Animal data was not successfully loaded. Closing...\n" << "Error = " << db.lastError().text();
        exit(21);
    }


    qDebug() << "Determining MAXANIMALID value";
    MAXANIMALID = -1;
    for(int i = 0; i < animalInfoList.length(); i++){
        if (animalInfoList[i].value(0).toInt() > MAXANIMALID){
            MAXANIMALID = animalInfoList[i].value(0).toInt();
        }
    }

    if (MAXANIMALID >= 0){
        qDebug() << "MAXANIMALID set to " << ++MAXANIMALID << ".";
    } else {
        qDebug() << "ERROR: Failed to set MAXANIMALID. Closing.";
        exit(22);
    }

    qDebug() << "Attempting to load Client data to internal variables";

    queryAndSave(selectAllClientProfilesAndPreferences, &clientInfoList);
    if (!clientInfoList.isEmpty()){
        qDebug() << "Client profile and preferences data successfully loaded.";
    } else {
        qDebug() << "Client profile and preferences data was not successfully loaded. Closing...\n" << "Error = " << db.lastError().text();
        exit(23);
    }


    qDebug() << "Determining MAXCLIENTID value";
    MAXCLIENTID = -1;
    for(int i = 0; i < clientInfoList.length(); i++){
        if (clientInfoList[i].value(0).toInt() > MAXCLIENTID){
            MAXCLIENTID = clientInfoList[i].value(0).toInt();
        }
    }

    if (MAXCLIENTID >= 0){
        qDebug() << "MAXCLIENTID set to " << ++MAXCLIENTID << ".";
    } else {
        qDebug() << "ERROR: Failed to set MAXCLIENTID. Closing.";
        exit(24);
    }


    qDebug() << "Attempting to load last bit of data to internal variables";

    queryAndSave(loginInfoQuery, &loginInfoList);
    if (!clientInfoList.isEmpty()){
        qDebug() << "All data successfully loaded.";
    } else {
        qDebug() << "Last bit of data was not successfully loaded. Closing...\n" << "Error = " << db.lastError().text();
        exit(25);
    }


    qDebug() << "****** Finishing Database Initialization ******";
}



/** Closes database and removes database connection.
  * Prints debugging/confirmation statements as it runs. **/
void StorageDatabase::closeDatabase(){
    qDebug() << "\n******Database Cleanup Initiated ******";
    qDebug() << "Database name = " << db.databaseName();
    db.close();
    qDebug() << "Database successfully closed.";
    qDebug() << "Attempting to remove database.";
    QSqlDatabase::removeDatabase(db.databaseName());
    qDebug() << "Database successfully removed.";
    qDebug() << "******Database Cleanup Complete ******\n";
}



/** Get Methods**/
QList<QList<QString>> *StorageDatabase::getCompleteAnimalListPtr(){ return &animalInfoList; }
QList<QList<QString>> StorageDatabase::getCompleteAnimalList(){ return animalInfoList; }
QList<QList<QString>> StorageDatabase::getSpecificAnimal(int index){
    QList<QList<QString>> results;
    if (index < animalInfoList.size()){
        QList<QString> animalID = {animalInfoList[index][0], animalInfoList[index][1]};
        QList<QString> animalPhysAttr = addValuesToListInRange(&animalInfoList[index], animalListIndex[1][0], animalListIndex[1][1]);
        QList<QString> animalNonPhysAttr = addValuesToListInRange(&animalInfoList[index], animalListIndex[2][0], animalListIndex[2][1]);;
//        qDebug() << "getSpecificAnimal Test";
//        qDebug() << "{" << animalID << "," << animalPhysAttr << "," << animalNonPhysAttr << "}";
        results.append(animalID);
        results.append(animalPhysAttr);
        results.append(animalNonPhysAttr);
    } else {
        qDebug() << "ERROR: Invlaid Index. **StorageDatabase::getSpecificAnimal(index)**";
    }
    return results;
}
QList<QList<QString>> StorageDatabase::getSpecificAnimalByID(int id){
    QList<QList<QString>> results;
    for (int i = 0; i < animalInfoList.size(); i++){
        if (animalInfoList[i].value(0).toInt() == id){
            results = getSpecificAnimal(i);
            break;
        }
    }
    return results;
}
QList<QList<QString>> *StorageDatabase::getCompleteClientListPtr(){ return &clientInfoList; }
QList<QList<QString>> StorageDatabase::getCompleteClientList(){ return clientInfoList; }
QList<QList<QString>> StorageDatabase::getSpecificClient(int index){
    QList<QList<QString>> results;
    if (index < clientInfoList.size()){
        QList<QString> clientInfo = addValuesToListInRange(&clientInfoList[index], clientListIndex[0][0], clientListIndex[0][1]);
        QList<QString> clientPhysAttr = addValuesToListInRange(&clientInfoList[index], clientListIndex[1][0], clientListIndex[1][1]);
        QList<QString> clientNonPhysAttr = addValuesToListInRange(&clientInfoList[index], clientListIndex[2][0], clientListIndex[2][1]);;
//        qDebug() << "getSpecificAnimal Test";
//        qDebug() << "{" << animalID << "," << animalPhysAttr << "," << animalNonPhysAttr << "}";
        results.append(clientInfo);
        results.append(clientPhysAttr);
        results.append(clientNonPhysAttr);
    } else {
        qDebug() << "ERROR: Invlaid I(ndex. **StorageDatabase::getSpecificClient(index)**";
    }
    qDebug() << "getSpecificClient(index) reuslts = " << results;
    return results;
}
QList<QList<QString>> StorageDatabase::getSpecificClientByID(int id){
    QList<QList<QString>> results;
    for (int i = 0; i < clientInfoList.size(); i++){
        if (clientInfoList[i].value(0).toInt() == id){
            results = getSpecificClient(i);
            break;
        }
    }
    return results;
}
QList<QList<QString>> *StorageDatabase::getCompleteLoginListPtr(){ return &loginInfoList; }
QList<QList<QString>> StorageDatabase::getCompleteLoginList(){ return loginInfoList; }

QString StorageDatabase::getSelectAllClientProfiles() { return selectAllClientProfiles; }
QString StorageDatabase::getSpecificClientProfile(int id){ return selectSpecificClientProfilesAndPreferences+id; }
QString StorageDatabase::getClientInfoInsertQuery(){ return clientInfoInsertQuery; }
QString StorageDatabase::getClientPhysAttrInsertQuery(){ return clientPhysAttrInsertQuery; }
QString StorageDatabase::getClientNonPhysAttrInsertQuery(){ return clientNonPhysAttrInsertQuery; }
QString StorageDatabase::getClientInfoDeletionQuery(){ return clientInfoDeletionQuery; }
QString StorageDatabase::getClientPhysAttrDeletionQuery(){ return clientPhysAttrDeletionQuery; }
QString StorageDatabase::getClientNonPhysAttrDeletionQuery(){ return clientNonPhysAttrDeletionQuery; }
QString StorageDatabase::getClientInfoUpdateQuery(){ return clientInfoUpdateQuery; }
QString StorageDatabase::getClientPhysAttrUpdateQuery(){ return clientPhysAttrUpdateQuery; }
QString StorageDatabase::getClientNonPhysAttrUpdateQuery(){ return clientNonPhysAttrUpdateQuery; }

QString StorageDatabase::getSelectAllAnimalProfiles() { return selectAllAnimalProfiles; }
QString StorageDatabase::getAnimalIDInsertQuery(){ return animalIDInsertQuery; }
QString StorageDatabase::getAnimalPhysAttrInsertQuery(){ return animalPhysAttrInsertQuery; }
QString StorageDatabase::getAnimalNonPhysAttrInsertQuery(){ return animalNonPhysAttrInsertQuery; }
QString StorageDatabase::getAnimalIDDeletionQuery(){ return animalIDDeletionQuery; }
QString StorageDatabase::getAnimalPhysAttrDeletionQuery(){ return animalPhysAttrDeletionQuery; }
QString StorageDatabase::getAnimalNonPhysAttrDeletionQuery(){ return animalNonPhysAttrDeletionQuery; }
QString StorageDatabase::getAnimalIDUpdateQuery(){ return animalIDUpdateQuery; }
QString StorageDatabase::getAnimalPhysAttrUpdateQuery(){ return animalPhysAttrUpdateQuery; }
QString StorageDatabase::getAnimalNonPhysAttrUpdateQuery(){ return animalNonPhysAttrUpdateQuery; }

int StorageDatabase::getMaxAnimalID(){ return MAXANIMALID; }
bool StorageDatabase::incrementMaxAnimalID(){
    bool flag = true;
    while (flag){
        flag = false;
        MAXANIMALID++;
        for(int i = 0; i < animalInfoList.length(); i++){
            if ((!flag) && (animalInfoList[i].value(0).toInt() == MAXANIMALID)){
                flag = true;
//                MAXANIMALID++;
//                break;
            }
        }

    }
    qDebug() << "New MAXANIMALID value = " << MAXANIMALID;
}
int StorageDatabase::getMaxClientID(){ return MAXCLIENTID; }
bool StorageDatabase::incrementMaxClientID(){
    bool flag = true;
    while (flag){
        flag = false;
        MAXCLIENTID++;
        for(int i = 0; i < clientInfoList.length(); i++){
            if ((!flag) && (clientInfoList[i].value(0).toInt() == MAXCLIENTID)){
                flag = true;
//                MAXCLIENTID++;
//                break;
            }
        }

    }
    qDebug() << "New MAXCLIENTID value = " << MAXCLIENTID;
}

QSqlQueryModel * StorageDatabase::getQueryModel(QString desiredQuery){
    model = new QSqlQueryModel();
    qry = new QSqlQuery();
    qry->prepare(desiredQuery);
    qry->exec();
    model->setQuery(*qry);
    return model;
}

bool StorageDatabase::addData(QString injectionQuery, QList<QString> *data){
    QSqlQuery query;
    query.prepare(injectionQuery);
    for (int i = 0; i < data->size(); i++){
        query.addBindValue((*data)[i]);
    }
    return query.exec();
}

bool StorageDatabase::addData(QString injectionQuery, QList<int> *data){
    QSqlQuery query;
    query.prepare(injectionQuery);
    for (int i = 0; i < data->size(); i++){
        query.addBindValue((*data)[i]);
    }
    return query.exec();
}

bool StorageDatabase::deleteData(QString deletionQuery, QList<QString> *data){
    QSqlQuery query;
    query.prepare(deletionQuery);
    query.addBindValue((*data)[0]);
    return query.exec();
}

bool StorageDatabase::deleteData(QString deletionQuery, QList<int> *data){
    QSqlQuery query;
    query.prepare(deletionQuery);
    query.addBindValue((*data)[0]);
    return query.exec();
}

bool StorageDatabase::updateData(QString updateQuery, QList<QString> *data){
    return addData(updateQuery, data);
//    QSqlQuery query;
//    query.prepare(updateQuery);
//    for (int i = 1; i < data->size(); i++){
//        query.addBindValue((*data)[i]);
//    }
//    query.addBindValue((*data)[0]);
//    return query.exec();
}

bool StorageDatabase::updateData(QString updateQuery, QList<int> *data){
    return addData(updateQuery, data);
//    QSqlQuery query;
//    query.prepare(updateQuery);
//    for (int i = 1; i < data->size(); i++){
//        query.addBindValue((*data)[i]);
//    }
//    query.addBindValue((*data)[0]);
//    return query.exec();
}


bool StorageDatabase::startTransaction(){ return db.transaction(); }
bool StorageDatabase::commit(){ return db.commit(); }
bool StorageDatabase::rollback(){ return db.rollback(); }

bool StorageDatabase::updateLocalClient(QList<QString> *infoList, QList<QString> *physList, QList<int> *nonPhysList){
    for (int i = 0; i < clientInfoList.size(); i++){
        if (infoList->value(0).toInt() == clientInfoList[i].value(0).toInt()){
            qDebug() << "Found client variable, updating. ";
            for (int j = 0; j <= clientListIndex[0][1]-clientListIndex[0][0]; j++){
                clientInfoList[i].replace(j+clientListIndex[0][0], infoList->value(j));
            }
            for (int j = 0; j <= clientListIndex[1][1]-clientListIndex[1][0]; j++){
                clientInfoList[i].replace(j+clientListIndex[1][0], physList->value(j));
            }
            for (int j = 0; j <= clientListIndex[2][1]-clientListIndex[2][0]; j++){
                clientInfoList[i][j+clientListIndex[2][0]] = QString::number(nonPhysList->value(j));
            }
            qDebug() << "Updated Local Variable = " << clientInfoList[i];
            break;
        } else if (i == clientInfoList.size()-1){
            qDebug() << "Couldn't find client variable, last searched = " << clientInfoList[i];
            return false;
        }
    }
    return true;
}

bool StorageDatabase::updateLocalAnimal(QList<QString> *infoList, QList<QString> *physList, QList<int> *nonPhysList){
    for (int i = 0; i < animalInfoList.size(); i++){
        if (infoList->value(0).toInt() == animalInfoList[i].value(0).toInt()){
            qDebug() << "Found animal variable, updating. ";
            for (int j = 0; j <= animalListIndex[0][1]-animalListIndex[0][0]; j++){
                animalInfoList[i].replace(j+animalListIndex[0][0], infoList->value(j));
            }
            for (int j = 0; j <= animalListIndex[1][1]-animalListIndex[1][0]; j++){
                animalInfoList[i].replace(j+animalListIndex[1][0], physList->value(j));
            }
            for (int j = 0; j <= animalListIndex[2][1]-animalListIndex[2][0]; j++){
                animalInfoList[i][j+animalListIndex[2][0]] = QString::number(nonPhysList->value(j));
            }
            qDebug() << "Updated Local Variable = " << animalInfoList[i];
            break;
        } else if (i == animalInfoList.size()-1){
            qDebug() << "Couldn't find animal variable, last searched = " << animalInfoList[i];
            return false;
        }
    }
    return true;
}



/** Takes an sql command as queryText, takes a list reference to save the information do.
  * This function queries the databse, gets the appropriate data and puts it into a QList,
  * and then bundles up all that data into a new, big QList to return. **/
QList<QList<QString>> * StorageDatabase::queryAndSave(QString queryText, QList<QList<QString>> * results){
    QSqlQuery query;
    query.prepare(queryText);   // Inputs text in query object
    query.exec();   // Runs query

    // Goes through and saves all the query results to "results"
    while (query.next()) {
        int i = 0;
        QList<QString> row;
        while(query.value(i).isValid()){
            row.append(query.value(i++).toString());
        }
        results->append(row);
    }

    return results;
}


/** Takes a QList, takes all the QString values between startIndex and endIndex
  * in that list, puts them into its own new QList, and returns that new QList. **/
QList<QString> StorageDatabase::addValuesToListInRange(QList<QString> * listToSearch, int startIndex, int endIndex){
    QList<QString> result;
    for (int i = startIndex; i <= endIndex; i++){
        result.append((*listToSearch)[i]);
    }
    return result;
}
