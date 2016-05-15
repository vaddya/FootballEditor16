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
    if( numberOfTeams % 4 == 0 && numberOfTeams != 0 ) {
        groupStage = new GroupStage(teams);
        groupStage->launch();
        groupStage->createGroups();
    }
    else
        throw WrongNumberOfTeams(numberOfTeams);
}

void Competition::startGroupStage(vector<int> teamIDs)
{
    if( numberOfTeams % 4 == 0 && numberOfTeams != 0 ) {
        groupStage = new GroupStage(teams);
        groupStage->launch();
        try {
            groupStage->createGroups(teamIDs);
        }
        catch( WrongID& e ) {
            delete groupStage;
            groupStage = 0;
            throw;
        }
    }
    else
        throw WrongNumberOfTeams(numberOfTeams);
}

GroupStage &Competition::getGroupStage()
{
    if( groupStage != 0 )
        return *groupStage;
    else
        throw GroupsAreNotCreated();
}

PlayoffStage &Competition::getPlayoffStage()
{
    if( playoffStage != 0 )
        return *playoffStage;
    else
        throw GroupStageIsNotOver();
}

void Competition::startPlayOffStage()
{
    if( groupStage != 0 && groupStage->getWinners().size() != 0 ) {
        playoffStage = new PlayoffStage(groupStage->getWinners());
        playoffStage->launch();
    }
    else
        throw GroupStageIsNotOver();
}

void Competition::startPlayOffStage(vector<int> teamIDs)
{
    if( groupStage->getWinners().size() != 0 ) {
        playoffStage = new PlayoffStage(groupStage->getWinners());
        playoffStage->launch();
        try {
            playoffStage->createMatches(teamIDs);
        }
        catch( WrongID& e ) {
            delete playoffStage;
            playoffStage = 0;
            //playoffStage = new PlayoffStage(groupStage->getWinners());
            //playoffStage->launch();
            throw;
        }
    }
    else
        throw GroupStageIsNotOver();
}

Competition::~Competition()
{
    if( groupStage )
        delete groupStage;
    if( playoffStage )
        delete playoffStage;
}
