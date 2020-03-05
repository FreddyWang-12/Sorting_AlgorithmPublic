#include <iostream>
#include <fstream>
#include "Sorter.h"
#include "DSString.h"
#include "DSVector.h"
#include "iostream"
#include "fstream"
using namespace std;

int main(int argc, char* argv[]){

    ifstream inputFile(argv[1]);
    ofstream outputFile(argv[2]);
    Sorter x;
    x.readWordFile(inputFile);
    x.printSortedWordFile(outputFile);
    inputFile.close();

    return 0;
}