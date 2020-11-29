#include <iostream>
#include "shplexicon.h"

using namespace std;

int main() {
    cout << "Hello, SHP Lexicon!" << endl;
    shplexicon words("words.txt");

    // test your shplexicon class here
    if (words.containsWord("doG")) {
        cout << "yes";
    } else {
        cout << "no";
    }
    cout << words.size();
    words.removeWord("dog");
    if (words.containsWord("dOg")) {
        cout << "yes";
    } else {
        cout << "no";
    }
    cout << words.size();

    set<string> prefixWords = words.getWordsWithPrefix("dog");
    for (auto itr = prefixWords.begin(); itr != prefixWords.end(); itr++) {
        cout << *itr << " ";
    }

    return 0;
}