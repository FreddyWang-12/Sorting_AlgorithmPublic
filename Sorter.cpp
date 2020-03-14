//
// Created by Frederick Wang on 3/5/20.
//

#include "Sorter.h"

#include "iostream"
#include "fstream"
#include <string.h>
#include "stdio.h"
#include "stdlib.h"
using namespace std;

// Default constructor of the Sorter Class
Sorter::Sorter(){
    length = 0;
    wordLengthCheckpoints = nullptr;
    allWords = nullptr;
}
// Reads a text file and adds all of the words inside a char** array
// @param inputFile: The file being read
void Sorter::readWordFile(ifstream& inputFile){
    if(inputFile.is_open()){
        char number[15];
        inputFile.getline(number, 15, '\n');
        length = atoi(number);
        allWords = new char *[length];

        char word[70];
        for(int i = 0; i < length; i++){
            allWords[i] = new char[70];
            inputFile.getline(allWords[i], 70, '\n');;
        }
    }
}


// @param start: The starting index of the sort
// @param end: The last index of the sort
void Sorter::sortWordsByWordLength(int start, int end){
    while (start < end) {
        int pivotPoint = partitionByWordLength(start, end);
        if(pivotPoint - start < end - pivotPoint){
            sortWordsByWordLength(start, pivotPoint - 1);
            start = pivotPoint + 1;
        }
        else{
            sortWordsByWordLength(pivotPoint + 1, end);
            start = pivotPoint - 1;
        }
    }
    maxWordLength = strlen(allWords[length - 1]);
}
<<<<<<< HEAD
=======
// Partitions a section of the list by word length
// @param start: The starting index of the partition
// @param end: The last index of the partion
>>>>>>> d68464931dab1f8d9a49cb6fd761b9ad3831c670
int Sorter::partitionByWordLength(int start, int end) {
    int i = start - 1;
    for(int j = start; j < end - 1; j++) {
        if (strlen(allWords[j]) < strlen(allWords[end])){
            i++;
            swap(allWords[i], allWords[j]);
        }
    }
    i++;
    swap(allWords[i], allWords[end]);
    return i;
}

<<<<<<< HEAD
=======

// Sorts a section of the list alphabetically based on word length
// Each part of the list will be sectioned off by checkpoints that 
// mark the end of a section of the list. Each section is based on 
// word length. It is this method's job to sort a individual section.
// @param start: The starting index of the sort
// @param end: The last index of the sort
>>>>>>> d68464931dab1f8d9a49cb6fd761b9ad3831c670
void Sorter::sortWordSectionAlpha(int start, int end){
    if(allWords != nullptr) {
        if (start < end) {
            int pivotPoint = partitionAlphabetically(start, end);
            int firstHalf = pivotPoint - 1;
            int secondHalf = pivotPoint + 1;
            sortWordSectionAlpha(start, firstHalf);
            sortWordSectionAlpha(secondHalf, end);
        }
    }
}
// Takes through all sections of the list (after being sorted by word length)
// and sorts them all out alphabetically. These sections are determined by their
// word length, so all 1-letter words will be sorted individually,all 2-letter 
// words will be sorted individually, etc.
void Sorter::sortAllWordsAlphabetically() {
    sortWordSectionAlpha(beginning, wordLengthCheckpoints[0]);
    for(int i = 0; i < maxWordLength - 1; i++){
        int nextIndex = wordLengthCheckpoints[i] + 1;
        sortWordSectionAlpha(nextIndex, wordLengthCheckpoints[i + 1]);
    }
    int finalIndex = wordLengthCheckpoints[lastCheckpoint] + 1;
    int ending = length - 1;
    sortWordSectionAlpha(finalIndex, ending);
}
// Partitions a section of the list via an alphabetical quicksort
// @param start: The starting index of the partition
// @param end: The last index of the partion
int Sorter::partitionAlphabetically(int start, int end) {
    int i = start - 1;
    for(int j = start; j < end - 1; j++){
        if(strcmp(allWords[j],allWords[end]) < 0){
            i++;
            swap(allWords[i], allWords[j]);
        }
    }
    i++;
    swap(allWords[i], allWords[end]);
    return i;
}
// Each part of the list will be sectioned off by checkpoints that 
// mark the end of a section of the list. Each section is based on 
// word length. It is this method's job to sort create those 
// checkpoints that will define those sections.
void Sorter::createAlphabeticalCheckpoints() {
    if(wordLengthCheckpoints != nullptr) {
        delete[] wordLengthCheckpoints;
    }
    wordLengthCheckpoints = new int[maxWordLength];
    int index = 0;

    for(int i = 0; i < length - 1; i++) {
        if(strlen(allWords[i + 1]) > strlen(allWords[i])) {
            wordLengthCheckpoints[index] = i;
            index++;
        }
    }
    lastCheckpoint = index - 1;
}


// Swaps the values of 2 of the elements inside allWords
// @param i, j: The two elements being swapped
void Sorter::swap(char *&i, char*&j) {
    char * temp = i;
    i = j;
    j = temp;
}


// Creates an output file of all of the contents of the word list
// @param outputFile: The name of the output file
void Sorter::printSortedWordFile(ofstream& outputFile){
    outputFile << length << endl;
    for(int i = 0; i < length; i++){
        outputFile << allWords[i] << endl;
    }
}
// Returns the length of the word list
int& Sorter::getListLength() {
    return length;
}
