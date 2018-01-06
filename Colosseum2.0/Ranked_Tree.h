//
// Created by Amir on 24/11/2017.
//

#ifndef DS_HW2_RANKED_TREE_H
#define DS_HW2_RANKED_TREE_H

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <limits.h>

#define nullptr 0
#define ERROR INT_MIN

/***************************************************************************/
/*  Ranked Splay tree class                                                       */
/*  Operations:                                                            */
/*  Insert - insert a given data to the data structure                                       */
/*  Delete - remove a given data to the data structure
 *  Search - finds a given data in the data structre
 *  InOrder - activates a function on the tree elemens by rank
 *  Select - returns the number k ranked element in the data structure
 *  GetBestKSum - returns the sum of best K keys in the DS                 */
/***************************************************************************/



template<class T,class Compare,class ExtractKey>
class RankedSplayTree {
    /***************************************************************************/
    /*  Node Declaration                                                       */
    /***************************************************************************/
    template<class N>
    class RankedVertex {
        N data;
        RankedVertex<N> *left;
        RankedVertex<N> *right;
         int sizeOfLeftSubTree;
         int sizeOfRightSubTree;
        int sumOfLeftSubTree;
        int sumOfRightSubTree;


        friend class RankedSplayTree;

    public:
        RankedVertex<N>(const T &data) : data(data),
                                         left(nullptr),
                                         right(nullptr), sizeOfLeftSubTree(0),
                                         sizeOfRightSubTree(0),
                                         sumOfLeftSubTree(0),
                                         sumOfRightSubTree(0) {}

        ~RankedVertex<N>() {
            left = nullptr;
            right = nullptr;
        }

        RankedVertex<N>(const RankedVertex<T> &node) : data(node.data),
                                                       left(node.left),
                                                       right(node.right),
                                                       sizeOfLeftSubTree(
                                                               node.sizeOfLeftSubTree),
                                                       sizeOfRightSubTree(
                                                               node.sizeOfRightSubTree),
                                                       sumOfLeftSubTree(
                                                               node.sumOfLeftSubTree),
                                                       sumOfRightSubTree(
                                                               node.sumOfRightSubTree) {}
    };
    /*******end of node********************/






    /**************************************************************************/
    /*  Splay_tree private  Parts                */
    /**************************************************************************/


    RankedVertex<T> *root;
    Compare compare;
    ExtractKey getKey;


    /* Description:   Rotates left_child to be new root
    * Input:         current root
    * Output:        None.
    * Return Values: A pointer to the new root
    */
    RankedVertex<T> *rightRotate(RankedVertex<T> *source) {
        RankedVertex<T> *new_root = source->left;
        source->left = new_root->right;
        source->sizeOfLeftSubTree = new_root->sizeOfRightSubTree;
        source->sumOfLeftSubTree = new_root->sumOfRightSubTree;
        new_root->sizeOfRightSubTree =
                source->sizeOfRightSubTree + source->sizeOfLeftSubTree + 1;
        new_root->sumOfRightSubTree =
                source->sumOfRightSubTree + source->sumOfLeftSubTree +
                getKey(source->data);
        new_root->right = source;
        source = new_root;
        return source;
    }

    /* Description:   Rotates right_child to be new root
    * Input:         current root
    * Output:        None.
    * Return Values: A pointer to the new root
    */
    RankedVertex<T> *leftRotate(RankedVertex<T> *source) {
        RankedVertex<T> *new_root = source->right;
        source->right = new_root->left;
        source->sizeOfRightSubTree = new_root->sizeOfLeftSubTree;
        source->sumOfRightSubTree = new_root->sumOfLeftSubTree;
        new_root->sizeOfLeftSubTree =
                source->sizeOfRightSubTree + source->sizeOfLeftSubTree + 1;
        new_root->sumOfLeftSubTree =
                source->sumOfRightSubTree + source->sumOfLeftSubTree +
                getKey(source->data);
        new_root->left = source;
        source = new_root;
        return source;
    }

