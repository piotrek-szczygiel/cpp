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

class Person {
private:
    static std::string random_first_name();

    static std::string random_last_name();

    static int random_birth_year();

public:
    std::string first_name;
    std::string last_name;
    int birth_year;

    Person(std::string first_name, std::string last_name, int birth_year) : first_name(std::move(first_name)),
                                                                            last_name(std::move(last_name)),
                                                                            birth_year(birth_year) {}

    Person() : first_name(random_first_name()), last_name(random_last_name()), birth_year(random_birth_year()) {}

    bool operator<(const Person &other) const {
        return get_key() < other.get_key();
    }

    std::string get_key() const {
        return first_name + last_name;
    }

    std::string info() const {
        return last_name + ", " + first_name + " (" + std::to_string(birth_year) + ")";
    }

    static Person generator();
};


#endif //LAB6_TREE_H
