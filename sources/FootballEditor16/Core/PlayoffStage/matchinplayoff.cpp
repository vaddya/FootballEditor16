#include "PlayoffStage/matchinplayoff.h"

MatchInPlayoff::MatchInPlayoff(): Match()
{

}

MatchInPlayoff::MatchInPlayoff(TeamInPlayoff &firstTeam, TeamInPlayoff &secondTeam): Match(firstTeam, secondTeam),
    firstTeamInPlayoff(&firstTeam), secondTeamInPlayoff(&secondTeam) {}

void MatchInPlayoff::setResult(int firstTeamGoals, int secondTeamGoals)
{
    firstTeamGoals++; // temp
    secondTeamGoals++;
}

TeamInPlayoff *MatchInPlayoff::getWinner()
{
    return firstTeam.getGoalsFor() > secondTeam.getGoalsFor() ? firstTeamInPlayoff : secondTeamInPlayoff;
}

