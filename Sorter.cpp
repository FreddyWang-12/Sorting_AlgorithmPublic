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



// Sorts all of the words in the list by their word length
// @param start: The starting index of the sort
// @param end: The last index of the sort
void Sorter::sortWordsByWordLength(int start, int end){
    if(sizeof(allWords) != 0) {
        if (start < end) {
            int middle = (start + (end - 1)) / 2;
            sortWordsByWordLength(start, middle);
            sortWordsByWordLength(middle + 1, end);
            mergeByWordLength(start, middle, end);
        }
    }
}
// Takes a section of the overall word list (allWords), divides
// in half, and merges its two halves together based on ascending
// word length
// @param start: The starting index of the section in allWords
// @param middle: The middle index of the section in allWords
// @param end: The last index of the section in allWords
void Sorter::mergeByWordLength(int start, int middle, int end) {
    int i = start;
    int j = middle + 1;
    int sortIndex = 0;
    char* sortedWords[end - start + 1];

    while(i <= middle && j <= end){
        if(strlen(allWords[i]) <= strlen(allWords[j])){
            sortedWords[sortIndex] = allWords[i];
            i++;
        }
        else{
            sortedWords[sortIndex] = allWords[j];
            j++;
        }
        sortIndex++;
    }
    while(i <= middle){
        sortedWords[sortIndex] = allWords[i];
        sortIndex++;
        i++;
    }
    while(j <= end){
        sortedWords[sortIndex] = allWords[j];
        sortIndex++;
        j++;
    }
    for(i = start; i <= end; i++){
        allWords[i] = sortedWords[i - start];
    }
}



// Sorts a section of the list alphabetically based on word length
// Each part of the list will be sectioned off by checkpoints that
// mark the end of a section of the list. Each section is based on
// word length. It is this method's job to sort a individual section.
// @param start: The starting index of the sort
// @param end: The last index of the sort
void Sorter::sortWordSectionAlpha(int start, int end){
    if(sizeof(allWords) != 0) {
        if (start < end) {
            int pivotPoint = partitionAlphabetically(start, end);
            sortWordSectionAlpha(start, pivotPoint - 1);
            sortWordSectionAlpha(pivotPoint + 1, end);
        }
    }
}
// Takes through all sections of the list (after being sorted by word length)
// and sorts them all out alphabetically. These sections are determined by their
// word length, so all 1-letter words will be sorted individually, all 2-letter
// words will be sorted individually, etc.
void Sorter::sortAllWordsAlphabetically() {
    sortWordSectionAlpha(beginning, wordLengthCheckpoints[0]);
    for(int i = 0; i < maxWordLength - 1; i++){
        int nextIndex = wordLengthCheckpoints[i] + 1;
        int nextCheckpoint = wordLengthCheckpoints[i + 1];
        sortWordSectionAlpha(nextIndex, nextCheckpoint);
    }
    sortWordSectionAlpha(wordLengthCheckpoints[lastCheckpoint] + 1, length - 1);
}
// Partitions a section of the list and sorts it alphabetically
// @param start: The starting index of the partition
// @param end: The last index of the partition
int Sorter::partitionAlphabetically(int start, int end) {
    int i = start - 1;
    for(int j = start; j < end; j++){
        if(strcmp(allWords[j],allWords[end]) < 0){
            i++;
            swap(&allWords[i], &allWords[j]);
        }
    }
    swap(&allWords[i + 1], &allWords[end]);
    return i + 1;
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
// Swaps the values of 2 of the elements inside allWords
// @param i, j: The two elements being swapped
void Sorter::swap(char** a, char** b) {
    char * temp = *a;
    *a = *b;
    *b = temp;
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