//
//  Hash_Table.h
//  Colosseum 2.0
//
//  Created by sagi bouzaglo on 29/12/2017.
//  Copyright © 2017 sagi bouzaglo. All rights reserved.
//

#ifndef Hash_Table_h
#define Hash_Table_h

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#define nullptr 0

/***************************************************************************/
/*  Hash Table class                                                       */
/*  types:                                                                 */
/*  K-Key                                                                  */
/*  N - node data                                                          */
/*  T - Hash data                                                          */
/*                                                                         */
/*  Operations:                                                            */
/*  insert - insert data to the table                                      */
/*  remove - remove data from the table                                    */
/*  isEmpty - return true if table cell is empty                           */
/***************************************************************************/

template <class N, class K>
class HashTable {
    /***********************/
    /*  Node Declaration   */
    /***********************/
    template <class N, class K>
    class HashNode {
        N nodeData;
        K key;
        HashNode *next;
        friend class HashTable;
    public:
        HashNode<N>(const T &nodeData, const K &key) :
                                   nodeData(nodeData),key(key), next(nullptr) {}
        K getKey(){
            return key;
        }
        N getNodeData(){
            return nodeData;
        }
        void setNodeData(N nodeData){
            hashVertex::nodeData = nodeData;
        }
        HashNode *getNext() const {
            return next;
        }
        void setNext(HashNode *next) {
            HashNode::next = next;
        }
    };
    /**************************/
    /*  Node Declaration End  */
    /**************************/
    int n;
    int counter;
    HashNode *table;
   
    public:
    
    HashMap() {
        // construct zero initialized hash table of size
        table = new HashNode<N, V> *[n]();
    }
    
}

#endif /* Hash_Table_h */
