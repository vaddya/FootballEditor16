#ifndef MATCHINPLAYOFF_H
#define MATCHINPLAYOFF_H

#include "playoffstage.h"
#include "match.h"
#include "teaminplayoff.h"

enum Round {
    FINAL = 1, SEMIFINAL = 2, QUARTERFINALS = 4, ROUNDOF16 = 8,
};

class PlayoffStage;

class MatchInPlayoff : public Match
{
public:
    MatchInPlayoff( TeamInPlayoff &firstTeam, TeamInPlayoff &secondTeam );
    void setResult( int firstTeamGoals, int secondTeamGoals );
private:
    TeamInPlayoff *firstTeamInPlayoff;
    TeamInPlayoff *secondTeamInPlayoff;
    Round round;
};

#endif // MATCHINPLAYOFF_H
