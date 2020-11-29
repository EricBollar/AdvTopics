//
// Created by Eric Bollar on 9/18/20.
//

#ifndef VECTORPROGRAM_SHPVECTOR_H
#define VECTORPROGRAM_SHPVECTOR_H

template <typename ElemType>
class shpvector {
public:
    shpvector();
    ~shpvector();

    void push_back(ElemType val);
    int size() const;
    ElemType at(int index) const;

    void insert(int index, ElemType value);
    void remove(int index);
    void set(int index, ElemType value);
    void clear();
private:
    ElemType* arr;
    int length;
    int capacity;
    void increaseCapacity();
};


#endif //VECTORPROGRAM_SHPVECTOR_H
