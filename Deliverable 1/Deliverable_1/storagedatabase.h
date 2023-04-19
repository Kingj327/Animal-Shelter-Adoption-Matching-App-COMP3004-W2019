#ifndef STORAGEDATABASE_H
#define STORAGEDATABASE_H

#include <string>
using namespace std;

#include <QtDebug>
#include <QString>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlQueryModel>

class StorageDatabase
{
public:
    StorageDatabase();  // Inactive (Called but doesn't do anthing really)
    StorageDatabase(string dbFileName); // Inactive
    ~StorageDatabase(); // Inactive
    void loadDatabase();
    void loadSimpleDatabase();
    void closeDatabase();
    QList<QList<QString>>* getCompleteAnimalListPtr();
    QList<QList<QString>> getCompleteAnimalList();
    QList<QList<QString>> getSpecificAnimal(int index); // index if looping through an array
    QList<QList<QString>> getSpecificAnimalByID(int id);
    QList<QList<QString>>* getCompleteClientListPtr();
    QList<QList<QString>> getCompleteClientList();
    QList<QList<QString>> getSpecificClient(int index); // index if looping through an array
    QList<QList<QString>> getSpecificClientByID(int id);
    QList<QList<QString>>* getCompleteLoginListPtr();
    QList<QList<QString>> getCompleteLoginList();
    QString getSelectAllClientProfiles(); // query
    QString getSpecificClientProfile(int id);
    QString getClientInfoInsertQuery();
    QString getClientPhysAttrInsertQuery();
    QString getClientNonPhysAttrInsertQuery();
    QString getClientInfoDeletionQuery();
    QString getClientPhysAttrDeletionQuery();
    QString getClientNonPhysAttrDeletionQuery();
    QString getClientInfoUpdateQuery();
    QString getClientPhysAttrUpdateQuery();
    QString getClientNonPhysAttrUpdateQuery();
    QString getLoginInfoQuery();
    QString getSelectAllAnimalProfiles(); // query
    QString getAnimalIDInsertQuery();
    QString getAnimalPhysAttrInsertQuery();
    QString getAnimalNonPhysAttrInsertQuery();
    QString getAnimalIDDeletionQuery();
    QString getAnimalPhysAttrDeletionQuery();
    QString getAnimalNonPhysAttrDeletionQuery();
    QString getAnimalIDUpdateQuery();
    QString getAnimalPhysAttrUpdateQuery();
    QString getAnimalNonPhysAttrUpdateQuery();
    int getMaxAnimalID();
    bool incrementMaxAnimalID();
    int getMaxClientID();
    bool incrementMaxClientID();
    QSqlQueryModel *getQueryModel(QString desiredQuery);
    bool addData(QString injectionQuery, QList<QString> *data);
    bool addData(QString injectionQuery, QList<int> *data);
    bool deleteData(QString deletionQuery, QList<QString> *data);
    bool deleteData(QString deletionQuery, QList<int> *data);
    bool updateData(QString updateQuery, QList<QString> *data);
    bool updateData(QString updateQuery, QList<int> *data);
//    bool editData(QString deletionQuery, QString injectionQuery, QList<QString> *data);
//    bool editData(QString deletionQuery, QString injectionQuery, QList<int> *data);
    bool startTransaction();
    bool commit();
    bool rollback();
    bool updateLocalClient(QList<QString> *infoList, QList<QString> *physList, QList<int> *nonPhysList);
    bool updateLocalAnimal(QList<QString> *infoList, QList<QString> *physList, QList<int> *nonPhysList);
//    int MAXANIMALID = 0; // Used to increment animalID in database
    QList<QList<QString>> * queryAndSave(QString queryText, QList<QList<QString>> *results);


private:
    QSqlDatabase db;
//    QString dbName = "../sqlDatabase_D1.db"; // For D1
    QString dbName = "../sqlDatabase_D3.db"; // For D2
    int MAXANIMALID = 0; // Used to increment animalID in database
    int MAXCLIENTID = 0; // Used to increment animalID in database
    QSqlQueryModel *model;
    QSqlQuery *qry;

