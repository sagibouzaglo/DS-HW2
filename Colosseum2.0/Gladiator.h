//
//  Gladiator.h
//  DS-HW-1
//
//  Created by sagi bouzaglo on 27/11/2017.
//  Copyright © 2017 sagi bouzaglo. All rights reserved.
//

#ifndef Gladiator_h
#define Gladiator_h

#include "library2.h"
class Trainer;

class Gladiator {
    int ID;
    Trainer* trainer;
    int level;

public:
    Gladiator(int ID, Trainer* trainer, int level);

    //~Gladiator();

    Gladiator(const Gladiator &glad);

    int GetID() const;

    StatusType LevelUp(int levelincrease);

    int GetLevel() const;

    StatusType ChangeID(int new_ID);

    StatusType LevelMultiply(int factor);

    Gladiator& operator=(const Gladiator& gladiator);

    Trainer* getTrainer();
};

class CompareGladiatorByID {

public:
    explicit CompareGladiatorByID() {}

    int operator()(const Gladiator &glad1, const Gladiator &glad2) const {
        return (glad2.GetID()-glad1.GetID());
    }
};

class CompareGladiatorByLevel {

public:
     CompareGladiatorByLevel() {}

    int operator()(const Gladiator &glad1, const Gladiator &glad2) const {
        //WE CANNOT ALLOW IDENTICALS IDS
        if (glad1.GetID() == glad2.GetID()) {
            return 0;
        }//Gladiators doesnt have same level
        else if (glad1.GetLevel() != glad2.GetLevel()) {
            return glad2.GetLevel() - glad1.GetLevel();
        }//Gladiators have same lvl, Its would be difficult to understand logic
            //in the following line but its OK
        else{
            return glad1.GetID()-glad2.GetID();
        }
    }
};

class getGladiatorLevel {

public:
    explicit getGladiatorLevel() {}

    int operator()(const Gladiator &glad1) const {
        return glad1.GetLevel();
    }
};

#endif /* Gladiator_h */
