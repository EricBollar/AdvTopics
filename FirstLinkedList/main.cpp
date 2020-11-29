#include <iostream>
#include <fstream>
#include <stack>
#include <queue>
#include <set>
#include <map>

using namespace std;

struct Node {
    int value;
    Node *next;
};

void printList(Node *list) {
    Node *temp = list;
    while (temp != nullptr) {
        cout << temp->value << "->";
        temp = temp->next;
    }
    cout << endl;
}

Node* splice(Node * &list, int spliceNumber) {
    Node *temp = list;
    if (temp == nullptr) {
        return nullptr;
    }
    if (temp->value == spliceNumber) {
        list = nullptr;
        return temp->next;
    }
    while (temp->next != nullptr) {
        if (temp->next->value == spliceNumber) {
            Node* save = temp->next->next;
            delete temp->next;
            temp->next = nullptr;
            return save;
        }
        temp = temp->next;
    }
}

void moveToFront(Node * &list, int goodNumber) {
    Node *temp = list;
    Node *prev = temp;
    while (temp != nullptr) {
        if (temp->value == goodNumber) {
            Node* step = temp->next;
            temp->next = list;
            prev->next = step;
            list = temp;
            temp = step;
        } else {
            prev = temp;
            temp = temp->next;
        }
    }
}

bool mostlyEven(Node *list) {
    int numEven = 0;
    int total = 0;

    Node *temp = list;
    while (temp != nullptr) {
        total++;
        if (temp->value % 2 == 0) {
            numEven++;
        }
        temp = temp->next;
    }

    return (numEven * 1.0 / total > 0.5);
}

void insertInOrder(Node *&list, int value) {
    if (list == nullptr) {
        list = new Node;
        list->value = value;
        list->next = nullptr;
        return;
    }
    if (list->value >= value) {
        Node *temp = new Node;
        temp->value = value;
        temp->next = list;
        list = temp;
        return;
    }
    Node *curr = list;
    Node *after = list->next;
    while (after != nullptr) {
        if (curr->value <= value && after->value >= value) {
            Node *temp = new Node;
            temp->value = value;
            curr->next = temp;
            temp->next = after;
            return;
        }
        curr = curr->next;
        after = after->next;
    }
    Node *temp = new Node;
    temp->value = value;
    temp->next = nullptr;
    curr->next = temp;
}

void stutter(Node *list) {
    if (list == nullptr) {
        return;
    }
    Node *temp = list;
    while (temp != nullptr) {
        Node *dupl = new Node;
        dupl->value = temp->value;
        dupl->next = temp->next;
        temp->next = dupl;
        temp = temp->next->next;
    }
}

void removeDuplicates(Node *& list) {
    if (list == nullptr) {
        return;
    }
    if (list->next == nullptr) {
        return;
    }
    Node* front = list->next;
    Node* back = list;
    while (front != nullptr) {
        if (front->value == back->value) {
            front = front->next;
            delete back->next;
            back->next = front;
        } else {
            front = front->next;
            back = back->next;
        }
    }
}

void reverse(Node *& list) {
    Node* current = list;
    Node *prev = nullptr;
    Node *next = nullptr;

    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    list = prev;
}

void doubleList(Node *list) {
    if (list == nullptr) {
        return;
    }
    Node *copy = new Node;
    copy->value = list->value;
    Node *temp = list->next;
    Node *curr = copy;
    while (temp != nullptr) {
        curr->next = new Node;
        curr->next->value = temp->value;
        temp = temp->next;
        curr = curr->next;
    }
    curr->next = nullptr;
    temp = list;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = copy;
}

