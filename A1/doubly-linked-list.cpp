#include "doubly-linked-list.h"
#include "iostream"

DoublyLinkedList::Node::Node(DataType data)
{
    next = nullptr;
    prev = nullptr;
    value = data;
}

DoublyLinkedList::DoublyLinkedList()
{
    head_ = nullptr;
    tail_ = nullptr;
    size_ = 0;
}

DoublyLinkedList::~DoublyLinkedList()
{
    while (head_){

        Node *deleteNode = head_;   //create a   new node to delete
        delete deleteNode;       // delete the node
        head_ = deleteNode->next; // increment the index by 1

    }

}

unsigned int DoublyLinkedList::size() const
{
    return size_;
}

unsigned int DoublyLinkedList::capacity() const
{
    return CAPACITY;
}

bool DoublyLinkedList::empty() const
{
    if (head_ == nullptr){
        return true;
    }
    else{
        return false;
    }
}

bool DoublyLinkedList::full() const
{

    if(size_ == CAPACITY){
        return true;
    }
    else{
        return false;
    }

}

DoublyLinkedList::DataType DoublyLinkedList::select(unsigned int index) const
{
    if( index > size_-1 || index < 0){
        return tail_->value;
    }
    Node *selectNode = head_;

    int i = 0;
    while(selectNode && i < index){
        selectNode = selectNode->next;
        i ++;
    }
    if (selectNode){
        return selectNode->value;
    }
    return tail_->value;
}

unsigned int DoublyLinkedList::search(DataType value) const
{
    Node *searchNode = head_;
    int index = 0;
        while(searchNode){
            if(searchNode->value == value){
                return index;
            }
            index++;
            searchNode = searchNode->next;
        }
    return size_;
}

void DoublyLinkedList::print() const
{
    if(head_ == nullptr){
        return;
    }
    Node *temp = head_;
    std::cout<< "[";
    while (temp){
        std::cout<< temp->value << "->";
        temp = temp->next;
    }

    std::cout<< "NULL]" << std::endl;
}

DoublyLinkedList::Node* DoublyLinkedList::getNode(unsigned int index) const
{

}

bool DoublyLinkedList::insert(DataType value, unsigned int index)
{
    // if index is out of bounds it should return false
    if(index > size_ || index < 0 ){
        return false;
    }
    //if index is 0 then we call the insert_front function
    if (index == 0) {
        return insert_front(value);
    }
    // if the index is same as size we insert at the end by calling insert_back
    if (index == size_) {
        return insert_back(value);;
    }
    //inititalize the new nodes we need to perform the insert
    Node *newNode = new Node(value);
    Node *temp = head_;

    for (int i = 0; i < size_; i++) {
        if (i == index) {
            Node *prevTemp = temp->prev;  // the node before the index we want to insert at

            temp->prev = newNode;         // set the current node's previous to the newNode
            prevTemp->next = newNode;     // set the next of the previous node to the newNode

            newNode->next = temp;         // set the newNode next to the initial node that was there before
            newNode->prev = prevTemp;     // set the newNode previous to the node that is before this index
            size_++;
            return true;
        }
        temp = temp->next;

    }
}

bool DoublyLinkedList::insert_front(DataType value)
{
    Node *newNode = new Node(value);
// if size is 0 we want to index to an empty linked list
   if(size_ == 0){

       head_ = newNode; //head and tail should point to the newNode since its the only element
       tail_ = newNode;
       newNode->next = nullptr;     //the previous should point to the null since there is no element before index 0
       newNode->prev = nullptr;     // next should be null becuase its the only element in the list
       size_++;                     //increase size since we added a value
       return true;
   }
   else{
       size_++;
       Node *temp = head_; // make a new Node pointing to the first element
       temp->prev = newNode; // set the first nodes prev to the newNode
       newNode->next = temp; // set the newNode next to the prev
       newNode->prev = nullptr; // since newNode is first we set the previous to null
       head_ = newNode;         // new head will point to the node we just inserted

       return true;
   }
}

bool DoublyLinkedList::insert_back(DataType value)
{
    Node *newNode = new Node(value);
    //if size is 0 we call the insert front function since we dont want to repeat
    if(size_ == 0){
        return insert_front(value);
    }

    else{
        size_++;
        Node *temp = tail_;

        newNode->prev = temp;       //set the newNode prev to the last node
        newNode->next = nullptr;    // set the newNode next to null

        temp->next = newNode;       // set the prev node pointing to the newNode
        tail_ = newNode;            // tail should point to the last node

        return true;

    }
}

bool DoublyLinkedList::remove(unsigned int index)
{
    Node *temp = head_;
    if(size_ == 0 || index < 0 || index > size_ -1) {
        return false;
    }

    if(index == size_ -1) {
        return remove_back();
    }
    if(index == 0) {
        return remove_front();
    }
    else{
        //we need to get access to the node we wish to remove
        for(int i = 0; i < index; i++) {
            temp = temp->next;
        }
        Node *prevTemp = temp->prev;
        Node *nextTemp = temp->next;

        //EXAMPLE: [1<-> 2<->3<->4] remove(1) the next pointer of one should point to 3 and 3's prev points to 1
        prevTemp->next = nextTemp;      //the node previous will point to the node after the one we want to remove
        nextTemp->prev = prevTemp;      //the node after will point to the element before the one removed

        temp->next = nullptr;       //prevent dangling pointers
        temp->prev = nullptr;       //prevent dangling pointers

        size_--;
        delete temp;                //we want to delete the node since we are not using it anymore
        return true;
    }
}

bool DoublyLinkedList::remove_front()
{
    if (size_ == 0 ){
        return false;
    }
    // if this is the only element in the list then just set head and tail to null
    if(size_ == 1){
        size_--;
        // set all the pointers to null
        head_->prev = nullptr;
        head_->next = nullptr;
        head_ = nullptr;
        tail_ = nullptr;

        return true;
    }
    else{
        Node *temp = head_;     //create a temp node
        head_ = head_->next;    //set the head node to point to index 1

        //set all the pointers of the node we removing to null
        temp->next = nullptr;
        temp->next = nullptr;
        head_->prev = nullptr;
        delete temp;        //delete the node
        size_--;
        return true;
    }

}

bool DoublyLinkedList::remove_back()
{
    if(size_ == 0){
        return false;
    }
    if(size_ == 1){
        remove_front();
    }
    else{
        Node *temp = tail_;
        tail_ = tail_->prev; // tail points to the second last element

        // the next of tail should be null since its the last element
        tail_->next = nullptr;
        temp->prev = nullptr;
        temp->next = nullptr;
        delete temp;        //delete the last pointer
        size_--;
        return true;

    }
}

bool DoublyLinkedList::replace(unsigned int index, DataType value)
{
    if(index < 0 || index > size_ -1){
        return false;
    }

    Node *temp = head_;

    for(int i = 0; i < index; i ++){
        temp = temp->next;
    }
    temp->value = value;




    return true;
}

