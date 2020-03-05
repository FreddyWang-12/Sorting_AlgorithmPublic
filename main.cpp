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
    Sorter x;
    x.readWordFile(inputFile);
    x.printAllWords();
    inputFile.close();

    return 0;
}