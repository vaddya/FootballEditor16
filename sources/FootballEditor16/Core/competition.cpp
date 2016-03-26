#include "competition.h"

Competition::Competition()
{
    title = "Competition1";
}

void Competition::setTitle(string title)
{
    this->title = title;
}

void Competition::setListOfTeams(vector<Team>& teams)
{
    if (teams.size() == numberOfTeams)
        this->teams = teams;
    else
        throw WrongListOfTeams();
}

void Competition::addTeam(string name, int fifaRating)
{
    teams.push_back(Team(name, fifaRating));
    numberOfTeams++;
}

string& Competition::getTitle()
{
    return title;
}

size_t Competition::getNumberOfTeams() const
{
    return numberOfTeams;
}

vector<Team> &Competition::getTeams()
{
    return teams;
}

void Competition::startGroupStage()
{
    if (numberOfTeams % 2 == 0 || true) {
        groupStage = new GroupStage(numberOfTeams, teams);
        groupStage->launch();
    }
    else
        throw WrongNumberOfTeams(numberOfTeams);
}

GroupStage &Competition::getGroupStage()
{
    return *groupStage;
}

void Competition::startPlayOffStage()
{
    //playoffStage->launch();
}

Competition::~Competition()
{
    delete groupStage;
}
