#include "cuacsmatchingalgorithm.h"

cuACSMatchingAlgorithm::cuACSMatchingAlgorithm(QList<QList<QString>> *animals, QList<QList<QString>> *clients)
{
    animalsList = animals;
    clientsList = clients;
    part1();
    part2();
    part3();
    part4();
}

/* NOTE: if creating a "Run" functions, make sure you have a "Clear all vairables" function for reusability */
QMap<int, int> * cuACSMatchingAlgorithm::getMatches(){ return &matches; }
int cuACSMatchingAlgorithm::getPhysMatchMinValue(){ return physMatchMinValue; }
int cuACSMatchingAlgorithm::getPassWhereMatchOccured(int clientID, int animalID){
    int currentPass = -1;
    if (!backupMatchesP1.isEmpty() && backupMatchesP1.keys().contains(clientID)
            && backupMatchesP1.values().contains(animalID)){
        currentPass = 1;
    } else if (!backupMatchesP2.isEmpty() && backupMatchesP2.keys().contains(clientID)
               && backupMatchesP2.values().contains(animalID)){
        currentPass = 2;
    } else if (!matches.isEmpty() && matches.keys().contains(clientID)
               && matches.values().contains(animalID)){
        currentPass = 3;
    }
    return currentPass;
}

void cuACSMatchingAlgorithm::part1(bool log){
    qDebug() << "\n********** Algorithm Part 1 **********";

    clientPercentageList = convertToPercentages(getCatValuesOfUser(clientsList, CLIENT_NON_PHYS_INDEX));
    animalPercentageList = convertToPercentages(getCatValuesOfUser(animalsList, ANIMAL_NON_PHYS_INDEX));
    clientPriorityCatList = determinePriorityCategoryOrder(clientPercentageList);
    animalPriorityCatList = determinePriorityCategoryOrder(animalPercentageList);

    if (log) qDebug() << "Client catValue = " << getCatValuesOfUser(clientsList, CLIENT_NON_PHYS_INDEX);
    if (log) qDebug() << "Client percentage = " << clientPercentageList;
    qDebug() << "Client Priority Cat = " << clientPriorityCatList;

    if (log) qDebug() << "";

    if (log) qDebug() << "Animal catValue = " << getCatValuesOfUser(animalsList, ANIMAL_NON_PHYS_INDEX);
    if (log) qDebug() << "Animal percentage = " << animalPercentageList;
    qDebug() << "Animal Priority Cat = " << animalPriorityCatList;

}

QList<QList<int>> cuACSMatchingAlgorithm::getCatValuesOfUser(QList<QList<QString>> *userList, int offset){
    QList<QList<int>> catValue;
    for (int i = 0; i < userList->size(); i++){
//        qDebug() << "Client ["<<i<<"] = " << clientsList->value(i)[1];
        QList<int> individualUserCatValue;
        for (int j = 0; j < catIndex.size(); j++){
            int sum = 0;
            for (int k = 0; k <= catIndex[j][1]-catIndex[j][0]; k++){
//                if (i == 0) qDebug() << "k = " << k << userList->value(i)[offset + catIndex[j][0] + k].toInt();
                sum += userList->value(i)[offset + catIndex[j][0] + k].toInt();
            }
            individualUserCatValue.append(sum);
        }
        catValue.append(individualUserCatValue);
    }
    return catValue;
}

QList<QList<float>> cuACSMatchingAlgorithm::convertToPercentages(QList<QList<int>> userList){
    QList<QList<float>> userPercentageList;
    for (int i = 0; i < userList.size(); i++){
//        qDebug() << "Client ["<<i<<"] = " << clientsList->value(i)[1];
        QList<float> individualUserPercentageList;
        for (int j = 0; j < catIndex.size(); j++){
//            if (i == 0) qDebug() << "userList = " << userList.value(i)[j]
//                                    << ", Calculation = "
//                                    << (userList.value(i)[j])
//                                    << totalCatValuePerAttribute[j]
//                                    << (float(userList.value(i)[j])/totalCatValuePerAttribute[j]);
            individualUserPercentageList.append((float(userList.value(i)[j])/totalCatValuePerAttribute[j])*100);
//            if (i == 0) qDebug() << "   after = " << individualUserPercentageList[j];
        }
        userPercentageList.append(individualUserPercentageList);
    }
    return userPercentageList;
}

