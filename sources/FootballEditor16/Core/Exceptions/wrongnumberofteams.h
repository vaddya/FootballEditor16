#ifndef WRONGNUMBEROFTEAMS
#define WRONGNUMBEROFTEAMS

#include "exception"

class WrongNumberOfTeams: public std::exception
{
public:
    WrongNumberOfTeams(int number): wrongNumber(number) {}
    int getWrongNum() const { return wrongNumber; }
    const char * what() { return "The number of teams should be a multiple of 8!"; }
private:
    int wrongNumber;
};

#endif // WRONGNUMBEROFTEAMS

