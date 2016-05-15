#ifndef WRONGPENALTYSCORE
#define WRONGPENALTYSCORE

#include "exception"

class WrongPenaltyScore: public std::exception
{
public:
    const char * what() { return "Penalty scores can't be equal"; }
};

#endif // WRONGPENALTYSCORE

