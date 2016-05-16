#include "teamstat.h"

TeamStat::TeamStat(Team &team): Team(team), goalsFor(0), goalsAgainst(0), possession(50), shots(0),
    shotsOnTarget(0), yellowCards(0), redCards(0), fouls(0) {}

void TeamStat::increaseGoals( int goalsFor_, int goalsAgainst_ )
{
    goalsFor += goalsFor_;
    goalsAgainst += goalsAgainst_;
}

void TeamStat::decreaseGoals( int goalsFor_, int goalsAgainst_ )
{
    goalsFor -= goalsFor_;
    goalsAgainst -= goalsAgainst_;
}

void TeamStat::setGoals( int goalsFor_, int goalsAgainst_ )
{
    goalsFor = goalsFor_;
    goalsAgainst = goalsAgainst_;
}

void TeamStat::setPossession( int possession_ )
{
    possession = possession_;
}

void TeamStat::setShots( int shots_ )
{
    shots = shots_;
}

void TeamStat::setShotOnTarget( int shotsOnTarget_ )
{
    shotsOnTarget = shotsOnTarget_;
}

void TeamStat::setYellowCards( int yellowCards_ )
{
    yellowCards = yellowCards_;
}

void TeamStat::setRedCards( int redCards_ )
{
    redCards = redCards_;
}

void TeamStat::setFouls( int fouls_ )
{
    fouls = fouls_;
}

int TeamStat::getGoalsFor() const
{
    return goalsFor;
}

int TeamStat::getGoalsAgainst() const
{
    return goalsAgainst;
}

int TeamStat::getGoalsDiffrence() const
{
    return goalsFor-goalsAgainst;
}

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

void TeamStat::clear()
{
    goalsFor = 0;
    goalsAgainst = 0;
    possession = 50;
    shots = 0;
    shotsOnTarget = 0;
    yellowCards = 0;
    redCards = 0;
    fouls = 0;
}
