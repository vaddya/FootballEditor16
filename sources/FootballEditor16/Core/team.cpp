#include "team.h"

Team::Team(string name, string coach): name(name), coach(coach)
{
    IdGenerator *idGen = IdGenerator::IdGeneratorInstance();
    id = idGen->getSecondId();
}

Team::Team(const Team &other): id(other.id), name(other.name), coach(other.coach) {}

int Team::getId() const
{
    return id;
}

string & Team::getName()
{
    return name;
}
string &Team::getCoach()
{
    return coach;
}

ostream& operator<<(ostream& os, const Team& team)
{
    os << "(" << team.id << ") " << team.name;
    return os;
}
