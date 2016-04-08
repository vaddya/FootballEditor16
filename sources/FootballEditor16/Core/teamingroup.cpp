#include "teamingroup.h"

bool operator < ( const TeamInGroup &one, const TeamInGroup &another ) {
    if (one.getPoints() < another.getPoints())
        return true;
    else
        return false;
}

void TeamInGroup::setPoints(int points_)
{
    points = points_;
}

void TeamInGroup::increasePoints(int points_)
{
    points += points_;
}

int TeamInGroup::getPoints() const
{
    return points;
}
