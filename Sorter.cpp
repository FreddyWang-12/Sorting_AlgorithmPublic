//
// Created by Frederick Wang on 3/5/20.
//

#include "Sorter.h"

#include "DSVector.h"
#include "DSString.h"
#include "iostream"
#include "fstream"
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

        char word[40];
        for(int i = 0; i < length; i++){
            inputFile.getline(word, 40, '\n');
            allWords[i] = new char[40];
            strcpy(allWords[i], word);
        }
    }
}

void Sorter::sortWordsByWordLength(int start, int end){
    if(allWords != nullptr) {
        if (start < end) {
            int pivotPoint = partitionByWordLength(start, end);
            sortWordsByWordLength(start, pivotPoint - 1);
            sortWordsByWordLength(pivotPoint + 1, end);
        }
    }
}

void Sorter::sortWordSectionAlpha(int start, int end){
    if(allWords != nullptr) {
        if (start < end) {
            int pivotPoint = partitionAlphabetically(start, end);
            sortWordSectionAlpha(start, pivotPoint - 1);
            sortWordSectionAlpha(pivotPoint + 1, end);
        }
    }
}

void Sorter::sortAllWordsAlphabetically() {
    sortWordSectionAlpha(0, wordLengthCheckpoints[0]);
    for(int i = 0; i < strlen(allWords[length - 1]) - 1; i++){
        sortWordSectionAlpha(wordLengthCheckpoints[i] + 1, wordLengthCheckpoints[i + 1]);
    }
    sortWordSectionAlpha(wordLengthCheckpoints[lastCheckpoint] + 1, length - 1);
}

void Sorter::printSortedWordFile(ofstream& outputFile){
    outputFile << length << endl;
    for(int i = 0; i < length; i++){
        outputFile << allWords[i] << endl;
    }
}

void Sorter::swap(int i, int j) {
    char * temp = allWords[i];
    allWords[i] = allWords[j];
    allWords[j] = temp;
}

int Sorter::getListLength() {
    return length;
}

int Sorter::partitionByWordLength(int start, int end) {
    int i = start - 1;
    for(int j = start; j < end; j++) {
        if (strlen(allWords[j]) < strlen(allWords[end])){
            i++;
            swap(i, j);
        }
    }
    i++;
    swap(i, end);
    return i;
}

int Sorter::partitionAlphabetically(int start, int end) {
    int i = start - 1;
    for(int j = start; j < end; j++){
        if(strcmp(allWords[j], allWords[end]) < 0){
            i++;
            swap(i, j);
        }
    }
    i++;
    swap(i, end);
    return i;
}

void Sorter::createAlphabeticalCheckpoints() {
    if(wordLengthCheckpoints != nullptr) {
        delete[] wordLengthCheckpoints;
    }
    wordLengthCheckpoints = new int[strlen(allWords[length - 1])];
    int index = 0;

    for(int i = 0; i < length - 1; i++) {
        if(strlen(allWords[i + 1]) > strlen(allWords[i])) {
            wordLengthCheckpoints[index] = i;
            index++;
        }
    }
    lastCheckpoint = index - 1;
}