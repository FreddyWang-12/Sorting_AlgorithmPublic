//
// Created by Frederick Wang on 3/5/20.
//

#ifndef S20_PA01_SORTING_SORTER_H
#define S20_PA01_SORTING_SORTER_H

#include "DSVector.h"
#include "DSString.h"
#include "iostream"
#include "fstream"
using namespace std;

class Sorter {
    private:
        DSVector<DSString> allWords;
        int length;
    public:
        Sorter();
        void readWordFile(ifstream& inputFile);
        void sortWordsByWordLength();
        void sortWordsAlphabetically();
        void printSortedWordFile(ofstream& outputFile);
        void swap(int i, int j);
};


#endif //S20_PA01_SORTING_SORTER_H
