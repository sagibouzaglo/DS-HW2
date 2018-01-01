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

template <class T, class V>
class HashTable {
    /***********************/
    /*  Node Declaration   */
    /***********************/
    template <class N, class K>
    class HashNode {
        N nodeData;
        K key;
        HashNode *next;
    public:
        HashNode<N>(const N &nodeData, const K &key) :
                                   nodeData(nodeData),key(key), next(nullptr) {}
        K getKey(){
            return key;
        }
        N getNodeData(){
            return nodeData;
        }
        void setNodeData(N nodeData){
            HashNode::nodeData = nodeData;
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
    int tableSize;
    int counter;
    HashNode<T,V> *table;
   
    public:
    // construct zero initialized hash table of size
    HashTable(int const size) {
        tableSize=size;
        counter=0;
        table = new HashNode<T, V> *[size]();
        for (int i = 0; i < size; i++){
            table[i] = NULL;
        }
    }
    
    // destroys the table
    ~HashTable(){
        delete [] table;
    }
    
    /* Description:  This function Searches for a given data in the table
     * Input:        The data to find
     *               Compare function for data 1 and 2, return True for a match
     * Return Value: The node who match the search, returns nullPtr if not found
     */
    template <class Compare>
    bool insert(const T &data,const V &key, const Compare& compare){
        if (search(key,compare)!=NULL){
            return false;
        }
        HashNode<T,V> tmpNode = new HashNode<T,V>(data,key);
        int index=this->hash(key);
        if(!this->table[index]){
            this->table[index].next=tmpNode;
        }else{
            tmpNode.next = this->table[index].next;
            this->table[index]=tmpNode;
        }
        return true;
    }
    
    /* Description:  This function Searches for a given data in the table
     * Input:        The data to find
     *               Compare function for data 1 and 2, return True for a match
     * Return Value: The node who match the search, returns nullPtr if not found
     */
    template <class Compare>
    HashNode<T,V>* search(const V& toCheck, const Compare& compare) {
        HashNode<T,V>* tmpNode = this->getCell(toCheck);
        if (!tmpNode){
            return NULL;
        }
        while ((compare(tmpNode->getKey(),toCheck)!=0) && (!tmpNode)){
            tmpNode=tmpNode->getNext();
        }
        if (!tmpNode){
            return NULL;
        }
        return tmpNode;
    }
    
    /* Description:   This function gets a key and return a pointer for the
     *                matching node for that key.
     * Input:         key for hash table
     * Output:        None.
     * Return Values: pointer for the matching node, null if node doesn't exist
     */
    HashNode<T,V>* getCell(const V& key) {
        return this->table[hash(key)];
    }
    
    /* Description:   This function gets a key and return the index to insert
     *                the input to the Hash table
     * Input:         key for hash table
     * Output:        None.
     * Return Values: this hashed key
     */
    int hash (const V& key){
        return key % this->tableSize;
    }
    
    /* Description:   This function inserts new data  with a given
     *                key to the Hash table
     * Input:         Data to be saved
     *               key in dictionary
     * Output:        None.
     * Exceptions:    KeyExists if the given key already exists
     * Return Values: true-if insert succeded
     *               false if not
     */
//    template <class Compare>
//    bool Insert(const T &data, const Compare& compare) {
       
//    }
    
    /* Description:   This function deletes the given DATA from the S_T
     * Input:         Data to be deleted
     *              Compare function
     * Output:        None.
     * Exceptions:    KeyDoesntExists if the given key doesnt exist
     * Return Values: true- if the data was found and deleted
     *               false- if data wasnt found
     */
//    template <class Compare>
//    bool Delete(const T& data,const Compare& compare) {
       
//    }
    
    
    
};
    
#endif /* Hash_Table_h */