    /* Description:   This function returns the pointer to newly assigned root
     *                 if key was found then he will be the new root,if not
     *                 it makes the root the last accessed node while searching
    * Input:         1)current root
     *               2)the data to compare to
    * Output:        None.
    * Return Values: A pointer to the new root
    */
    RankedVertex<T> *splay(RankedVertex<T> *root, const T &check) {
        //root is NULL or key is in root
        if (root == nullptr || !(compare(root->data, check))) return root;

        //Key is in right tree
        if ((compare(root->data, check) > 0)) {
            //Couldnt find key in tree, return the last known root
            if (root->right == nullptr) return root;
            /*RR-Zag-Zag rotation*/
            if ((compare(root->right->data, check) > 0)) {
                //Make key the new Right_Right
                root->right->right = splay(root->right->right, check);
                //Rotate top_down, second rotation will follow
                root = leftRotate(root);
                //RL-Zag-Zig roatation
            } else if ((compare(root->right->data, check) < 0)) {
                //Make key the new Right_Left child
                root->right->left = splay(root->right->left, check);
                //Make key the Right_child
                if (root->right->left != nullptr) {
                    root->right = rightRotate(root->right);
                }
            }
            //if possiable bring r_child to root.
            return (root->right == nullptr) ? (root) : (leftRotate(root));
        }
            //Key is in left tree
        else {
            //Couldnt find key in tree, return the last known root
            if (root->left == nullptr) return root;
            /*LL-Zig-Zig rotatation */
            if ((compare(root->left->data, check) < 0)) {
                //make Key the new L_L child
                root->left->left = splay(root->left->left, check);
                root = rightRotate(root);
            }
                /*LR-Zig-Zag rotatation */
            else if ((compare(root->left->data, check) > 0)) {
                root->left->right = splay(root->left->right, check);
                if (root->left->right != nullptr) {
                    root->left = leftRotate(root->left);
                }
            }
            return (root->left == nullptr) ? (root) : (rightRotate(root));
        }
    }


    /* Description:   This function splits root to 2 trees around a given
    *  key.
    * Input:         1)The root you want to split
     *               2)the data to compare to
     *               4)pointer to aftermath left_root.
     *              5)pointer to aftermath right_root
    * Output:        None.
    * Return Values: false if key wasnt found, true if key is in tree
    */
    bool split(RankedVertex<T> *root, RankedVertex<T> *&left,
               RankedVertex<T> *&right, const T &check) {
        if (root == nullptr) {
            return false;
        }
        //splay to the root
        root = splay(root, check);
        //root is smaller then key
        if ((compare(root->data, check) > 0)) {
            right = root->right;
            left = root;
            left->right = nullptr;
            left->sizeOfRightSubTree=0;
            left->sumOfRightSubTree=0;
            return false;
        }
            //root is bigger than key
        else if ((compare(root->data, check) < 0)) {
            left = root->left;
            right = root;
            right->left = nullptr;
            right->sizeOfLeftSubTree=0;
            right->sumOfLeftSubTree=0;
            return false;
        }
            //root equals key
        else {
            this->root = root;
            left = root->left;
            right = root->right;
            return true;
        }
    }

    /* Description:   This function joins "this" tree with a "BiggerTree"
     * meaning all keys in "BiggerTree" are bigger then all keys in "this" Tree
    * Input:         1) A vertex pointer for the left tree
     *               2) A vertex pointer for the right tree
     *               3)Function object "compare" function-
     *               that should give 1 if second arg is bigger 0 if equal and
     *               -1 if first arg is bigger.
    * Output:        None.
    * Return Values: new root pointer.
    */
    RankedVertex<T> *join(RankedVertex<T> *T1, RankedVertex<T> *T2) {
        RankedVertex<T> *current = T1;
        if (current != nullptr) {
            while (current->right != nullptr) {
                current = current->right;
            }
            T1 = splay(T1, current->data);
        }
        current = T2;
        if (current != nullptr) {
            while (current->left != nullptr) {
                current = current->left;
            }
            T2 = splay(T2, current->data);
        }
        RankedVertex<T> *new_root;
        if (T1 != nullptr) {
            T1->right = T2;
            new_root = T1;
        } else {
            new_root = T2;
        }
        return new_root;
    }

