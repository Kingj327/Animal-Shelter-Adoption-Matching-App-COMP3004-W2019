#ifndef ANIMAL_H
#define ANIMAL_H

#include <QList>

class Animal {
    public:
        Animal();
        Animal(QList<QList<QString>> *animalInfo);
        ~Animal();
        int getID();
        QString getName();
        QList<QString> * getPhysAttr();
        QList<QString> * getNonPhysAttr();
//        QList<QList<QString>> * getConstListOfNonPhysAttr();
        void setID(int animalID);
        void setName(QString name);
        void setPhysAttr(QList<QString> list);
        void setNonPhysAttr(QList<QString> list);
        void setNonPhysAttr(QList<int> list);
        void setAllValues(QList<QList<QString>> animalInfo);
        QString toString();

    private:
        /** Constant string containing the names of all the physical
          * attributes. **/
        const QString constListOfPhysAttr[10] = {
            "animalID",
            "Athletic",
            "Gender",
            "Age",
            "Size",
            "Weight (lbs.)",
            "Primary Color",
            "Secondary Color",
            "Breed",
            "Type of Animal"
        };

        /** Constant string containing the names of all the non-physical
          * attributes in position [_][0] (the first position in the inner
          * list) and the descriptors for the attributes in the following
          * positions of te inner list (positions 1-3).
          * NOTE: The listOfNonPhysAttr contains numbers from 0-2.
          *       The pre-defined options/attributes are stored in this constant
          *         string in position 1-3. This can be changed in the database
          *         later. **/
        const QList<QList<QString>> constListOfNonPhysAttr = {
            {"animalID"},
            {"aggression",        "low", "average", "high"},
            {"protectiveness",    "low", "average", "high"},
            {"confidence",        "low", "average", "high"},
            {"friendliness",      "low", "average", "high"},
            {"sociable",          "low", "average", "high"},
            {"loyal",             "low", "average", "high"},
            {"neediness",         "low", "average", "high"},
            {"habits",            "Night Owl", "Early Bird", "unknown"},
            {"intelligence",      "low", "average", "high"},
            {"diet",              "heavy diet", "regular diet", "light diet"},
            {"allergies",         "no allergies", "some allergies", "unknown"},
            {"preferences",       "single-owner", "couple", "family"},
            {"activityLevel",     "low", "average", "high"},
            {"maintenance",       "low", "average", "high"},
            {"health",            "health issues (unknown severity)", "health issues (minor)", "healthy"},
            {"obedienceTrained",  "not trained", "partially", "trained"},
            {"toiletTrained",     "not trained", "partially", "trained"},
            {"environment",       "indoors", "both", "outdoors"}
        };


        /** Variables to be filled from database **/
        int animalID;
        QString name;
        QList<QString> listOfPhysAttr;
        QList<QString> listOfNonPhysAttr;

};


#endif // ANIMAL_H


/*  Extra stuff...

        const string listOfNonPhysAtt[12] = {
            "animalID",
            "aggression",
            "protectiveness",
            "confidence",
            "friendliness",
            "sociable",
            "loyal",
            "neediness",
            "habits",
            "intelligence",
            "diet",
            "allergies",
            "preferences",
            "activityLevel",
            "maintenance",
            "health",
            "obedienceTrained",
            "toiletTrained",
            "environment"
        };

*/
