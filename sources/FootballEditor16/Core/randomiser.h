#ifndef RANDOMISER_H
#define RANDOMISER_H

#include "random"

using std::mt19937;
using std::uniform_int_distribution;
using std::random_device;

/**
 * @brief The Randomiser class
 */
class Randomiser {
public:
    /**
     * @brief Instance randomiser
     * @return pointer to randomiser
     */
    static Randomiser * RandomiserInstance();
    /**
     * @brief Get random value from begin to end
     * @param begin
     * @param end
     * @return randomed value
     */
    int random( int begin, int end );
private:
    Randomiser();
    static Randomiser *randomiser;
};

#endif // RANDOMISER_H
