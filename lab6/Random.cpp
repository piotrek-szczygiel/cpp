//
// Created by Piotr on 27.05.2019.
//

#include <chrono>
#include "Random.h"

std::mt19937 gen;

void random_seed() {
    gen.seed(std::chrono::high_resolution_clock::now().time_since_epoch().count());
}