    /* Description:   This function does an InOrder Traversal on a given root
     *                and use the function that is given on each vertex
* Input:         1) to root to start from
 *               2)Function object "function" function-
 *               that should do whatever you want on a given data
* Output:        None.
* Return Values: None.
*/
    template<class Function>
    void inOrderTraversal(RankedVertex<T> *root, Function &func) {
        if (root == nullptr) return;
        inOrderTraversal(root->left, func);
        func(root->data);
        inOrderTraversal(root->right, func);
        return;
    }

    /* Description:   This function does an BackwardsInOrder Traversal on a given root
 *                and use the function that it is given on each vertex
* Input:         1) to root to start from
*               2)Function object "function" function-
*               that should do whatever you want on a given data
* Output:        None.
* Return Values: None.
*/
    template<class Function>
    void BackwardsinOrderTraversal(RankedVertex<T> *root, Function &func) {
        if (root == nullptr) return;
        BackwardsinOrderTraversal(root->right, func);
        func(root->data);
        BackwardsinOrderTraversal(root->left, func);
        return;
    }

    /**
     * The function destroys the tree from a given root to bottom
     * @param root to destory
     */
    void postOrderDemolition(RankedVertex<T> *root) {
        if (root == nullptr) {
            return;
        }
        postOrderDemolition(root->left);
        postOrderDemolition(root->right);
        delete root;
    }
    /**
 * Recursive function the travels on the tree to find the K ranked element
      */
    T& innerSelect(RankedVertex<T> *vertex,  int biggerthanI , int k){
        //found the k index
        if(k==biggerthanI+vertex->sizeOfLeftSubTree+1) return vertex->data;
        //k index is in left sub tree
        if(k<=biggerthanI+vertex->sizeOfLeftSubTree){
            return innerSelect(vertex->left,biggerthanI,k);
        }
        //k index is in right sub tree
        return innerSelect(vertex->right,biggerthanI+vertex->sizeOfLeftSubTree+1,k);
    }

public:

    RankedSplayTree<T,Compare,ExtractKey>(const Compare &comparef, const ExtractKey& getkeyf):
    root(nullptr),compare(comparef),getKey(getkeyf){}

    RankedSplayTree<T,Compare,ExtractKey>():
            root(nullptr),compare(Compare()),getKey(ExtractKey()){}

    ~RankedSplayTree() {
        postOrderDemolition(this->root);
    }


    /* Description:   This function Searches for a given data in the tree
    * Input:         The data to find
     *               Compare function for data 1 and 2, should return
     *               1 if second arg is bigger, -1 if first arg is bigger,
     *               0 if first and second arg are equal
    * Output:        None.
    * Return Values: true if key was found
     *               false if not
    */
    T* Search(const T &toCheck) {
        if (this->root == nullptr) {
            return nullptr;
        }
        this->root = splay(this->root, toCheck);
        if(compare(this->root,toCheck)!=0) return nullptr;
        return (&(this->root->data));
    }

    /* Description:   This function returns the minimum key
    * Input:         None.
    * Output:        None.
    * Exceptions:    TreeIsEmpty- if this is an empty tree
    * Return Values: The minimum key
    */
    T* Find_Min() {
        if (this->root == nullptr) {
            return nullptr;
        }
        RankedVertex<T> *current = this->root;
        while (current->left != nullptr) {
            current = current->left;
        }
        this->root = splay(this->root, current->data);
        return (&(this->root->data));
    }

