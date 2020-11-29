#include <iostream>

using namespace std;

bool isPrime(int num) {
    for (int i=2; i<num; i++) {
        if (num % i == 0)
            return false;
    }
    return true;
}

int main() {
    cout << "This program determines if a number is prime or not." << endl;
    cout << "(Enter zero to quit.)" << endl;
    int num;
    cout << "Enter a number: ";
    cin >> num;
    while (num != 0) {
        if (isPrime(num))
            cout << num << " is a prime number!" << endl;
        else
            cout << num << " is NOT a prime number." << endl;
        cout << "Enter a number: ";
        cin >> num;
    }
    cout << "Have a nice day!" << endl;
    return 0;
}