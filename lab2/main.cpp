#include <iostream>
#include "objects.h"

int main() {
    Matrix m{1.0, 2.0, 3.0, 4.0};
    Vector v{2.0, 4.0};
    std::cout << "m:\n" << m << std::endl;
    std::cout << "v:\n" << v << std::endl;

    std::cout << "v + {0.5, 0.5}:\n" << v + Vector{0.5, 0.5} << std::endl;

    Vector v_add{6.0, 6.0};
    v_add += v;
    std::cout << "{6.0, 6.0} += v:\n" << v_add << std::endl;

    std::cout << "10.0 * m:\n" << 10.0 * m << std::endl;
    std::cout << "m * 10.0:\n" << m * 10.0 << std::endl;

    std::cout << "m * v:\n" << m * v << std::endl;

    std::cout << "++v:\n" << ++v << std::endl;
    std::cout << "v++:\n" << v++ << std::endl;
    std::cout << "v:\n" << v << std::endl;

    std::cout << "-m:\n" << -m << std::endl;

    std::cout << "v == {4.0, 6.0}: " << (v == Vector{4.0, 6.0}) << std::endl;

    std::cout << "v[0]: " << v[0] << std::endl;
    std::cout << "v[1]: " << v[1] << std::endl;

    std::cout << "(double) m: " << (double) m << std::endl;

    return 0;
}