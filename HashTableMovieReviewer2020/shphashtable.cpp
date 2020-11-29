//
// Created by Kevin Morris on 11/5/19.
//

#include "shphashtable.h"
#include <string>
#include <iostream>

using namespace std;

shphashtable::shphashtable(int numBuckets) {
    table = new Node*[numBuckets];
    size = numBuckets;
    collisions = 0;
    for (int i=0; i<size; i++)
        table[i] = nullptr;
}

bool shphashtable::contains(WordEntry str) {
    int whichBucket = getHashCode(str.getString());
    Node* bucket = table[whichBucket];
    while (bucket != nullptr) {
        collisions++;
        if (bucket->value.getString() == str.getString())
            return true;
        else
            bucket = bucket->next;
    }
    return false;
}

void shphashtable::put(WordEntry str, int score) {
    if (!contains(str)) {
        str.addNewScore(score);
        int whichBucket = getHashCode(str.getString());
        Node *bucket = table[whichBucket];
        Node *temp = new Node(str, bucket);
        table[whichBucket] = temp;
   } else {
        int whichBucket = getHashCode(str.getString());
        table[whichBucket]->value.addNewScore(score);
    }
}

int shphashtable::getHashCode(string str) const {
    // this uses the built-in hashing function for strings
    // feel free to change this by writing your own!
    hash<string> hashFunc;
    return hashFunc(str) % size;
}

void shphashtable::printStats() {
    cout << "--------------------------------------------------" << endl;
    cout << "                      Stats                       " << endl;
    cout << "Size: " << size;
    int numUsed = getBucketsUsed();
    cout << " (" << numUsed << "/" << size << " Used)" << endl;
    cout << "Collisions: " << collisions << endl;
    cout << "Average Length: " << getAverageLength() << endl;
    cout << "Longest Length: " << getLongestLength() << endl;
    cout << "--------------------------------------------------" << endl;
}

int shphashtable::getBucketsUsed() {
    int numUsed = 0;
    for (int i=0; i<size; i++) {
        if (table[i] != nullptr) {
            numUsed++;
        }
    }
    return numUsed;
}

int shphashtable::getLongestLength() {
    int longest = 0;
    for (int i=0; i<size; i++) {
        Node *curr = table[i];
        int length = 0;
        while (curr != nullptr) {
            length++;
            curr = curr->next;
        }
        if (length > longest) {
            longest = length;
        }
    }
    return longest;
}

double shphashtable::getAverageLength() {
    int numerator = 0;
    for (int i=0; i<size; i++) {
        Node *curr = table[i];
        while (curr != nullptr) {
            numerator++;
            curr = curr->next;
        }
    }
    return numerator * 1.0 / size;
}

double shphashtable::getAverage(string str) {
    if (!contains(str)) {
        return 2.0;
    } else {
        int whichBucket = getHashCode(str);
        Node *bucket = table[whichBucket];
        return bucket->value.getAverageScore();
    }
}

shphashtable::~shphashtable() {

}