/* Returns list where index 0 is priority, index 1 is second priority, index 2 is third priority, etc.
   Also note the value at each index is the category number
   (ie. value 0 = conscientiousness, 1 = sociable... */
QList<QList<int>> cuACSMatchingAlgorithm::determinePriorityCategoryOrder(QList<QList<float>> userPercentageList){
    QList<QList<int>> results;
//    qDebug() << "Starting Percentages = " << userPercentageList;
    for (int i = 0; i < userPercentageList.size(); i++){
//        temp.append(determineUserPriorityCategoryOrder(userPercentageList->value(i)));
        QMap<int, int> tempMap;
        for (int j = 0; j < userPercentageList.value(i).size(); j++){
//            if (i < 3) qDebug() << "j = " << j << userPercentageList.value(i)[j];
            tempMap.insert(j, userPercentageList.value(i)[j]);
        }

        QList<int> tempList = tempMap.values();
        std::sort(tempList.begin(), tempList.end());
        std::reverse(tempList.begin(), tempList.end());
        QList<int> temp;

        for (int j = 0; j < userPercentageList.value(i).size(); j++){
//            if (i < 3) qDebug() << "j = " << j << tempMap.key(tempList[j]) << tempList << tempMap;
            temp.append(tempMap.key(tempList[j]));
            tempMap.remove(tempMap.key(tempList[j]));
        }
        results.append(temp);
    }
    return results;
}






void cuACSMatchingAlgorithm::part2(int currentPass, bool log){
    qDebug() << "\n********** Algorithm Part 2 **********";
    qDebug() << "Current Pass = " << currentPass+1; // only +1 for view sake. Starts at 0.

    /*
    1. Consider the highest scoring category as the highest priority category. That is the category we
        will prioritize matching for the client. Also consider a threshold value that we will use to
        find and match animals in which their category value is within the clients category value +-
        the threshold.

                If (Animal Priority Category Value)
                within (Client Priority Category Value +- Threshold)
                then match.

    2. Repeat the above step between every possible client/animal match (cross product of clients and
        animals).
        */

    // Going through all clients
    for (int clientIndex = 0; clientIndex < clientPriorityCatList.size(); clientIndex++){
        QList<int> tempMatches;

        if (currentPass > 0 && matches.contains(clientIndex)){
            /* Skip to the next client */
            if (log) qDebug() << "Client" << clientIndex << "already matched. Moving on.";
        } else {    // Else that client hasn't been matched yet so carry on searching...

            // Going through all animals
            for (int animalIndex = 0; animalIndex < animalPriorityCatList.size(); animalIndex++){
                if (currentPass > 0 && matches.values().contains(animalIndex)){
                    if (log) qDebug() << "Animal" << animalIndex << "already matched. Moving on.";
                } else {    // Else that animal hasn't been matched yet so carry on searching...
                    int priorityCat = clientPriorityCatList[clientIndex][currentPass];
                    if ((clientPercentageList[clientIndex][priorityCat]
                        >= animalPercentageList[animalIndex][priorityCat] - threshold) &&
                        (clientPercentageList[clientIndex][priorityCat]
                        <= animalPercentageList[animalIndex][priorityCat] + threshold)){
        //                    if (clientIndex == 0) {
        //                        qDebug() << "Match on animal" << animalIndex << "where"
        //                                 << clientPercentageList[clientIndex][priorityCat] << "within"
        //                                 << (animalPercentageList[animalIndex][priorityCat] - threshold) << "-"
        //                                 << (animalPercentageList[animalIndex][priorityCat] + threshold);
        //                    }

//                        qDebug() << "Check Physical Attributes of client" << clientIndex << "and animal" << animalIndex
//                                 << checkPhysicalAttributesOf(clientIndex, animalIndex);
                        // Match
                        int matchDeterminer = checkPhysicalAttributesOf(clientIndex, animalIndex);
                        //qDebug() << "Total value from our physical attributes: " << matchDeterminer;

                        /* This if-statement determines which animal gets matched mainly based on the most important category which is
                         * the type of animal +- minor adjustment points from the other physical attributes.
                         * How it works -- It adopts a point system that tallies total points from the physical attribute preferences */
                        qDebug() << "Phisical Attribute match for client" << clientIndex
                                 << "and animal" << animalIndex << "is" << matchDeterminer;
                        if(matchDeterminer >= physMatchMinValue){
                            /* With the way this is set up, if you match the animal type and breed, and
                             * lose points on everything else, you'd get a 60. If you get any (10 at least)
                             * bonus points along the way, then we'll allow the match. Otherwise no match.
                             *
                             * */
                            // Match
                            tempMatches.append(animalIndex);
                        }
                    }
                }
            }
        }
        if (!tempMatches.isEmpty()) allPotentialMatches.insert(clientIndex, tempMatches);
    }
    qDebug() << "All Potential Matches = " << allPotentialMatches;
}

