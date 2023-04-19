#include "Random.h"

Random::Random()
    :
        rng(dev())
{

}

int Random::GenerateRandomNumber(int min, int max)
{
    std::uniform_int_distribution<std::mt19937::result_type> dist(min, max);

    return dist(rng);
}
