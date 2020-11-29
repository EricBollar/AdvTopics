#include <iostream>
#include <fstream>
#include <string>
#include <stack>

using namespace std;

struct TreeNode {
    string value;
    TreeNode *left;
    TreeNode *right;
    TreeNode(string val) {
        value = val;
        left = nullptr;
        right = nullptr;
    }
    TreeNode() {
        left = nullptr;
        right = nullptr;
    }
};

void loadFile(TreeNode *& tree, ifstream & infile) {
    stack<TreeNode*> questions;
    while (!infile.eof()) {
        string line;
        getline(infile, line);
        TreeNode* curr = new TreeNode(line.substr(1));

        if (line[0] == 'Q') {
            if (questions.size() > 0) {
                if (questions.top()->left == nullptr) {
                    questions.top()->left = curr;
                } else {
                    questions.top()->right = curr;
                }
            } else {
               tree = curr;
            }
            questions.push(curr);
        } else if (line[0] == 'A') {
            if (questions.top()->left == nullptr) {
                questions.top()->left = curr;
            } else {
                questions.top()->right = curr;
                while (questions.size() > 0 && questions.top()->right != nullptr) {
                    questions.pop();
                }
            }
        }
    }
}

// must manually delete last line of new file (it makes a new line at the end which breaks loadFile function)
void saveFile(TreeNode *& tree, string fileName) {
    ofstream file(fileName);
    stack<TreeNode*> questions;
    TreeNode* temp = tree;
    while (temp->right != nullptr && temp->left != nullptr || questions.size() > 0) {
        if (temp->right == nullptr && temp->left == nullptr) {
            file << "A" << temp->value << endl ;
            if (questions.top()->right != nullptr) {
                temp = questions.top()->right;
                questions.pop();
            } else {
                file.close();
                return;
            }
        } else {
            file << "Q" << temp->value << endl;
            questions.push(temp);
            temp = temp->left;
        }
    }
    file << "A" << temp->value << endl;
    file.close();
}

void playGame(TreeNode *& tree) {
    cout << endl << "Think of a city... Press return when you are ready to begin.";
    string response;
    getline(cin, response);
    cout << endl;
    TreeNode *temp = tree;
    TreeNode *prev = tree;
    while (temp->left != nullptr && temp->right != nullptr) {
        cout << temp->value << " ";
        getline(cin, response);
        prev = temp;
        if (response[0] == 'y') {
            temp = temp->left;
        } else {
            temp = temp->right;
        }
    }
    cout << "Is " << temp->value << " your city? ";
    getline(cin, response);
    if (response[0] == 'y') {
        cout << endl << "Yes! I guessed your city correctly!" << endl;
    } else {
        cout << "Darn. What was your city? ";
        string city;
        getline(cin, city);
        cout << "Please enter a question that would distinguish between " << temp->value << " and " << city << "." << endl;
        cout << "Enter question: ";
        string question, answer;
        getline(cin, question);
        cout << "If you were thinking of " << city << ", what would the correct answer to your question be? ";
        getline(cin, answer);
        if (prev->right == temp) {
            prev->right = new TreeNode(question);
            if (answer[0] == 'y') {
                prev->right->right = temp;
                prev->right->left = new TreeNode(city);
            } else {
                prev->right->left = temp;
                prev->right->right = new TreeNode(city);
            }
        } else if (prev->left == temp) {
            prev->left = new TreeNode(question);
            if (answer[0] == 'y') {
                prev->left->right = temp;
                prev->left->left = new TreeNode(city);
            } else {
                prev->left->left = temp;
                prev->left->right = new TreeNode(city);
            }
        }
    }
}

int main() {
    cout << "City Guessing Game" << endl << endl;
    cout << "Welcome to the City Guessing Game!" << endl;
    string filename;
    cout << "Enter the name of the data file: ";
    getline(cin, filename);
    TreeNode* root = nullptr;
    ifstream infile(filename);
    loadFile(root, infile);

    // continue here
    bool playing = true;
    while (playing) {
        playGame(root);
        cout << endl << "Do you want to play again? ";
        string answer;
        getline(cin, answer);
        if (answer[0] != 'y') {
            playing = false;
            cout << "Do you want to save the current city information to a file? ";
            getline(cin, answer);
            if (answer[0] == 'y') {
                cout << "Enter name of file (duplicate files will be overwritten): ";
                getline(cin, answer);
                saveFile(root, answer);
            }
        }
    }

    cout << endl << "Goodbye. Thank you for playing the City Guessing Game." << endl;

    return 0;
}