//
// Eric Bollar, 9/10/20
//

#include "Celebrity.h"

Celebrity::Celebrity(string name, string clues) {
    this->name = name;
    string curr = "";
    for (int i = 0; i < clues.length(); i++) {
        if (clues[i] == ',') {
            this->clues.push_back(curr);
            curr = "";
        } else {
            curr += clues[i];
        }
    }
    this->clues.push_back(curr);
}

string Celebrity::getName() {
    return this->name;
}

string Celebrity::getClue() {
    if (clues.size() <= 0) {
        return "No more clues.";
    }
    srand(0);
    int index = rand() % clues.size();
    string clue = clues[index];
    clues.erase(clues.begin()+index);
    return clue;
}