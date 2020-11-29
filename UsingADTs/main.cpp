#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>

using namespace std;

int main() {
    cout << "Hello, World!" << endl;

    stack<string> s;
    s.push("a");
    s.push("b");
    s.push("c");

    while (!s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }

    queue<string> q;
    q.push("W");
    q.push("X");
    q.push("Y");
    q.push("Z");

    while (!q.empty()) {
        cout << q.front() << " " << q.back() << endl;
        q.pop();
    }

    set<string> names;
    names.insert("Jane");
    names.insert("Aidan");
    names.insert("Gus");
    names.insert("Jane"); // does nothing
    names.insert("Nikash");

    names.erase("Gus");
    names.erase("Eliot"); // does nothing

    set<string>::iterator itr = names.begin();

    while (itr != names.end()) {
        cout << *itr << endl;
        itr++;
    }

    map<string, double> moneyMap;

    moneyMap.insert({"Eric", 6.5});
    moneyMap.insert({"Eliot", 0.03});
    moneyMap.insert({"Michael", 12.01});
    moneyMap.insert({"Heather", 85.35});

    map<string, double>::iterator itr2 = moneyMap.begin();

    while (itr2 != moneyMap.end()) {
        cout << itr2->first << " " << itr2->second << endl;
        itr2++;
    };

    moneyMap["Michael"] += 0.25;

    if (moneyMap.find("gus") != moneyMap.end()) {
        cout << "found gus";
    }



    return 0;

}
