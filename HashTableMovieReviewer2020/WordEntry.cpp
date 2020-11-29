//
// Created by Eric Bollar on 11/19/20.
//

#include "WordEntry.h"

WordEntry::WordEntry() {
    WordEntry("");
}

WordEntry::WordEntry(string str) {
    numScores = 0;
    scoreTotal = 0;
    word = str;
}

string WordEntry::getString() {
    return word;
}

double WordEntry::getAverageScore() {
    return 1.0 * scoreTotal / numScores;
}

void WordEntry::addNewScore(int score) {
    numScores++;
    scoreTotal += score;
}
