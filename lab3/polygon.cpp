#include <iostream>
#include "polygon.h"

Polygon &Polygon::operator=(const Polygon &other) {
    if (capacity != other.capacity) {
        capacity = other.capacity;
        delete[] array;
        array = new Pixel[capacity];
    } else if (array == nullptr) {
        array = new Pixel[capacity];
    }

    size = other.size;
    for (int i = 0; i < size; ++i) {
        array[i] = other.array[i];
    }

    return *this;
}

Polygon &Polygon::operator=(Polygon &&other) noexcept {
    capacity = other.capacity;
    size = other.size;

    delete[] array;
    array = other.array;
    other.array = nullptr;
    return *this;
}

void Polygon::debug() {
    std::cout << "Polygon: ";
    for (int i = 0; i < size; ++i) {
        std::cout << " ";
        array[i].debug();
    }
    std::cout << std::endl;
}