Node* searchListPtr(Node *list, int value) {
    Node *temp = list;
    while (temp != nullptr) {
        if (temp->value == value) {
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}

int searchListInd(Node *list, int value) {
    int pos = 0;
    Node *temp = list;
    while (temp != nullptr) {
        if (temp->value == value) {
            return pos;
        }
        pos++;
        temp = temp->next;
    }
    return -1;
}

void removeDoubleDigits(Node *&list) {
    while (list != nullptr && list->value >= 10 && list->value <= 99) {
        Node *save = list;
        list = list->next;
        delete save;
    }

    if (list == nullptr) {
        return;
    }

    Node *temp = list;
    while (temp->next != nullptr) {
        if (temp->next->value >= 10 && temp->next->value <= 99) {
            Node *save = temp->next;
            temp->next = save->next;
            delete save;
        } else {
            temp = temp->next;
        }
    }
}

void makeCircular(Node *list) {
    if (list == nullptr) {
        return;
    }
    Node *temp = list;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = list;
}

void deleteLast(Node *&list) {
    if (list == nullptr) {
        return;
    }
    if (list->next == nullptr) {
        delete list;
        list = nullptr;
        return;
    }
    Node *temp = list;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
}

int sumList(Node *list) {
    Node *temp = list;
    int result = 0;
    while (temp != nullptr) {
        result += temp->value;
        temp = temp->next;
    }
    return result;
}

int length(Node *head) {
    int counter = 0;
    Node *temp = head;
    while (temp != nullptr) {
        counter++;
        temp = temp->next;
    }
    return counter;
}

void destroyList(Node *&list) {
    while (list != nullptr) {
        Node *save = list;
        list = list->next;
        delete save;
    }
}

Node* buildList(ifstream & infile) {
    Node *list = nullptr;
    int num;
    while (infile >> num) {
        Node *temp = new Node;
        temp->value = num;
        temp->next = list;
        list = temp;
    }
    return list;
}

map<string, set<string>> getAreaCodeMap(map<string, string> &directoryMap) {
    map<string, set<string>> out;
    map<string, string>::iterator itr;
    for (itr = directoryMap.begin(); itr != directoryMap.end(); itr++) {
        string code = itr->second.substr(0, 3);
        string name = itr->first;
        if (out.find(code) != out.end()) {
            out.find(code)->second.insert(name);
        } else {
            set<string> names = { name };
            out.insert({code, names});
        }
    }
    return out;
};

bool uniqueFronts(set<queue <string>> &setOfQueues) {
    set<queue <string>>::iterator itr;
    set<string> fronts;
    for (itr = setOfQueues.begin(); itr != setOfQueues.end(); itr++) {
        string front = itr->front();
        if (fronts.find(itr->front()) != fronts.end()) {
            return false;
        }
        fronts.insert(itr->front());
    }
    return true;
}

void removeAllBottomValues(stack<int> &theStack) {
    stack<int> out;
    while (!theStack.empty()) {
        out.push(theStack.top());
        theStack.pop();
    }
    int val = out.top();
    while (!out.empty()) {
        if (out.top() != val) {
            theStack.push(out.top());
        }
        out.pop();
    }
}

int main() {

//    stack<int> test;
//    test.push(3);test.push(2);test.push(3);test.push(4);test.push(3);test.push(5);test.push(6);test.push(7);test.push(1);
//    stack<int> before = test;
//    while (!before.empty()) {
//        cout << before.top() << " ";
//        before.pop();
//    }
//    cout << endl;
//    removeAllBottomValues(test);
//    while (!test.empty()) {
//        cout << test.top() << " ";
//        test.pop();
//    }

//    set<queue <string>> test;
//    queue<string> temp; temp.push("hey"); test.insert(temp);
//    queue<string> temp1; temp1.push("hey2"); test.insert(temp1);
//    queue<string> temp2; temp2.push("hey3"); test.insert(temp2);
//    queue<string> temp3; temp3.push("hey"); temp3.push("test"); test.insert(temp3);
//
//    set<queue <string>>::iterator itr;
//    for (itr = test.begin(); itr != test.end(); itr++) {
//        cout << itr->front() << " ";
//    }
//    if (uniqueFronts(test)) {
//        cout << "true";
//    } else {
//        cout << "false";
//    }

//    map<string, string> test;
//    test.insert({"A", "650-969-2459"});
//    test.insert({"B", "650-969-2459"});
//    test.insert({"C", "408-969-2459"});
//    test.insert({"D", "555-969-2459"});
//    map<string, set<string>> vals = getAreaCodeMap(test);
//
//    map<string, set<string>>::iterator itr;
//    for (itr = vals.begin(); itr != vals.end(); itr++) {
//        set<string>::iterator itr2;
//        cout << itr->first << ": ";
//        for (itr2 = itr->second.begin(); itr2 != itr->second.end(); itr2++) {
//            cout << *itr2 << " ";
//        }
//        cout << endl;
//    }

    return 0;
}
