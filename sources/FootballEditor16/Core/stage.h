#ifndef STAGE_H
#define STAGE_H

#include "vector"
#include "team.h"
using namespace std;

class Stage
{
public:
    /**
     * @brief Launch this stage
     */
    Stage(vector<Team>& teams): teams(teams) {}
    vector<Team>& getTeams() { return teams; }
    virtual void launch() = 0;
    virtual ~Stage() {}
private:
    vector<Team>& teams;
};

#endif // STAGE_H
