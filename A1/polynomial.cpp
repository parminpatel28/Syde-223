#include "polynomial.h"
#include <iostream>
using namespace std;
Polynomial::Polynomial(int A[], int size) {
    size_ = size;
    int index = 0;
    while(index != size){       // go through the loop and just add the values from the array to the back of the linked list
        coefficients.insert_back(A[index]);
        index ++;       // increment index
    }
}
Polynomial* Polynomial::add(Polynomial* rhs) {
    int maxSize = 0;
    int minSize = 0;
    if(rhs->coefficients.size() < coefficients.size()){     // if the rhs is shorter then set its size to minSize and other to maxSize
        maxSize = size_;
        minSize = rhs->size_;
    }
    else{               // if rhs is longer then set its size to maxSize and other one to minSize
        maxSize = rhs->size_;
        minSize = size_;
    }
    int newArray[maxSize];      // create a new array with a size of maxSize

    for(int i = 0; i < minSize; i ++){          // loop through from 0 to minSize and add the elements at that index in both lists to the array
        newArray[i] = coefficients.select(i) + rhs->coefficients.select(i);
    }

    if(rhs->size_ == maxSize){              // if the rhs is the maxSize then we add the remaining elements from the list to the array
        for(int i = minSize; i < maxSize; i++){
            newArray[i] = coefficients.select(i);
        }
    }
    else{                                   // if the other list is maxSize then we add the remaining elements from the list to the array
        for(int i = minSize; i < maxSize; i++){
            newArray[i] = rhs->coefficients.select(i);
        }
    }
    Polynomial *newPloynomial = new Polynomial(newArray, maxSize); // create a new polynomial with the newArray and maxSize as params
    return newPloynomial;       // return the new polynomial


}
Polynomial* Polynomial::sub(Polynomial* rhs) {
    int maxSize = 0;
    int minSize = 0;
    if(rhs->coefficients.size() < coefficients.size()){     // find which list is greater and set the variables accordingly
        maxSize = size_;
        minSize = rhs->size_;
    }
    else{
        maxSize = rhs->size_;
        minSize = size_;
    }
    int newArray[maxSize];          // create a new array to store the new subtracted values

    for(int i = 0; i < minSize; i ++){          // loop through and subtract the current list from the rhs list and add it to the array
        newArray[i] = coefficients.select(i) - rhs->coefficients.select(i);
    }

    if(rhs->size_ == maxSize){          // if the rhs is greater then add the remaining values to the array
        for(int i = minSize; i < maxSize; i++){
            newArray[i] = rhs->coefficients.select(i);
        }
    }
    else{                              // if the current linked list is greater then add its remaining values to the array
        for(int i = minSize; i < maxSize; i++){
            newArray[i] = coefficients.select(i);
        }
    }
    Polynomial *newPloynomial = new Polynomial(newArray, maxSize);      // create a new polynomial with the array and maxSize
    return newPloynomial;       //return the new polynomial that was just create
}
Polynomial* Polynomial::mul(Polynomial* rhs) {
    int maxSize = rhs->coefficients.size() + coefficients.size() -1;
    int newArray[maxSize];

    for(int i = 0; i < maxSize; i ++){
        newArray[i] = 0;                // set all the values to 0 so we dont have random array values
    }

    for(int i =0; i < coefficients.size() ; i++ ){      // nested loop to increment the value of each multiplication of the elements
        for(int j = 0; j < rhs->coefficients.size(); j ++){
            // whenever we have the same exponent polynomial we just add it to the one we currently have so if current
            //EXAMPLE: current = 3x^3  then we do 2x^1 * 4x^2 = 8^3 so now we just add the 8 with the previous coefficients of 3 so its 11x^3
            newArray[i+j] +=  coefficients.select(i) * rhs->coefficients.select(j);     // indexes add i+j because x^2 * x^ 3 = x^5
        }
    }
    Polynomial *newPolynomial = new Polynomial(newArray, maxSize);      // make a new polynomial with the new array and max size possible
    return newPolynomial;       // return that ploynomial
}
void Polynomial::print() {

 int count = size_ -1;
    // this for loop gets the first non-zero element in the list and print it
    for(int index = size_ -1; index>=0; index--){
        if(coefficients.select(index) > 0) {
            // this wouldn't have brackets since its the first element
            cout << coefficients.select(index) << "x^" << index;        // if its more than 0 we just print Ex: 2^2
            count = index-1;
            break;      // terminate since we got the first value
        }
        else if(coefficients.select(index) < 0){
            cout<< "(" << coefficients.select(index)<<")" <<"x^" <<index;   // if its less than 0 we have brackets EX: (-3)^3
            count = index-1;
            break;      //terminate since we got the first value
        }
    }
    // then we start off at the index where the first loop has left off and continue to print the polynomial from there
    for(count-1; count >= 0; count--){
        if (coefficients.select(count) > 0){        // print when its more than 0 but with the sign
            cout<< " + " << coefficients.select(count) << "x^" << count;        // format for positive coefficients
        }
        else if(coefficients.select(count) < 0){        // prints if its less than 0 with the sign
            cout << " + " << "(" << coefficients.select(count)<<")" <<"x^" <<count;     // format for negative coefficients
        }
    }
    cout<<endl;
}
