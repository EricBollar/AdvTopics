// Eric Bollar
// Sep 8, 2020

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

struct RoomAssignment {
    string teacher;
    int number;
};

vector<RoomAssignment> assignments;

void loadAssignments() {
    ifstream f("rooms.txt");

    while (!f.eof()) {
        int num;
        string teacher;
        f >> num;
        getline(f, teacher);
        RoomAssignment ra;
        ra.number = num;
        ra.teacher = teacher;
        assignments.push_back(ra);
    }
}

int getChoice() {
    cout << "1 = Search by room" << endl;
    cout << "2 = Search by teacher" << endl;
    cout << "3 = Quit" << endl;
    while (true) {
        cout << "Your choice: ";
        int choice;
        cin >> choice;
        if (choice >=  1 && choice <= 3) {
            return choice;
        }
    }
}

void searchByRoom() {
    int num;
    cout << "Enter a room number: ";
    cin >> num;
    cout << "Teachers: ";
    for (int i = 0; i < assignments.size(); i++) {
        if (assignments.at(i).number == num) {
            cout << assignments.at(i).teacher.substr(1) << " ";
        }
    }
    cout << endl;
    cout << endl;
}

void searchByTeacher() {
    string name;
    cout << "Enter a teacher's name: ";
    cin >> name;
    cout << "Room #'s: ";
    for (int i = 0; i < assignments.size(); i++) {
        if (assignments.at(i).teacher.substr(1) == name) {
            cout << assignments.at(i).number << " ";
        }
    }
    cout << endl;
    cout << endl;
}

int main() {
    loadAssignments();
    while (true) {
        int choice = getChoice();
        if (choice == 1) {
            searchByRoom();
        } else if (choice == 2) {
            searchByTeacher();
        } else {
            break;
        }
    }
    cout << "Goodbye" << endl;
    return 0;
}