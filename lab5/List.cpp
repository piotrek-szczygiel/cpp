//
// Created by Piotr on 21.05.2019.
//

#include "List.h"

template<class T>
void List<T>::insert(T val) {
    if (root == nullptr) {
        root = std::make_unique<Node<T>>(val);
    } else {
        auto ptr = std::make_unique<Node<T>>(val);
        ptr->next = std::move(root);
        root = std::move(ptr);
    }
}

template<class T>
T List<T>::remove() {
    if (root == nullptr) {
        throw std::invalid_argument("list is empty");
    }

    T tmp = root->data;
    root = std::move(root->next);

    return tmp;
}

template<class T>
void List<T>::print() {
    root->print();
}

template<class T>
std::ostream &operator<<(std::ostream &o, const List<T> &l) {
    o << *l.root;
    return o;
}


template<class T>
void Node<T>::print() {
    std::cout << data << " ";

    if (next != nullptr) {
        next->print();
    }
}

template<class T>
std::ostream &operator<<(std::ostream &o, const Node<T> &n) {
    o << n.data;
    if (n.next != nullptr) o << " " << *n.next;
    return o;
}
