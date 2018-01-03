//
// Created by Amir on 03/01/2018.
//

//
// Created by Amir on 29/11/2017.
//
#include <iostream>
#include <sstream>
#include "../Ranked_Tree.h"

class Compare {

public:
    int operator()(const int& x, const int& y) const {
        if (x == y) return 0;
        else if (x < y) return 1;
        return -1;
    }
};
class getKey {
public:
    int operator()(int y) const {
        return y;
    }
};

void printInt(const int& x) {
    std::cout << x << " ";
}

int main() {
    //RankedSplayTree<int,Compare,getKey>  myTree(Compare(),getKey());
    RankedSplayTree<int,Compare,getKey> tree;
    int arr[8] = {1,15,3,8,32,6,4,8};
    for(int i=0; i<8; i++)
        tree.Insert(arr[i]);
    for(int i=1; i<=7;i++){
        int *index=tree.Select(i);
        std::cout << "The number with index " << i<<" is "<<*index<<std::endl;
        int bestKsum = tree.getBestKSum(i);
        std::cout << "The sum of the best " << i<<" is "<<bestKsum<<std::endl;
    }
/**
    std::cout << "InOrder Print: " << std::endl; //EXPECTED: 1 3 4 6 8 15 32
    tree.InOrder(printInt);
    tree.Delete(8,compare,extractKey);
    tree.Delete(20,compare,extractKey);
    std::cout << "InOrder Print: " << std::endl; //EXPECTED: 1 3 4 6 8 15 32
    tree.InOrder(printInt);

    for(int i=1; i<20; i++)
        tree.Insert((rand()%i)*(rand()%i +i),compare,extractKey);
    tree.Insert(12,compare,extractKey);
    tree.Search(12,compare,extractKey);
    for(int i=130; i<400; i++)
        tree.Delete(i,compare,extractKey);

    std::cout << "InOrder Print: " << std::endl; //EXPECTED: 1 3 4 6 8 15 32
    tree.InOrder(printInt);
     **/
    return 0;
}