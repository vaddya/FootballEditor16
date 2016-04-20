#ifndef PLAYOFFSTAGE_H
#define PLAYOFFSTAGE_H

#include "stage.h"
#include "iostream"
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
    void createPairs(vector<int> teamIDs);
    friend ostream& operator<<(ostream& os, PlayoffStage &playoff);
};

#endif // PLAYOFFSTAGE_H
