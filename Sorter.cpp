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

        char word[50];
        for(int i = 0; i < length; i++){
            allWords[i] = new char[50];
            inputFile.getline(allWords[i], 50, '\n');;
        }
    }
}


// @param start: The starting index of the sort
// @param end: The last index of the sort
void Sorter::sortWordsByWordLength(int start, int end){
    while(start < end){
        int pivotPoint = partitionByWordLength(start, end);
        if(pivotPoint - start < end - pivotPoint){
            sortWordsByWordLength(start, pivotPoint - 1);
            start = pivotPoint + 1;
        }
        else{
            sortWordsByWordLength(pivotPoint + 1, end);
            end = pivotPoint - 1;
        }
    }
}
// Partitions a section of the list by word length
// @param start: The starting index of the partition
// @param end: The last index of the partion
int Sorter::partitionByWordLength(int start, int end) {
    int pivotLength = strlen(allWords[end]);
    int i = start - 1;

    for(int j = start; j < end; j++) {
        if (strlen(allWords[j]) < pivotLength){
            i++;
            swap(&allWords[i], &allWords[j]);
        }
    }
    swap(&allWords[i + 1], &allWords[end]);
    return i + 1;
}
int Sorter::partitionWordLenRandomPivot(int start, int end) {
    int pivot = randomPivot(start, end);
    swap(&allWords[pivot], &allWords[end]);
    return partitionByWordLength(start, end);
}



// Swaps the values of 2 of the elements inside allWords
// @param i, j: The two elements being swapped
void Sorter::swap(char** a, char** b) {
    char * temp = *a;
    *a = *b;
    *b = temp;
}



// Sorts a section of the list alphabetically based on word length
// Each part of the list will be sectioned off by checkpoints that 
// mark the end of a section of the list. Each section is based on 
// word length. It is this method's job to sort a individual section.
// @param start: The starting index of the sort
// @param end: The last index of the sort
void Sorter::sortWordSectionAlpha(int start, int end){
    if(start < end){
        int pivotpoint = partitionAlphabetically(start, end);
        sortWordSectionAlpha(start, pivotpoint - 1);
        sortWordSectionAlpha(pivotpoint + 1, end);
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
    for(int j = start; j < end; j++){
        if(strcmp(allWords[j],allWords[end]) < 0){
            i++;
            swap(&allWords[i], &allWords[j]);
        }
    }
    i++;
    swap(&allWords[i], &allWords[end]);
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
    maxWordLength = strlen(allWords[length - 1]);
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



int Sorter::medianPivot(int first, int second, int third){
    if(first > second){
        if(second > third){
            return second;
        }
        else if (first > third){
            return third;
        }
        else{
            return first;
        }
    }
    else {
        if(first > third){
            return first;
        }
        else if(second > third){
            return third;
        }
        else{
            return second;
        }
    }
}
int Sorter::randomPivot(int start, int end){
    return medianPivot(start + rand()%(end-start), start + rand()%(end-start), start + rand()%(end-start));
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

void Sorter::printAllWords() {
    for(int i = 0; i < length; i++){
        cout << allWords[i] << " ";
    }
    cout << endl;
}