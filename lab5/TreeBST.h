//
// Created by Piotr on 21.05.2019.
//

#ifndef LAB5_TREEBST_H
#define LAB5_TREEBST_H

#include <iostream>
#include "NodeBST.h"

template<class T>
class TreeBST {
private:
    NodeBST<T> *root;

public:
    TreeBST() : root(nullptr) {}

    bool contains(T val) const;


    void insert(T val);

    void print() const;
};


#endif //LAB5_TREEBST_H