int cuACSMatchingAlgorithm::checkPhysicalAttributesOf(int clientID, int animalID){
//    qDebug() << clientID << animalID;
//    if (clientID == 18) qDebug() << *clientsList;
    QList<QString> client = clientsList->value(clientID);
    QList<QString> animal = animalsList->value(animalID);
    int res = 0;

    /*** EXTREMELY IMPORTANT Matches ***/
    //: Type of Animal (ie.  Dog, Cat, Horse)
    if (client[CLIENT_PHYS_INDEX+8].toLower().trimmed().compare(animal[ANIMAL_PHYS_INDEX+8].toLower().trimmed()) != 0
            && client[CLIENT_PHYS_INDEX+8] != "" && animal[ANIMAL_PHYS_INDEX+8] != ""){
            /* MAJOR Negative Points */
//            qDebug() << "Type1: " << client[CLIENT_PHYS_INDEX+8].toLower().trimmed().compare(animal[ANIMAL_PHYS_INDEX+8].toLower().trimmed())
//                    << client[CLIENT_PHYS_INDEX+8].toLower().trimmed() << animal[ANIMAL_PHYS_INDEX+8].toLower().trimmed();
            res -= 100;
    } else {
        if (client[CLIENT_PHYS_INDEX+8].toLower().trimmed().compare(animal[ANIMAL_PHYS_INDEX+8].toLower().trimmed()) == 0
                && client[CLIENT_PHYS_INDEX+8] != "" && animal[ANIMAL_PHYS_INDEX+8] != ""){
            /* MAJOR BONUS Points */
//            qDebug() << "Type2: " << client[CLIENT_PHYS_INDEX+8].toLower().trimmed().compare(animal[ANIMAL_PHYS_INDEX+8].toLower().trimmed())
//                    << client[CLIENT_PHYS_INDEX+8].toLower().trimmed() << animal[ANIMAL_PHYS_INDEX+8].toLower().trimmed();
            res += 100;
        }
        //: Breed (if the type of animal and breed matches, major bonus points).
        if (client[CLIENT_PHYS_INDEX+7].toLower().trimmed().compare(animal[ANIMAL_PHYS_INDEX+7].toLower().trimmed()) != 0){
            /* MAJOR Bonus points */
//            qDebug() << "Breed: " << client[CLIENT_PHYS_INDEX+7].toLower().trimmed().compare(animal[ANIMAL_PHYS_INDEX+7].toLower().trimmed())
//                    << client[CLIENT_PHYS_INDEX+7].toLower().trimmed() << animal[ANIMAL_PHYS_INDEX+7].toLower().trimmed();
            res += 50;
        }
    }


    /*** Somewhat Important Matches ***/
    //: Size: (if you ask for small, can't get a Large)
    if ((client[CLIENT_PHYS_INDEX+3].toLower() == "small" && animal[ANIMAL_PHYS_INDEX+3].toLower() == "large")
            || (client[CLIENT_PHYS_INDEX+3].toLower() == "large" && animal[ANIMAL_PHYS_INDEX+3].toLower() == "small")){
        /* Negative Size points */
            res -= 30;
    } else {
        if (client[CLIENT_PHYS_INDEX+3].compare(animal[CLIENT_PHYS_INDEX+3]) == 0){
            /* Bonus Size Points */
            res += 30;

            //: Weight: (if weight within a generous threshold and the proper size is matched, give bonus points)
            try {
                if (client[CLIENT_PHYS_INDEX+4].toInt() < animal[ANIMAL_PHYS_INDEX+4].toInt()*1.5 &&
                        client[CLIENT_PHYS_INDEX+4].toInt() > animal[ANIMAL_PHYS_INDEX+4].toInt()*0.667){
                    /* Bonus Weight Points */
                        res += 10;
                }
            } catch (const std::exception err) { qDebug() << "Caught toInt() Weight handling error?"; }

        }
        /* Neutral Size Points */
        res += 0;
    }


    //: Athletic (opposites are negative points, match is bonus)
    if ((client[CLIENT_PHYS_INDEX+0] == "Y" && animal[ANIMAL_PHYS_INDEX+0] == "N")
            || (client[CLIENT_PHYS_INDEX+0] == "N" && animal[ANIMAL_PHYS_INDEX+0] == "Y")){
        /* Negative Atheltic Points */
            res -= 30;
    } else {
        if (client[CLIENT_PHYS_INDEX+0].compare(animal[ANIMAL_PHYS_INDEX+0]) == 0){
            /* Bonus Athletic Points */
            res += 30;
        }
        /* Neutral Athletic Points */
            res += 0;
    }


    //: Gender (opposites are negative points, match is bonus)
    if ((client[CLIENT_PHYS_INDEX+1] == "Male" && animal[ANIMAL_PHYS_INDEX+1] == "Female")
            || (client[CLIENT_PHYS_INDEX+1] == "Female" && animal[ANIMAL_PHYS_INDEX+1] == "Male")){
        /* Negative Gender Points */
            res -= 30;
    } else {
        if (client[CLIENT_PHYS_INDEX+1].compare(animal[ANIMAL_PHYS_INDEX+1]) == 0){
            /* Bonus Gender Points */
            res += 30;
        }
        /* Neutral Gender Points */
            res += 0;
    }


    //: Age
    try {
        if (client[CLIENT_PHYS_INDEX+2].toInt() < animal[ANIMAL_PHYS_INDEX+2].toInt()+2 &&
                client[CLIENT_PHYS_INDEX+2].toInt() > animal[ANIMAL_PHYS_INDEX+2].toInt()-2){
            /* Bonus Age Points */
                res += 30;
        } else { /* Negative Age Points? */ res -= 30; }
    } catch (const std::exception err) { qDebug() << "Caught toInt() Age handling error?"; }


    //: Primary Color (match is bonus)
    if (client[CLIENT_PHYS_INDEX+5].toLower().trimmed().compare(animal[ANIMAL_PHYS_INDEX+5].toLower().trimmed()) == 0){
        /* Bonus Primary Color Points */
        res += 10;
    }


    //: Secondary Color (match is bonus)
    if (client[CLIENT_PHYS_INDEX+6].toLower().trimmed().compare(animal[ANIMAL_PHYS_INDEX+6].toLower().trimmed()) == 0){
        /* Bonus Secondary Color Points */
        res += 5;
    }

    return res;
}





