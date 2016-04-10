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

string& Competition::getTitle()
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
    }
    else
        throw WrongNumberOfTeams(numberOfTeams);
}

GroupStage& Competition::getGroupStage()
{
    if (groupStage != 0)
        return *groupStage;
    else
        throw GroupAreNotCreated();
}

void Competition::startPlayOffStage()
{
    playoffStage->launch();
}

Competition::~Competition()
{
    if (groupStage != 0)
        delete groupStage;
    if (playoffStage != 0)
        delete playoffStage;
}
