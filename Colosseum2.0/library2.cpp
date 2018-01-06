//
//  library2.cpp
//  Colosseum 2.0
//
//  Created by sagi bouzaglo on 06/01/2018.
//  Copyright © 2018 sagi bouzaglo. All rights reserved.
//

#include <stdio.h>
#include "library2.h"
#include "Colosseum2.h"
#define NULL_CHECK(condition) if(!(condition)) { \
                                  return INVALID_INPUT; \
                              } ;

void* init(int n, int *trainingGroupsIDs){
    Colosseum2* system = new Colosseum2(n,trainingGroupsIDs);
    return (void*)system;
}

StatusType addTrainingGroup(void *DS, int trainingGroupID){
    NULL_CHECK(DS);
    return ((Colosseum2*)DS)->addTrainingGroup(trainingGroupID);
}

StatusType addGladiator(void *DS, int gladiatorID, int score, int trainingGroup){
    NULL_CHECK(DS);
    return ((Colosseum2*)DS)->addGladiator(gladiatorID,score, trainingGroup);
}

StatusType trainingGroupFight(void *DS, int trainingGroup1, int trainingGroup2, int k1, int k2){
    NULL_CHECK(DS);
    return ((Colosseum2*)DS)->trainingGroupFight(trainingGroup1, trainingGroup2, k1, k2);
}

StatusType getMinTrainingGroup(void *DS, int *trainingGroup){
    NULL_CHECK(DS);
    return ((Colosseum2*)DS)->getMinTrainingGroup(trainingGroup);
}
void quit(void** DS){
    if(DS==NULL){
        return;
    }
    Colosseum2** col=((Colosseum2**)DS);
    delete *col;
    *DS=NULL;
}