    /** List of commonly used queries into this database **/
    const QString selectAllClientProfiles = "SELECT * FROM client_info";
    const QString selectAllClientProfilesAndPreferences =
            "SELECT * FROM client_info LEFT NATURAL JOIN "
            "(SELECT * FROM client_phys_attr_pref NATURAL JOIN client_non_phys_attr_pref)";
    const QString selectSpecificClientProfilesAndPreferences =
            "SELECT * FROM client_info LEFT NATURAL JOIN "
            "(SELECT * FROM client_phys_attr_pref NATURAL JOIN client_non_phys_attr_pref)"
            "WHERE clientID = ";
    const QString clientInfoInsertQuery =
            "INSERT INTO client_info (clientID, cName, cBirthDay, cBirthMonth, cBirthYear,"
            "cEmail, cAreaCode, cOfficeCode, cStationCode) VALUES (?,?,?,?,?,?,?,?,?)";
    const QString clientPhysAttrInsertQuery =
            "INSERT INTO client_phys_attr_pref (clientID, athletic, gender, age, size, weight, "
            "primaryColor, secondaryColor, breed, type_of_animal) VALUES (?,?,?,?,?,?,?,?,?,?)";
//    const QString clientNonPhysAttrInsertQuery =
//            "INSERT INTO client_non_phys_attr_pref (clientID, intelligence, reliability, attentiveness, "
//            "hardWorking, disciplined, awareness, friendliness, neediness, sociability, adaptable, "
//            "leadership, outgoing, patience, independence, affection, loyalty, sharp, hyperactive, "
//            "submissive,shyness, courageous, protectiveness, aggression, healthIssues, illnessChance, "
//            "activityLevel, diet, lifespan, sleepPatterns)"
//            "VALUES (?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)"
    const QString clientNonPhysAttrInsertQuery =
            "INSERT INTO client_non_phys_attr_pref VALUES (?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)";
    const QString clientInfoDeletionQuery =
            "DELETE FROM client_info WHERE clientID = ?";
    const QString clientPhysAttrDeletionQuery =
            "DELETE FROM client_phys_attr_pref WHERE clientID = ?";
    const QString clientNonPhysAttrDeletionQuery =
            "DELETE FROM client_non_phys_attr_pref WHERE clientID = ?";
    const QString clientInfoUpdateQuery =
            "UPDATE client_info SET cName = ?, cBirthDay = ?, cBirthMonth = ?, "
            "cBirthYear = ?, cEmail = ?, cAreaCode = ?, cOfficeCode = ?, cStationCode = ? "
            "WHERE clientID = ?";
    const QString clientPhysAttrUpdateQuery =
            "UPDATE client_phys_attr_pref SET athletic = ?, gender = ?, age = ?, "
            "size = ?, weight = ?, primaryColor = ?, secondaryColor = ?, breed = ?, "
            "type_of_animal = ? WHERE clientID = ?";
    const QString clientNonPhysAttrUpdateQuery =
            "UPDATE client_non_phys_attr_pref SET "
            "intelligence = ?, reliability = ?, attentiveness = ?, hardWorking = ?, disciplined = ?, awareness = ?, "
            "friendliness = ?, neediness = ?, sociability = ?, adaptable = ?, leadership = ?, outgoing = ?, "
            "patience = ?, independence = ?, affection = ?, loyalty = ?, sharp = ?, hyperactive = ?, "
            "submissive = ?, shyness = ?, courageous = ?, protectiveness = ?, aggression = ?, "
            "healthIssues = ?, illnessChance = ?, activityLevel = ?, diet = ?, lifespan = ?, sleepPatterns = ? "
            "WHERE clientID = ?";


    const QString loginInfoQuery = "SELECT * from login_info";


    const QString selectAllAnimalProfiles =
            "SELECT * FROM animals LEFT NATURAL JOIN "
            "(SELECT * FROM animals_phys_attr NATURAL JOIN animals_non_phys_attr)";
    const QString animalIDInsertQuery = "INSERT INTO animals (animalID, name) VALUES (?,?)";
    const QString animalPhysAttrInsertQuery =
            "INSERT INTO animals_phys_attr (animalID, athletic, gender, age, size, weight, "
            "primaryColor, secondaryColor, breed, type_of_animal) VALUES (?,?,?,?,?,?,?,?,?,?)";
//    const QString animalNonPhysAttrInsertQuery =
//            "INSERT INTO animals_non_phys_attr (animalID, intelligence, reliability, attentiveness, "
//            "hardWorking, disciplined, awareness, friendliness, neediness, sociability, adaptable, "
//            "leadership, outgoing, patience, independence, affection, loyalty, sharp, hyperactive, "
//            "submissive,shyness, courageous, protectiveness, aggression, healthIssues, illnessChance, "
//            "activityLevel, diet, lifespan, sleepPatterns)"
//            "VALUES (?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)"
    const QString animalNonPhysAttrInsertQuery =
            "INSERT INTO animals_non_phys_attr VALUES (?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)";
    const QString animalIDDeletionQuery =
            "DELETE FROM animals WHERE animalID = ?";
    const QString animalPhysAttrDeletionQuery =
            "DELETE FROM animals_phys_attr WHERE animalID = ?";
    const QString animalNonPhysAttrDeletionQuery =
            "DELETE FROM animals_non_phys_attr WHERE animalID = ?";
    const QString animalIDUpdateQuery =
            "UPDATE animals SET name = ? WHERE animalID = ?";
    const QString animalPhysAttrUpdateQuery =
            "UPDATE animals_phys_attr SET athletic = ?, gender = ?, age = ?, "
            "size = ?, weight = ?, primaryColor = ?, secondaryColor = ?, breed = ?, "
            "type_of_animal = ? WHERE animalID = ?";
    const QString animalNonPhysAttrUpdateQuery =
            "UPDATE animals_non_phys_attr SET "
            "intelligence = ?, reliability = ?, attentiveness = ?, hardWorking = ?, disciplined = ?, awareness = ?, "
            "friendliness = ?, neediness = ?, sociability = ?, adaptable = ?, leadership = ?, outgoing = ?, "
            "patience = ?, independence = ?, affection = ?, loyalty = ?, sharp = ?, hyperactive = ?, "
            "submissive = ?, shyness = ?, courageous = ?, protectiveness = ?, aggression = ?, "
            "healthIssues = ?, illnessChance = ?, activityLevel = ?, diet = ?, lifespan = ?, sleepPatterns = ? "
            "WHERE animalID = ?";

