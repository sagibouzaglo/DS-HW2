//
//  Colosseum2.cpp
//  Colosseum 2.0
//
//  Created by sagi bouzaglo on 06/01/2018.
//  Copyright © 2018 sagi bouzaglo. All rights reserved.
//

#include "Colosseum2.h"

/**---------------------------------------------------------------------------*/
Colosseum2::Colosseum2(int size, int *trainingGroupsIDs):trainingGroupsTable(size),
                                                         allGladiators(),
                                                         trainingGroupsID() {
    for (int i=0; i<size;i++){
        Training_Group tmpGroup(trainingGroupsIDs[i]);
        trainingGroupsTable.insert(tmpGroup,trainingGroupsIDs[i],CompareTrainingGroups());
    }
    trainingGroupsID.MakeHeap(trainingGroupsIDs,size);
}
/**---------------------------------------------------------------------------*/
/**---------------------------------------------------------------------------*/
Colosseum2::~Colosseum2() {}
/**---------------------------------------------------------------------------*/
/**---------------------------------------------------------------------------*/
StatusType Colosseum2::addTrainingGroup(int trainingGroupID) {
    if(trainingGroupID<0)
        return INVALID_INPUT;
    Training_Group* ptr= this->trainingGroupsTable.search(trainingGroupID,CompareTrainingGroups());
    if(ptr!=nullPtr){//If the given Group exists in the system
        return FAILURE;
    }
    Training_Group groupToInsert(trainingGroupID);
    this->trainingGroupsTable.insert(groupToInsert,trainingGroupID,CompareTrainingGroups());
}
/**---------------------------------------------------------------------------*/
StatusType Colosseum2::addGladiator(int gladiatorID, int score,
                                    int trainingGroup) {}
/**---------------------------------------------------------------------------*/
StatusType Colosseum2::trainingGroupFight(int trainingGroup1,
                                          int trainingGroup2, int k1, int k2) {}
/**---------------------------------------------------------------------------*/
StatusType Colosseum2::getMinTrainingGroup(int *trainingGroup) {}
/**---------------------------------------------------------------------------*/
/**---------------------------------------------------------------------------*/

