#include <utility>

//
// Created by Piotr on 27.05.2019.
//

#ifndef LAB6_TREE_H
#define LAB6_TREE_H

#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <cmath>

class Tree {
private:
    std::string type;
    double diameter;
    int age;

    std::string get_key() const {
        return type + std::to_string(age);
    }

    static std::string random_type();

    static double random_diameter();

    static int random_age();

public:
    Tree(std::string type, double diameter, int age) : type(std::move(type)), diameter(diameter), age(age) {}

    Tree() : type(random_type()), diameter(random_diameter()), age(random_age()) {}

    bool operator<(const Tree &other) const {
        return get_key() < other.get_key();
    }

    std::string get_type() const {
        return type;
    }

    double get_diameter() const {
        return diameter;
    }

    void increase_diameter(double value) {
        diameter += value;
    }

    std::string info() const {
        return type + std::string(", ") + std::to_string(diameter) + std::string(", ") + std::to_string(age);
    }

    static bool compare_diameter(const Tree &a, const Tree &b) {
        return a.diameter < b.diameter;
    }

    static Tree generator();
};


#endif //LAB6_TREE_H
