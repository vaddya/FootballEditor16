#ifndef PLAYOFFSTAGE_H
#define PLAYOFFSTAGE_H

#include "../stage.h"
#include "../team.h"
#include "matchinplayoff.h"
#include "teaminplayoff.h"
#include "iostream"
#include "vector"
#include "iomanip"
using namespace std;

class MatchInPlayoff;

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
    Team &findTeam( int id );
    vector<MatchInPlayoff> &getMatches();
    friend ostream& operator<<(ostream& os, PlayoffStage &playoff);

private:
    vector<MatchInPlayoff> matches;
    int numberOfRounds;
};

#endif // PLAYOFFSTAGE_H
