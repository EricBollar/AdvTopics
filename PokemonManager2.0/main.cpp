//
// Eric Bollar
// Advanced Topics in Computer Science, Period E
// 9/25/20
//

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

struct Node {
    string name;
    int num;
    Node* next;
};

void saveListTypeTwo(string filename, Node* list) {
    ofstream outfile(filename);

    for (Node *temp = list; temp != nullptr; temp = temp->next) {
        outfile << temp->num << " " << temp->name << endl;
    }

    outfile.close();
}

void saveListTypeOne(string filename, Node* list) {
    ofstream outfile(filename);

    for (Node *temp = list; temp != nullptr; temp = temp->next) {
        for (int i = 0; i < temp->num; i++) {
            outfile << temp->name << endl;
        }
    }

    outfile.close();
}

Node* findPokemon(Node* list, string name) {
    Node *temp = list;
    while (temp != nullptr) {
        if (temp->name == name) {
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}

void printPokemon(Node* head) {
    cout << "Pokémon List: ";
    Node *temp = head;
    if (temp == nullptr) {
        cout << "Empty!" << endl;
        return;
    }
    while (temp != nullptr) {
        cout << "[" << temp->name << ", " << temp->num << "] -> ";
        temp = temp->next;
    }
    cout << "End of list." << endl;
}

void addPokemon(string name, Node *& list, int num) {
    Node* temp = list;
    Node* prev = temp;
    if (list != nullptr && list->name == name) {
        list->num += num;
        if (list->num <= 0) {
            Node* temp = list;
            if (list->next != nullptr) {
                list = list->next;
            }
            delete temp;
        }
        return;
    }
    while (temp != nullptr) {
        if (temp->name == name) {
            temp->num += num;
            if (temp->num <= 0) {
                prev->next = temp->next;
                delete temp;
            }
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    if (num > 0) {
        Node *newPokemon = new Node;
        newPokemon->name = name;
        newPokemon->num = num;
        newPokemon->next = list;
        list = newPokemon;
    }
}

void loadFileTypeOne(string filename, Node *& list) {
    ifstream f(filename);

    while (!f.eof()) {
        string line;
        getline(f, line);
        addPokemon(line, list, 1);
    }
}

void loadFileTypeTwo(string filename, Node *& list) {
    ifstream f(filename);

    while (!f.eof()) {
        string line;
        getline(f, line);
        int colIndex = line.find(' ');
        int num = stoi(line.substr(0, colIndex));
        string name = line.substr(colIndex+1);
        addPokemon(name, list, num);
    }
}

int main() {
    cout << "Enter the name of a Pokémon file: ";
    string filename;
    getline(cin, filename);

    cout << "Please select the type of Pokémon file this is.\n"
            "1. One Pokémon card per line, multiple entries for multiple cards\n"
            "2. One type of Pokémon per line, preceded by the number in collection\n";
    cout << "Which type? ";
    int fileType;
    cin >> fileType;

    Node* list = nullptr;
    if (fileType == 1) {
        loadFileTypeOne(filename, list);
    } else if (fileType == 2) {
        loadFileTypeTwo(filename, list);
    } else {
        cout << "Sorry, an error occured." << endl;
        return 0;
    }

    int choice = -1;
    while (choice != 6) {
        cout << " 1. I want to add a Pokémon to my collection.\n"
                " 2. I want to remove a Pokémon from my collection.\n"
                " 3. I want to lookup a Pokémon in my collection.\n"
                " 4. I want to view all the Pokémon in my collection.\n"
                " 5. I want to save changes.\n"
                " 6. Quit" << endl;
        cout << "Enter a choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Enter the name of the new Pokémon: ";
                string name;
                cin >> name;
                cout << "Enter the number of " << name << "s you want to add: ";
                int num;
                cin >> num;
                if (num > 0) {
                    addPokemon(name, list, num);
                }
                cout << "Operation completed." << endl;
                break;
            }
            case 2: {
                cout << "Enter the name of the Pokémon: ";
                string name;
                cin >> name;
                cout << "Enter the number of " << name << "s you want to remove: ";
                int num;
                cin >> num;
                if (num > 0) {
                    addPokemon(name, list, -num);
                }
                cout << "Operation completed." << endl;
                break;
            }
            case 3: {
                cout << "Enter the name of the Pokémon: ";
                string name;
                cin >> name;
                Node* ptr = findPokemon(list, name);
                if (ptr != nullptr) {
                    cout << "You have " << ptr->num << " Pokémon named " << name << "." << endl;
                } else {
                    cout << "You don't have any Pokémon named " << name << "." << endl;
                }
                break;
            }
            case 4: {
                printPokemon(list);
                break;
            }
            case 5: {
                if (fileType == 1) {
                    saveListTypeOne(filename, list);
                } else {
                    saveListTypeTwo(filename, list);
                }
                cout << "File saved!" << endl;
                break;
            }
            default: {
                choice = 6;
                cout << "Exiting..." << endl;
            }
        }
    };

    return 0;
}