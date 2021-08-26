#ifndef SYDE223_A3_AVL_TREE_H
#define SYDE223_A3_AVL_TREE_H

#include "binary-search-tree.h"

class AVLTree: public BinarySearchTree
{
public:
    // Overriden insert and remove functions
    // Do not modify these definitions

    //The AVL tree should be kept balanced after calling just insert or remove.
    bool insert(DataType val);
    bool remove(DataType val);
    void left(Node *node);
    void right(Node *node);
    int heightDifference(Node *N);
    void checkBalance(Node *node);
    int getAvlBalance(Node *node);
    void getLeafNodes(Node *node);

    // Define additional functions and attributes below if you need
};

#endif //SYDE223_A3_AVL_TREE_H
