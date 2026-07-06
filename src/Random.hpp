#pragma once
#include <random>

class Random {
public:
    Random();
    int RandInt(int min, int max);
private:
    std::mt19937 gen;
};