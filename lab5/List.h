//
// Created by Piotr on 21.05.2019.
//

#ifndef LAB5_LIST_H
#define LAB5_LIST_H

#include <iostream>
#include <memory>

template<class T>
class Node;

template<class T>
class List {
private:
    std::unique_ptr<Node<T>> root;

public:
    List() : root(nullptr) {}
    List(const List&) = delete;

    void insert(T val);

    T remove();

    void print();

    template<class U>
    friend std::ostream &operator<<(std::ostream &o, const List<U> &l);
};


template<class T>
class Node {
private:
    std::unique_ptr<Node<T>> next;
    T data;

    friend class List<T>;

public:
    explicit Node(T data) : data(data), next(nullptr) {}
    Node() = delete;
    Node(const Node &) = delete;

    void print();


    template<class U>
    friend std::ostream &operator<<(std::ostream &o, const Node<U> &n);
};


#include "List.cpp"

#endif //LAB5_LIST_H
