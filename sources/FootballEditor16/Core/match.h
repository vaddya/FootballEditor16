#ifndef MATCH_H
#define MATCH_H

#include "teamstat.h"
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

    string & getFirstTeam() { return fteam.getName(); }
    string & getSecondTeam() { return steam.getName(); }
    string getResult() const;

private:
    TeamStat fteam;
    TeamStat steam;
};

#endif // MATCH_H
