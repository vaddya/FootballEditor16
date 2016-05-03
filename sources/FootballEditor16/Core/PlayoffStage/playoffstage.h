#ifndef PLAYOFFSTAGE_H
#define PLAYOFFSTAGE_H

#include "../stage.h"
#include "../team.h"
#include "matchinplayoff.h"
#include "teaminplayoff.h"
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
    friend ostream& operator<<(ostream& os, PlayoffStage &playoff);

private:
    Team &findTeam( int id );
    vector<MatchInPlayoff> matches;
    int numberOfRounds;
    Round currentRound;
};

#endif // PLAYOFFSTAGE_H
