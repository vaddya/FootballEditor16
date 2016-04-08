#include "randomiser.h"

Randomiser *Randomiser::randomiser = 0;

Randomiser::Randomiser() {}

Randomiser *Randomiser::RandomiserInstance() {
    if( randomiser == 0 )
        return randomiser = new Randomiser();
    return randomiser;
}

int Randomiser::random(int begin, int end)
{
    mt19937 rng;
    rng.seed(random_device()());
    uniform_int_distribution<std::mt19937::result_type> dist6(begin, end); // distribution in range [begin, end]
    return dist6(rng);
}
