#include "avl-tree.h";

bool AVLTree::insert(DataType val)
{

    if(BinarySearchTree::insert(val)){ // if the insert is successful we check if the tree is balanced by calling the function
        checkBalance(getRootNode());
        return true;
    }
    return false;   // return false if the insert didn't happen

}

bool AVLTree::remove(DataType val)
{
    if(BinarySearchTree::remove(val)) {     // if the remove is successful we check balance and make sure its balanced
        checkBalance(getRootNode());
        return true;
    }
    return false;   // false if the remove didnt happen
}


void AVLTree::left(Node *node) {    // manually change the values of the nodes within the tree to make it balanced

    Node *temp = new Node(node->val);       // make a temp node with the parent node value
    temp->right = node->right->left;        // make the temp nodes right be the parent nodes right subtrees left node
    temp->left = node->left;                // make the temp nodes left to be the parent's node left
    node->left = temp;                      // make the parent nodes left to be the temp node so the rotation is successful now
    node->val = node->right->val;           // now update the values of the nodes so the values are the expected ones
    node->right = node->right->right;       // make the parent nodes right node be the parents nodes right subtrees nodes right
}

void AVLTree::right(Node *node) {        // manually change the values of the nodes within the tree to make it balanced

    Node *temp = new Node(node->val);   // make a temp node with the parent node value
    temp->left = node->left->right;     // have the temp nodes left be the parents node left subtrees right node
    temp->right = node->right;          // temp nodes right will be the parents node right
    node->right = temp;                 // make the parents node's right be the temp node so the rotation is successful
    node->val = node->left->val;        // update the values of the nodes so its the one we want
    node->left = node->left->left;      // make the parent nodes left be the parents node's left subtrees left

}

int AVLTree::heightDifference(Node *N) { // helper function to get the height difference of left and right nodes
    return getAvlBalance(N->left) - getAvlBalance(N->right);
}

int AVLTree::getAvlBalance(Node *node) { // helper function to get the height of the node
    if(node){
        updateNodeBalance(node);
        return node->avlBalance;
    }
    return 0;
}
void AVLTree::getLeafNodes(Node *node){     // recursion into the node to get every leaf node
    checkBalance(node->left);
    checkBalance(node->right);
}
void AVLTree::checkBalance(Node *node){
    if(!node) return;
    getLeafNodes(node);
    // if the right tree is larger then do a left rotation
    if(heightDifference(node) < -1) {
        // perform rightleft rotation
        if(heightDifference(node->right) > 0 ){ // if the right sub trees left children nodes are greater then do a right left rotation
            right(node->right);
            left(node);
        } else {        // if the right sub trees right children nodes are greater then do a right left rotation
            left(node);
        }
    } else if(heightDifference(node) > 1){ // if the left tree is greater

        if(heightDifference(node->left) < 0){        // if the left tree has a larger right children node then do right rotation
            left(node->left);
            right(node);
        }
        else {      // if the left tree has a larger left children node then do right rotation
            right(node);
        }
    }
}
