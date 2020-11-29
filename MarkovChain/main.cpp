#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <vector>
using namespace std;

string getSeed(map<string, vector<char>> m) {
    string seed = "";
    int max = 0;
    for (map<string, vector<char>>::iterator itr = m.begin(); itr != m.end(); itr++)
    {
        if (itr->second.size() > max) {
            seed = itr->first;
            max = itr->second.size();
        }
    }
    return seed;
}

void buildMap(map<string, vector<char>> & m, ifstream & f, int l) {
    string key = "";
    char ch;
    while (f >> noskipws >> ch) {
        if (key.length() == l) {
            m[key].push_back(ch);
            key = key.substr(1);
        }
        key += ch;
    }
}

int main() {
    srand(time(0));
    cout << "Hello, Markov Chain!" << endl;
    cout << "Enter level (1-10): ";
    int level;
    cin >> level;
    cout << "Enter file name: ";
    string filename;
    cin >> filename;
    // finish this up

    cout << "Generated Markov Chain:" << endl;

    map<string, vector<char>> m;
    ifstream f(filename);
    buildMap(m, f, level);

    string s = getSeed(m);
    int totalCharacters = 2000;
    int generatedCharacters = level;

    cout << s;
    while (generatedCharacters < totalCharacters) {
        int index = rand() % m[s].size();
        char next = m[s].at(index);
        cout << next;
        generatedCharacters++;
        s += next;
        s = s.substr(1);
    }

    return 0;
}
