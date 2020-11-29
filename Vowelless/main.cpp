#include <iostream>
#include <vector>

using namespace std;

bool isVowel(char ch) {
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

string makeVowelles(string str) {
    string result = "";
    for (int i = 0; i < str.size(); i++) {
        char ch = str[i];
        if (!isVowel(ch) && isalpha(ch)) {
            result += toupper(ch);
        }
    }
    return result;
}

int main() {
    srand(time(0));
    cout << "Hello, World!" << endl;
    vector<string> phrases;
    phrases.push_back("summer vacation");
    phrases.push_back("have a nice day");
    phrases.push_back("gus gurley");
    phrases.push_back("aidan pereira");

    cout << "How many times would you like to play? ";
    int numTimes;
    cin >> numTimes;
    string bogus;
    getline(cin, bogus);

    for(int i = 0; i < numTimes; i++) {
        int index = rand() % phrases.size();
        string answer = phrases.at(index);
        string clue = makeVowelles(answer);
        cout << "Here's your clue: " << clue << endl;
        cout << "Enter your guess: ";
        string guess;
        getline(cin, guess);

        if (guess == answer) {
            cout << "Correct!" << endl;
        } else {
            cout << "Wrong! The correct answer was " << answer << "." << endl;
        }
    }
    cout << "Thanks for playing!" << endl;
    return 0;
}
