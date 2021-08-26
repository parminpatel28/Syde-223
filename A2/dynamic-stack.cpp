#include "dynamic-stack.h"
#include <iostream>
const DynamicStack::StackItem DynamicStack::EMPTY_STACK = 42069;
DynamicStack::DynamicStack() {
     size_ = 0;
     capacity_ = 16;
     items_ = new StackItem[capacity_];
     init_capacity_ = 16;

}
// constructor: make the stack with the given capacity and initialize the variables
DynamicStack::DynamicStack(unsigned int capacity){
    capacity_ = capacity;
    size_ = 0;
    init_capacity_ = capacity_;
    items_ = new StackItem[capacity_];
}
// set the pointer to null and remove its memory allocation
DynamicStack::~DynamicStack() {
    delete []items_;
    items_ = NULL;

}
// check if its empty using the size variable
bool DynamicStack::empty() const {
    if(size_ != 0){
        return false;
    }
    return true;
}
// return the size of the stack
int DynamicStack::size() const {
    return size_;
}

void DynamicStack::push(StackItem value) {
   // if the push isn't going to make stack full we can add elements to the end of the stack
    if(size_ != capacity_){
        items_[size_] = value;
        size_++;
    }

    else{
        StackItem *temp = items_;
        delete []temp;
        //double the capacity size if the stack is full
        capacity_ = capacity_*2;

        // make a new stack with new capacity and copy it to the original one and push new element to the end
        StackItem* newItems = new StackItem[capacity_];
        items_ = newItems;
        items_[size_] = value;
        size_++;

    }
}

DynamicStack::StackItem DynamicStack::pop() {
    // if stack is empty then return the constant
    if(size_ == 0){
        return EMPTY_STACK;
    }
    // if it isnt empty then remove the element from the end
    else{
        // store the removed element in a variable to return at the end
        StackItem popVar = items_[size_-1];
        items_[size_ -1] = 0;                   // set the element that is popped to 0
        size_--;                                // decrease size so the last element isn't considered

        if(size_<= capacity_*0.25){             // if size less than 1/4 of capacity then run this statement
            if(capacity_/2 >= init_capacity_){  // if capacity/2 is less than initial capacity then half the array
                StackItem *temp = items_;
                delete []temp;
                capacity_ = capacity_*0.5;      // half the capacity value
                StackItem* newItems = new StackItem[capacity_];     // make new stack with half the capacity
                items_ = newItems;                                  //copy the new stack to old one

            }
        }
        return popVar;      // return the element we deleted
    }
}

DynamicStack::StackItem DynamicStack::peek() const {
    // if there is no element in the stack then return the empty stack constant
    if(size_ == 0){
        return EMPTY_STACK;
    }
    // if stack is filled then return the last element in the stack
    return items_[size_-1];
}
// didn't need to use it
void DynamicStack::print() const {

}