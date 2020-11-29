#include <iostream>
using namespace std;

int main() {
    cout << "An example program involving pointers" << endl;

    int num;
    string word;
    num = 7;
    word = "banana";
    cout << num << " " << word << endl;

    int *a, *b;

    a = new int;
    *a = 10;

    cout << *a << endl;
    cout << a << endl;
    cout << endl;

    b = new int;
    *b = *a;

    cout << *b << endl;
    cout << b << endl;
    cout << endl;

    int *c;
    c = a;

    cout << *c << endl;
    cout << c << endl;
    cout << endl;

    *a = 15;
    cout << *c << endl;
    cout << c << endl;
    cout << endl;

    delete b;
    b = new int;
    *b = 7;

    b = a;

    delete a;
    a = nullptr;

    cout << *b << endl;
    cout << *c << endl;

    c = nullptr;

    return 0;
}