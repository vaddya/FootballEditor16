#ifndef PLAYOFFSTAGE_H
#define PLAYOFFSTAGE_H

#include "team.h"
#include "matchinplayoff.h"
#include "stage.h"
#include "iostream"
#include "vector"
#include "iomanip"
#include "teaminplayoff.h"

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
    Team *findTeam( int id );
    friend ostream& operator<<(ostream& os, PlayoffStage &playoff);

private:
    vector<MatchInPlayoff> matches;
    int numberOfRounds;
};

#endif // PLAYOFFSTAGE_H
