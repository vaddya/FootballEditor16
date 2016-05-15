#ifndef PLAYOFFSTAGE_H
#define PLAYOFFSTAGE_H

#include "../stage.h"
#include "../team.h"
#include "matchinplayoff.h"
#include "teaminplayoff.h"
#include "round.h"
#include "../Exceptions/wrongid.h"
#include "Exceptions/competitionisover.h"
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
    void createNewMatches();
    int getNumberOfRounds() const;
    vector<MatchInPlayoff> &getMatches();
    RoundEnum getCurrentRound() const;
    vector<Round> &getRounds();
    friend ostream& operator<<(ostream& os, PlayoffStage &playoff);

private:
    RoundEnum nextStage();
    Team &findTeam( int id );
    vector<Round> rounds;
    int numberOfRounds;
    RoundEnum currentRound;
};

#endif // PLAYOFFSTAGE_H
