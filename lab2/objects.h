#pragma once

class Matrix;

class Vector;

class Vector {
private:
    friend class Matrix;

    double a, b;

public:
    Vector() : a(0.0), b(0.0) {}

    Vector(double a, double b) : a(a), b(b) {}

    friend std::ostream &operator<<(std::ostream &out, const Vector &v);

    Vector operator+(const Vector &v) const {
        return {a + v.a, b + v.b};
    }

    Vector &operator+=(const Vector &v);

    Vector &operator++();

    Vector operator++(int) &;

    bool operator==(const Vector &v) {
        return a == v.a && b == v.b;
    }

    double operator[](int i) {
        if (i == 0) return a;
        if (i == 1) return b;

        return 0.0; // or throw an exception
    }
};

class Matrix {
private:
    double a, b, c, d;

public:
    Matrix() : a(0.0), b(0.0), c(0.0), d(0.0) {}

    Matrix(double a, double b, double c, double d) : a(a), b(b), c(c), d(d) {}

    friend std::ostream &operator<<(std::ostream &out, const Matrix &m);

    friend Matrix operator*(const Matrix &m, double scalar);

    friend Matrix operator*(double scalar, const Matrix &m);

    Vector operator*(const Vector &v) const {
        return Vector{a * v.a + b * v.b, c * v.a + d * v.b};
    }

    Matrix operator-() const {
        return {-a, -b, -c, -d};
    }

    explicit operator double() {
        return a * d - b * c;
    }
};

