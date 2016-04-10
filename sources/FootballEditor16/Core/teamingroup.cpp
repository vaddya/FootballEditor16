#include "teamingroup.h"

bool operator < ( const TeamInGroup &one, const TeamInGroup &another ) {
    if (one.getPoints() < another.getPoints())
        return true;
    else
        return false;
}

void TeamInGroup::increasePoints( int points_ )
{
    points += points_;
}

void TeamInGroup::increaseGames(int games_)
{
    games += games_;
}

void TeamInGroup::increaseWins(int wins_)
{
    wins += wins_;
}

void TeamInGroup::increaseDrawns(int drawn_)
{
    drawns += drawn_;
}

void TeamInGroup::increaseLoses(int loses_)
{
    loses += loses_;
}

int TeamInGroup::getPoints() const
{
    return points;
}

int TeamInGroup::getGames() const
{
    return games;
}

int TeamInGroup::getWins() const
{
    return wins;
}

int TeamInGroup::getDrawns() const
{
    return drawns;
}

int TeamInGroup::getLoses() const
{
    return loses;
}
