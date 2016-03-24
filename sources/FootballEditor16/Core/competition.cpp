#include "competition.h"

Competition::Competition(size_t num)
{
    if (num % 2 == 0 || true)
        numberOfTeams = num;
    else
        throw WrongNumberOfTeams(num);
    groupStage = new GroupStage(num);
    playoffStage = new PlayoffStage();
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

string Competition::getTitle()
{
    return title;
}

int Competition::getNumberOfTeams()
{
    return numberOfTeams;
}

vector<Team> &Competition::getTeams()
{
    return teams;
}

void Competition::startGroupStage()
{
    std::cout << "launch";
    groupStage->launch();
}

GroupStage &Competition::getGroupStage()
{
    return *groupStage;
}

void Competition::startPlayOffStage()
{
    playoffStage->launch();
}

Competition::~Competition()
{
    delete groupStage;
    delete playoffStage;
}
