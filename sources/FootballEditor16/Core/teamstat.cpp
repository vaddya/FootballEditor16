#include "teamstat.h"

TeamStat::TeamStat(Team &team): Team(team) {}

void TeamStat::setGoals(int goals_)
{
    goals = goals_;
}

void TeamStat::setPossession(int possession_)
{
    possession = possession_;
}

void TeamStat::setShots(int shots_)
{
    shots = shots_;
}

void TeamStat::setShotOnTarget(int shotsOnTarget_)
{
    shotsOnTarget = shotsOnTarget_;
}

void TeamStat::setYellowCards(int yellowCards_)
{
    yellowCards = yellowCards_;
}

void TeamStat::setRedCards(int redCards_)
{
    redCards = redCards_;
}

void TeamStat::setFouls(int fouls_)
{
    fouls = fouls_;
}

int TeamStat::getGoals() const
{
    return goals; }

int TeamStat::getPossession() const
{
    return possession;
}

int TeamStat::getShots() const
{
    return shots;
}

int TeamStat::getShotOnTarget() const
{
    return shotsOnTarget;
}

int TeamStat::getYellowCards() const
{
    return yellowCards; }

int TeamStat::getRedCards() const
{
    return redCards;
}

int TeamStat::getFouls() const
{
    return fouls;
}
