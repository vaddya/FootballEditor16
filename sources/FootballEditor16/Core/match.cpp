#include "match.h"

Match::Match(TeamInGroup &fteam, TeamInGroup &steam): firstTeam(fteam), secondTeam(steam), firstTeamGroup(&fteam), secondTeamGroup(&steam), result("Hasn't started yet")
{
    IdGenerator *idGen = IdGenerator::IdGeneratorInstance();
    id = idGen->getFirstId();
}

void Match::setResult(int firstTeamGoals, int secondTeamGoals)
{
    if (result != "Hasn't started yet")
        pickPoints(firstTeam.getGoals(), secondTeam.getGoals()); // pick previously acquired points
    firstTeam.setGoals(firstTeamGoals);
    secondTeam.setGoals(secondTeamGoals);
    updatePoints(firstTeamGoals, secondTeamGoals);
    updateResult();
}

string& Match::getResult()
{
    return result;
}

void Match::simulate()
{
    Randomiser *randomiser = Randomiser::RandomiserInstance();
    int firstTeamGoals = randomiser->random(0, 4);
    int secondTeamGoals = randomiser->random(0, 4);
    setResult(firstTeamGoals, secondTeamGoals);
}

void Match::updatePoints(int fTeamGoals, int sTeamGoals)
{
    if (fTeamGoals > sTeamGoals)
        firstTeamGroup->increasePoints(3);
    if (fTeamGoals < sTeamGoals)
        secondTeamGroup->increasePoints(3);
    if (fTeamGoals == sTeamGoals) {
        firstTeamGroup->increasePoints(1);
        secondTeamGroup->increasePoints(1);
    }
}

void Match::pickPoints(int fTeamGoals, int sTeamGoals)
{
    if (fTeamGoals > sTeamGoals)
        firstTeamGroup->increasePoints(-3);
    if (fTeamGoals < sTeamGoals)
        secondTeamGroup->increasePoints(-3);
    if (fTeamGoals == sTeamGoals) {
        firstTeamGroup->increasePoints(-1);
        secondTeamGroup->increasePoints(-1);
    }
}

void Match::updateResult()
{
    ostringstream convert;
    convert << firstTeam.getGoals() << ':' << secondTeam.getGoals();
    result = convert.str();
}
