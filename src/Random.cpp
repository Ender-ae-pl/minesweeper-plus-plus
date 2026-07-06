#include "Random.hpp"
#include <random>

Random::Random() {
    std::random_device rd;
    gen = std::mt19937(rd());
}

int Random::RandInt(int min, int max) {
    std::uniform_int_distribution<> dist(min, max);
    return dist(gen);
}