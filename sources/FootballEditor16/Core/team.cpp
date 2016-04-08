#include "team.h"

Team::Team()
{
    IdGenerator *idGen = IdGenerator::IdGeneratorInstance();
    id = idGen->getSecondId();
    name = "Empty";
    fifaPoints = 0;
}

Team::Team(const Team &other): id(other.id), name(other.name), fifaPoints(other.fifaPoints), coach(other.coach) {}

Team::Team(string name, int FifaPoints, string coach): name(name), fifaPoints(FifaPoints), coach(coach)
{
    IdGenerator *idGen = IdGenerator::IdGeneratorInstance();
    id = idGen->getSecondId();
}

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

int Team::getId() const
{
    return id;
}

ostream& operator<<(ostream& os, const Team& team)
{
    os << team.name;
    return os;
}
