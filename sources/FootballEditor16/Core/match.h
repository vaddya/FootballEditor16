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
     * @param ftm First team
     * @param stm Second team
     */
    Match(Team& ftm, Team& stm);

    void setResult(int ftmGoals, int stmGoals);
    void simulate();

    string& getFirstTeam() const;
    string& getSecondTeam() const;
    string getResult() const;

private:
    TeamStat fteam;
    TeamStat steam;
};

#endif // MATCH_H
