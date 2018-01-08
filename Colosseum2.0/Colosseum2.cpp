//
//  Colosseum2.cpp
//  Colosseum 2.0
//
//  Created by sagi bouzaglo on 06/01/2018.
//  Copyright © 2018 sagi bouzaglo. All rights reserved.
//

#include "Colosseum2.h"
bool compare(int x,int y){
    return x==y;
}

/**---------------------------------------------------------------------------*/
Colosseum2::Colosseum2(int size, int *trainingGroupsIDs):trainingGroupsTable(size,SetNull()),
                                                         allGladiators(),
                                                         trainingGroupsID() {
    for (int i=0; i<size;i++){
        Training_Group tmpGroup(trainingGroupsIDs[i]);
        trainingGroupsTable.insert(tmpGroup,trainingGroupsIDs[i],compare);
    }
    trainingGroupsID.MakeHeap(trainingGroupsIDs,size);
}

/**---------------------------------------------------------------------------*/
/**---------------------------------------------------------------------------*/
StatusType Colosseum2::addTrainingGroup(int trainingGroupID) {
    if(trainingGroupID<0){
        return INVALID_INPUT;
    }
    Training_Group* ptr= this->trainingGroupsTable.search(trainingGroupID,compare);
    if(ptr!=nullPtr){//If the given Group exists in the system
        return FAILURE;
    }
    Training_Group groupToInsert(trainingGroupID);
    this->trainingGroupsTable.insert(groupToInsert,trainingGroupID,compare);
    this->trainingGroupsID.Insert(trainingGroupID);
    return SUCCESS;
}
/**---------------------------------------------------------------------------*/
StatusType Colosseum2::addGladiator(int gladiatorID, int score,
                                    int trainingGroup) {
    if (gladiatorID<0 || score<0 || trainingGroup<0){
        return INVALID_INPUT;
    }
    Gladiator tmpGladiator(gladiatorID,nullPtr,score);
    Training_Group* tmpGroup = this->trainingGroupsTable.search(trainingGroup, compare);
    if ((tmpGroup == nullPtr) ||
        (this->allGladiators.Search(tmpGladiator, CompareGladiatorByID()))){
        return FAILURE;
    }
    tmpGroup->addGladiator(gladiatorID, score);
    this->allGladiators.Insert(tmpGladiator, CompareGladiatorByID());
    return SUCCESS;
}
/**---------------------------------------------------------------------------*/
StatusType Colosseum2::trainingGroupFight(int trainingGroup1,
                                          int trainingGroup2, int k1, int k2) {
    if (k1<=0 || k2<=0 || trainingGroup1<0 || trainingGroup2<0){
        return INVALID_INPUT;
    }
    Training_Group* tmpGroup1 = this->trainingGroupsTable.search(trainingGroup1, compare);
    Training_Group* tmpGroup2 = this->trainingGroupsTable.search(trainingGroup2, compare);
    if (tmpGroup1==nullPtr || tmpGroup2 == nullPtr || trainingGroup1==trainingGroup2 ||
                            tmpGroup1->getSize()<k1 ||tmpGroup2->getSize()<k2){
        return FAILURE;
    }
    if (tmpGroup1->getBestKGladiatorsScore(k1)>tmpGroup2->getBestKGladiatorsScore(k2)){
        tmpGroup2->TurnOFF();
    }else if(tmpGroup1->getBestKGladiatorsScore(k1)<tmpGroup2->getBestKGladiatorsScore(k2)){
        tmpGroup1->TurnOFF();
    }else{
        if (trainingGroup1<trainingGroup2){
            tmpGroup2->TurnOFF();
        }else{
            tmpGroup1->TurnOFF();
        }
    }
    // check if min group is inactive
    while (!(this->trainingGroupsTable.search(*this->trainingGroupsID.FindMin(), compare))->isActive()){
        this->trainingGroupsID.DelMin();
    }
    return SUCCESS;
}

/**---------------------------------------------------------------------------*/
StatusType Colosseum2::getMinTrainingGroup(int *trainingGroup) {
    if (trainingGroup == nullPtr){
        return INVALID_INPUT;
    }
    if(this->trainingGroupsID.FindMin() == nullPtr){
        return FAILURE;
    }
    *trainingGroup = *this->trainingGroupsID.FindMin();
    return SUCCESS;
}
/**---------------------------------------------------------------------------*/
/**---------------------------------------------------------------------------*/

