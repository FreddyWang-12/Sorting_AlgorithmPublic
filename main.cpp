#include <iostream>
#include <fstream>
#include "Sorter.h"
#include "iostream"
#include "fstream"
#include "stdio.h"
using namespace std;

int main(int argc, char* argv[]){

    ifstream inputFile(argv[1]);
    ofstream outputFile(argv[2]);
    Sorter x;
    x.readWordFile(inputFile);

    x.sortWordsByWordLength(0, x.getListLength() - 1);
    x.createAlphabeticalCheckpoints();
    x.sortAllWordsAlphabetically();

    x.printSortedWordFile(outputFile);
    inputFile.close();

    return 0;
}