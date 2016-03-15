#ifndef GROUPSTAGE_H
#define GROUPSTAGE_H

#include "competition.h"
/**
 * @brief The GroupStage class
 */
class GroupStage
{
public:
    /**
     * @brief Constructor of GroupStage
     * @param teams Vector of the teams
     */
    GroupStage(vector<Team> & teams);

private:
    vector<Team> teams;
};

#endif // GROUPSTAGE_H
