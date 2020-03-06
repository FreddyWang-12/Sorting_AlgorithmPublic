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
    if(!allWords.isEmpty()){
        // In progress
        /*for(int i = 0; i < length - 1; i++){
            for(int j = i+ 1; j < length; j++){
                if(allWords[i].getLength() == allWords[j].getLength()){
                    DSString temp = allWords[i];
                    allWords[i] = allWords[j];
                    allWords[j] = temp;
                }
            }
        }*/
    }
    else{
        cout << "There are no words here, dummy." << endl;
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