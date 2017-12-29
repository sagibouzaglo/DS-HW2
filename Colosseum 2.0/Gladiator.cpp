//
// Created by Amir on 30/11/2017.
//

#include "Gladiator.h"

/**---------------------------------------------------------------------------*/
Gladiator::Gladiator(int ID, Trainer*  trainer, int level): ID(ID), trainer(trainer),
level(level) {}
/**---------------------------------------------------------------------------*/
/**---------------------------------------------------------------------------*/
Gladiator::Gladiator(const Gladiator& glad):ID(glad.ID),trainer(glad.trainer),
                                 level(glad.level){}
/**---------------------------------------------------------------------------*/
StatusType Gladiator::LevelUp(int levelincrease) {
    this->level=this->level+levelincrease;
    return SUCCESS;
}
/**---------------------------------------------------------------------------*/
int Gladiator::GetLevel() const {
    return this->level;
}
/**---------------------------------------------------------------------------*/
StatusType Gladiator::ChangeID(int new_ID) {
    this->ID=new_ID;
    return SUCCESS;
}
/**---------------------------------------------------------------------------*/
StatusType Gladiator::LevelMultiply(int factor) {
    this->level=this->level*factor;
    return SUCCESS;
}
/**---------------------------------------------------------------------------*/
int Gladiator::GetID() const{
    return this->ID;
}
/**---------------------------------------------------------------------------*/
Gladiator& Gladiator::operator=(const Gladiator &gladiator) {
    this->ID=gladiator.ID;
    this->trainer=gladiator.trainer;
    this->level=gladiator.level;
    return *this;
}
/**---------------------------------------------------------------------------*/
Trainer* Gladiator::getTrainer(){
    return this->trainer;
}
/**---------------------------------------------------------------------------*/
