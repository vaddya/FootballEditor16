#include "team.h"

Team::Team()
{
    name = "Empty";
    fifaPoints = 0;
}

Team::Team(const Team &other): name(other.name), fifaPoints(other.fifaPoints) {}

Team::Team(string name, int FifaPoints): name(name), fifaPoints(FifaPoints) {}

string & Team::getName()
{
    return name;
}

int Team::getFifaPoints() const
{
    return fifaPoints;
}


ostream& operator<<(ostream& os, const Team& team)
{
    os << team.name;
    return os;
}
