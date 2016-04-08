#ifndef MATCH_H
#define MATCH_H

#include "team.h"
#include "teamstat.h"
#include "teamingroup.h"
#include "string"
#include "sstream"
#include "algorithm"
#include "idgenerator.h"

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
    Match(TeamInGroup& fTeam, TeamInGroup& sTeam);

    void setResult(int fTeamGoals, int sTeamGoals);
    string& getResult();
    int getId() { return id; }
    void simulate();

    TeamStat& getFirstTeam() { return fTeam; }
    TeamStat& getSecondTeam() { return sTeam; }

private:
    int id;
    TeamStat fTeam;
    TeamStat sTeam;
    TeamInGroup * fTeamGroup;
    TeamInGroup * sTeamGroup;
    string result;

    void updatePoints( int fTeamGoals, int sTeamGoals );
    void pickPoints( int fTeamGoals, int sTeamGoals );
    void updateResult();
};

#endif // MATCH_H
