#include <iostream>
#include <fstream>
#include "Sorter.h"
#include "iostream"
#include "fstream"
using namespace std;

int main(int argc, char* argv[]){

    ifstream inputFile(argv[1]);
    ofstream outputFile(argv[2]);
    Sorter x;
    x.readWordFile(inputFile);

    int beginning = 0;
    int endpoint = x.getListLength() - 1;
    x.sortWordsByWordLength(beginning, endpoint);
    x.createAlphabeticalCheckpoints();
    x.sortAllWordsAlphabetically();
    x.printSortedWordFile(outputFile);
    inputFile.close();

    return 0;
}