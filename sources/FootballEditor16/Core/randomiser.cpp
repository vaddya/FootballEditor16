#include "randomiser.h"
#include "chrono"

Randomiser *Randomiser::randomiser = 0;

Randomiser::Randomiser() {}

Randomiser *Randomiser::RandomiserInstance() {
    if( randomiser == 0 )
        return randomiser = new Randomiser();
    return randomiser;
}

int Randomiser::random(int begin, int end , time_t seed)
{
//    mt19937 rng;
//    rng.seed(random_device()());
//    uniform_int_distribution<std::mt19937::result_type> dist6( begin, end ); // distribution in range [begin, end]
//    return dist6( rng );
    srand(seed+time(NULL)+int(begin*end%15/16*2.5));
    return rand() % end + begin;
}
