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

void Sorter::sortWordsByWordLength(){
    
}

void Sorter::sortWordsAlphabetically(){

}

void Sorter::printSortedWordFile(ofstream outputFile){

}

void Sorter::printAllWords() {
    for(int i = 0; i < 12; i++){
        allWords[i].print();
    }
}