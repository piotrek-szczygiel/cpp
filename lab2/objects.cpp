#include <iomanip>
#include <ostream>
#include "objects.h"

std::ostream &operator<<(std::ostream &out, const Matrix &m) {
    out << std::setprecision(2) << std::fixed;
    out << "[ "
        << std::setw(7) << m.a
        << std::setw(7) << m.b << std::endl << "  "
        << std::setw(7) << m.c
        << std::setw(7) << m.d << " ]" << std::endl;
    return out;
}

std::ostream &operator<<(std::ostream &out, const Vector &v) {
    out << std::setprecision(2) << std::fixed;
    out << "[ "
        << std::setw(7) << v.a
        << std::setw(7) << v.b << " ]" << std::endl;
    return out;
}

Matrix operator*(const Matrix &m, double scalar) {
    return {m.a * scalar, m.b * scalar, m.c * scalar, m.d * scalar};
}

Matrix operator*(double scalar, const Matrix &m) {
    return {m.a * scalar, m.b * scalar, m.c * scalar, m.d * scalar};
}

Vector &Vector::operator+=(const Vector &v) {
    a += v.a;
    b += v.b;
    return *this;
}

Vector &Vector::operator++() {
    ++a;
    ++b;
    return *this;
}

Vector Vector::operator++(int) &{
    Vector copy{a, b};
    operator++();
    return copy;
}
