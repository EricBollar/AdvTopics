#include <iostream>
#include "shpvector.h"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    shpvector<string> vec;
    vec.push_back("hey");
    vec.push_back("hey2");
    vec.push_back("hey3");
    for (int i = 0; i < vec.size(); i++) {
        cout << vec.at(i) << endl;
    }
    return 0;
}
