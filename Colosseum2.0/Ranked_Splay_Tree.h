//
// Created by Amir on 31/12/2017.
//

#ifndef DS_HW2_RANKED_SPLAY_TREE_H
#define DS_HW2_RANKED_SPLAY_TREE_H

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <Splay_Tree.h>

#define nullptr 0

/***************************************************************************/
/*  Splay tree class                                                       */
/*  Operations:                                                            */
/*  insert - insert node to the tree                                       */
/*  remove - remove node from the tree                                     */
/*  isEmpty - return true if tree is empty                                 */
/***************************************************************************/
template<class T>
class RankedSplayTree::SplayTree {
    /***************************************************************************/
    /*  Node Declaration                                                       */
    /***************************************************************************/
    template<class N>
    class RankedVertex : SplayTree {
        unsigned int degree;
        unsigned int biggerThanSum;

        friend class RankedSplayTree;

    public:
        RankedVertex<N>(const T &data) : Vertex(data),degree(0),biggerThanSum(0){}

        Vertex<N>(const T &data, Vertex <T> *left, Vertex <T> *right) :
                data(data), left(left), right(right) {}

        ~Vertex<N>() {
            left = nullptr;
            right = nullptr;
        }

        Vertex<N>(const Vertex <T> &node) : data(node.data),
                                            left(node.left),
                                            right(node.right) {}
    };
};

#endif //DS_HW2_RANKED_SPLAY_TREE_H
