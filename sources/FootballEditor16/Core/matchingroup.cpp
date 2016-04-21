#include "matchingroup.h"

MatchInGroup::MatchInGroup(TeamInGroup &firstTeam, TeamInGroup &secondTeam): Match(firstTeam, secondTeam), firstTG(&firstTeam), secondTG(&secondTeam)
{

}

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
    firstTG->increaseGoals( fTeamGoals, sTeamGoals );
    secondTG->increaseGoals( sTeamGoals, fTeamGoals );
    if (fTeamGoals > sTeamGoals) {
        firstTG->win();
        secondTG->lose();
    }
    if (fTeamGoals < sTeamGoals) {
        firstTG->lose();
        secondTG->win();
    }
    if (fTeamGoals == sTeamGoals) {
        firstTG->draw();
        secondTG->draw();
    }
}

void MatchInGroup::pickPointsBack(int fTeamGoals, int sTeamGoals)
{
    if (fTeamGoals > sTeamGoals) {
        firstTG->unWin();
        secondTG->unLose();
    }
    if (fTeamGoals < sTeamGoals) {
        firstTG->unLose();
        secondTG->unWin();
    }
    if (fTeamGoals == sTeamGoals) {
        firstTG->unDraw();
        secondTG->unDraw();
    }
}
