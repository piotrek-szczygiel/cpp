//
// Created by piotr on 02.04.19.
//

#ifndef LAB3_POLYGON_H
#define LAB3_POLYGON_H

#include <stdexcept>
#include "pixel.h"

class Polygon {
private:
    int size;
    int capacity;
    Pixel *array;

public:
    explicit Polygon(int n = 10) {
        capacity = n;
        array = new Pixel[capacity];
        size = 0;
    }

    Polygon(const Polygon &other) : size(other.size), capacity(other.capacity) {
        array = new Pixel[capacity];
        for (int i = 0; i < size; ++i) {
            array[i] = other.array[i];
        }
    }

    Polygon(Polygon &&other) noexcept : size(other.size), capacity(other.capacity) {
        array = other.array;
        other.array = nullptr;
    }

    Polygon &operator=(const Polygon &other);

    Polygon &operator=(Polygon &&other) noexcept;

    ~Polygon() {
        delete[] array;
    }

    int get_size() {
        return size;
    }

    void push(const Pixel &pixel) {
        if (size >= capacity) {
            throw std::invalid_argument("pixel array is full");
        }

        array[size++] = pixel;
    }

    Pixel pop() {
        return array[--size];
    }

    const Pixel &get(int n) {
        if (n >= size) {
            throw std::invalid_argument("index out of range");
        }

        return array[n];
    }

    void debug();
};


#endif //LAB3_POLYGON_H
