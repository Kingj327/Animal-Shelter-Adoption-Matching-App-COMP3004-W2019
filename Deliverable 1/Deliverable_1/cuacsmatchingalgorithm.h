#ifndef CUACSMATCHINGALGORITHM_H
#define CUACSMATCHINGALGORITHM_H

#include <QList>
#include <QMap>
#include <QDebug>


class cuACSMatchingAlgorithm
{
public:
    cuACSMatchingAlgorithm(QList<QList<QString>> *animals, QList<QList<QString>> *clients);
    QMap<int, int> * getMatches();
    int getPassWhereMatchOccured(int clientID, int animalID);
    int getPhysMatchMinValue();

    /* Part 2 */
    int checkPhysicalAttributesOf(int clientID, int animalID);

private:
    QList<QList<QString>> *animalsList;
    QList<QList<QString>> *clientsList;
    QList<QList<QString>> matchingAlgList;
    int CLIENT_PHYS_INDEX = 9;
    int CLIENT_NON_PHYS_INDEX = 18;
    int ANIMAL_PHYS_INDEX = 2;
    int ANIMAL_NON_PHYS_INDEX = 11;

    // Filled in in part 1
    QList<QList<float>> clientPercentageList, animalPercentageList;
    QList<QList<int>> clientPriorityCatList, animalPriorityCatList;

    // Filled in in part 2
    QMap<int, QList<int>> allPotentialMatches;
    int threshold = 10;

    // Filled in in part 3
    QMap<int, int> clientNumberOfMatches, animalNumberOfMatches;
    QMap<int, int> matches;
    QMap<int, int> backupMatchesP1, backupMatchesP2;
    int maxNumberOfPotentialMatches;

    QList<QList<int>> catIndex = {
        {0, 5},     // Cat 1: Conscientiousness (6)
        {6, 11},    // Cat 2: Sociable (6)
        {12, 17},   // Cat 3: Temparament (6)
        {18, 22},   // Cat 4: Actions (5)
        {23, 28}    // Cat 5: Health Issues (6)
    };

    QList<int> totalCatValuePerAttribute = {24, 24, 24, 20, 14};

    void part1(bool log = false);
    void part2(int currentPass = 0, bool log = false);
    void part3(bool log = false);
    void part4(bool log = false);

    /* Part 1 */
    QList<QList<int>> getCatValuesOfUser(QList<QList<QString>> *userList, int offset);
    QList<QList<float>> convertToPercentages(QList<QList<int>> userList);
    QList<QList<int>> determinePriorityCategoryOrder(QList<QList<float>> userPercentageList);

    /* Part 2 */
    int physMatchMinValue = 70;
//    int checkPhysicalAttributesOf(int clientID, int animalID);

    /* Part 3 */
    void matchAllSinglePairs();
    void matchAMultiPair(bool log = false);
    void match(int clientID, int animalID, bool log = false);
    void cleanupPotentialMatches(int clientID, int animalID, bool log = false);
    void updateNumberOfPotentialMatches(bool log = false);
    int getMaxNumberOfPotentialMatches();
};

#endif // CUACSMATCHINGALGORITHM_H