void cuACSMatchingAlgorithm::part3(bool log){
    qDebug() << "\n********** Algorithm Part 3 **********";
    /*

      1. Get info from part 2.

      2. Get the amount of matches each animal/client has (both animals anc clients)

      3. Main algorithm:

        - Look for client with 1 match to an animal. If found, give the client that match and remove that
          animal from every other client's list (clean up the matches).

        - If no matches of size 1, look for the client with the next smallest amount of matches:

            - If client not found then there are no more potential matches, so move on to part 4.

            - If client found with size (# of matches to animal) > 1, then look at each animal’s individual
              number of matches, take the animal with the smallest number of matches, and match that animal
              to this client.
                - Clean up the matches (ie. lets say the client above was client A, and the animal was
                  animal #6. Since client A and animal #6 are no longer available to be matched to any
                  other entity, remove any edges connected to them.)
    */


    /* Step 2, get the amount of matches for each client/animal */
    matches.clear(); // used below, so just making sure its cleared.
    updateNumberOfPotentialMatches();
    maxNumberOfPotentialMatches = getMaxNumberOfPotentialMatches();



    /* Step 3, match. */
    matchAllSinglePairs();

    bool flag = true;
    while (flag){
        matchAMultiPair();
        matchAllSinglePairs();
        flag = false;
        for (int i = 0; i < allPotentialMatches.size(); i++){
            if (!allPotentialMatches[i].isEmpty()) flag = true;
        }
    }
    if (log) qDebug() << "";
    qDebug() << "Part 3 of Algorithm Complete. "
                "\nThere were" << matches.size() << "matches found out of a maximum of"
                    << maxNumberOfPotentialMatches << "possible total matches between"
                    << clientsList->size()-backupMatchesP1.size()-backupMatchesP2.size() << "clients and"
                    << animalsList->size()-backupMatchesP1.size()-backupMatchesP2.size() << "animals."
                "\nMatched (clientID, animalID) pairs are:\n" << matches;
}


