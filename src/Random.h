#pragma once

#include <random>

class Random
{
public:
    Random();

    int GenerateRandomNumber(int min, int max);

private:
    std::random_device dev;
    std::mt19937 rng;
};
