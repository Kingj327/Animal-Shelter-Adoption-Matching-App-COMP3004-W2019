#include "animal.h"

/** Default Constructor **/
Animal::Animal()
    : animalID(-1), name("") {

}

/** "Set All Values" Constructor**/
Animal::Animal(QList<QList<QString>> * animalInfo){
    setAllValues(*animalInfo);
}


/** Deconstructor **/
Animal::~Animal(){

}

/** Get Methods **/
int Animal::getID(){ return animalID; }
QString Animal::getName(){ return name; }
QList<QString> * Animal::getPhysAttr(){ return &listOfPhysAttr; }
QList<QString> * Animal::getNonPhysAttr(){ return &listOfNonPhysAttr; }
//QList<QList<QString>> * getConstListOfNonPhysAttr(){ return &constListOfNonPhysAttr; }

/** Set Methods **/
void Animal::setID(int animalID){ this->animalID = animalID; }
void Animal::setName(QString name){ this->name = name; }
void Animal::setPhysAttr(QList<QString> list){ this->listOfPhysAttr = list; }
void Animal::setNonPhysAttr(QList<QString> list){ this->listOfNonPhysAttr = list; }
void Animal::setNonPhysAttr(QList<int> list){
    QList<QString> tempList;
    for (int i = 0; i < list.size(); i++) {
        tempList.append(QString::number(list[0]));
    }
    this->listOfNonPhysAttr = tempList;
}
void Animal::setAllValues(QList<QList<QString>> animalInfo){
    animalID = animalInfo[0][0].toInt();
    name = animalInfo[0][1];
    listOfPhysAttr = animalInfo[1];
    listOfNonPhysAttr = animalInfo[2];
}

/** toString Method **/
QString Animal::toString(){
    QString str = QString("{(%1, %2) , (").arg(animalID).arg(name);
    foreach(QString word, listOfPhysAttr){
        str.append(word);
        str.append(", ");
    }
    str.chop(2);
    str.append(") , (");
    foreach(QString word, listOfNonPhysAttr){
        str.append(word);
        str.append(", ");
    }
    str.chop(2);
    str.append(")}");
    return str;
}
