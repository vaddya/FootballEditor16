#ifndef MATCHINPLAYOFF_H
#define MATCHINPLAYOFF_H

#include "../match.h"
#include "teaminplayoff.h"
/**
 * @brief The Penalty struct
 */
struct Penalty {
    int firstTeamPenaltyScore = 0;
    int secondTeamPenaltyScore = 0;
};

enum RoundEnum {
    END = 0, FINAL = 1, SEMIFINAL = 2, QUARTERFINAL = 4, ROUNDOF16 = 8, // stages 1, 1/2, 1/4, 1/8
};

/**
 * @brief The MatchInPlayoff class
 */
class MatchInPlayoff : public Match
{
public:
    MatchInPlayoff( TeamInPlayoff &firstTeam, TeamInPlayoff &secondTeam );
    void setResult( int firstTeamGoals, int secondTeamGoals );
    TeamInPlayoff &getWinner();

private:
    TeamInPlayoff firstTeamInPlayoff;
    TeamInPlayoff secondTeamInPlayoff;
    bool isWithPenalty;
    Penalty penalty;
};

#endif // MATCHINPLAYOFF_H
