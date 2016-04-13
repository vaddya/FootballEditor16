#ifndef STAGE_H
#define STAGE_H

#include "vector"
#include "team.h"
using namespace std;

/**
 * @brief The Stage class
 */
class Stage
{
public:
    /**
     * @brief Launch this stage
     */
    Stage(vector<Team>& teams): teams(teams) {}
    /**
     * @brief Get vector of teams participating in the competition
     * @return vector of teams
     */
    vector<Team>& getTeams() { return teams; }
    /**
     * @brief Launch the stage
     */
    virtual void launch() = 0;

    virtual ~Stage() {}
private:
    vector<Team>& teams;
};

#endif // STAGE_H
