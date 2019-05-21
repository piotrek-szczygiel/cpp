#include <iostream>
#include <cstring>
#include <memory>
#include "List.h"

template<class T>
T add(T a, T b) {
    return a + b;
}

template<>
const char* add<const char*>(const char* a, const char* b) {
    long len = strlen(a) + strlen(b);
    char* str = new char[len+1];
    strcpy(str, a);
    strcat(str, b);
    str[len] = '\0';
    return str;
}

int main() {
    std::cout << add(2, 1) << std::endl;
    std::cout << add(3.5, 2.5) << std::endl;
    std::cout << add<std::string>("ala ma ", "kota") << std::endl;
    const char* str = add("ala ma ", "kota");
    std::cout << str << std::endl << std::endl;
    delete[] str;

    List<int> l;
    l.insert(1);
    l.insert(2);
    l.insert(3);

    std::cout << "removing first: " << l.remove() << std::endl;
    l.print();
    std::cout << std::endl;

    l.insert(4);
    l.insert(5);

    l.print();
    std::cout << std::endl;
    std::cout << "stream: " <<  l << std::endl;

    std::cout << l.remove() << " " << l.remove() << " " << l.remove() << " " << l.remove() << std::endl;

    std::cout << l.remove() << std::endl;  // should throw
    return 0;
}