//
//  Colosseum2.h
//  Colosseum 2.0
//
//  Created by sagi bouzaglo on 06/01/2018.
//  Copyright © 2018 sagi bouzaglo. All rights reserved.
//

#ifndef Colosseum2_h
#define Colosseum2_h
#include "Hash_Table.h"
#include "Min_Heap.h"
#include "Ranked_Tree.h"
#include "Splay_Tree.h"
#include "Training_Group.h"
#include "Gladiator.h"



class SetNull{
    public:
    void operator()(Training_Group* group){
        group->setTreeToNull();
    }
};

class Colosseum2{
    HashTable <Training_Group, SetNull> trainingGroupsTable;
    SplayTree<Gladiator> allGladiators;
    MinHeap<int> trainingGroupsID;
    
    public:
    
    Colosseum2(int size, int* trainingGroupsIDs);

    StatusType addTrainingGroup(int trainingGroupID);

    StatusType addGladiator(int gladiatorID,int score,int trainingGroup);

    StatusType trainingGroupFight(int trainingGroup1,int trainingGroup2,int k1,int k2);

    StatusType getMinTrainingGroup(int* trainingGroup);
 
};

#endif /* Colosseum2_h */
