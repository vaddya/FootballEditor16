#ifndef MATCH_H
#define MATCH_H

#include "teamstat.h"
#include "team.h"
#include "string"
#include "sstream"

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
    Match(Team& fteam, Team& steam);

    void setResult(int fteamGoals, int steamGoals);
    string& getResult();
    void simulate();

    TeamStat& getFirstTeam() { return fteam; }
    TeamStat& getSecondTeam() { return steam; }

private:
    TeamStat fteam;
    TeamStat steam;
    string result;

    void updateResult();
};

#endif // MATCH_H
