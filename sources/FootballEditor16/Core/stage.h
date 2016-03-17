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
    virtual void setListOfTeams(vector<Team> &teams) = 0;
    virtual void launch() = 0;
    virtual ~Stage() {}
};

#endif // STAGE_H
