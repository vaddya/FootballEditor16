#include "team.h"

Team::Team( string name_, string coach_ ): name(name_), coach(coach_)
{
    IdGenerator *idGen = IdGenerator::IdGeneratorInstance();
    id = idGen->getTeamId();
}

Team::Team( int id_ )
{
    id = id_;
}

Team::Team(const Team &another ): id(another.id), name(another.name), coach(another.coach) {}

int Team::getId() const
{
    return id;
}

string& Team::getName()
{
    return name;
}
string& Team::getCoach()
{
    return coach;
}

//bool operator==( const Team &one, const Team &another )
//{
//    return one.getId() == another.getId();
//}

ostream& operator<<( ostream& os, const Team& team )
{
    //os << "(" << team.id << ") " << team.name;
    os << team.name;
    return os;
}
