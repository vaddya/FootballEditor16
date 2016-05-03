#include "teamingroup.h"

void TeamInGroup::win()
{
    ++games;
    ++wins;
    points += 3;
}

void TeamInGroup::draw()
{
    ++games;
    ++draws;
    ++points;
}

void TeamInGroup::lose()
{
    ++games;
    ++loses;
}

void TeamInGroup::unWin()
{
    --games;
    --wins;
    points -= 3;
}

void TeamInGroup::unDraw()
{
    --games;
    --draws;
    --points;
}

void TeamInGroup::unLose()
{
    --games;
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

bool operator<( const TeamInGroup &one, const TeamInGroup &another )
{
    return one.getPoints() < another.getPoints();
}
