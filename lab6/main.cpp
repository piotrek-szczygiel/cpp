#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <iomanip>
#include "Tree.h"
#include "Random.h"

int main() {
    random_seed();

    const int size = 10;

    std::vector<Tree> v_trees;
    std::set<Tree> s_trees;
    std::map<int, Tree> m_trees;

    for (int i = 0; i < size - 1; ++i) {
        v_trees.emplace_back();
    }

    // create duplicate
    v_trees.push_back(v_trees[0]);

    for (auto const &t : v_trees) {
        std::cout << "vector: " << t.info() << std::endl;
    }

    for (auto const &t : v_trees) {
        if (!s_trees.insert(t).second) {
            std::cout << "set duplicate: " << t.info() << std::endl;
        }
    }

    for (int i = 0; i < v_trees.size(); ++i) {
        m_trees[i] = v_trees[i];
    }

    for (auto const&[key, val] : m_trees) {
        std::cout << "map[" << key << "]: " << val.info() << std::endl;
    }

    std::vector<Tree> g_trees(25);
    std::generate(g_trees.begin(), g_trees.end(), Tree::generator);

    for (auto const &t : g_trees) {
        std::cout << "gen: " << t.info() << std::endl;
    }

    std::cout << "min_element: "
              << std::min_element(g_trees.begin(), g_trees.end(), Tree::compare_diameter)->info() << std::endl;


    std::string type = "Elm";
    std::cout << "number of " << type << " elements: " << std::count_if(g_trees.begin(), g_trees.end(),
                                                                        [&type](const Tree &t) {
                                                                            return t.get_type() == type;
                                                                        }) << std::endl;

    std::cout << "increasing diameter" << std::endl;
    std::for_each(g_trees.begin(), g_trees.end(), [](Tree &t) { t.increase_diameter(0.1); });
    for (auto const &t : g_trees) {
        std::cout << "gen: " << t.info() << std::endl;
    }

    std::cout << "removing trees" << std::endl;
    g_trees.erase(std::remove_if(g_trees.begin(), g_trees.end(), [](const Tree &t) { return t.get_diameter() > 1.0; }),
                  g_trees.end());
    for (auto const &t : g_trees) {
        std::cout << "gen: " << t.info() << std::endl;
    }

    return 0;
}