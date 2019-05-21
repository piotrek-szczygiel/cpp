//
// Created by Piotr on 21.05.2019.
//

#ifndef LAB5_NODEBST_H
#define LAB5_NODEBST_H

#include <iostream>

template<class T>
class NodeBST {
private:
    T data;
    NodeBST *left;
    NodeBST *right;

public:
    explicit NodeBST(T _data) : data(_data), left(nullptr), right(nullptr) {}

    bool contains(T val) const;

    bool insert(T val);

    void print() const;
};


#endif //LAB5_NODEBST_H
