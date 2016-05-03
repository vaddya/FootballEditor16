#ifndef MATCHINPLAYOFF_H
#define MATCHINPLAYOFF_H

#include "../match.h"
#include "teaminplayoff.h"

struct Penalty {
    int firstTeamPenaltyScore, secondTeamPenaltyScore;
};

class MatchInPlayoff : public Match
{
public:
    MatchInPlayoff( TeamInPlayoff &firstTeam, TeamInPlayoff &secondTeam );
    void setResult( int firstTeamGoals, int secondTeamGoals );
    TeamInPlayoff *getWinner();
private:
    TeamInPlayoff *firstTeamInPlayoff;
    TeamInPlayoff *secondTeamInPlayoff;
    Penalty penalty;
};

#endif // MATCHINPLAYOFF_H