void cuACSMatchingAlgorithm::matchAllSinglePairs(){
    /* Matches all client/animal single pairs */
    /* If theres atleast 1 client with only a single animal match, then go through all possible matches,
       find all clients with a single animal pair, and match them up. */
    if (animalNumberOfMatches.values().contains(1)){
        for (int i = 0; i < allPotentialMatches.size(); i++){
            if (clientNumberOfMatches[i] == 1){
                match(i, allPotentialMatches[i][0]);
            }
        }
    }
}

void cuACSMatchingAlgorithm::matchAMultiPair(bool log){
    /* Finds a single client with the smallest amount of potnential matches > 1, and matches it. */
    if (log) qDebug() << "\nMoving on to finding Clients with > 1 match.";
    int tempMinNumberOfMatches = -1;
    int tempClientID = -1;
    for (int i = 0; i < allPotentialMatches.size(); i++){
        if (clientNumberOfMatches[i] > 1){
            if (clientNumberOfMatches[i] < tempMinNumberOfMatches || tempMinNumberOfMatches == -1){
                tempClientID = i;
                tempMinNumberOfMatches = clientNumberOfMatches[tempClientID];
            }
        }
    }


    if (log) qDebug() << "Client" << tempClientID << "found with minimum possible number of matches that are > 1. Potential matches are" << allPotentialMatches[tempClientID];
    int tempMaxNumberOfMatches = 0;
    int tempAnimalID = -1;
    for (int j = 0; j < allPotentialMatches.value(tempClientID).size(); j++){
        if (log) qDebug() << "Animal" << allPotentialMatches[tempClientID][j] << "has" << animalNumberOfMatches[allPotentialMatches[tempClientID][j]] << "potential matches.";
        if (animalNumberOfMatches[allPotentialMatches[tempClientID][j]] > tempMaxNumberOfMatches){
            tempAnimalID = allPotentialMatches[tempClientID][j];
            tempMaxNumberOfMatches = animalNumberOfMatches[tempAnimalID];
        }
    }
    if (log) qDebug() << "Animal" << tempAnimalID << "has the most matches. Therefore match Client" << tempClientID << "with Animal" << tempAnimalID;
    match(tempClientID, tempAnimalID);
}

