#ifndef RANDOMISER_H
#define RANDOMISER_H

#include "random"

using std::mt19937;
using std::uniform_int_distribution;
using std::random_device;

class Randomiser {
public:
    static Randomiser * RandomiserInstance();
    int random(int begin, int end);
private:
    Randomiser();
    static Randomiser *randomiser;
};

#endif // RANDOMISER_H
