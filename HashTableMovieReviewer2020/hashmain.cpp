#include <iostream>
#include "shphashtable.h"
using namespace std;

int main() {
    cout << "Hello, Hash Table!" << endl;
    shphashtable names(23);
    names.put("Elsie");
    names.put("Nikash");
    names.put("Bollar");
    names.put("Brockett");
    names.put("KMo");
    names.put("Aidan");
    names.put("Heather");
    names.put("Sun");
    names.put("Eliot");
    names.put("Gus Gurley");
    names.put("Heller");
    names.put("Jacqueline");


    if (names.contains("Heather"))
        cout << "Heather = YES" << endl;
    if (!names.contains("Jose"))
        cout << "Jose = NO" << endl;

    names.printStats();
    return 0;
}