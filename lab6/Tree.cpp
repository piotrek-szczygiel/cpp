//
// Created by Piotr on 27.05.2019.
//

#include "Tree.h"
#include "Random.h"

std::string Tree::random_type() {
    static const std::vector<std::string> types{
            "Birch",
            "Dogwood",
            "Maple",
            "Elm",
            "Pine",
            "Oak"
    };

    std::vector<std::string> random_type;
    std::sample(types.begin(), types.end(), std::back_inserter(random_type), 1, gen);

    return random_type[0];
}

double Tree::random_diameter() {
    static std::uniform_real_distribution<> diameter_dis(0.1, 2.0);
    return diameter_dis(gen);
}

int Tree::random_age() {
    static std::uniform_int_distribution<> age_dis(1, 100);
    return age_dis(gen);
}

Tree Tree::generator() {
    static int age = 1;
    return Tree(random_type(), random_diameter(), age++);
}
