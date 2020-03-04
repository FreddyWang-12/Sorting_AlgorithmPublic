//
// Created by Frederick Wang on 1/30/20.
// "A copy of the string class that takes an array of chars and makes a line of string from it"
// "that can then be modified and adjusted"
// CS2341 - Data Structures
// Professor Mark Fontenot
//

#include "DSString.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

// Default constructor of the DSString
DSString::DSString(){
    data = nullptr;
    length = 0;
}

// Overloaded constructor of the DSString
// @param stringIdentity: The char array that defines this DSString's contents
DSString::DSString(const char* stringIdentity){
    data = new char[strlen(stringIdentity) + 1];
    strcpy(data, stringIdentity);
    length = strlen(stringIdentity);
}

// Copy constructor of the DSString
// @param dopplerString: The DSString that the current string will copy from
DSString::DSString(const DSString &dopplerString){
    data = new char[strlen(dopplerString.data) + 1];
    strcpy(data, dopplerString.data);
    length = dopplerString.length;
}

// Overloaded destructor for the DSString
DSString::~DSString(){
    if(data != nullptr) {
        delete[] data;
    }
}

// First Overloaded copy assigner operator for the DSString using another DSString
// @param copy: The DSString that the current string will copy from
DSString& DSString:: operator = (const DSString &copy){
    if(data != nullptr){
        delete[] data;
    }
    data = new char[strlen(copy.data) + 1];
    strcpy(data, copy.data);
    length = copy.length;
    return *this;
}

// Second Overloaded copy assigner operator for the DSString using a char array
// @param copy: The char array that defines this DSString's contents
DSString& DSString::operator = (const char* copy){
    if(data != nullptr){
        delete[] data;
    }
    data = new char[strlen(copy) + 1];
    strcpy(data, copy);
    length = strlen(copy);
    return *this;
}

// Overloaded addition operator for the DSString
// @param add: The DSString whose contents will be added to the current DSString
DSString DSString::operator + (const DSString &add) {
    int tLength = strlen(data) + strlen(add.data) + 1;
    char *newString = new char[tLength];


    strcpy(newString, data);
    strcat(newString, add.data);
    DSString temp(newString);
    length = tLength;

    delete[]newString;

    return temp;
}

// Overloaded addition-assigner operator for the DSString
// @param add: The DSString whose contents will be added to the current DSString
DSString DSString:: operator+=(const DSString &add) {
    int newLength = strlen(data) + strlen(add.data);
    char *newString = new char[newLength + 1];

    strcpy(newString, data);
    strcat(newString, add.data);

    delete[] data;
    data = new char[newLength + 1];
    strcpy(data, newString);
    delete[]newString;
    length = strlen(data);

    return *this;
}

// Returns the length of the DSString
int DSString::getLength(){
    return length;
}

// Overloaded equivalence operator for the DSString using another DSString
// @param compare: The DSString the current DSString will be compared to
bool DSString::operator == (const DSString &compare) const {
    bool bothStringsEqual = false;
    if(strcmp(data, compare.data) == 0){
        bothStringsEqual = true;
    }
    return bothStringsEqual;
}

// Overloaded equivalence operator for the DSString using a char array
// @param compare: The char array the current DSString will be compared to
bool DSString::operator == (const char* &compare) const {
    bool bothStringsEqual = false;
    if(strcmp(data, compare) == 0){
        bothStringsEqual = true;
    }
    return bothStringsEqual;
}

// Prints out the contents of the DSString's data
void DSString::print() {
    cout << data << endl;
}

// Creates a smaller DSString from the main DSString
// @param index: The first character of the new smaller DSString
// @param strLength: The length of the new smaller DSString
DSString DSString::substring(int index, int strLength){
    if(strLength > length){
        throw std::out_of_range("Out of Range in substr method");
    }

    DSString temp;
    temp.length = strLength;

    // The subscript of the data string
    char* string = new char[temp.length+1];

    int i;
    for(i = 0; i < temp.length; i++){
        string[i] = data[i + index];
    }
    string[temp.length] = '\0';
    temp.data = string;

    return temp;
}

// Returns the char found at a specific place in data
// @param index: The place in data where the char will be found
char DSString::operator [](const int index){
    return data[index];
}

// Overload "greater-than" operator for the DSString
// Returns whether or not the current DSString is bigger than the other
// @param other: The DSString the main DSString is being compared to
bool DSString ::operator > (const DSString &other) const {
    if(strcmp(data, other.data) > 0){
        return true;
    }
    else{
        return false;
    }
}

// Overload "greater-than" operator for the DSString
// Returns whether or not the current DSString is bigger than the other
// @param other: The DSString the main DSString is being compared to
bool DSString ::operator < (const DSString &other) const {
    if(strcmp(data, other.data) < 0){
        return true;
    }
    else{
        return false;
    }
}

// Returns the DSString's data as a separate char array
char* DSString::c_str(){
    char* strcopy = data;
    return strcopy;
}

// Turns all of the DSString's alphabetical chars into the lower-cased versions of themselves
void DSString::toLowercase() {
    for(int i = 0; i < length; i++){
        data[i] = tolower(data[i]);
    }
}

// Removes all punctuations from the char array
void DSString::removePunctuation() {
    for(int i = 0; i < length; i++){
        if(ispunct(data[i]) && data[i] != '-') {
            if (data[i] == '\'') {
                for (int j = i; j < length - 1; j++) {
                    data[j] = data[j + 1];
                }
                length--;
                i--;
            }
            else {
                data[i] = ' ';
                if (data[i + 1] == ' ') {
                    for (int j = i; j < length - 1; j++) {
                        data[j] = data[j + 1];
                    }
                    length--;
                    i--;
                }
            }
        }
    }

    char * temp = new char[length+1];
    for(int i = 0; i < length; i++){
        temp[i] = data[i];
    }
    temp[length] = '\0';
    delete[] data;
    data = temp;
}