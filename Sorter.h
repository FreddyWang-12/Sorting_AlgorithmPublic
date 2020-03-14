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
        char ** allWords;
        int length;
        int * wordLengthCheckpoints;
        int lastCheckpoint;
        int beginning = 0;
        int maxWordLength;
    public:
        Sorter();
        void readWordFile(ifstream& inputFile);

        void sortWordsByWordLength(int start, int end); //pass by reference
        int partitionByWordLength(int start, int end);

        void sortWordSectionAlpha(int start, int end); // pass by reference
        void sortAllWordsAlphabetically();
        int partitionAlphabetically(int start, int end);
        void createAlphabeticalCheckpoints();

        void swap(char *&i, char *&j);

        void printSortedWordFile(ofstream& outputFile);
        int& getListLength();
};


#endif //S20_PA01_SORTING_SORTER_H
