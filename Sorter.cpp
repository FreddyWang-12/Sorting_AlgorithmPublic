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
}

void Sorter::readWordFile(ifstream& inputFile){
    if(inputFile.is_open()){
        char number[20];
        inputFile.getline(number, 20, '\n');
        length = atoi(number);

        char word[70];
        for(int i = 0; i < length; i++){
            inputFile.getline(word, 70, '\n');
            DSString newWord(word);
            allWords.push_back(newWord);
        }
    }
    else{
        cout << "Good Try! Now put in an actual file that exists, you dummy." << endl;
    }
}

void Sorter::sortWordsByWordLength(int start, int end){
    if(!allWords.isEmpty()) {
        if (start < end) {
            int pivotPoint = partitionByWordLength(start, end);
            sortWordsByWordLength(start, pivotPoint - 1);
            sortWordsByWordLength(pivotPoint + 1, end);
        }
    }
}

void Sorter::sortWordsAlphabetically(){

}

void Sorter::printSortedWordFile(ofstream& outputFile){
    outputFile << length << endl;
    for(int i = 0; i < length; i++){
        outputFile << allWords[i].c_str() << endl;
    }
}

void Sorter::swap(int i, int j) {
    DSString temp = allWords[i];
    allWords[i] = allWords[j];
    allWords[j] = temp;
}

int Sorter::getListLength() {
    return length;
}

int Sorter::partitionByWordLength(int start, int end) {
    int i = start - 1;
    for(int j = start; j < end; j++) {
        if (allWords[j].getLength() < allWords[end].getLength()){
            i++;
            swap(i, j);
        }
    }
    i++;
    swap(i, end);
    return i;
}