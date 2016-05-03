#include "groupstage.h"

GroupStage::GroupStage(vector<Team> &teams): Stage(teams)
{
    numberOfGroups = teams.size()/4;
    groups.reserve(numberOfGroups);
    winners.reserve(numberOfGroups*2);
    sortTeams();
}

void GroupStage::launch()
{
    //createGroups();
}

vector<Group> &GroupStage::getGroups()
{
    return groups;
}

unsigned GroupStage::getNumberOfGroups() const
{
    return numberOfGroups;
}

void GroupStage::determineWinners()
{
    winners.clear();
    vector<Team> winnersOfGroup;
    for (Group group: groups) {
        group.sort();
        winnersOfGroup = group.getWinners();
        winners.insert(winners.end(), winnersOfGroup.begin(), winnersOfGroup.end());
    }
}

vector<Team>& GroupStage::getWinners()
{
    determineWinners();
    return winners;
}

Group &GroupStage::getGroup( char id )
{
    for( Group &group: groups )
        if ( id == group.getId() )
            return group;
    throw WrongID( id );
}

void GroupStage::sortTeams()
{
    //TODO implement sorting
}

void GroupStage::createGroups()
{
    for( unsigned i = 0; i < numberOfGroups; i++ ) {
        groups.push_back(Group());
        for( unsigned j = 0; j < 4; j++ )
            groups.back().addTeam(getTeams()[i+j*4]);
        groups.back().createMatches();
    }
}

void GroupStage::createGroups( vector<int> teamIDs )
{
    int id = 0;
    for( unsigned i = 0; i < numberOfGroups; i++ )
    {
        groups.push_back(Group());
        for( unsigned j = 0; j < 4; j++ )
            groups.back().addTeam(getTeams()[teamIDs[id++]]);
        groups.back().createMatches();
    }
}
