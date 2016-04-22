#ifndef PLAYOFFSTAGE_H
#define PLAYOFFSTAGE_H

#include "team.h"
#include "match.h"
#include "stage.h"
#include "iostream"
#include "vector"
#include "iomanip"

using namespace std;

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

    friend ostream& operator<<(ostream& os, PlayoffStage &playoff);

private:
    vector<Match> matches;
};

#endif // PLAYOFFSTAGE_H
