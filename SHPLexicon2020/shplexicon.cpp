
#include <iostream>
#include <fstream>
#include "shplexicon.h"
using namespace std;

shplexicon::shplexicon() {
    root = nullptr;
}

shplexicon::shplexicon(string filename) {
    root = nullptr;
    ifstream infile(filename);
    string word;
    while (infile >> word) {
        insert(word);
    }
}

shplexicon::~shplexicon() {
    freeHelper(root);
}

void shplexicon::freeHelper(shplexicon::Node *&tree) {
    if (tree == nullptr) {
        return;
    }
    for (auto itr = tree->letters.begin(); itr != tree->letters.end(); itr++) {
        freeHelper(itr->second);
    }
    delete tree;
}

int shplexicon::size() const {
    return sizeHelper(root);
}

int shplexicon::sizeHelper(shplexicon::Node* tree) const {
    if (tree == nullptr) {
        return 0;
    } else {
        int counter = 0;
        if (tree->isWord) {
            counter++;
        }
        for (auto itr = tree->letters.begin(); itr != tree->letters.end(); itr++) {
             counter += sizeHelper(itr->second);
        }
        return counter;
    }
}

void shplexicon::insert(string word) {
    validate(word);
    insertHelper(root, word);
}

void shplexicon::insertHelper(Node *& tree, string word) {
    if (tree == nullptr) {
        tree = new Node();
    }
    if (word == "") {
        tree->isWord = true;
    } else {
        insertHelper(tree->letters[word[0]], word.substr(1));
    }
}

bool shplexicon::containsWord(string word) const {
    if (!validate(word)) {
        return false;
    } else {
        Node* tree = getNode(word);
        return (tree != nullptr && tree->isWord);
    }
}

bool shplexicon::validate(string & word) const {
    for (int i = 0; i < word.length(); i++) {
        if (!isalpha(word[i])) {
            return false;
        } else {
            word[i] = tolower(word[i]);
        }
    }
    return true;
}

shplexicon::Node* shplexicon::getNode(string word) const {
    return getNodeHelper(root, word);
}

shplexicon::Node* shplexicon::getNodeHelper(Node *tree, string word) const {
    if (tree == nullptr) {
        return nullptr;
    } else if (word == "") {
        return tree;
    } else {
        return getNodeHelper(tree->letters[word[0]], word.substr(1));
    }
}

bool shplexicon::containsPrefix(string prefix) const {
    if (!validate(prefix)) {
        return false;
    } else {
        Node* tree = getNode(prefix);
        return (tree != nullptr);
    }
}

void shplexicon::removeWord(string word) {
    validate(word);
    removeHelper(root, word);
}

void shplexicon::removeHelper(shplexicon::Node *&tree, string word) {
    if (tree == nullptr) {
        return;
    }
    if (word == "") {
        tree->isWord = false;
        for (auto itr = tree->letters.begin(); itr != tree->letters.end(); itr++) {
            if (itr->second != nullptr) {
                return;
            }
        }
        delete tree;
        tree = nullptr;
    } else {
        removeHelper(tree->letters[word[0]], word.substr(1));
    }
}

set<string> shplexicon::getWordsWithPrefix(string prefix) const {
    return getWordsWithPrefixHelper(prefix);
}

set<string> shplexicon::getWordsWithPrefixHelper(string prefix) const {
    Node* prefixNode = getNode(prefix);
    set<string> out;
    if (prefixNode == nullptr) {
        return out;
    }
    for (auto itr = prefixNode->letters.begin(); itr != prefixNode->letters.end(); itr++) {
        if (itr->second != nullptr) {
            set<string> more = getWordsWithPrefixHelper(prefix + itr->first);
            for (auto itr = more.begin(); itr != more.end(); itr++) {
                out.insert(*itr);
            }
            if (itr->second->isWord) {
                out.insert(prefix + itr->first);
            }
        }
    }
    return out;
}

