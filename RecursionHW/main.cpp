#include <iostream>
#include <cctype>

using namespace std;

struct Node {
    int val;
    Node* next;
};

string replaceAll(string str, char orig, char replacement) {
    if (str.size() <= 0) {
        return "";
    }
    if (str[0] == orig) {
        return replacement + replaceAll(str.substr(1), orig, replacement);
    }
    return str[0] + replaceAll(str.substr(1), orig, replacement);
}

string toUpperString(string str) {
    if (str.size() <= 1) {
        return "" + putchar(toupper(str[0]));
    }
    return "" + putchar(toupper(str[0])) + toUpperString(str.substr(1));
}

int sumList(Node* list) {
    if (list == nullptr) {
        return 0;
    }
    return list->val + sumList(list->next);
}

int numDigits(int num) {
    if (num < 10) {
        return 1;
    }
    return 1 + numDigits(num/10);
}

int triangular(int base) {
    if (base <= 1) {
        return 1;
    }
    return base + triangular(base - 1);
}

int main() {
    cout << toUpperString("hellothere");
    return 0;
}
