//
//  Hash_Table_test.cpp
//  Colosseum 2.0
//
//  Created by sagi bouzaglo on 01/01/2018.
//  Copyright © 2018 sagi bouzaglo. All rights reserved.
//

//
//  Hash_Table_test.h
//  Colosseum 2.0
//
//  Created by sagi bouzaglo on 01/01/2018.
//  Copyright © 2018 sagi bouzaglo. All rights reserved.
//

#ifndef Hash_Table_test_h
#define Hash_Table_test_h

#include "Hash_Table.h"
#include <assert.h>
#include<iostream>

void printInt(const int& x) {
    std::cout << x << " ";
}

int main() {
    /* int arr[7] = {1,15,3,8,32,6,4};
    HashTable<int,getKey> hashTable(arr, 7);
    assert(*hashTable.search(15) == 15);
    assert(*hashTable.search(1) == 1);
    assert(*hashTable.search(3) == 3);
    assert(*hashTable.search(8) == 8);
    assert(*hashTable.search(32) == 32);
    assert(*hashTable.search(6) == 6);
    assert(*hashTable.search(4) == 4);
    
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
