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
/*  Operations:                                                            */
/*  insert - insert data to the table                                      */
/*  remove - remove data from the table                                    */
/*  isEmpty - return true if table cell is empty                           */
/***************************************************************************/


template<class T>
class HashTable {
    template <class N, class K>
    class HashVertex {
        N nodeData;
        K key;
        HashVertex *next;
    public:
        HashVertex<N>(const T &nodeData, const k &key) :
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
    
    
}

#endif /* Hash_Table_h */
