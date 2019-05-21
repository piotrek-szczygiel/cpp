#include <iostream>
#include "TreeBST.h"

template<class T>
bool equal(T a, T b, T c) {
    return a == b && b == c;
}

int main() {
    std::cout << equal(1, 1, 1) << std::endl;
    std::cout << equal(std::string("abc"), std::string("abc"), std::string("abc")) << std::endl;
    std::cout << equal(1, 2, 3) << std::endl << std::endl;

    TreeBST<int> tree;
    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    tree.insert(-2);
    tree.insert(-1);
    tree.insert(0);
    tree.print();

    tree.insert(-2);  // should throw

    return 0;
}