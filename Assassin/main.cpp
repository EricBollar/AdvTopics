#include <iostream>

using namespace std;

struct DNode {
    string name;
    int numKills;
    DNode *next;
    DNode *prev;
};

DNode* buildList() {
    string name;
    getline(cin, name);
    DNode *head = new DNode;
    head->name = name;
    head->numKills = 0;
    head->next = nullptr;
    head->prev = nullptr;
    DNode *last = head;
    getline(cin, name);
    while (name != "") {
        DNode *temp = new DNode;
        temp->name = name;
        temp->numKills = 0;
        temp->next = head;
        head->prev = temp;
        temp->prev = nullptr;
        head = temp;
        getline(cin, name);
    }
    head->prev = last;
    last->next = head;
    return head;
}

void killSomeone (DNode *dead) {
    dead->prev->numKills++;
    cout << dead->name << "(" << dead->numKills <<
    ") was killed by " << dead->prev->name <<
    "(" << dead->prev->numKills << ")" << endl;
    dead->prev->next = dead->next;
    dead->next->prev = dead->prev;
    delete dead;
}

int main() {
    cout << "Welcome to Assassin!" << endl;
    cout << "Enter names of players, one per line." << endl;
    cout << "Enter a blank line to quit." << endl;
    DNode *head = buildList();

    /*
    DNode *temp = head->next;
    cout << head->name << "->";
    while (temp != head) {
        cout << temp->name << "->";
        temp = temp->next;
    }*/

    cout << "Who died?" << endl;
    string deadPerson;
    getline(cin, deadPerson);
    DNode *temp = head;
    bool foundSomeone = false;
    if (head->name == deadPerson) {
        head = head->next;
        killSomeone(temp);
    }
    while (temp != head) {
        if (temp->name != deadPerson) {
            temp = temp->next;
        } else {
            foundSomeone = true;
            break;
        }
    }

    if (foundSomeone) {
        killSomeone(temp);
    } else {
        cout << "No living player named " << deadPerson << endl;
    }
    return 0;
}
