#include "match.h"

Match::Match(Team &fteam, Team &steam): fteam(fteam), steam(steam), result("Hasn't started yet") {}

void Match::setResult(int fteamGoals, int steamGoals)
{
    fteam.setGoals(fteamGoals);
    steam.setGoals(steamGoals);
    updateResult();
}

string& Match::getResult()
{
    return result;
}

void Match::updateResult()
{
    ostringstream convert;
    convert << fteam.getGoals() << ':' << steam.getGoals();
    result = convert.str();
}
