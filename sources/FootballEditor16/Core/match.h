#ifndef MATCH_H
#define MATCH_H

#include "teamstat.h"
#include "team.h"

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
    void simulate();

    TeamStat& getFirstTeam() { return fteam; }
    TeamStat& getSecondTeam() { return steam; }

private:
    TeamStat fteam;
    TeamStat steam;
};

#endif // MATCH_H
