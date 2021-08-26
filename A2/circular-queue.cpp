#include "circular-queue.h"
#include <iostream>
using namespace std;
const CircularQueue::QueueItem CircularQueue::EMPTY_QUEUE = 42069;
CircularQueue::CircularQueue() {
    size_ = 0;
    capacity_ = 16;
    items_ = new QueueItem[capacity_];
    head_ = 0;
    tail_ = 0;
}

CircularQueue::CircularQueue(unsigned int capacity) {
    size_ = 0;
    capacity_ = capacity;
    items_ = new QueueItem[capacity_];
    head_ = 0;
    tail_ = 0;
}

CircularQueue::~CircularQueue() {
    delete []items_;
    items_ = NULL;
}

bool CircularQueue::empty() const {

    if(size_ == 0){
        return true;
    }
    return false;
}

bool CircularQueue::full() const {
    if(size_ == capacity_){
        return true;
    }
    return false;
}

int CircularQueue::size() const {
    return size_;
}


bool CircularQueue::enqueue(QueueItem value) {
    // if the queue is full then it shouldn't allow elements to be added
    if(size_ == capacity_){
        return false;
    }

    items_[tail_] = value;  // add the value at the end of the queue
    size_++;                //increase size
    tail_++;                // tail is the element after last so it should also be incremented
    if(tail_ == capacity_){     // if the tail is at capacity that means it should be the first element since it circular
        tail_ = 0;
    }
    return true;
}

CircularQueue::QueueItem CircularQueue::dequeue() {
    // if size is empty nothing can be removed so return false
    if(size_ == 0){
        return EMPTY_QUEUE;
    }
    QueueItem temp = items_[head_];         // store the element to remove so it can be used for return statement
    head_++;                                // increase head since so the element is now not part of the queue
    // if head is at capacity then it needs to start from the start of the queue again so its set to 0
    if(head_ == capacity_){
        head_ = 0;
    }
    size_--;                                //decrease size since the element got removed
    return temp;                            //return the element we stored
}

CircularQueue::QueueItem CircularQueue::peek() const {
    // if the queue is empty then just return empty value
    if(size_ == 0){
        return EMPTY_QUEUE;
    }
    return items_[head_];       //return the top of the queue which is the first element in it
}

void CircularQueue::print() const {
    for(int i = 0; i < size_; i++){
        std::cout<< items_[i];
        cout<< ", ";

    }
    std::cout << std::endl;
}