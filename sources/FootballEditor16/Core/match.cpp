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
    if( randomiser->random( 0,1,firstTeam.getId()+secondTeam.getId()+firstTeam.getName()[2]+secondTeam.getName()[1]+this->id ) ) { // Chance is 2/3
        firstTeamGoals = randomiser->random(0,3,firstTeam.getId()+secondTeam.getId());
        secondTeamGoals = randomiser->random(0,3,firstTeam.getName()[2]+secondTeam.getName()[1]+this->id);
    }
    else {
        if( randomiser->random( 0,2,firstTeam.getId()+secondTeam.getId()+firstTeam.getName()[2]+secondTeam.getName()[1]+this->id ) ) { // Chance is 2/9
            firstTeamGoals = randomiser->random(0,4,firstTeam.getId()+secondTeam.getId());
            secondTeamGoals = randomiser->random(0,4,firstTeam.getName()[2]+secondTeam.getName()[1]+this->id);
        }
        else { // Chance is 1/9
            firstTeamGoals = randomiser->random(0,5,firstTeam.getId()+secondTeam.getId());
            secondTeamGoals = randomiser->random(0,5,firstTeam.getName()[2]+secondTeam.getName()[1]+this->id);
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
    os << "(" << match.getId() << ") " << match.getFirstTeam()
       << " " << match.getResult() << " "
       << match.getSecondTeam();
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
