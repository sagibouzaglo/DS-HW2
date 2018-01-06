//
// Created by Amir on 05/01/2018.
//

#include <iostream>
#include <sstream>
#include <assert.h>
#include "../Min_Heap.h"

#define TEST 2
using std::cout;
using std::endl;

int main(){
    int arr[TEST];
    cout<<"Given arr is: ";
    for (int i = TEST; i >0 ; --i) {
        arr[TEST-i]=rand()%101;
        cout<< arr[TEST-i]<<", ";
    }
    cout<<endl;
    MinHeap<int> heap;
    heap.MakeHeap(arr,TEST);
    cout<<"The rearranged heap is: ";
    heap.PrintHeap();
    cout<<"Inserting random numbers to the heap."<<endl;
    for (int k = 0; k <16; ++k) {
        heap.Insert(rand()%10);
    }
    cout<<"Heap is: "<<endl;
    heap.PrintHeap();
    for (int j = 0; j <18 ; ++j) {
        heap.DelMin();
        heap.PrintHeap();
    }


    return 0;
}
