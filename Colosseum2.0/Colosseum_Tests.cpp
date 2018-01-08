//
// Created by Amir on 06/01/2018.
//
#include "Colosseum2.h"
#include <iostream>
#define BARCA 1
#define REAL 0
#define MANU 2

#define MESSI 10
#define FELLAINI 31
#define CR7 7
#define SUAREZ 9
#define BALE 11
#define RASHFORD 19


#define GOD 100
#define B_DOR 99
#define CAPTAIN 10
#define AVG 5

using namespace std;
#define ERR -1

void checkAddTrainingGroup(){
    int arr[]={1,2};

    Colosseum2 colosseum2(2,arr);
    assert(colosseum2.addTrainingGroup(-1)==INVALID_INPUT);
    assert(colosseum2.addTrainingGroup(1)==FAILURE);
    assert(colosseum2.addTrainingGroup(2)==FAILURE);
    assert(colosseum2.addTrainingGroup(3)==SUCCESS);
    for (int i = 13; i <400 ; ++i) {
        assert(colosseum2.addTrainingGroup(i)==SUCCESS);
    }
}

void checkAddGladiator(){
    int arr[]={BARCA,REAL};

    Colosseum2 colosseum2(2,arr);
    assert(colosseum2.addGladiator(ERR,AVG,BARCA)==INVALID_INPUT);
    assert(colosseum2.addGladiator(MESSI,ERR,BARCA)==INVALID_INPUT);
    assert(colosseum2.addGladiator(MESSI,GOD,ERR)==INVALID_INPUT);
    assert(colosseum2.addGladiator(MESSI,GOD,BARCA)==SUCCESS);
    //Failure- Messi exists is the system
    assert(colosseum2.addGladiator(MESSI,GOD,REAL)==FAILURE);
    assert(colosseum2.addGladiator(MESSI,GOD,BARCA)==FAILURE);
    //Failure- group 3 doesnt exist in the system
    assert(colosseum2.addGladiator(CR7,B_DOR,3)==FAILURE);
}

void pythoncheck(){
    int arr[]={0,1};
    Colosseum2 colosseum2(2,arr);
    colosseum2.addTrainingGroup(8);
    cout << "Isert 8" << endl;
    colosseum2.print();
    colosseum2.addTrainingGroup(7);
    cout << "Isert 7" << endl;
    colosseum2.print();
    colosseum2.addTrainingGroup(6);
    cout << "Isert 6" << endl;
    colosseum2.print();
    colosseum2.addTrainingGroup(3);
    cout << "Isert 3" << endl;
    colosseum2.print();
    colosseum2.addTrainingGroup(2);
    cout << "Isert 2" << endl;
    colosseum2.print();
    colosseum2.addGladiator(436,33,0);
    colosseum2.addGladiator(205,966,2);
    colosseum2.addTrainingGroup(5);
    cout << "Isert 5" << endl;
    colosseum2.print();
    colosseum2.addTrainingGroup(1);
    cout << "Isert 1" << endl;
    colosseum2.print();
    colosseum2.addTrainingGroup(1);
 //   cout << "Isert 2" << endl;
  //  colosseum2.print();
   // colosseum2.addTrainingGroup(1);
   // cout << "Isert 2" << endl;
   // colosseum2.print();
   // colosseum2.addTrainingGroup(1);
   // cout << "Isert 2" << endl;
   // colosseum2.print();
}

void checkTrainingGroupFightAndFindMin(){
    int arr[]={BARCA,REAL,MANU};
    int minGroup;

    Colosseum2 colosseum2(3,arr);
    /**
     * Checking for INVALID INPUTS for FIGHT
     */
    assert(colosseum2.trainingGroupFight(ERR,REAL,1,1)==INVALID_INPUT);
    assert(colosseum2.trainingGroupFight(BARCA,ERR,1,1)==INVALID_INPUT);
    assert(colosseum2.trainingGroupFight(BARCA,REAL,0,1)==INVALID_INPUT);
    assert(colosseum2.trainingGroupFight(BARCA,REAL,1,0)==INVALID_INPUT);
    assert(colosseum2.getMinTrainingGroup(NULL)==INVALID_INPUT);


    assert(colosseum2.addGladiator(MESSI,GOD,BARCA)==SUCCESS);
    assert(colosseum2.addGladiator(CR7,B_DOR,REAL)==SUCCESS);
    assert(colosseum2.addGladiator(FELLAINI,CAPTAIN,MANU)==SUCCESS);
    /**
     * GroupID-#  ,Gladiators: #ID-#SCORE  #IsActive
     * GroupID- 0 , Gladiators: 7-99  ON
     * GroupID- 1 , Gladiators: 10-100  ON
     * GroupID- 2 , Gladiators: 31-10  ON
     */
    assert(colosseum2.getMinTrainingGroup(&minGroup)==SUCCESS);
    assert(minGroup==REAL);
    assert(colosseum2.trainingGroupFight(BARCA,REAL,1,1)==SUCCESS);
    assert(colosseum2.getMinTrainingGroup(&minGroup)==SUCCESS);
    assert(minGroup==BARCA);
    minGroup=3;
}

int main(){
  //  checkAddTrainingGroup();
  //  cout << "Add training group: OK" << endl;
  //  checkAddGladiator();
  //  cout << "Add Gladiator: OK" << endl;
  //  checkTrainingGroupFightAndFindMin();
  //  cout << "Training group fight: OK" << endl;
    pythoncheck();
    cout << "Python: OK" << endl;


    return 0;
}
