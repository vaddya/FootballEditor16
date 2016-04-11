#include "groupstage.h"

GroupStage::GroupStage(vector<Team> &teams): Stage(teams)
{
    numberOfGroups = teams.size()/4;
    groups.reserve(numberOfGroups);
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

unsigned GroupStage::getNumberOfGroups() const
{
    return numberOfGroups;
}

void GroupStage::sortTeams()
{
    //TODO implement sorting
}

void GroupStage::createGroups()
{
    for (unsigned i = 0; i < numberOfGroups; i++)
    {
        groups.push_back(Group(char(65+i)));
        for (unsigned j = 0; j < 4; j++) {
            groups.back().addTeam(getTeams()[i+j*4]);
        }
        groups.back().createMatches();
    }
}
