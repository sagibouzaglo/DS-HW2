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
#include <sstream>
#include <iostream>

#define nullPtr 0
#define ROOT 1
/**
 * BLAH BLAH
 */
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

template<class T>
class MinHeap {
    int arrSize;
    int numOfElements;
    T **arr;

    /**
     * This function swaps 2 elements pointers
     * @param element1
     * @param element2
     */
    void swap(T *element1, T *element2) {
        T tmp = *element1;
        *element1 = *element2;
        *element2 = tmp;
    }
    void siftDown( int index) {
        if (index * 2 <= numOfElements) {
            //If there is only one son
            if ((index * 2) + 1 > numOfElements) {
                if (*(arr[2 * index]) < *(arr[index])) {
                    swap(arr[2 * index], arr[index]);
                }
            }
                //If there are 2 sons
            else {
                //if first son is smaller then second son
                if (*(this->arr[2 * index]) < *(this->arr[(2 * index) + 1]) ) {
                    if (*(arr[2 * index]) < *(arr[index])) {
                        swap(arr[2 * index], arr[index]);
                        siftDown(2*index);
                    }
                } else {
                    //If the second son is smaller or equal to first
                    if (*(arr[2 * index + 1]) < *(arr[index])) {
                        swap(arr[2 * index + 1], arr[index]);
                        siftDown(2*index+1);
                    }
                }
            }
        }
    }
    public:
    MinHeap<T>(): arrSize(0),numOfElements(0),arr(nullPtr){}

    ~MinHeap<T>(){
        for (int i = 0; i <this->arrSize ; ++i) {
            delete (this->arr[i]);
        }
            delete [] this->arr;
    }

    void MakeHeap(T* arr_of_elements, int n){
        this->arr=new T*[(2*n)+1];
        this->numOfElements=n;
        this->arrSize=2*n+1;
        for (int i = 0; i <2*n+1 ; ++i) {
            this->arr[i] = new T;
        }
        for (int i = 1; i <=n ; ++i) {
            (*(this->arr[i]))=arr_of_elements[i-1];
        }
        for (int j = n/2; j >=1 ; --j) {
            siftDown(j);
        }
    }


    void Insert(const T &data) {
        if(numOfElements+1==arrSize){
            T** old_arr=this->arr;
            this->arr=new T*[(2*numOfElements)+1];
            for (int i = 0; i <(2*numOfElements)+1 ; ++i) {
                this->arr[i] = new T;
            }
            for (int i = 0; i <=numOfElements ; ++i) {
                (*(this->arr[i]))=*(old_arr[i]);
            }
            for (int j = 0; j <arrSize ; ++j) {
                delete old_arr[j];
            }
            delete [] old_arr;
            this->arrSize=(2*numOfElements)+1;

        }
        this->numOfElements++;
        *(this->arr[this->numOfElements])=data;
        for (int i = numOfElements/2; i >=1 ; i=i/2) {
            siftDown(i);
        }
    }

    /* Description:   This function find the min of the Heap
     * Input:
     * Output:        None.
     * Exceptions:
     * Return Values: pointer to the minimum of the heap, null if empty
     */
    T * FindMin() {
        if(this->numOfElements==0) return nullPtr;
        return this->arr[1];
    }

    /* Description:   This function find the min of the Heap and delete it
     * Input:
     * Output:        None.
     * Exceptions:
     * Return Values: None.
     */
    void DelMin() {
        if(this->numOfElements==0) return;
        *(this->arr[ROOT])=*(this->arr[numOfElements]);
            this->numOfElements--;
            siftDown(ROOT);
    }

    void PrintHeap(){
        for (int i = 0; i <this->numOfElements ; ++i) {
            int check=*(this->arr[i+1]);
            std::cout<<check<<" ";
        }
        std::cout<<std::endl;
    }
};

#endif /* Min_Heap_h */
