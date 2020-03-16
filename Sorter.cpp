//
// Created by Frederick Wang on 3/5/20.
// A class designed to take a list of words and
// sort the out by length and then alphabetical
// order as quickly and efficiently as possible.
// CS2341 - Mark Fontenot
// 3/15/2020
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
    lastCheckpoint = 0;
    maxWordLength = 0;
    length = 0;
    wordLengthCheckpoints = nullptr;
    allWords = nullptr;
}
// Reads a text file and adds all of the words inside a char** array ('allWords')
// @param inputFile: The file being read
void Sorter::readWordFile(ifstream& inputFile){
    // Makes sure the file being read is actually opened
    if(inputFile.is_open()){
        char number[15]; // The first line of the file is a number
        inputFile.getline(number, 15, '\n'); // That number is extracted
        length = atoi(number); // And then made the length of 'allWords'
        if(allWords != nullptr){
            delete[] allWords;
        }
        allWords = new char *[length]; // Create a new char double array for 'allWords'

        char word[50]; // Each word is roughly 30 characters max, but it could be
                       // slightly bigger than expected

        // Read every word inside of the list and add them to 'allWords'
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
    // If 'allWords' even has any actually words in it
    if(sizeof(allWords) != 0) {
        // If the parameters 'start' and 'end' are reasonable
        // i.e. if 'start' is not a greater value than 'end'
        if (start < end) {
            int middle = (start + (end - 1)) / 2; // The middle value of allWords
            sortWordsByWordLength(start, middle); // Sort all words in the first half of 'allWords'
            sortWordsByWordLength(middle + 1, end); // Sorts all words in the last half of 'allWords'
            mergeByWordLength(start, middle, end); // Merge them all back together
        }
    }
}
// Takes a section of the overall word list ('allWords'), divides
// in half, and merges its two halves together based on ascending
// word length
// @param start: The starting index of the section in 'allWords'
// @param middle: The middle index of the section in 'allWords'
// @param end: The last index of the section in 'allWords'
void Sorter::mergeByWordLength(int start, int middle, int end) {
    int i = start; // 'i' is the index that will represent everything in the first half of this section of 'allWords'
    int j = middle + 1; // 'j' is the index that will represent everything in the second half of this section of
                        // 'allWords'
    char* sortedWords[end - start + 1]; // Acts as a temporary char double array that act as the sorted version of this
                                        // section of the list
    int sortIndex = 0; // Acts as the index counter for 'sortedWords'

    // Loops while 'i' doesn't reach its index limit ('start') and while 'j' doesn't reach its index limit ('end')
    while(i <= middle && j <= end){
        // In this section, the next words of both halves are compared and the word with the smaller word length will
        // be added next to the 'sortedWords' list
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

    // In this section, any words left inside both lists will be added into 'sortedWords'
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
    // Replaces this unsorted section in 'allWords' with the sorted version
    for(i = start; i <= end; i++){
        allWords[i] = sortedWords[i - start];
    }
}



// Sorts a section of the list alphabetically based on word length
// after being sorted by word length
// Each part of the list will be sectioned off by checkpoints that
// mark the end of a section of the list. Each section is based on
// word length. It is this method's job to sort a individual section.
// @param start: The starting index of the sort
// @param end: The last index of the sort
void Sorter::sortWordSectionAlpha(int start, int end){
    // If 'allWords' even has any actually words in it
    if(sizeof(allWords) != 0) {
        // If the parameters 'start' and 'end' are reasonable
        // i.e. if 'start' is not a greater value than 'end'
        if (start < end) {
            int pivotPoint = partitionAlphabetically(start, end); // Acts as the pivot word of 'allWords'
                                                                  // after partitioning the list once
            sortWordSectionAlpha(start, pivotPoint - 1); // Sort every word below the chosen pivot
            sortWordSectionAlpha(pivotPoint + 1, end); // Sort every word above the chosen pivot
        }
    }
}
// Takes through all sections of the list (after being sorted by word length)
// and sorts them all out alphabetically. These sections are determined by their
// word length, so all 1-letter words will be sorted individually, all 2-letter
// words will be sorted individually, etc.
void Sorter::sortAllWordsAlphabetically() {
    sortWordSectionAlpha(beginning, wordLengthCheckpoints[0]); // Sorts the first section of 'allWords'
                                                                    // alphabetically
    // Sort every other section of 'allWords' alphabetically except for the last one
    for(int i = 0; i < maxWordLength - 1; i++){
        int nextIndex = wordLengthCheckpoints[i] + 1; // The start of the next section
        int nextCheckpoint = wordLengthCheckpoints[i + 1]; // The end of the next section
        sortWordSectionAlpha(nextIndex, nextCheckpoint);
    }
    // Sort the last section of 'allWords' alphabetically
    sortWordSectionAlpha(wordLengthCheckpoints[lastCheckpoint] + 1, length - 1);
}
// Partitions a section of the list and sorts it alphabetically
// @param start: The starting index of the partition
// @param end: The last index of the partition
int Sorter::partitionAlphabetically(int start, int end) {
    int i = start - 1; // Acts as an index counter for all values below the pivot
                       // In this instance, the pivot value is the word at the very end of the section ('end')
    // 'j' acts as a counter that iterates throught the entire list
    for(int j = start; j < end; j++){
        // If the word at 'j' is lesser than the value at the pivot ('end'), then swap the word at 'j' with the word
        // at 'i', which theoretically should be at a lesser index than 'j'
        if(strcmp(allWords[j],allWords[end]) < 0){
            i++;
            swap(&allWords[i], &allWords[j]);
        }
    }
    // Swap the value at the next index of 'i' with the last element, so the pivot is at its right spot and all words
    // below the pivot are lesser than it alphabetically and all words above the pivot are greater than it
    // alphabetically
    swap(&allWords[i + 1], &allWords[end]);
    // Return the index of the of the given pivot
    return i + 1;
}
// Each part of the list will be sectioned off by checkpoints that 
// mark the end of a section of the list. Each section is based on 
// word length. It is this method's job to sort create those 
// checkpoints that will define those sections.
void Sorter::createAlphabeticalCheckpoints() {
    // Delete a pre-existing 'wordLengthCheckpoints' if there was one there
    // already
    if(wordLengthCheckpoints != nullptr) {
        delete[] wordLengthCheckpoints;
    }

    // The maximum word length is equal to the size of the last word of the
    // word-length sorted 'allWords'
    maxWordLength = strlen(allWords[length - 1]);
    wordLengthCheckpoints = new int[maxWordLength]; // 'wordLengthCheckpoints' will contain a checkpoint value for each
                                                    // word section, which are based on the length of every word
    int checkPointIndex = 0; // Acts as the counter for 'wordLengthCheckpoints'

    // Adds a checkpoint for every word section in 'allWords'
    for(int i = 0; i < length - 1; i++) {
        if (strlen(allWords[i + 1]) > strlen(allWords[i])) {
            wordLengthCheckpoints[checkPointIndex] = i;
            checkPointIndex++;
        }
    }
    lastCheckpoint = checkPointIndex - 1; // Grabs the last checkpoint for the last section of words
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