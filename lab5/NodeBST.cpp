//
// Created by Piotr on 21.05.2019.
//

#include "NodeBST.h"

template<class T>
bool NodeBST<T>::contains(T val) const {
    if (val == data) {
        return true;
    }

    NodeBST *next = (val < data) ? left : right;

    if (next != nullptr) {
        return next->contains(val);
    }

    return false;
}

template<class T>
bool NodeBST<T>::insert(T val) {
    if (val == data) {
        return false;
    }

    NodeBST *&next = (val < data) ? left : right;

    if (next == nullptr) {
        next = new NodeBST(val);
        return true;
    } else {
        return next->insert(val);
    }
}

template<class T>
void NodeBST<T>::print() const {
    if (left != nullptr) {
        left->print();
    }

    std::cout << data << " ";

    if (right != nullptr) {
        right->print();
    }
}

template
class NodeBST<int>;