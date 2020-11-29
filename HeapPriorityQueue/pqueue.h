//
// Created by Eric Bollar on 11/6/20.
//

#ifndef HEAPPRIORITYQUEUE_PQUEUE_H
#define HEAPPRIORITYQUEUE_PQUEUE_H

#include <iostream>
#include <vector>

using namespace std;

class pqueue {
public:
    pqueue();
    ~pqueue();
    void pop();
    string top() const;
    void push(string str);
    int size() const;
    bool empty() const;
private:
    vector<string> heap;
    void heapifyUp(int index);
    void heapifyDown(int index);
};


#endif //HEAPPRIORITYQUEUE_PQUEUE_H
