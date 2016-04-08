#ifndef MATCH_H
#define MATCH_H

#include "team.h"
#include "teamstat.h"
#include "teamingroup.h"
#include "string"
#include "sstream"
#include "algorithm"
#include "idgenerator.h"
#include "randomiser.h"

using std::string;
using std::ostringstream;

/**
 * @brief The Match class
 */
class Match
{
public:
    /**
     * @brief Constructor of Match
     * @param fteam First team
     * @param steam Second team
     */
    Match(TeamInGroup& firstTeam, TeamInGroup& secondTeam);

    void setResult(int fTeamGoals, int sTeamGoals);
    string& getResult();
    int getId() { return id; }
    void simulate();

    TeamStat& getFirstTeam() { return firstTeam; }
    TeamStat& getSecondTeam() { return secondTeam; }

private:
    int id;
    TeamStat firstTeam;
    TeamStat secondTeam;
    TeamInGroup * firstTeamGroup;
    TeamInGroup * secondTeamGroup;
    string result;

    void updatePoints( int fTeamGoals, int sTeamGoals );
    void pickPoints( int fTeamGoals, int sTeamGoals );
    void updateResult();
};

#endif // MATCH_H
