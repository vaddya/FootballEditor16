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

//class MatchInPlayoff;

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
    vector<Round> rounds;
    vector<MatchInPlayoff> matches;
    int numberOfRounds;
};

#endif // PLAYOFFSTAGE_H
