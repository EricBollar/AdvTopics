#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>

using namespace std;

bool checkBalance(string str) {
    stack<char> s;
    for (int i = 0; i < str.length(); i++) {
        char ch = str[i];
        if (ch == '(' || ch == '{') {
            s.push(ch);
        } else if (ch == ')') {
            if (s.empty() || s.top() != '(') {
                return false;
            } else {
                s.pop();
            }
        } else if (ch == '}') {
            if (s.empty() || s.top() != '{') {
                return false;
            } else {
                s.pop();
            }
        }
    }
    return s.empty();
}

void showLetterFrequency() {
    ifstream infile("file.txt");
    map<char, int> freqMap;
    char ch;
    while (infile >> ch) {
        ch = toupper(ch);
        if (freqMap.find(ch) == freqMap.end()) {
            freqMap.insert({ch, 1});
        } else {
            freqMap.at(ch)++;
        }
    }
    map<char, int>::iterator itr = freqMap.begin();
    while (itr != freqMap.end()) {
        cout << itr->first << "=" << itr->second << endl;
        itr++;
    }
}

template <typename type>
set<type> unionSets(set<type> a, set<type> b) {
    set<type> out;
    for (type val : a) {
        out.insert(val);
    }
    for (type val : b) {
        out.insert(val);
    }
    return out;
}

template <typename type>
queue<type> reverse(queue<type> a) {
    queue<type> out;
    vector<type> temp;
    while (a.size() > 0) {
        temp.push_back(a.front());
        a.pop();
    }
    for (int i = temp.size() - 1; i >= 0; i--) {
        out.push(temp[i]);
    }
    return out;
}

template <typename ElemType>
set<ElemType> intersection(set<ElemType> x, set<ElemType> y) {
    set<ElemType> result;
    for (ElemType val : x) {
        if (y.find(val) != y.end()) {
            result.insert(val);
        }
    }
    return result;
}

template <typename type>
void printQueue(queue<type> a) {
    while (a.size() > 0) {
        cout << a.front() << ", ";
        a.pop();
    }
    cout << endl;
}

int main() {
    cout << "Hooray for ADTs!" << endl;

//    if (checkBalance("if (num < 0) { x = 3; } else { y = 4; }")) {
//        cout << "it balances" << endl;
//    } else {
//        cout << "it does not balance" << endl;
//    }

//    showLetterFrequency();

//    set<int> a;
//    for (int i = 1; i <= 5; i++) {
//        a.insert(i);
//    }
//    set<int> b;
//    for (int i = 3; i <= 10; i++) {
//        b.insert(i);
//    }
//    set<int> c = unionSets(a, b);
//    set<int>::iterator itr = c.begin();
//    while (itr != c.end()) {
//        cout << *itr << " ";
//        itr++;
//    }

    queue<int> a;
    for (int i = 1; i <= 10; i++) {
        a.push(i);
    }
    printQueue(a);
    queue<int> b = reverse(a);
    printQueue(b);

    return 0;
}