//
// Created by Piotr on 21.05.2019.
//

#include "TreeBST.h"

template<class T>
bool TreeBST<T>::contains(T val) const {
    if (root != nullptr) {
        return root->contains(val);
    }

    return false;
}

template<class T>
void TreeBST<T>::insert(T val) {
    if (root == nullptr) {
        root = new NodeBST(val);
    } else {
        if (!root->insert(val)) {
            throw std::logic_error("value already exists");
        }
    }
}

template<class T>
void TreeBST<T>::print() const {
    std::cout << "tree: [";

    if (root == nullptr) {
        std::cout << "empty" << std::endl;
    } else {
        root->print();
    }

    std::cout << "]" << std::endl;
}

template
class TreeBST<int>;