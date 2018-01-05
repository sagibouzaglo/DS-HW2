//
// Created by Amir on 05/01/2018.
//

#ifndef DS_HW2_TRAINING_GROUP_H
#define DS_HW2_TRAINING_GROUP_H

#include "library2.h"
#include "Ranked_Tree.h"
#include "Gladiator.h"

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

    bool addGladiator(int gladiatorID,int level);

    bool TurnOFF();

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
