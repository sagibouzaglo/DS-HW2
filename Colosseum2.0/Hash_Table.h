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

#define nullPtr 0

/***************************************************************************/
/*  Hash Table class                                                       */
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
class HashTable {
    /***********************/
    /*  Node Declaration   */
    /***********************/
    template <class N>
    class HashNode {
        N nodeData;
        int key;
        HashNode *next;
        
    public:
        // construct hash node with the given data and key
        HashNode<N>(const N &nodeData, const int &key) :
                                   nodeData(nodeData),key(key), next(nullPtr) {}
        HashNode<N>(const HashNode &);
        HashNode<N> & operator=(const HashNode<N> &);
        int getKey(){
            return key;
        }
        N* getNodeData(){
            return &nodeData;
        }
        void setNodeData(N nodeData){
            HashNode::nodeData = nodeData;
        }
        HashNode *getNext()  {
            return next;
        }
        void setNext(HashNode *newNext)
        {
            next = newNext;
        }
    };
    /**************************/
    /*  Node Declaration End  */
    /**************************/
    int tableSize;
    int numOfElements;
    HashNode<T> **table;
   
    /* Description:   This function change the size of the Hash Table, and
     *                insert the old data with the new hash key.
     * Input:         Compare function
     * Output:        None.
     * Return Values: None.
     */
    template <class Compare>
    void tableReSize(const Compare& compare){
        int oldTableSize = tableSize;
        HashNode<T> **oldTable = table;
        tableSize*=2;
        table = new HashNode<T>*[tableSize];
        for (int i = 0; i < tableSize; i++){
            table[i] = nullptr;
        }
        numOfElements = 0;
        for (int index = 0; index < oldTableSize; ++index){
            if (oldTable[index] != nullptr) {
                HashNode<T> *previous;
                HashNode<T> *current = oldTable[index];
                while (current != NULL) {
                    insert( *current->getNodeData(),current->getKey(),compare);
                    previous = current;
                    current = current->getNext();
                    delete previous;
                }
            }
        }
        delete[] oldTable;
    }
    
    
    /* Description:   This function gets a key and return the index to insert
     *                the input to the Hash table
     * Input:         key for hash table
     * Output:        None.
     * Return Values: this hashed key
     */
    int hash (const int& key){
        return key % this->tableSize;
    }
    
    public:
    // construct zero initialized hash table of size
    HashTable(int const size) {
        tableSize=size;
        numOfElements=0;
        table = new HashNode<T> *[size]();
        for (int i = 0; i < size; i++){
            table[i] = nullptr;
        }
    }
    
    // destroys the table
    ~HashTable(){
        for (int i = 0; i < this->tableSize; ++i) {
            HashNode<T> *current = table[i];
            while (current != NULL) {
                HashNode<T> *previous = current;
                current = current->getNext();
                delete previous;
            }
            table[i] = nullptr;
        }
        delete [] table;
    }
    
    /* Description:   This function inserts new data  with a given key to the
     *                Hash table
     * Input:         Data
     *                key of data
     *                Compare function
     * Output:        None.
     * Exceptions:
     * Return Values: true if insert succeded, false if not
     */
    template <class Compare>
    bool insert(const T &data,const int &key, const Compare& compare){
        if (search(key,compare) != nullptr){
            return false;
        }
        HashNode<T> *tmpNode = new HashNode<T>(data,key);
        int index=this->hash(key);
        if (!(this->table[index])) {
            (this->table[index])=tmpNode;
        }else{
            tmpNode->setNext(table[index]);
            this->table[index]=tmpNode;
        }
        this->numOfElements++;
        if (this->numOfElements >= (this->tableSize/2)){
           tableReSize(compare);
        }
        return true;
    }
    
    /* Description:  This function Searches for a given data in the table
     * Input:        The data to find
     *               Compare function for data 1 and 2, return True for a match
     * Return Value: The node who match the search, returns nullPtr if not found
     */
    template <class Compare>
    T* search(const int& key, const Compare& compare) {
        int index = hash(key);
        HashNode<T> *prev = nullptr;
        HashNode<T> *current = table[index];
        while (current != nullptr && (!compare(key,current->getKey()))) {
            prev = current;
            current = current->getNext();
        }
        // reached the end of the objects, object doesnt exist
        if (current == nullptr){
            return nullptr;
        }else{ // object exist
            return (current->getNodeData());
        }
    }
};
    
#endif /* Hash_Table_h */
