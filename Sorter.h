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
    public:
        Sorter();
        void readWordFile(ifstream& inputFile);
        void sortWordsByWordLength(int &start, int &end); //pass by reference
        void sortWordSectionAlpha(int &start, int &end); // pass by reference
        void sortAllWordsAlphabetically();
        void printSortedWordFile(ofstream& outputFile);
        void swap(int i, int j);
        int& getListLength();
        int partitionByWordLength(int &start, int &end);
        int partitionAlphabetically(int &start, int &end);
        void createAlphabeticalCheckpoints();
};


#endif //S20_PA01_SORTING_SORTER_H
