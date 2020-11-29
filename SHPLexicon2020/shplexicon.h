
#ifndef SHPLEXICON_SHPLEXICON_H
#define SHPLEXICON_SHPLEXICON_H
#include <string>
#include <set>
#include <map>

using namespace std;

class shplexicon {
public:
    shplexicon();
    shplexicon(string filename);
    ~shplexicon();

    int size() const;
    void insert(string word);
    bool containsWord(string word) const;
    bool containsPrefix(string prefix) const;
    void removeWord(string word);
    set<string> getWordsWithPrefix(string prefix) const;

private:
   // up to you!
   struct Node {
       bool isWord;
       map<char, Node*> letters;
       Node() {
           isWord = false;
       }
   };
   Node *root;

    int sizeHelper(Node* tree) const;
    void insertHelper(Node *& tree, string word);
    bool validate(string & word) const;
    Node* getNode(string word) const;
    Node* getNodeHelper(Node* tree, string word) const;
    void freeHelper(shplexicon::Node *&tree);
    void removeHelper(shplexicon::Node *&tree, string word);
    set<string> getWordsWithPrefixHelper(string prefix) const;
};


#endif //SHPLEXICON_SHPLEXICON_H
