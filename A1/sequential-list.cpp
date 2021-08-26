#include "sequential-list.h"
#include "iostream"

SequentialList::SequentialList(unsigned int cap)
{
    capacity_ = cap;
    size_ = 0;
    data_ = new DataType[capacity_];

}
// Destructor removes the dynamic array from the memory
SequentialList::~SequentialList()
{
    delete data_;
    data_ = nullptr;
}
// return the size of the array
unsigned int SequentialList::size() const
{
    return size_;
}

//return the capacity of the capacity
unsigned int SequentialList::capacity() const
{
    return capacity_;
}
// if the size is 0 then return true otherwise return false
bool SequentialList::empty() const
{
    if(size_ == 0) {
        return true;
    }
    return false;
}
//if the size equals capacity then its full and return true otherwise return false
bool SequentialList::full() const
{
    if(size_ == capacity_) {
        return true;
    }
    else{
        return false;
    }
}
// returns the element at the index in the list
SequentialList::DataType SequentialList::select(unsigned int index) const
{
    // if the index is more than capacity or size then it would be considered an invalid index
    // if index is less than 0 then it would be invalid
    if(index > capacity_ -1 || index > size_-1 || index < 0){
        return data_[size_ -1];
    }
    //if the if statement fails then we know the index is valid and we return the correct value at the index
    else{
        return data_[index];
    }
}
// searches for a value within a list
unsigned int SequentialList::search(DataType val) const
{
    // apply linear search if the size exists
    if(size_ !=0) {
        //Binary search is more optimal however the list could be of any datatype and we don't know if its sorted
        for (int i = 0; i < size_; i++) {
            if (data_[i] == val) {
                return i;
            }
        }
    }

    return size_;
}
//prints the list in the correct format
void SequentialList::print() const
{
    std::cout<< "[";
    for (int i = 0; i < size_; i++){
        std::cout<< data_[i];
        if(i != size_-1) {
            std::cout << ", ";
        }
    }
    std::cout<< "]" << std::endl;
}
// insert the element at a certain index
bool SequentialList::insert(DataType val, unsigned int index)
{
    // if the index is invalid then it would return false
    if(size_ + 1 > capacity_ || index > size_ || index < 0){
        return false;
    }
    // if the user decides to insert at index 0 insert front would be called
    else if (index == 0 ){

        return insert_front(val);;
    }
    else{
        size_++;
        int i;
        // start from the end of the list and move each element to the right until we reach the index we want to insert at
        // EXAMPLE: list: [1,2,3,4] index: 2 -> [1,2,3,3,4] then we change the value at index 2 to val which is the parameter
        for(i = size_; i> index; i--){
            data_[i] = data_[i-1];
        }
        data_[i] = val;       // this sets the element at the specific index to val

        return true;
    }
}
// this is similar to insert however the index we are inserting to is hard set to 0
bool SequentialList::insert_front(DataType val)
{
    if(size_ + 1 > capacity_){
        return false;
    }
    else{
        size_++;
        int i;

        for(i = size_ +1; i>= 0; i--){
            data_[i] = data_[i-1];
        }
        data_[i+1] = val;
        return true;
    }
}
//add the size by 1 and set the last value of the index to the value we want to insert
bool SequentialList::insert_back(DataType val)
{   // cant be greater than the capacity
    if(size_ + 1 > capacity_){
        return false;
    }
    else{
        size_++;
        data_[size_-1] = val;
        return true;
    }
}
// start from the index we wish to remove and set it the current index equal to the next value
//EXAMPLE: [1,2,3,4] remove index: 1 -> [1,3,3,4] -> [1,3,4]
bool SequentialList::remove(unsigned int index)
{
    if (size_ == 0 || index < 0 || index > size_ -1) {
        return false;
    }
    else if (index == 0) {
        return remove_front();
    }
    else{
        // Shift the element at the index we are looking for 1 to the right which will remove the element at index
        for(int i = index; i < size_; i++){
            data_[i] = data_[i+1];
        }
        size_--;
        return true;
    }

}
//similar to the remove function but the index is set to 0 and the current index value equals the next one
bool SequentialList::remove_front()
{
    if (size_ == 0) {
        return false;
    }
    else{
        for(int i = 0; i < size_; i++){
            data_[i] = data_[i+1];
        }
        size_--;
        return true;
    }
}
// set the last value to NULL and decrement size so the last value isn't considered(# dont care) part of the list
bool SequentialList::remove_back()
{
    if(size_ == 0){
        return false;
    }
    else {
        data_[size_ - 1] = NULL;
        size_--;
        return true;
    }
}
// change the values at the index to a new value by just assigning it
bool SequentialList::replace(unsigned int index, DataType val)
{
    if(index > size_ -1 || index < 0){
        return false;
    }
    else{
        data_[index] = val;
    }
}

