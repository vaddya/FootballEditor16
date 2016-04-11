#include "match.h"

Match::Match(TeamInGroup &firstTeam, TeamInGroup &secondTeam): firstTeam(firstTeam),
    secondTeam(secondTeam), firstTG(&firstTeam), secondTG(&secondTeam), result("Hasn't started yet")
{
    IdGenerator *idGen = IdGenerator::IdGeneratorInstance();
    id = idGen->getFirstId();
}

void Match::setResult(int firstTeamGoals, int secondTeamGoals)
{
    if (result != "Hasn't started yet")
        pickPointsBack(firstTeam.getGoals(), secondTeam.getGoals()); // pick previously acquired points
    firstTeam.setGoals(firstTeamGoals);
    secondTeam.setGoals(secondTeamGoals);
    updatePoints(firstTeamGoals, secondTeamGoals);
    updateResult();
}

string& Match::getResult()
{
    return result;
}

int Match::getId() const
{
    return id;
}

void Match::simulate()
{
    Randomiser *randomiser = Randomiser::RandomiserInstance();
    int firstTeamGoals = randomiser->random(0, 4);
    int secondTeamGoals = randomiser->random(0, 4);
    setResult(firstTeamGoals, secondTeamGoals);
}

ostream& operator<<(ostream &os, Match &match)
{
    os << "(" << match.getId() << ") " << match.getFirstTeam();
    if (match.getResult() == "Hasn't started yet")
        os << " vs ";
    else
        os << " " << match.getResult() << " ";
    os << match.getSecondTeam() << endl;
    return os;
}

void Match::updatePoints(int fTeamGoals, int sTeamGoals)
{
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

void Match::pickPointsBack(int fTeamGoals, int sTeamGoals)
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

void Match::updateResult()
{
    ostringstream convert;
    convert << firstTeam.getGoals() << ':' << secondTeam.getGoals();
    result = convert.str();
}
