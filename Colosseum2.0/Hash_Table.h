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
    // construct zero initialized hash table of size
    HashTable() {
        table = new HashNode<N, V> *[n]();
    }
    
    SplayTree<T>():root(nullptr){}
    
    ~SplayTree(){
        postOrderDemolition(this->root);
    }
    
    SplayTree<T>(const SplayTree<T> &toCopy) : root(toCopy.root) {}///////////////////////////////////////////////
    
    /* Description:   This function Searches for a given data in the tree
     * Input:         The data to find
     *               Compare function for data 1 and 2, should return
     *               1 if second arg is bigger, -1 if first arg is bigger,
     *               0 if first and second arg are equal
     * Output:        None.
     * Return Values: true if key was found
     *               false if not
     */
    template <class Compare>
    bool Search(const T& toCheck, const Compare& compare) {
        if (this->root == nullptr) {
            return false;
        }
        this->root= splay(this->root,toCheck,compare);
        return compare(root->data,toCheck)==0 ;
    }
    
    /* Description:   This function returns the minimum key
     * Input:         None.
     * Output:        None.
     * Exceptions:    TreeIsEmpty- if this is an empty tree
     * Return Values: The minimum key
     */
    template <class Compare>
    void Find_Min(const Compare& compare) {
        if (this->root == nullptr) {
            return ;
        }
        Vertex<T> *current = this->root;
        while (current->left != nullptr) {
            current = current->left;
        }
        this->root=splay(this->root, current->data,compare);
    }
    
    /* Description:   This function returns the maximum key
     * Input:         None.
     * Output:        None.
     * Exceptions:    TreeIsEmpty- if this is an empty tree
     * Return Values: The maximum key
     */
    template <class Compare>
    T* Find_Max(const Compare& compare) {
        if (this->root == nullptr) {
            return nullptr;
        }
        Vertex<T> *current = this->root;
        while (current->right != nullptr) {
            current = current->right;
        }
        this->root=splay(this->root, current->data,compare);
        return (&(this->root->data));
    }
    
    /* Description:   This function inserts new data  with a given
     * key to the Splay Tree
     * Input:         Data to be saved
     *               key in dictionary
     * Output:        None.
     * Exceptions:    KeyExists if the given key already exists
     * Return Values: true-if insert succeded
     *               false if not
     */
    template <class Compare>
    bool Insert(const T &data, const Compare& compare) {
        if (this->root == nullptr) {
            this->root=new Vertex<T>(data);
            return true;
        }
        Vertex<T> *right, *left;
        //Key wasnt found
        if (!(split(this->root, left, right, data,compare))) {
            Vertex<T>* new_root=new Vertex<T>(data,left,right);
            this->root=new_root;
            return true;
        }
        //Key exists
        else{
            return false;
        }
    }
    
    /* Description:   This function deletes the given DATA from the S_T
     * Input:         Data to be deleted
     *              Compare function
     * Output:        None.
     * Exceptions:    KeyDoesntExists if the given key doesnt exist
     * Return Values: true- if the data was found and deleted
     *               false- if data wasnt found
     */
    template <class Compare>
    bool Delete(const T& data,const Compare& compare) {
        if(this->root== nullptr){
            return false;
        }
        //key was found
        if(this->Search(data,compare)){
            Vertex<T>* toDelete=this->root;
            this->root=join(this->root->left,this->root->right,compare);
            delete toDelete;
            return true;
        }
        else{
            return false;
        }
    }
    template <class Function>
    void InOrder(Function& func){
        inOrderTraversal(this->root,func);
    }
    
    template <class Function>
    void BackwardsInOrder(Function& func){
        BackwardsinOrderTraversal(this->root,func);
    }
    
    T& GetRoot(){
        return this->root->data;
    }
};
    
}

#endif /* Hash_Table_h */
