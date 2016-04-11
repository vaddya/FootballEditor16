#include "teamingroup.h"

bool operator < ( const TeamInGroup &one, const TeamInGroup &another ) {
    if (one.getPoints() < another.getPoints())
        return true;
    else
        return false;
}

void TeamInGroup::win()
{
    ++wins;
    points += 3;
}

void TeamInGroup::draw()
{
    ++draws;
    ++points;
}

void TeamInGroup::lose()
{
    ++loses;
}

void TeamInGroup::unWin()
{
    --wins;
    points -= 3;
}

void TeamInGroup::unDraw()
{
    --draws;
    --points;
}

void TeamInGroup::unLose()
{
    --loses;
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

int TeamInGroup::getDraws() const
{
    return draws;
}

int TeamInGroup::getLoses() const
{
    return loses;
}
