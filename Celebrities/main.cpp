//
// Eric Bollar, 9/10/20
//

#include <iostream>
#include <vector>
#include <fstream>
#include "Celebrity.h"

using namespace std;

vector<Celebrity> celebrities;

void loadCelebrities() {
    ifstream f("celebrities.txt");

    while (!f.eof()) {
        string line;
        getline(f, line);
        int colIndex = line.find(':');
        string name = line.substr(0, colIndex);
        string clues = line.substr(colIndex+1);
        Celebrity c(name, clues);
        celebrities.push_back(c);
    }
}

Celebrity getRandomCelebrity() {
    srand(time(0));
    int index = rand() % celebrities.size();
    Celebrity curr = celebrities[index];
    celebrities.erase(celebrities.begin()+index);
    return curr;
}

int main() {
    loadCelebrities();
    int points = 0;

    cout << "Welcome to Celebrities!" << endl;
    cout << "The goal is to earn as many points as possible!" << endl;
    cout << "Correct Guesses = +100 points, Incorrect Guesses = -50 points, Skips = -10 points" << endl;

    while (celebrities.size() > 0) {
        Celebrity curr = getRandomCelebrity();

        string guess;
        bool pass = false;

        cout << endl;
        cout << "Score: " << points << endl;
        cout << "Guess the celebrity! (Enter S to skip) Your clue: " << curr.getClue() << endl;
        getline(cin, guess);

        while (guess != curr.getName()) {
            if (guess == "S" || guess == "s") {
                pass = true;
                break;
            } else {
                cout << "Incorrect. -50 points!" << endl;
                points -= 50;
                cout << "Your next clue: " << curr.getClue() << endl;
                getline(cin, guess);
            }
        }

        if (!pass) {
            cout << "Correct! +100 points!" << endl;
            points += 100;
        } else {
            cout << "Skipped! -10 points!" << endl;
            points -= 10;
        }
    }

    cout << endl;
    cout << "GAME OVER!" <<  endl;
    return 0;
}