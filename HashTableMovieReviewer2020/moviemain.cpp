#include <iostream>
#include <fstream>
#include "shphashtable.h"

using namespace std;

int main() {
    cout << "Hello, Movie Reviews!" << endl;

    shphashtable reviews(8529);
    ifstream f("reviews.txt");
    while (!f.eof()) {
        string line;
        getline(f, line);
        int score = stoi(line.substr(0, 1));
        int spaceInd = line.find(' ');
        while (spaceInd != -1) {
            string word = line.substr(0, spaceInd);
            if (word.length() >= 2) {
                WordEntry newWord(word);
                reviews.put(newWord, score);
            }
            line = line.substr(spaceInd + 1);
            spaceInd = line.find(' ');
        }
    }

    reviews.printStats();
    cout << "Your Review: ";
    string review;
    getline(cin, review);
    cout << "Your Score (1-5): ";
    int score;
    cin >> score;

    int numWords = 0;
    double sumAverages = 0.0;
    int spaceInd = review.find(' ');
    while (spaceInd != -1) {
        WordEntry word(review.substr(0, spaceInd));
        if (reviews.contains(word)) {
            sumAverages += reviews.getAverage(word.getString());
            numWords++;
        }
        review = review.substr(spaceInd + 1);
        spaceInd = review.find(' ');
    }

    double prediction = 2.0;
    if (numWords > 0) {
        prediction = sumAverages / numWords + 1;
    }
    cout << "Predicted Score: " << prediction << " out of 5" << endl;

    return 0;
}