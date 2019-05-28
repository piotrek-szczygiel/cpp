#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <iomanip>
#include "Person.h"
#include "Random.h"

int main() {
    random_seed();

    const int size = 5;

    std::vector<Person> v_people;
    std::set<Person> s_people;
    std::map<std::string, Person> m_people;

    for (int i = 0; i < size - 1; ++i) {
        v_people.emplace_back();
    }

    // create duplicate
    v_people.push_back(v_people[0]);

    for (auto it = v_people.begin(); it != v_people.end(); ++it) {
        std::cout << "vector: " << it->info() << std::endl;
    }

    for (auto const &p : v_people) {
        if (!s_people.insert(p).second) {
            std::cout << "set duplicate: " << p.info() << std::endl;
        }
    }

    for (auto &v_tree : v_people) {
        m_people[v_tree.get_key()] = v_tree;
    }

    for (auto const&[key, val] : m_people) {
        std::cout << "map[" << key << "]: " << val.info() << std::endl;
    }

    std::vector<Person> g(20);
    std::generate(g.begin(), g.end(), Person::generator);

    for (auto const &p : g) {
        std::cout << "gen: " << p.info() << std::endl;
    }

    auto find_result = std::find_if(g.begin(), g.end(),
                                    [](const Person &p) { return p.birth_year == 2000; });

    if (find_result != g.end()) {
        std::cout << "find_if: " << find_result->info() << std::endl;
    } else {
        std::cout << "find_if: no results" << std::endl;
    }

    std::cout << "enter birth year to count: ";
    int birth_year;
    std::cin >> birth_year;

    std::cout << "people born in " << birth_year << ": "
              << std::count_if(g.begin(), g.end(), [birth_year](const Person &p) { return p.birth_year == birth_year; })
              << std::endl;

    std::sort(g.begin(), g.end(), [](const Person &a, const Person &b) {
        if (a.birth_year != b.birth_year) {
            return a.birth_year < b.birth_year;
        }

        return a.last_name < b.last_name;
    });

    std::cout << "sorted: " << std::endl;
    for (auto const &p : g) {
        std::cout << p.info() << std::endl;
    }

    std::sort(g.begin(), g.end(), [](const Person &a, const Person &b) {
        return a.last_name < b.last_name;
    });

    auto last = std::unique(g.begin(), g.end(), [](const Person &a, const Person &b) {
        return a.last_name == b.last_name;
    });
    g.erase(last, g.end());

    std::cout << "unique: " << std::endl;
    for (auto const &p : g) {
        std::cout << p.info() << std::endl;
    }

    return 0;
}