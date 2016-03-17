#include "competition.h"

Competition::Competition(size_t num)
{
    if (num % 2 == 0 || true)
        numberOfTeams = num;
    else
        throw WrongNumberOfTeams(num);
    groupstage = new GroupStage(num);
    playoffstage = new PlayoffStage();
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
    groupstage->launch();
}

void Competition::enterResultsOfGroupStage()
{
    //TODO implement me
}

void Competition::startPlayOffStage()
{
    playoffstage->launch();
}

Competition::~Competition()
{
    delete groupstage;
    delete playoffstage;
}
