#ifndef MATCH_H
#define MATCH_H

#include "teamstat.h"

class Match
{
public:
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
