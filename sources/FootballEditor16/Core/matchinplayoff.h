#ifndef MATCHINPLAYOFF_H
#define MATCHINPLAYOFF_H

#include "playoffstage.h"
#include "match.h"
#include "teaminplayoff.h"

enum Round {
    FINAL = 2, SEMIFINAL = 4, QUARTERFINALS = 8, ROUNDOF16 = 16,
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
