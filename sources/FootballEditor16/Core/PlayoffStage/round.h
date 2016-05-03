#ifndef ROUND_H
#define ROUND_H

#include "vector"
#include "teaminplayoff.h"
#include "matchinplayoff.h"

using std::vector;

enum RoundEnum {
    FINAL = 1, SEMIFINAL = 2, QUARTERFINALS = 4, ROUNDOF16 = 8, // stages 1, 1/2, 1/4, 1/8
};

class Round
{
public:
    Round();

private:
    RoundEnum round;
    vector<TeamInPlayoff> teams;
    vector<MatchInPlayoff> matches;
};

#endif // ROUND_H
