//
// Created by Amir on 05/01/2018.
//

#ifndef DS_HW2_TRAINING_GROUP_H
#define DS_HW2_TRAINING_GROUP_H

#include "library2.h"
#include "Ranked_Tree.h"
#include "Gladiator.h"
#include "Splay_Tree.h"

class Training_Group {
    int ID;
    RankedSplayTree<Gladiator,CompareGladiatorByLevel,getGladiatorLevel> gladiators;
    bool IsActive;

public:
    Training_Group(int ID);

    //~Training_Group();

    //Training_Group(const Training_Group &toCopy);

    int getID() const;

    bool isActive() const;

    /**
     * Importent!- Because Training group Class doesnt have an ID tree
     * it CANNOT!!!! differ 2 gladiators with same ID but not same level
     * Please Advise to check correctness of insertion prior of using
     * or add a GladiatorID tree to the class
     * @param gladiatorID -
     * @param level - 
     * @return True if insertion was successful
     *          Flase if not
     */
    bool addGladiator(int gladiatorID,int level);

    void TurnOFF();

    int getBestKGladiatorsScore(int k);

    bool operator==(Training_Group toCompare);

    bool operator!=(Training_Group toCompare);
};

class CompareTrainingGroups {

public:
    explicit CompareTrainingGroups() {}

    int operator()(const Training_Group &group1, const Training_Group &group2) const {
        return (group2.getID()-group2.getID());
    }
};


#endif //DS_HW2_TRAINING_GROUP_H
