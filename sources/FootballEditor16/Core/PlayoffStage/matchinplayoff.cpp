#include "PlayoffStage/matchinplayoff.h"

MatchInPlayoff::MatchInPlayoff( RoundEnum round, TeamInPlayoff &firstTeam, TeamInPlayoff &secondTeam ): Match(firstTeam, secondTeam), round(round),
    firstTeamInPlayoff(&firstTeam), secondTeamInPlayoff(&secondTeam), isWithPenalty(false) {}

void MatchInPlayoff::setResult(int firstTeamGoals, int secondTeamGoals)
{
    firstTeam.setGoals( firstTeamGoals, secondTeamGoals );
    secondTeam.setGoals( secondTeamGoals, firstTeamGoals );
    updateResult();
}

TeamInPlayoff *MatchInPlayoff::getWinner()
{
    return firstTeam.getGoalsFor() > secondTeam.getGoalsFor() ? firstTeamInPlayoff : secondTeamInPlayoff;
}
