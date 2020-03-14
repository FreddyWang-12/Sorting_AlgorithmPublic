//
// Created by Frederick Wang on 3/5/20.
//

#include "Sorter.h"

#include "iostream"
#include "fstream"
#include <string.h>
#include "stdio.h"
using namespace std;

Sorter::Sorter(){
    length = 0;
    wordLengthCheckpoints = nullptr;
    allWords = nullptr;
}

void Sorter::readWordFile(ifstream& inputFile){
    if(inputFile.is_open()){
        char number[15];
        inputFile.getline(number, 15, '\n');
        length = atoi(number);
        allWords = new char *[length];

        char word[70];
        for(int i = 0; i < length; i++){
            inputFile.getline(word, 70, '\n');
            allWords[i] = new char[70];
            strcpy(allWords[i], word);
        }
    }
}

void Sorter::sortWordsByWordLength(int &start, int &end){
    if(allWords != nullptr) {
        if (start < end) {
            int pivotPoint = partitionByWordLength(start, end);
            int firstHalf = pivotPoint - 1;
            int otherHalf = pivotPoint + 1;
            sortWordsByWordLength(start, firstHalf);
            sortWordsByWordLength(otherHalf, end);
        }
        maxWordLength = strlen(allWords[length - 1]);
    }
}

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

void Sorter::printSortedWordFile(ofstream& outputFile){
    outputFile << length << endl;
    for(int i = 0; i < length; i++){
        outputFile << allWords[i] << endl;
    }
}

void Sorter::swap(char *&i, char*&j) {
    char * temp = i;
    i = j;
    j = temp;
}

int& Sorter::getListLength() {
    return length;
}

int Sorter::partitionByWordLength(int start, int end) {
    int i = start - 1;
    for(int j = start; j < end; j++) {
        if (strlen(allWords[j]) < strlen(allWords[end])){
            i++;
            swap(allWords[i], allWords[j]);
        }
    }
    i++;
    swap(allWords[i], allWords[end]);
    return i;
}

int Sorter::partitionAlphabetically(int start, int end) {
    int i = start - 1;
    for(int j = start; j < end; j++){
        if(strcmp(allWords[j],allWords[end]) < 0){
            i++;
            swap(allWords[i], allWords[j]);
        }
    }
    i++;
    swap(allWords[i], allWords[end]);
    return i;
}

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