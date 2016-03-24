#include "groupstage.h"
#include "iostream"

GroupStage::GroupStage(unsigned num, vector<Team> &teams)
{
    numberOfGroups = num/4;
    groups.reserve(numberOfGroups);
    this->teams = teams;
    sortTeams();
}

void GroupStage::launch()
{
    createGroups();
}

void GroupStage::sortTeams()
{
    //TODO implement sorting
}

void GroupStage::createGroups()
{
    for (unsigned i = 0; i < numberOfGroups; i++)
    {
        vector<Team> group(4);
        for (unsigned j = 0; j < 4; j++)
            group.push_back(teams[i+j*4]);
        groups.push_back(Group(group));
        groups.back().createMatches();
    }
}
