#include <iostream>
#include <fstream>
#include "shplexicon.h"

using namespace std;

void findWordHelper(const char grid[5][5], shplexicon & words, int r, int c, string str) {
    string curr = str + grid[r][c];
    if (0 <= r < 5 && 0 <= c < 5 && words.containsPrefix(curr)) {
        if (str.length() >= 3 && words.containsWord(str)) {
            cout << str << endl;
        }
        for (int x = -1; x < 2; x++) {
            for (int y = -1; y < 2; y++) {
                if (x != 0 && y != 0) {
                    findWordHelper(grid, words, r + x, c + y, curr);
                }
            }
        }
    }
}

void printAllWords(const char grid[5][5], shplexicon & words) {
    for (int r = 0; r < 5; r++) {
        for (int c = 0; c < 5; c++) {
            findWordHelper(grid, words, r, c, "");
        }
    }
}

int main() {
    srand(time(nullptr));
    shplexicon words("words.txt");

    // your code here
    char grid[5][5];
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int r = 0; r < 5; r++) {
        for (int c = 0; c < 5; c++) {
            int i = rand() % alphabet.length();
            grid[r][c] = alphabet[i];
            alphabet = alphabet.substr(0, i) + alphabet.substr(i+1);
        }
    }
    cout << "Boggle Grid:" << endl;
    for (int r = 0; r < 5; r++) {
        for (int c = 0; c < 5; c++) {
            cout << grid[r][c];
        }
        cout << endl;
    }
    cout << endl;
    cout << "All Words:" << endl;
    printAllWords(grid, words);

    return 0;

}