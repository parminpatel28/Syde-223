#include "binary-search-tree.h"

BinarySearchTree::Node::Node(DataType newval)
{
    val = newval;
    left = nullptr;
    right = nullptr;

}

int BinarySearchTree::getNodeDepth(Node* n) const
{
    if(!n){
        return 0;
    }
    int leftDepth = 0;
    int rightDepth = 0;
    leftDepth = getNodeDepth(n->left);
    rightDepth = getNodeDepth(n->right);

    if(rightDepth > leftDepth){
        return rightDepth + 1;
    }else{
        return leftDepth + 1;
    }
}

void BinarySearchTree::updateNodeBalance(Node *n) {
    if(n){
        n->avlBalance = getNodeDepth(n);
    }
}

BinarySearchTree::BinarySearchTree()
{
    size_ = 0;
    root_ = nullptr;
}
void DestroyRecursion(BinarySearchTree:: Node* root){
    if(root) {
        DestroyRecursion(root->left);
        DestroyRecursion(root->right);
        delete root;
    }
}
BinarySearchTree::~BinarySearchTree()
{
    DestroyRecursion(root_);
}

unsigned int BinarySearchTree::size() const
{
    return size_;
}

BinarySearchTree::DataType BinarySearchTree::max() const
{
    Node *temp = root_;

    while (temp->right){
        temp = temp->right;
    }
    return temp->val;
}

BinarySearchTree::DataType BinarySearchTree::min() const
{
    Node *temp = root_;

    while (temp->left){
        temp = temp->left;
    }
    return temp->val;
}

unsigned int BinarySearchTree::depth() const
{
    return getNodeDepth(root_) -1;
}

void BinarySearchTree::print() const
{

}

bool BinarySearchTree::exists(DataType val) const
{
    Node *temp = root_;

    //Implement binary search to search for the value and return true if it exists

    while(temp){
        if(temp->val == val) {
            return true;
        }
        else if(temp->val > val){
            temp = temp->left;
        }
        else {
            temp = temp->right;
        }
    }
    return false;
}

BinarySearchTree::Node* BinarySearchTree::getRootNode()
{
    return root_;
}

BinarySearchTree::Node** BinarySearchTree::getRootNodeAddress()
{
    return &root_;
}

bool BinarySearchTree::insert(DataType val)
{
    if(!root_){     // if there is no root node then we can make the root node be the one with the val
        root_ = new Node(val);
        size_++;
        return true;
    }

    // we have to keep track of the parent node node since we will insert to its left or right node

    Node *temp = root_;
    Node *parentNode = temp;

    // first we will binary search to see if the value already exists or not if it does return false
    while(temp){
        if(temp->val == val) {
            return false;
        }
        else if(temp->val > val){ // we know left side value is less than parentNode node value so it will search left now
            parentNode = temp;
            temp = temp->left;
        }
        else {              // if the left value is not less than parent node that means it will be on the right so seach on right side
            parentNode = temp;
            temp = temp->right;
        }
    }

    if (val > parentNode->val){         // if the value of val is more than the value of parent node then insert at the right side
        Node *insertNode = new Node(val);
        parentNode->right = insertNode;
    } else{                            // if its less than val then insert on left side because that how binary trees work
        Node *insertNode = new Node(val);
        parentNode->left = insertNode;
    }
    size_++;
    return true;
}

bool BinarySearchTree::remove(DataType val) {
    // check to see if the value exists in our binary tree
    if (!root_) {
        return false;
    } else if (!exists(val)) {      // call the exist function and if the value doesnt exist return false
        return false;
    } else {
        Node *temp = root_;
        Node *parentNode = root_;
        bool is_left = false;

        while (temp) {      // this while loop find the node we want to delete and stores the node as temp
            if (val == temp->val) {     // if the value is found just break out of the while loop
                break;
            } else if (val < temp->val) {
                parentNode = temp;      // sets the parentNode which is used later
                temp = temp->left;
                is_left = true;

            } else {
                parentNode = temp;      // sets the parentNode which is used for deletion later
                temp = temp->right;
                is_left = false;
            }
        }

        if(temp->left && temp->right){     // if the node we are deleting has both right and left node then run this
            Node *prev = temp->left;
            while (prev->right){        // find the greatest value in the right subtree
                prev = prev->right;
            }
            int  prevVal = prev->val;
            remove(prevVal);            // call the remove function using recursion to remove change the value and modify the tree
            temp->val = prevVal;        // change the value of the node to delete to the precedossor value
            size_ = size_ -1;           // decrease size
            return true;
        }

        if(temp->right && !temp->left){        // if the parent node only had a right child node
            if (temp == root_){     // if the temp value is the root then we set the root to be the right value of temp
                root_ = temp->right;
            } if(!is_left){     // the node isn't a left node we know that we can set the right side of parent not to the right side of the node we want to delete
                parentNode->right = temp->right;
            }
            else{       // if the node is a left node then we can set the parent node's left side to be the delete node's right
                parentNode->left = temp->right;
            }
            size_ = size_ -1;   // decrease size
            delete temp;        // delete the temp variable
            return true;

        }

        else if(temp->left && !temp->right){        // if the parent node has only a right child

            if (temp == root_){     // if the temp value is the root then we set the root to be the left value of temp
                root_ = temp->left;
            } if(!is_left){     // if there is no left node then I set the parent nodes right to be the left node of the one that is being deleted
                parentNode->right = temp->left;
            }
            else{       // if there is a left node for the one that is being deleted then set the parent nodes left to the delete node's left
                parentNode->left = temp->left;
            }
            size_ = size_ -1;
            delete temp;
            return true;
        }

        else{
            if(temp == root_) {     // if the node we are deleting is the root node then delete it
                delete root_;
                root_ = nullptr;
                size_ = size_ - 1;
                return true;
            }
            if(is_left){        // set the left node of parent to null since the root node is being deleted
                parentNode->left = nullptr;
            }else{              // // set the left node of parent to null since the root node is being deleted
                parentNode->right = nullptr;
            }

            size_ = size_ - 1;
            delete temp;
            return true;
        }

    }
}




