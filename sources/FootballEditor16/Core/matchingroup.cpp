#include "matchingroup.h"

MatchInGroup::MatchInGroup(TeamInGroup &firstTeam, TeamInGroup &secondTeam): Match(firstTeam, secondTeam),
    firstTeamInGroup(&firstTeam), secondTeamInGroup(&secondTeam) {}

void MatchInGroup::setResult(int firstTeamGoals, int secondTeamGoals)
{
    if (result != "Hasn't started yet")
        pickPointsBack( firstTeam.getGoalsFor(), secondTeam.getGoalsFor() ); // pick previously acquired points
    firstTeam.setGoals( firstTeamGoals, secondTeamGoals );
    secondTeam.setGoals( secondTeamGoals, firstTeamGoals );
    updatePoints( firstTeamGoals, secondTeamGoals );
    updateResult();
}

void MatchInGroup::clear()
{
    pickPointsBack(firstTeam.getGoalsFor(), secondTeam.getGoalsFor());
    firstTeam.setGoals(0, 0);
    secondTeam.setGoals(0, 0);
    result = "Hasn't started yet";
}


void MatchInGroup::updatePoints(int fTeamGoals, int sTeamGoals)
{
    firstTeamInGroup->increaseGoals( fTeamGoals, sTeamGoals );
    secondTeamInGroup->increaseGoals( sTeamGoals, fTeamGoals );
    if (fTeamGoals > sTeamGoals) {
        firstTeamInGroup->win();
        secondTeamInGroup->lose();
    }
    if (fTeamGoals < sTeamGoals) {
        firstTeamInGroup->lose();
        secondTeamInGroup->win();
    }
    if (fTeamGoals == sTeamGoals) {
        firstTeamInGroup->draw();
        secondTeamInGroup->draw();
    }
}

void MatchInGroup::pickPointsBack(int fTeamGoals, int sTeamGoals)
{
    if (fTeamGoals > sTeamGoals) {
        firstTeamInGroup->unWin();
        secondTeamInGroup->unLose();
    }
    if (fTeamGoals < sTeamGoals) {
        firstTeamInGroup->unLose();
        secondTeamInGroup->unWin();
    }
    if (fTeamGoals == sTeamGoals) {
        firstTeamInGroup->unDraw();
        secondTeamInGroup->unDraw();
    }
}


ostream& operator<<( ostream &os, MatchInGroup &match )
{
    os << "(" << match.getId() << ") " << match.getFirstTeam();
    if (match.getResult() == "Hasn't started yet")
        os << " vs ";
    else
        os << " " << match.getResult() << " ";
    os << match.getSecondTeam();
    return os;
}

istream& operator>>( istream &is, MatchInGroup &match )
{
    int goalsOfFirstTeam, goalsOfSecondTeam;
    char separator;
    is >> goalsOfFirstTeam >> separator >> goalsOfSecondTeam;
    match.setResult(goalsOfFirstTeam, goalsOfSecondTeam);
    return is;
}
