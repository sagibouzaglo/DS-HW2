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
    HashTable<int> hashTable(7);
    assert(hashTable.insert(1, 15,compare) == true);
    assert(hashTable.insert(2, 8,compare) == true);
    assert(hashTable.insert(3, 4,compare) == true);
    assert(hashTable.insert(4, 770,compare) == true);
    assert(hashTable.insert(5, 142,compare) == true);
    assert(hashTable.insert(6, 24,compare) == true);
    assert(hashTable.insert(7, 6,compare) == true);
    assert(hashTable.insert(8, 40,compare) == true);
    assert(hashTable.insert(3, 4,compare) == false);
    assert(*(hashTable.search(8, compare)) == 2);
    assert(*(hashTable.search(770, compare)) == 4);
    assert(*(hashTable.search(4, compare)) == 3);

    printInt(3);
    
 //   assert(*hashTable.search(15) == 15);
//    assert(*hashTable.search(1) == 1);
  //  assert(*hashTable.search(3) == 3);
//    assert(*hashTable.search(8) == 8);
//    assert(*hashTable.search(32) == 32);
//    assert(*hashTable.search(6) == 6);
//    assert(*hashTable.search(4) == 4);
    /*
       try {
     hashTable.find(2);
     } catch (std::exception& e) {
     std::cout << "1 - caught exception [V]" << std::endl;
     }
     try {
     hashTable.insert(8);
     } catch (std::exception& e) {
     std::cout << "2 - caught exception [V]" << std::endl;
     }
     hashTable.remove(8);
     try {
     hashTable.find(8);
     } catch (std::exception& e) {
     std::cout << "3 - caught exception [V]" << std::endl;
     }
     hashTable.insert(8);
     hashTable.insert(57);
     hashTable.insert(4516);
     hashTable.insert(6543);
     hashTable.insert(99);
     hashTable.insert(1222);
     hashTable.insert(137);
     hashTable.insert(385);
     // Check table size here
     hashTable.remove(8);
     hashTable.remove(57);
     hashTable.remove(4516);
     hashTable.remove(6543);
     hashTable.remove(99);
     hashTable.remove(1222);
     hashTable.remove(137);
     hashTable.remove(385);
     // Check table size here*/
}

#endif /* Hash_Table_test_h */

