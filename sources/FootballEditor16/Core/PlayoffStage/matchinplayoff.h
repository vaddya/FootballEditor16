#ifndef MATCHINPLAYOFF_H
#define MATCHINPLAYOFF_H

#include "teaminplayoff.h"
#include "roundenum.h"
#include "../match.h"
#include "../PlayoffStage/Exceptions/inputpenaltryscore.h"
#include "../PlayoffStage/Exceptions/wrongpenaltyscore.h"
#include "iomanip"
#include "sstream"
using std::setw;

struct Penalty {
    int firstTeamPenaltyScore = 0;
    int secondTeamPenaltyScore = 0;
};

/**
 * @brief The MatchInPlayoff class
 */
class MatchInPlayoff : public Match
{
public:
    MatchInPlayoff( TeamInPlayoff &firstTeam, TeamInPlayoff &secondTeam );
    void setResult( int firstTeamGoals, int secondTeamGoals );
    void setPenaltyScore( int firstTeamPenaltyScore, int secondTeamPenaltyScore );
    void simulate();
    TeamInPlayoff &getWinner();
    string showFirstTeam();
    string showSecondTeam();
    bool isWithPenalty();
    Penalty &getPenalty();

private:
    void updateResult();
    TeamInPlayoff firstTeamInPlayoff;
    TeamInPlayoff secondTeamInPlayoff;
    bool withPenalty;
    Penalty penalty;
};

#endif // MATCHINPLAYOFF_H
