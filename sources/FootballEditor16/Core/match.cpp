#include "match.h"

Match::Match( TeamInGroup &firstTeam, TeamInGroup &secondTeam ): firstTeam(firstTeam), secondTeam(secondTeam), result("Hasn't started yet")
{
    IdGenerator *idGen = IdGenerator::IdGeneratorInstance();
    id = idGen->getMatchId();
}

string& Match::getResult()
{
    return result;
}

int Match::getId() const
{
    return id;
}

void Match::simulate()
{
    Randomiser *randomiser = Randomiser::RandomiserInstance();
    int firstTeamGoals = randomiser->random(0, 4);
    int secondTeamGoals = randomiser->random(0, 4);
    setResult(firstTeamGoals, secondTeamGoals);
}

void Match::updateResult()
{
    ostringstream convert;
    convert << firstTeam.getGoalsFor() << ':' << secondTeam.getGoalsFor();
    result = convert.str();
}

ostream &operator<<(ostream &os, Match &match)
{
    os << "(" << match.getId() << ") " << match.getFirstTeam();
    if (match.getResult() == "Hasn't started yet")
        os << " vs ";
    else
        os << " " << match.getResult() << " ";
    os << match.getSecondTeam();
    return os;
}

istream &operator>>(istream &is, Match &match)
{
    int goalsOfFirstTeam, goalsOfSecondTeam;
    char separator;
    is >> goalsOfFirstTeam >> separator >> goalsOfSecondTeam;
    match.setResult(goalsOfFirstTeam, goalsOfSecondTeam);
    return is;
}
