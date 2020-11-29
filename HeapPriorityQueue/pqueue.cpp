//
// Created by Eric Bollar on 11/6/20.
//

#include "pqueue.h"

using namespace std;

pqueue::pqueue() {
    // done
}

pqueue::~pqueue() {
    // done
}

void pqueue::pop() {
    heap[0] = heap[heap.size() - 1];
    heap.pop_back();
    heapifyDown(0);
}

string pqueue::top() const {
    return heap[0];
}

void pqueue::push(string str) {
    heap.push_back(str);
    heapifyUp(heap.size() - 1);
}

int pqueue::size() const {
    return heap.size();
}

bool pqueue::empty() const {
    return heap.size() == 0;
}

void pqueue::heapifyUp(int index) {
    if (index == 0) {
        return;
    }
    int parentIndex = (index - 1)/2;
    if (heap[parentIndex] > heap[index]) {
        string temp = heap[parentIndex];
        heap[parentIndex] = heap[index];
        heap[index] = temp;
        heapifyUp(parentIndex);
    }
}

void pqueue::heapifyDown(int index) {
    int leftChildIndex = 2*index + 1;
    int rightChildIndex = 2*index + 2;
    int largestIndex = index;
    if (leftChildIndex < heap.size() && heap[leftChildIndex] < heap[largestIndex]) {
        largestIndex = leftChildIndex;
    }
    if (rightChildIndex < heap.size() && heap[rightChildIndex] < heap[largestIndex]) {
        largestIndex = rightChildIndex;
    }
    if (index != largestIndex) {
        string temp = heap[largestIndex];
        heap[largestIndex] = heap[index];
        heap[index] = temp;
        heapifyDown(largestIndex);
    }
}
