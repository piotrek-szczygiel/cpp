//
// Created by Piotr on 27.05.2019.
//

#include "Person.h"
#include "Random.h"

std::string Person::random_first_name() {
    static const std::vector<std::string> first_names{
            "Oliver", "George", "Harry", "Jack", "Jacob",
            "Olivia", "Amelia", "Isla", "Emily", "Ava"
    };

    std::vector<std::string> random_type;
    std::sample(first_names.begin(), first_names.end(), std::back_inserter(random_type), 1, gen);

    return random_type[0];
}

std::string Person::random_last_name() {
    static const std::vector<std::string> last_names{
            "Smith", "Johnson", "Williams", "Brown", "Jones", "Garcia", "Miller", "Davis", "Rodriguez"
    };

    std::vector<std::string> random_type;
    std::sample(last_names.begin(), last_names.end(), std::back_inserter(random_type), 1, gen);

    return random_type[0];
}

int Person::random_birth_year() {
    static std::uniform_int_distribution<> year_dis(1950, 2010);
    return year_dis(gen);
}

Person Person::generator() {
    return Person();
}
