#ifndef PLAYOFFSTAGE_H
#define PLAYOFFSTAGE_H

#include "../stage.h"
#include "../team.h"
#include "matchinplayoff.h"
#include "teaminplayoff.h"
#include "round.h"
#include "iostream"
#include "vector"
#include "iomanip"

using std::vector;
using std::endl;
using std::setw;

/**
 * @brief The PlayoffStage class
 */
class PlayoffStage : public Stage
{
public:
    PlayoffStage( vector<Team>& teams );
    /**
     * @brief Launch this stage
     */
    void launch();
    void createMatches( vector<int> teamIDs );
    vector<MatchInPlayoff> &getMatches();
    RoundEnum getCurrentRound() const;
    vector<Round> &getRounds();
    friend ostream& operator<<(ostream& os, PlayoffStage &playoff);

private:
    RoundEnum nextStage();
    void createNewMatches();
    Team &findTeam( int id );
    vector<Round> rounds;
    int numberOfRounds;
    RoundEnum currentRound;
};

#endif // PLAYOFFSTAGE_H