    /** Holds all the animal info from the database in one Qlist, with each specific
      * animal's information being joined/merged together to one QList (inner list). **/
    QList<QList<QString>> animalInfoList;
    /** Note: animalInfoList's inner list has the following format (As of Mar 5, 2:00 am)
            "animalID",
            "name",
            "Athletic",
            "Gender",
            "Age",
            "Size",
            "Weight (lbs.)",
            "Primary Color",
            "Secondary Color",
            "Breed",
            "Type of Animal"
            "intelligence",
            "reliability",
            "attentiveness",
            "hardWorking",
            "disciplined",
            "awareness",
            "friendliness",
            "neediness",
            "sociability",
            "adaptable",
            "leadership",
            "outgoing",
            "patience",
            "independence",
            "affection",
            "loyalty",
            "sharp",
            "hyperactive",
            "submissive",
            "shyness",
            "courageous",
            "protectiveness",
            "aggression",
            "healthIssues",
            "illnessChance",
            "activityLevel",
            "diet",
            "lifespan",
            "sleepPatterns",
      * **/

    /** Constant index values used to easily sort through the information above. **/
    const int animalListIndex[3][2] = {
        {0,1},  // Hard-Coded indicies for all attributes in the animals table
        {2,10}, // Hard-Coded indicies for all attributes in the animals_phys_attr table
        {11,39} // Hard-Coded indicies for all attributes in the animals_non_phys_attr table
    };


    /** Holds all the client info from the database in one Qlist, with each specific client info +
      * animal's preferences being joined/merged together to one QList (inner list). **/
    QList<QList<QString>> clientInfoList;
    /** Note: ClientInfoList's inner list has the following format (As of Mar 19, 4:30 pm)
            "clientID",
            "cName",
            "cBirthDay",
            "cBirthMonth",
            "cBirthYear",
            "cEmail",
            "cAreaCode",
            "cOfficeCode",
            "cStationCode",


            "Athletic",
            "Gender",
            "Age",
            "Size",
            "Weight (lbs.)",
            "Primary Color",
            "Secondary Color",
            "Breed",
            "Type of Animal"


            "intelligence",
            "reliability",
            "attentiveness",
            "hardWorking",
            "disciplined",
            "awareness",
            "friendliness",
            "neediness",
            "sociability",
            "adaptable",
            "leadership",
            "outgoing",
            "patience",
            "independence",
            "affection",
            "loyalty",
            "sharp",
            "hyperactive",
            "submissive",
            "shyness",
            "courageous",
            "protectiveness",
            "aggression",
            "healthIssues",
            "illnessChance",
            "activityLevel",
            "diet",
            "lifespan",
            "sleepPatterns",
      * **/

    /** Constant index values used to easily sort through the information above. **/
    const int clientListIndex[3][2] = {
        {0,8},  // Hard-Coded indicies for all client info in the client_info table
        {9,17}, // Hard-Coded indicies for all animal prefereces in the client_phys_attr table
        {18,46} // Hard-Coded indicies for all animal prefereces in the client_non_phys_attr table
    };

    /** Holds all the login info from the database in one Qlist. Note that the default client
      * login still exists, and there is only 1 generic staff login for the system. **/
    QList<QList<QString>> loginInfoList;
    /** Note: ClientInfoList's inner list has the following format (As of Mar 19, 4:30 pm)
            "clientID",
            "username",
            "password",
      * **/


//    QList<QList<QString>> * queryAndSave(QString queryText, QList<QList<QString>> *results);
    QList<QString> addValuesToListInRange(QList<QString> * listToSearch, int startIndex, int endIndex); // Used in getSpecificAnimal()
};

#endif // STORAGEDATABASE_H
