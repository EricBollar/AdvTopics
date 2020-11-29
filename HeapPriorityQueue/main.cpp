#include <iostream>
#include "pqueue.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    pqueue students;
    students.push("Jane");
    students.push("Aidan");
    students.push("Gus");
    students.push("Eric");
    students.push("Eliot");
    return 0;
}
