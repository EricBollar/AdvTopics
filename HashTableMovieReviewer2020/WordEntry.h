//
// Created by Eric Bollar on 11/19/20.
//

#ifndef HASHTABLEMOVIEREVIEWER_WORDENTRY_H
#define HASHTABLEMOVIEREVIEWER_WORDENTRY_H

#include <string>

using namespace std;

class WordEntry {
public:
    WordEntry();
    WordEntry(string str);
    string getString();
    double getAverageScore();
    void addNewScore(int score);
private:
    int scoreTotal;
    int numScores;
    string word;
};


#endif //HASHTABLEMOVIEREVIEWER_WORDENTRY_H
