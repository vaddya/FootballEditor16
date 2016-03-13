#ifndef MATCH_H
#define MATCH_H

#include "teamstat.h"

class Match
{
public:
    Match(Team& ftm, Team& stm): fteam(ftm), steam(stm) {}

    void setResult(int ftmGoals, int stmGoals);
    void simulate();

    string& getFirstTeam();
    string& getSecondTeam();
    string getResult();
private:
    TeamStat fteam;
    TeamStat steam;
};

#endif // MATCH_H
