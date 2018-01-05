//
//  Min_Heap.h
//  Colosseum 2.0
//
//  Created by sagi bouzaglo on 02/01/2018.
//  Copyright © 2018 sagi bouzaglo. All rights reserved.
//
#ifndef Min_Heap_h
#define Min_Heap_h

#include <stdlib.h>
#include <stdio.h>
#define nullPtr 0

/***************************************************************************/
/*  Min Heap class                                                         */
/*  types:                                                                 */
/*  int - Key                                                              */
/*  T - node data                                                          */
/*  HashNode - Hash data                                                   */
/*                                                                         */
/*  Operations:                                                            */
/*  insert - insert data to the table                                      */
/*  search - check if the data already exist                               */
/***************************************************************************/

template <class T>
class MinHeap {
    int tableSize;
    int* lastIn;
    T* heap;
    
    void siftDown(){
    
    }
    public:
    // construct zero initialized Min Heap of size
    HeapTable(int const size) {
        tableSize=size;
        table = new HashNode<T> *[size]();
        for (int i = 0; i < size; i++){
            table[i] = nullptr;
        }
        lastIn=heap;
    }

    /* Description:   This function inserts new data to the Heap
     * Input:         Data
     *                Compare function
     * Output:        None.
     * Exceptions:
     * Return Values: true if insert succeded, false if not
     */
    template <class Compare>
    bool insert(const T &data, const Compare& compare){
        
    }
    
    /* Description:   This function find the min of the Heap
     * Input:
     * Output:        None.
     * Exceptions:
     * Return Values: pointer to the minimum of the heap, null if empty
     */
    T* findMin(){
        
    }
    
    /* Description:   This function find the min of the Heap and delete it
     * Input:
     * Output:        None.
     * Exceptions:
     * Return Values: None.
     */
    template <class Compare>
    void delMin(const Compare& compare){
        
    }
};
#endif /* Min_Heap_h */
