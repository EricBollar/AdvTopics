#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

vector<string> loadWords();
int showChoiceMenu();
void handleWordLengthMap(const vector<string> &words);
void handleFirstLetterMap(const vector<string> &words);
void handleFirstLetterSetMap(const vector<string> &words);
void handleWordCountMap(const vector<string> &words);
void handleUniqueWordSet(const vector<string> &words);

map<string, int> createWordLengthMap(const vector<string> &words);
map<string, char> createFirstLetterMap(const vector<string> &words);
map<char, set<string>> createFirstLetterSetMap(const vector<string> &words);
map<string, int> createWordCountMap(const vector<string> &words);
set<string> createUniqueWordSet(const vector<string> &words);

int main() {
    cout << "Let's get more practice with maps!" << endl;
    vector<string> words = loadWords();
    int choice = showChoiceMenu();
    while (choice != 5) {
        switch (choice) {
            case 0:
                handleWordLengthMap(words);
                break;
            case 1:
                handleFirstLetterMap(words);
                break;
            case 2:
                handleFirstLetterSetMap(words);
                break;
            case 3:
                handleWordCountMap(words);
                break;
            case 4:
                handleUniqueWordSet(words);
                break;
            default:
                cout << "Unknown choice" << endl;
        }
         choice = showChoiceMenu();
    }
    return 0;
}

int showChoiceMenu() {
    cout << "   0) Create word length map" << endl;
    cout << "   1) Create first letter map" << endl;
    cout << "   2) Create first letter set map" << endl;
    cout << "   3) Create word count map" << endl;
    cout << "   4) Get unique word set" << endl;
    cout << "   5) Quit" << endl;
    int choice = -1;
    while (choice < 0 || choice > 5) {
        cout << "   Enter your choice: ";
        cin >> choice;
    }
    return choice;
}

vector<string> loadWords() {
    vector<string> result;
    result.push_back("cat");
    result.push_back("dog");
    result.push_back("mouse");
    result.push_back("moose");
    result.push_back("dog");
    result.push_back("platypus");
    result.push_back("dog");
    result.push_back("elephant");
    result.push_back("chicken");
    result.push_back("cat");
    result.push_back("dog");
    result.push_back("pigeon");
    result.push_back("panda");
    result.push_back("pangolin");
    result.push_back("porcupine");
    result.push_back("pig");
    result.push_back("chicken");
    result.push_back("chicken");
    return result;
}

void handleWordLengthMap(const vector<string> &words) {
    map<string, int> m = createWordLengthMap(words);

   for (auto itr = m.begin(); itr != m.end(); itr++){
        cout << itr->first << " ---> " << itr->second << endl;
    }
}
void handleFirstLetterMap(const vector<string> &words) {
    map<string, char> m = createFirstLetterMap(words);

    for (auto itr = m.begin(); itr != m.end(); itr++){
        cout << itr->first << " ---> " << itr->second << endl;
    }
}

void handleFirstLetterSetMap(const vector<string> &words) {
    map<char, set<string>> m = createFirstLetterSetMap(words);

    for (auto itr = m.begin(); itr != m.end(); itr++){
        cout << itr->first << " ---> ";
        string str;
        for (string w : itr->second)
            str += w + ", ";
        cout << str.substr(0, str.length()-2) << endl;
    }
}

void handleWordCountMap(const vector<string> &words) {
    map<string, int> m = createWordCountMap(words);

    for (auto itr = m.begin(); itr != m.end(); itr++){
        cout << itr->first << " ---> " << itr->second << endl;
    }
}
void handleUniqueWordSet(const vector<string> &words) {
    set<string> uniques = createUniqueWordSet(words);
    string str;
    for (string w : uniques)
        str += w + ", ";
    cout << str.substr(0, str.length()-2) << endl;
}

/* YOU FINISH THE FUNCTIONS BELOW */
map<string, int> createWordLengthMap(const vector<string> &words) {
    map<string, int> m;
    for (string word : words) {
        m[word] = word.length();
    }
    return m;
}

map<string, char> createFirstLetterMap(const vector<string> &words) {
    map<string, char> m;
    for (string word : words) {
        m[word] = word[0];
    }
    return m;
}

map<char, set<string>> createFirstLetterSetMap(const vector<string> &words) {
    map<char, set<string>> m;
    for (string word : words) {
        char f = word[0];
        m[f].insert(word);
    }
    return m;
}

map<string, int> createWordCountMap(const vector<string> &words) {
    map<string, int> m;
    for (string word : words) {
        m[word]++;
    }
    return m;
}

set<string> createUniqueWordSet(const vector<string> &words) {
   
}