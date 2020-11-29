

#ifndef HASHTABLEMOVIEREVIEWER_SHPHASHTABLE_H
#define HASHTABLEMOVIEREVIEWER_SHPHASHTABLE_H
#include <string>
#include "WordEntry.h"

using namespace std;

class shphashtable {
public:
    shphashtable(int numBuckets);
    ~shphashtable();
    bool contains(WordEntry str);
    void put(WordEntry str, int score);
    void printStats();
    double getAverageLength();
    int getLongestLength();
    int getBucketsUsed();
    double getAverage(string str);
private:
    int getHashCode(string str) const;

    struct Node {
        WordEntry value;
        Node *next;

        Node() {
            value = WordEntry("");
            next = nullptr;
        }
        Node(WordEntry str) {
            value = str;
            next = nullptr;
        }
        Node(WordEntry str, Node *ptr) {
            value = str;
            next = ptr;
        }
    };

    Node** table;
    int size;
    int collisions;

};


#endif //HASHTABLEMOVIEREVIEWER_SHPHASHTABLE_H