void cuACSMatchingAlgorithm::match(int clientID, int animalID, bool log){
    /*
        Adds client/animal pair to match QMap.
        Removes/Cleans up potential matches (removes animal/client from potential match list)
        Updates client/animal number of potential matches.

    */
    if (clientID != -1 && animalID != -1){
        if (log) qDebug() << "";
        matches.insert(clientID, animalID);
        cleanupPotentialMatches(clientID, animalID);
        updateNumberOfPotentialMatches();
        if (log) qDebug() << "Matches: " << matches;
    } else if (log) { qDebug() << "One of the ID's given to \"match()\" was -1, so no matching occured."; }

}

void cuACSMatchingAlgorithm::cleanupPotentialMatches(int clientID, int animalID, bool log){
    if (log) qDebug() << "Pre-Cleanup: " << allPotentialMatches;
    allPotentialMatches.remove(clientID);
    if (log) qDebug() << "Client" << clientID << "matched and removed.";
    for (int i = 0; i < allPotentialMatches.size(); i++){
        if (allPotentialMatches[i].contains(animalID)){
            allPotentialMatches[i].removeOne(animalID);
            if (log) qDebug() << "Animal" << animalID << "removed from Client" << i;
        }
    }
    if (log) qDebug() << "Post-Cleanup: " << allPotentialMatches;
}

void cuACSMatchingAlgorithm::updateNumberOfPotentialMatches(bool log){
    if (log) qDebug() << "Pre-Update: " << clientNumberOfMatches << animalNumberOfMatches;
    clientNumberOfMatches.clear();
    animalNumberOfMatches.clear();
    for (int i = 0; i < allPotentialMatches.size(); i++){
        clientNumberOfMatches.insert(i, allPotentialMatches[i].size());

        for (int j = 0; j < allPotentialMatches[i].size(); j++){
//            if (!matches.contains(j)){Kingj327-patch-2
                int temp = 0;
                if (animalNumberOfMatches.value(allPotentialMatches[i][j]) > temp) temp = animalNumberOfMatches.value(allPotentialMatches[i][j]);
                animalNumberOfMatches.insert(allPotentialMatches[i][j], temp+1);
//            }
        }

//        qDebug() << allPotentialMatches[i] << clientNumberOfMatches[i] << animalNumberOfMatches;
    }
    if (log) qDebug() << "Post-Update: " << clientNumberOfMatches << animalNumberOfMatches;
}

int cuACSMatchingAlgorithm::getMaxNumberOfPotentialMatches(){
    int tempMaxNumberOfMatches = 0;
    for (int i = 0; i < clientNumberOfMatches.size(); i++){
        if (clientNumberOfMatches[i] > tempMaxNumberOfMatches) tempMaxNumberOfMatches = clientNumberOfMatches[i];
    }

    for (int i = 0; i < animalNumberOfMatches.size(); i++){
        if (animalNumberOfMatches[i] > tempMaxNumberOfMatches) tempMaxNumberOfMatches = animalNumberOfMatches[i];
    }
    return tempMaxNumberOfMatches;
}






