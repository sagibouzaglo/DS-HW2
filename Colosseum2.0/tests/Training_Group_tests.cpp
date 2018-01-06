//
// Created by Amir on 05/01/2018.
//

#include "../Training_Group.h"
#include <iostream>
#include <sstream>
#include <assert.h>

#define NUMBEROFTESTS 2*2500

using std::cout;


int main(){
    //Checking constructor
    Training_Group group1(1);
    Training_Group group2(2);
    //Checking getID func
    assert(group1.getID()==1);
    assert(group2.getID()==2);
    //Checking isActive func
    assert(group1.isActive());
    assert(group2.isActive());
    //Checking TurnOFF func
    group1.TurnOFF();
    assert(group1.isActive()== false);
    //Checking operator ==
    assert((group1==group2)==false);
    Training_Group group3(1);
    assert(group1==group3);
    //Checking addGladiator func

    for (int j = 1; j <=NUMBEROFTESTS ; ++j) {
        if(j==NUMBEROFTESTS/2) continue;
        assert(group1.addGladiator(NUMBEROFTESTS+j,j));
    }
    //The next line makes the splay tree split in half
    assert(group1.addGladiator(3*NUMBEROFTESTS,NUMBEROFTESTS/2));
    //Checking getBestKScore func
    for (int i = 1; i <=NUMBEROFTESTS ; ++i) {
        int sum=0;
        for (int j = NUMBEROFTESTS; j >NUMBEROFTESTS-i ; --j) {
            sum += j;
        }
        assert(group1.getBestKGladiatorsScore(i)==sum);

    }

    return 0;
}