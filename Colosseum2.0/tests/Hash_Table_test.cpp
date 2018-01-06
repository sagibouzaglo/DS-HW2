//
//  Hash_Table_test.cpp
//  Colosseum 2.0
//
//  Created by sagi bouzaglo on 01/01/2018.
//  Copyright © 2018 sagi bouzaglo. All rights reserved.
//

#ifndef Hash_Table_test_h
#define Hash_Table_test_h

#include "Hash_Table.h"
#include "Training_Group.h"
#include <assert.h>
#include<iostream>
#include "Gladiator.h"
void printInt(const int& x) {
    std::cout << x << " ";
}

bool compare(int x,int y){
    return x==y;
}
int main() {
    Training_Group group1(15);
    Training_Group group2(8);
    Training_Group group3(4);
    Training_Group group4(770);
    Training_Group group5(142);
    Training_Group group6(24);
    Training_Group group7(6);
    Training_Group group8(40);
    HashTable<Training_Group> hashTable(7);;
    assert(hashTable.insert(group1, group1.getID(),compare) == true);
    assert(hashTable.insert(group2, group2.getID(),compare) == true);
    assert(hashTable.insert(group3, group3.getID(),compare) == true);
    assert(hashTable.insert(group4, group4.getID(),compare) == true);
    assert(hashTable.insert(group5, group5.getID(),compare) == true);
    assert(hashTable.insert(group6, group6.getID(),compare) == true);
    assert(hashTable.insert(group7, group7.getID(),compare) == true);
    assert(hashTable.insert(group8, group8.getID(),compare) == true);
    assert(hashTable.insert(group3, group3.getID(),compare) == false);
    assert(*(hashTable.search(group2.getID(), compare)) == group2.getID());
    assert(*(hashTable.search(group4.getID(), compare)) == group4.getID());
    assert(*(hashTable.search(group3.getID(), compare)) == group3.getID());
    printInt(3);
}

#endif /* Hash_Table_test_h */

