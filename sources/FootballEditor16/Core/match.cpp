#include "match.h"

Match::Match(TeamInGroup &fteam, TeamInGroup &steam): fTeam(fteam), sTeam(steam), fTeamGroup(&fteam), sTeamGroup(&steam), result("Hasn't started yet")
{
    IdGenerator *idGen = IdGenerator::IdGeneratorInstance();
    id = idGen->getFirstId();
}

void Match::setResult(int fTeamGoals, int sTeamGoals)
{
    if (result != "Hasn't started yet")
        pickPoints(fTeam.getGoals(), sTeam.getGoals()); // pick previously acquired points
    fTeam.setGoals(fTeamGoals);
    sTeam.setGoals(sTeamGoals);
    updatePoints(fTeamGoals, sTeamGoals);
    updateResult();
}

string& Match::getResult()
{
    return result;
}

void Match::updatePoints(int fTeamGoals, int sTeamGoals)
{
    if (fTeamGoals > sTeamGoals)
        fTeamGroup->increasePoints(3);
    if (fTeamGoals < sTeamGoals)
        sTeamGroup->increasePoints(3);
    if (fTeamGoals == sTeamGoals) {
        fTeamGroup->increasePoints(1);
        sTeamGroup->increasePoints(1);
    }
}

void Match::pickPoints(int fTeamGoals, int sTeamGoals)
{
    if (fTeamGoals > sTeamGoals)
        fTeamGroup->increasePoints(-3);
    if (fTeamGoals < sTeamGoals)
        sTeamGroup->increasePoints(-3);
    if (fTeamGoals == sTeamGoals) {
        fTeamGroup->increasePoints(-1);
        sTeamGroup->increasePoints(-1);
    }
}

void Match::updateResult()
{
    ostringstream convert;
    convert << fTeam.getGoals() << ':' << sTeam.getGoals();
    result = convert.str();
}
