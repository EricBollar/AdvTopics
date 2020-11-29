//
// Created by Eric Bollar on 9/18/20.
//

#include "shpvector.h"
#include <iostream>
using namespace std;

template <typename ElemType>
shpvector<ElemType>::shpvector() {
    arr = new ElemType[10];
    length = 0;
    capacity = 10;
}

template <typename ElemType>
shpvector<ElemType>::~shpvector() {
    delete[] arr;
}

template <typename ElemType>
void shpvector<ElemType>::push_back(ElemType val) {
    if (length == capacity) {
        increaseCapacity();
    }
    arr[length] = val;
    length++;
}

template <typename ElemType>
int shpvector<ElemType>::size() const {
    return length;
}

template <typename ElemType>
ElemType shpvector<ElemType>::at(int index) const {
    if (index < 0 || index >= size()) {
        cout << "index out of bounds exception" << endl;
    }
    return arr[index];
}

template <typename ElemType>
void shpvector<ElemType>::insert(int index, ElemType value) {
    if (length == capacity) {
        increaseCapacity();
    }
    for (int i = length; i > index; i--) {
        arr[i] = arr[i-1];
    }
    arr[index] = value;
    length++;
}

template <typename ElemType>
void shpvector<ElemType>::remove(int index) {
    length--;
    for (int i = index; i < length; i++) {
        arr[i]=arr[i+1];
    }
}

template <typename ElemType>
void shpvector<ElemType>::set(int index, ElemType value) {
    if (index < 0 || index >= size()) {
        cout << "index out of bounds exception" << endl;
    }
    arr[index] = value;
}

template <typename ElemType>
void shpvector<ElemType>::clear() {
    ElemType *cleared = new ElemType[10];
    capacity = 10;
    length = 0;
    delete[] arr;
    arr = cleared;
}

template <typename ElemType>
void shpvector<ElemType>::increaseCapacity() {
    ElemType *bigger = new ElemType[capacity*2];
    for (int i = 0; i < capacity; i++) {
        bigger[i] = arr[i];
    }
    capacity *= 2;
    delete[] arr;
    arr = bigger;
}
