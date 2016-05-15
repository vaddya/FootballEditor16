#ifndef COMPETITIONISOVER
#define COMPETITIONISOVER

#include "exception"

class CompetitionIsOver: public std::exception
{
public:
    const char * what() { return "The compeition is over!"; }
};

#endif // COMPETITIONISOVER

