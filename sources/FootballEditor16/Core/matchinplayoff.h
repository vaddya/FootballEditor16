#ifndef MATCHINPLAYOFF_H
#define MATCHINPLAYOFF_H

#include "match.h"
#include "teaminplayoff.h"

class MatchInPlayoff : public Match
{
public:
    MatchInPlayoff(Team &firstTeam, Team &secondTeam );
    void setResult(int firstTeamGoals, int secondTeamGoals);
private:

};

#endif // MATCHINPLAYOFF_H
