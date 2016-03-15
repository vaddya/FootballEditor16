#include "competition.h"

Competition::Competition(int num): numberOfTeams(num) {}

void Competition::setTitle(std::string &name)
{
    title = name;
}

void Competition::setListOfTeams(vector<Team> &teams)
{
    listOfTeams = teams;
}

std::string &Competition::getTitle()
{
    return title;
}

void Competition::startGroupStage()
{
    //TODO realization
}

void Competition::startPlayOffGames()
{
    //TODO realization
}