    /* Description:   This function returns the maximum key
    * Input:         None.
    * Output:        None.
    * Exceptions:    TreeIsEmpty- if this is an empty tree
    * Return Values: The maximum key
    */
    T *Find_Max() {
        if (this->root == nullptr) {
            return nullptr;
        }
        RankedVertex<T> *current = this->root;
        while (current->right != nullptr) {
            current = current->right;
        }
        this->root = splay(this->root, current->data);
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
    bool Insert(const T &data) {
        if (this->root == nullptr) {
            this->root = new RankedVertex<T>(data);
            return true;
        }
        RankedVertex<T> *right, *left;
        //Key wasnt found
        if (!(split(this->root, left, right, data))) {
            RankedVertex<T> *new_root = new RankedVertex<T>(data);
            new_root->left = left;
            if(new_root->left!=nullptr){
                new_root->sizeOfLeftSubTree =
                        (left->sizeOfLeftSubTree) + (left->sizeOfRightSubTree) +
                        1;
                new_root->sumOfLeftSubTree =
                        (left->sumOfLeftSubTree) + (left->sumOfRightSubTree) +
                        this->getKey(left->data);
            }
            new_root->right = right;
            if (new_root->right!=nullptr){
                new_root->sizeOfRightSubTree =
                        (right->sizeOfLeftSubTree) + (right->sizeOfRightSubTree) +
                        1;
                new_root->sumOfRightSubTree =
                        right->sumOfLeftSubTree + right->sumOfRightSubTree +
                        this->getKey(right->data);
            }


            this->root = new_root;
            return true;
        }
            //Key exists
        else {
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
    bool Delete(const T &data) {
        if (this->root == nullptr) {
            return false;
        }
        //key was found
        if (this->Search(data)) {
            RankedVertex<T> *toDelete = this->root;
            this->root = join(this->root->left, this->root->right);
            delete toDelete;
            return true;
        } else {
            return false;
        }
    }
    /* Description:   This function travels on a tree in an inorder way
    * Input:         function to implement on elements
    * Output:        None.

*/
    template<class Function>
    void InOrder(Function &func) {
        inOrderTraversal(this->root, func);
    }
    /* Description:   This function travels on a tree in a
     *                Backwardsinorder way
    * Input:         function to implement on elements
    * Output:        None.

*/
    template<class Function>
    void BackwardsInOrder(Function &func) {
        BackwardsinOrderTraversal(this->root, func);
    }

    /* Description:   This function returns the k ranked element in the tree
* Input:         The rank to find
* Output:        nullptr if not found or bad argument
     *           a pointer to the desired element if found.
*/
    T* Select( int k){
        if(this->root==nullptr) return nullptr;
        if(k>this->root->sizeOfLeftSubTree+this->root->sizeOfRightSubTree+1 || k<0)
            return nullptr;
        if(k==this->root->sizeOfLeftSubTree+1) return &(this->root->data);
        //The k key is at left subtree
        if(k<=this->root->sizeOfLeftSubTree){
            this->root=splay(this->root,innerSelect(this->root->left,0,k));
        }
        //the k key is at right subtree
        else{
            this->root=splay(this->root,innerSelect(this->root->right,this->root->sizeOfLeftSubTree+1,k));
        }
        return &(this->root->data);
    }
    /* Description:   This function returns the sum of the best k elements in
     *                  the tree
* Input:         k
* Output:        ERROR if given a bad argument
     *           sum of best k elements if succeful
*/
    int getBestKSum(int k){
        int numberOfElements=this->root->sizeOfLeftSubTree+this->root->sizeOfRightSubTree+1;
        if(k>numberOfElements || k<0) return ERROR;
        if(k==numberOfElements){
            this->Select(1);
           return this->root->sumOfRightSubTree+this->getKey(this->root->data);
        }
        int bestK=numberOfElements-k;
        this->Select(bestK);
        return this->root->sumOfRightSubTree;
    }
};


/**---------------Implementation of Splay_tree functions--------------------*/

#endif //DS_HW2_RANKED_TREE_H
