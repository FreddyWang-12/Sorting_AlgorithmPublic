//
// Created by Frederick Wang on 3/5/20.
//

#ifndef S20_PA01_SORTING_SORTER_H
#define S20_PA01_SORTING_SORTER_H

#include "iostream"
#include "fstream"
using namespace std;

class Sorter {
    private:
        char ** allWords; // A char double array that will store all of the given words
        int length; // The length of allWords
        int * wordLengthCheckpoints; // A series of checkpoints meant to divide the list into sections
                                     // based on word length. After the list is sorted by word length,
                                     // individual indexes in the word list will be marked off as checkpoints.
                                     // These checkpoints mark the last instance of a particular word length,
                                     // so all of the one-letter words will be marked off as a section, all of
                                     // the two-letter words will be marked off as a section, etc.
        int lastCheckpoint; // The checkpoint of the words with the longest word length
        int beginning = 0; // The index of the first element of allWords
        int maxWordLength; // The length of the longest word
    public:
        Sorter(); // Default constructor of the Sorter Class

        void readWordFile(ifstream& inputFile);// Reads a text file and adds all of the words inside a char** array
                                               // @param inputFile: The file being read


        void sortWordsByWordLength(int start, int end);// Sorts all of the words in the list by their word length
                                                       // @param start: The starting index of the sort
                                                       // @param end: The last index of the sort

        void mergeByWordLength(int start, int middle, int end); // Takes a section of the overall word list (allWords), divides
                                                                // in half, and merges its two halves together based on ascending
                                                                // word length
                                                                // @param start: The starting index of the section in allWords
                                                                // @param middle: The middle index of the section in allWords
                                                                // @param end: The last index of the section in allWords


        void sortWordSectionAlpha(int start, int end); // Sorts a section of the list alphabetically based on word length
                                                       // Each part of the list will be sectioned off by checkpoints that
                                                       // mark the end of a section of the list. Each section is based on
                                                       // word length. It is this method's job to sort a individual section.
                                                       // @param start: The starting index of the sort
                                                       // @param end: The last index of the sort

        void sortAllWordsAlphabetically(); // Takes through all sections of the list (after being sorted by word length)
                                           // and sorts them all out alphabetically. These sections are determined by their
                                           // word length, so all 1-letter words will be sorted individually, all 2-letter
                                           // words will be sorted individually, etc.

        int partitionAlphabetically(int start, int end);// Partitions a section of the list and sorts it alphabetically
                                                        // @param start: The starting index of the partition
                                                        // @param end: The last index of the partition

        void createAlphabeticalCheckpoints(); // Each part of the list will be sectioned off by checkpoints that
                                              // mark the end of a section of the list. Each section is based on
                                              // word length. It is this method's job to sort create those
                                              // checkpoints that will define those sections.

        void swap(char** a, char** b); // Swaps the values of 2 of the elements inside allWords
                                       // @param i, j: The two elements being swapped


        void printSortedWordFile(ofstream& outputFile); // Creates an output file of all of the contents of the word list
                                                        // @param outputFile: The name of the output file

        int& getListLength(); // Returns the length of the word list
};


#endif //S20_PA01_SORTING_SORTER_H
