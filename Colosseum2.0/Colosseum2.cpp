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
/**
Training_Group::Training_Group(const Training_Group &toCopy){
    this->ID=toCopy.ID;
    this->gladiators=toCopy.gladiators;

}
 **/
/**---------------------------------------------------------------------------*/
StatusType Colosseum2::addTrainingGroup(int trainingGroupID) {

}
/**---------------------------------------------------------------------------*/
void Training_Group::TurnOFF() {
    this->IsActive= false;
}
/**---------------------------------------------------------------------------*/
bool Training_Group::addGladiator(int gladiatorID,int level) {
    Gladiator gladiator(gladiatorID,nullptr,level);
    return this->gladiators.Insert(gladiator);
}
/**---------------------------------------------------------------------------*/
bool Training_Group::operator==(Training_Group toCompare) {
    return this->ID==toCompare.ID;
}
/**---------------------------------------------------------------------------*/
bool Training_Group::operator!=(Training_Group toCompare) {
    return !(*(this)==toCompare);
}
/**---------------------------------------------------------------------------*/
int Training_Group::getBestKGladiatorsScore(int k) {
    return this->gladiators.getBestKSum(k);
}
/**---------------------------------------------------------------------------*/
int Training_Group::getID() const {
    return this->ID;
}
/**---------------------------------------------------------------------------*/
