#include "groupstage.h"

GroupStage::GroupStage(size_t num)
{
    numberOfGroups = num/4;
    groups.reserve(numberOfGroups);
}

void GroupStage::setListOfTeams(vector<Team> &teams)
{
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
    for (size_t i = 0; i < numberOfGroups; i++)
    {
        vector<Team> group(4);
        for (size_t j = 0; j < 4; j++)
            group.push_back(teams[i+j*4]);
        groups.push_back(Group(group));
    }
}
