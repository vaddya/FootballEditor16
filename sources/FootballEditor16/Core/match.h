#ifndef MATCH_H
#define MATCH_H

#include "team.h"

class Match
{
public:
    Match(string& ftm, string& stm);
    Match(string& ftm, string& stm, int ftmGoals, int stmGoals);
    void setResult(int ftmGoals, int stmGoals);
    void simulate();

    string& getFirstTeam();
    string& getSecondTeam();

    void getResult();
private:
    Team fteam;
    Team steam;
    int fteamGoals;
    int steamGoals;
};

#endif // MATCH_H
