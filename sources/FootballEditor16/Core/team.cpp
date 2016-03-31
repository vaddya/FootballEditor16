#include "team.h"

Team::Team()
{
    name = "Empty";
    fifaPoints = 0;
}

Team::Team(const Team &other): name(other.name), fifaPoints(other.fifaPoints), coach(other.coach) {}

Team::Team(string name, int FifaPoints, string coach): name(name), fifaPoints(FifaPoints), coach(coach) {}

string & Team::getName()
{
    return name;
}

int Team::getFifaPoints() const
{
    return fifaPoints;
}

string &Team::getCoach()
{
    return coach;
}


ostream& operator<<(ostream& os, const Team& team)
{
    os << team.name;
    return os;
}
