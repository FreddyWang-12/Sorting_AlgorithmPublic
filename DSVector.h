//
// Created by Frederick Wang on 2/12/20.
// "A copy of the vector class that takes a collection of elements of the same type/class"
// "and places them in a list/vector"
// CS2341 - Data Structures
// Professor Mark Fontenot
//

#ifndef INC_20S_PA02_AUTOINDEXER_DSVECTOR_H
#define INC_20S_PA02_AUTOINDEXER_DSVECTOR_H

#include <iostream>
#include <stdexcept>
using namespace std;

template<class T>
class DSVector {
    private:
        int length; // Current length of the DSVector
        int capacity; // The max capacity of the DSVector
        T* data; // Current data array of class 'T'

    public:
        // Default constructor of the DSVector
        DSVector<T>();
        // 1. Overloaded destructor for the DSVector
        ~DSVector();
        // 2. Overloaded copy assignment operator for the DSVector
        // @param &copy: The DSVector whose data is being copied from
        DSVector<T>& operator = (const DSVector<T> &copy);
        // 3. Overloaded copy constructor for the DSVector
        // @param &copy: The DSVector whose data is being copied from
        DSVector<T> (const DSVector<T> &copy);
        // Returns the value of the data found within the given index value
        T& operator [](int index);
        // Returns the current size of the DSVector
        int size();
        // Returns the max capacity of the DSVector
        int getCapacity();
        // Determines if the DSVector has any values inside
        bool isEmpty();
        // Resizes the DSVector and increases the max capacity of the data array
        void resize();
        // Adds a new element to the DSVector
        // @param token: The new value being added
        void push_back(T token);
        // Removes the top value of the DSVector
        void pop_back();
        // Returns the first value of the DSVector
        T front();
        // Clears all of the elements inside the DSVector
        void clear();
        // Sorts the values in data by increasing order
        void sort();
        // Removes all duplicate values found in data
        void removeDuplicates();
};

template <class T>
DSVector<T>::DSVector(){
    length = 0;
    capacity = 100;
    data = new T[capacity];
}

template <class T>
DSVector<T>::~DSVector(){
    if(data != nullptr){
        delete[] data;
    }
}

template <class T>
DSVector<T>& DSVector<T>:: operator = (const DSVector<T> &copy){
    if(data != nullptr){
        delete[] data;
    }
    this->data = new T[copy.capacity];
    for(int i = 0; i < copy.length; i++){
        data[i] = copy.data[i];
    }
    this->capacity = copy.capacity;
    this->length = copy.length;
    return *this;
}

template <class T>
DSVector<T>:: DSVector(const DSVector<T> &copy){
    this->data = new T[copy.capacity];
    for(int i = 0; i < copy.length; i++){
        data[i] = copy.data[i];
    }
    this->capacity = copy.capacity;
    this->length = copy.length;
}

template <class T>
T& DSVector<T>::operator [](int index){
    return data[index];
}

template <class T>
int DSVector<T>::size(){
    return length;
}

template <class T>
int DSVector<T>::getCapacity(){
    return capacity;
}

template <class T>
bool DSVector<T>::isEmpty(){
    // Returns true if the length is zero
    if(length == 0){
        return true;
    }
    else{
        return false;
    }
}

template <class T>
void DSVector<T>::resize(){
    T * temp = new T[capacity * 2]; // Creates a temporary array of class T with double the capacity

    // Assigns the values of data to the temporary array
    for(int i= 0; i < capacity; i++){
        temp[i] = data[i];
    }

    capacity *= 2; // Doubles the max capacity
    delete[] data; // Deletes the pointer to the old data set
    data = temp; // Data is set to the new temporary T array
}

template <class T>
void DSVector<T>::push_back(T token){
    // Assign token as the first value of data if data was originally empty
    if(isEmpty()){
        data[0] = token;
        length = 1;
    }
    else{
        length++; // Increase the length of the DSVector
        if(length > capacity){ // If the length is greater than the max capacity,
            resize(); // then the DSVector resizes
        }
        data[length - 1] = token; // Adds token to the appropriate index
    }
}

template <class T>
void DSVector<T>::pop_back(){
    // Tells you if the DSVector is empty
    if(isEmpty()){
        throw std::out_of_range("Out of Range, no elements");
    }
    else {
        // Removes the first value of data and moves over the other values of data over to the front
        for(int i = 0; i < length; i++){
            data[i] = data[i+1];
        }
        length--; // Reduces the length of the DSVector

        T * temp = new T[capacity];
        for(int i = 0; i < length; i++){
            temp[i] = data[i];
        }
        delete[]data;
        data = temp;
    }
}

template <class T>
T DSVector<T>::front(){
    return data[0];
}

template <class T>
void DSVector<T>::clear(){
    delete[] data;
    data = new T[capacity];
    length = 0;
}

template <class T>
void DSVector<T>::sort(){
    // Tells you if the DSVector is empty
    if(isEmpty()){
        cout << "No data to sort" << endl;
    }

    else{
        // Compares each value by each other
        for(int i = 0; i < length - 1; i++){
            for(int j = i + 1; j < length; j++){
                if(data[i] > data[j]){ // If the first value found at "i" is greater than the second value at "j"
                    T temp = data[i];  // then swap the values.
                    data[i] = data[j];
                    data[j] = temp;
                }
            }
        }
    }
}

template <class T>
void DSVector<T>::removeDuplicates(){
    // Tells you if the DSVector is empty
    if(isEmpty()){
        cout << "No data to sort" << endl;
    }
    else{
        for(int i = 0; i < length - 1; i++){
            for(int j = i + 1; j < length; j++){
                if(data[i] == data[j]){ // If these two values are the same
                    for(int k = j; k < length - 1; k++){
                        data[k] = data[k+1]; // Then erase the duplicate value found at "j" by moving over the
                        // values ahead of index "j"
                    }
                    --length; // Reduces the length of the DSVector by one
                    --j;
                }
            }
        }
        T * temp = new T[capacity];
        for(int i = 0; i < length; i++){
            temp[i] = data[i];
        }
        delete[] data;
        data = temp;
    }
}


#endif //INC_20S_PA02_AUTOINDEXER_DSVECTOR_H
