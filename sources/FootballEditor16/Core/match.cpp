#include "match.h"

Match::Match( TeamStat &firstTeam, TeamStat &secondTeam ): firstTeam(firstTeam), secondTeam(secondTeam), result("-:-")
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

TeamStat& Match::getFirstTeam()
{
    return firstTeam;
}

TeamStat &Match::getSecondTeam()
{
    return secondTeam;
}

bool Match::isPlayed() const
{
    if( result != "-:-" )
        return true;
    else
        return false;
}

void Match::simulate()
{
    Randomiser *randomiser = Randomiser::RandomiserInstance();
    int firstTeamGoals;
    int secondTeamGoals;
    if( randomiser->random(0,2) ) { // Chance is 2/3
        firstTeamGoals = randomiser->random(0,2);
        secondTeamGoals = randomiser->random(0,2);
    }
    else {
        if( randomiser->random(0,2) ) { // Chance is 2/9
            firstTeamGoals = randomiser->random(0,3);
            secondTeamGoals = randomiser->random(0,3);
        }
        else { // Chance is 1/9
            firstTeamGoals = randomiser->random(0,4);
            secondTeamGoals = randomiser->random(0,4);
        }
    }
    setResult(firstTeamGoals, secondTeamGoals);
}

void Match::updateResult()
{
    ostringstream convert;
    convert << firstTeam.getGoalsFor() << ':' << secondTeam.getGoalsFor();
    result = convert.str();
}

ostream& operator<<( ostream &os, Match &match )
{
    os << "(" << match.getId() << ") " << match.getFirstTeam();
//    if( match.getResult() == "-:-" )
//        os << " vs ";
//    else
        os << " " << match.getResult() << " ";
    os << match.getSecondTeam();
    return os;
}

istream& operator>>( istream &is, Match &match )
{
    int goalsOfFirstTeam, goalsOfSecondTeam;
    char separator;
    is >> goalsOfFirstTeam >> separator >> goalsOfSecondTeam;
    match.setResult(goalsOfFirstTeam, goalsOfSecondTeam);
    return is;
}
