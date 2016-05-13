#include "competition.h"

Competition::Competition()
{
    title = "Competition";
    numberOfTeams = 0;
    groupStage = 0;
    playoffStage = 0;
}

void Competition::setTitle(string title)
{
    this->title = title;
}

void Competition::addTeam(string name)
{
    teams.push_back(Team(name));
    numberOfTeams++;
}

string &Competition::getTitle()
{
    return title;
}

unsigned Competition::getNumberOfTeams() const
{
    return numberOfTeams;
}

vector<Team> &Competition::getTeams()
{
    return teams;
}

void Competition::startGroupStage()
{
    if (numberOfTeams % 4 == 0 && numberOfTeams != 0) {
        groupStage = new GroupStage(teams);
        groupStage->launch();
        groupStage->createGroups();
    }
    else
        throw WrongNumberOfTeams(numberOfTeams);
}

void Competition::startGroupStage(vector<int> teamIDs)
{
    if (numberOfTeams % 4 == 0 && numberOfTeams != 0) {
        groupStage = new GroupStage(teams);
        groupStage->launch();
        groupStage->createGroups(teamIDs);
    }
    else
        throw WrongNumberOfTeams(numberOfTeams);
}

GroupStage &Competition::getGroupStage()
{
    if (groupStage != 0)
        return *groupStage;
    else
        throw GroupsAreNotCreated();
}

PlayoffStage &Competition::getPlayoffStage()
{
    return *playoffStage;
}

void Competition::startPlayOffStage()
{
    if (groupStage != 0 && groupStage->getWinners().size() != 0) {
        playoffStage = new PlayoffStage(groupStage->getWinners());
        playoffStage->launch();
    }
    else
        throw GroupStageIsNotOver();
}

void Competition::startPlayOffStage(vector<int> teamIDs)
{
    if (groupStage->getWinners().size() != 0) {
        playoffStage = new PlayoffStage(groupStage->getWinners());
        playoffStage->launch();
        playoffStage->createMatches(teamIDs);
    }
    else
        throw GroupStageIsNotOver();
}

Competition::~Competition()
{
    if (groupStage != 0)
        delete groupStage;
    if (playoffStage != 0)
        delete playoffStage;
}
