#include <iostream>
#include "pixel.h"
#include "polygon.h"

int main() {
    Polygon p1(5);
    p1.push({1, 1});
    p1.push({2, 2});
    p1.push({3, 3});
    p1.debug();

    Polygon p2 = p1;
    p2.debug();
    p2.pop().debug();
    std::cout << std::endl;
    p1.debug();
    p2.debug();

    Polygon p3(std::move(p1));
    p3.debug();

    Polygon p4 = std::move(p3);
    p4.push({4, 4});
    p4.debug();

    p3 = p4;
    p3.push({5, 5});
    p3.debug();

    std::cout << "p3 size: " << p3.get_size() << std::endl;

    try {
        p3.push({});
    } catch (const std::invalid_argument &e) {
        std::cout << "exception: " << e.what() << std::endl;
    }

    try {
        p3.get(5);
    } catch (const std::invalid_argument &e) {
        std::cout << "exception: " << e.what() << std::endl;
    }

    return 0;
}