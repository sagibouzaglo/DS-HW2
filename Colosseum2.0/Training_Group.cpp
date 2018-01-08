//
// Created by Amir on 05/01/2018.
//

#include "Training_Group.h"

/**---------------------------------------------------------------------------*/
Training_Group::Training_Group(int ID): ID(ID),gladiators(),IsActive(true){
    gladiators=new RankedSplayTree<Gladiator, CompareGladiatorByLevel, getGladiatorLevel>;
}
/**---------------------------------------------------------------------------*/
/**
Training_Group::Training_Group(const Training_Group &toCopy){
    this->ID=toCopy.ID;
    this->gladiators=toCopy.gladiators;
}
 **/
/**---------------------------------------------------------------------------*/
bool Training_Group::isActive() const {
    return this->IsActive;
}
/**---------------------------------------------------------------------------*/
void Training_Group::TurnOFF() {
    this->IsActive= false;
}
/**---------------------------------------------------------------------------*/
bool Training_Group::addGladiator(int gladiatorID,int level) {
    Gladiator gladiator(gladiatorID,nullptr,level);
    return this->gladiators->Insert(gladiator);
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
    return this->gladiators->getBestKSum(k);
}
/**---------------------------------------------------------------------------*/
int Training_Group::getID() const {
    return this->ID;
}
/**---------------------------------------------------------------------------*/

int Training_Group::getSize(){
    return this->gladiators->getNumOfElements();
}
/**---------------------------------------------------------------------------*/

void Training_Group::setTreeToNull(){
    this->gladiators = nullPtr;
}


