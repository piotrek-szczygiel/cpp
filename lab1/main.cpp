#include <iostream>
#include <iomanip>
#include <cmath>

class Point {
private:
    static int counter;

    float x, y, z;

public:
    Point() : x(0.0f), y(0.0f), z(0.0f) {}

    Point(float x, float y, float z = 0.0f) : x(x), y(y), z(z) {}

    float get_x() {
        return x;
    }

    void set_x(float x) {
        this->x = x;
    }

    float distance_from(const Point &p) {
        return sqrt(pow(p.x - x, 2.0f) + pow(p.y - y, 2.0f) + pow(p.z - z, 2.0f));
    }

    void print() {
        std::cout << x << ", " << y << ", " << z;
    }

    void write(std::ostream &out);

    void load(std::istream &in);

    static int get_counter() {
        return counter;
    }

};

void Point::write(std::ostream &out) {
    out << std::fixed << std::setprecision(4)
        << "[" << x << ", " << y << ", " << z << "]";
}

void Point::load(std::istream &in) {
    char dummy;
    in >> dummy >> x >> dummy
       >> y >> dummy
       >> z >> dummy;
}

int Point::counter = 0;

int main() {
    Point p1;
    Point p2{1.0f, 1.0f, 1.0f};

    std::cout << "distance from ";
    p1.print();
    std::cout << " to ";
    p2.print();
    std::cout << " = " << p1.distance_from(p2) << std::endl;

    Point p3{1.0f, 2.0f};
    p3.set_x(0.0f);
    p3.write(std::cout);
    std::cout << std::endl;

    Point p4;
    p4.load(std::cin);
    p4.write(std::cout);

    std::cout << std::endl << Point::get_counter() << std::endl;

    return 0;
}