#include "groupstage.h"

GroupStage::GroupStage(vector<Team> &teams)
{
    numberOfGroups = teams.size()/4;
    groups.reserve(numberOfGroups);
    this->teams = teams;
    sortTeams();
}

void GroupStage::launch()
{
    createGroups();
}

vector<Group> &GroupStage::getGroups()
{
    return groups;
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
        for (unsigned j = 0; j < 4; j++) {
            group[j] = teams[i+j*4];
        }
        groups.push_back(Group(group, char(65+i)));
        groups.back().createMatches();
    }
}