void cuACSMatchingAlgorithm::part4(bool log){
    /* Get min number of clients/animals */
    int maxNumberOfMatchesPossible = (clientsList->size() < animalsList->size() ? clientsList->size() : animalsList->size());
    int currentPass = 0;



    qDebug() << "\n********* Algorithm Part 4.1 *********";
    if (log) qDebug() << "After pass 1 - Current Matches:" << matches;
    int p1PotentialMatches = matches.size();
    if ((float)p1PotentialMatches/(float)maxNumberOfMatchesPossible < 0.5){
        qDebug() << "Less than 50% Matches from Pass 1 ("
                 << ((float)p1PotentialMatches/(float)maxNumberOfMatchesPossible)*100 << "%)"
                 << ". Run this a second time using priority category 2.";
        backupMatchesP1 = matches;
        currentPass = 1;
        part2(currentPass, log);
        part3(log);
        matches.unite(backupMatchesP1);   // Get all the previous matches from pass 1 and add it to this pass
    }




    if (currentPass == 1) qDebug() << "\n********* Algorithm Part 4.2 *********";
    if (currentPass == 1 && log) qDebug() << "\nAfter pass 2 - Current Matches:" << matches;
    int p2PotentialMatches = matches.size();
    if ((float)p2PotentialMatches/(float)maxNumberOfMatchesPossible < 0.5){
        qDebug() << "Less than 50% Matches from Pass 2 ("
                 << ((float)p2PotentialMatches/(float)maxNumberOfMatchesPossible)*100 << "%)"
                 << ". Run this a third time using priority category 3.";
        backupMatchesP2 = matches;
        currentPass = 2;
        part2(currentPass, log);
        part3(log);
        matches.unite(backupMatchesP2);   // Get all the previous matches from pass 2 and add it to this pass
    }




    int p3PotentialMatches = matches.size();
    if ((float)p3PotentialMatches/(float)maxNumberOfMatchesPossible > 0.85 &&
            (float)p2PotentialMatches/(float)maxNumberOfMatchesPossible > 0.6 && currentPass == 2){
        /* Assume that the quality of matches have degraded too much, so resort back to
           the matches from Pass 2. */
        qDebug() << "\n********* Algorithm Part 4.3 *********";
        qDebug() << "Quality of matches have degraded with this step. Resort back to "
                    "matches from pass #2 of algorithm";
        if (log) qDebug() << "Matches from Pass 2 are :" << backupMatchesP2;
    } else if (currentPass == 2){
        qDebug() << "\n********* Algorithm Part 4.3 *********";
        if (log) qDebug() << "After pass 3 - Current Matches:" << matches;
        qDebug() << "No more passes allowed. Optimal solution found without degrading "
                    "match quality.";
    }




//    qDebug() << maxNumberOfPotentialMatches << p1PotentialMatches << p2PotentialMatches << p3PotentialMatches;
    qDebug() << "\nAlgorithm Complete. % match = " <<((float)p3PotentialMatches/(float)maxNumberOfMatchesPossible)*100 << "%\n";
}








/*
 * NOTE: Apparently we're supposed to have 2 screens.
 *          - One where we display the summary of the match (ie. the names of the matched clients and
 *            animals, and thats it).
 *          - One where we display the detailed information and exact rules used to compute the match.
 *
 *  For the second portion detailing the exact rules, you can get some of the details as follows.
 *    Non-Physical Attributes:
 *      - backupMatchesP1 contains a list of all the client/animal ID pairs matched in the first iteration
 *        of the algorithm (so using the first priority category)
 *      - backupMatchesP2 contains a list of all the client/animal ID pairs matched in the second iteration
 *        of the algorithm (so using not the priority category, but the category with the next highest
 *        score).
 *      - Anything else not contained in these QMaps were matched using the third highest priority category
 *        on iteration 3 of this algorithm.
 *          NOTE: the actual priority category order for the client/animal is stored in order in the inner
 *          clientPriorityCatList and animalPriorityCatList QList (respectively) in order of
 *          the client/animal ID.
 *    Threshold:
 *      - The default is set to a + or - 10% threshold. For everything except the last category, assume
 *        that every 5% difference in priority category score is actually a 1 point difference in score.
 *        (Actual differences of 1 point are 1/24 (Around 4.2%) for the first 3 categories, 1/20 (5%) for
 *        the 4th category, and 1/14 (around 7.15%) for the last category. Not necessary to know this tho).
 *        All you really need to know from this is that the default has it so that the threshold is +- 2
 *        points, so a client and animal can only differ by at most +-2 points.
 *    Physical Attributes:
 *      - Major bonus points if the breed and type of animal match
 *      - Some points (either positive, negative, or neutral) based on other categories
 *      NOTE: Not to sure what to display here or how to go about doing it yet.
 *    Rules:
 *      -
 *
 *
 *
 *
 *
 * */
