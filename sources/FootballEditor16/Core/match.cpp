#include "match.h"

Match::Match(TeamInGroup &fteam, TeamInGroup &steam): firstTeam(fteam), secondTeam(steam), firstTG(&fteam), secondTG(&steam), result("Hasn't started yet")
{
    IdGenerator *idGen = IdGenerator::IdGeneratorInstance();
    id = idGen->getFirstId();
}

void Match::setResult(int firstTeamGoals, int secondTeamGoals)
{
    if (result != "Hasn't started yet")
        pickPointsBack(firstTeam.getGoals(), secondTeam.getGoals()); // pick previously acquired points
    firstTeam.setGoals(firstTeamGoals);
    secondTeam.setGoals(secondTeamGoals);
    updatePoints(firstTeamGoals, secondTeamGoals);
    updateResult();
}

string& Match::getResult()
{
    return result;
}

void Match::simulate()
{
    Randomiser *randomiser = Randomiser::RandomiserInstance();
    int firstTeamGoals = randomiser->random(0, 4);
    int secondTeamGoals = randomiser->random(0, 4);
    setResult(firstTeamGoals, secondTeamGoals);
}

ostream& operator<<(ostream &os, Match &match)
{
    os << "(" << match.getId() << ") " << match.getFirstTeam();
    if (match.getResult() == "Hasn't started yet")
        os << " vs ";
    else
        os << " " << match.getResult() << " ";
    os << match.getSecondTeam() << endl;
    return os;
}

void Match::updatePoints(int fTeamGoals, int sTeamGoals)
{
    if (fTeamGoals > sTeamGoals) {
        firstTG->increaseGames();
        firstTG->increaseWins();
        firstTG->increasePoints(3);
        secondTG->increaseGames();
        secondTG->increaseLoses();
    }
    if (fTeamGoals < sTeamGoals) {
        firstTG->increaseGames();
        firstTG->increaseLoses();
        secondTG->increasePoints(3);
        secondTG->increaseGames();
        secondTG->increaseWins();
    }
    if (fTeamGoals == sTeamGoals) {
        firstTG->increaseGames();
        firstTG->increaseDrawns();
        firstTG->increasePoints(1);
        secondTG->increasePoints(1);
        secondTG->increaseGames();
        secondTG->increaseDrawns();
    }
}

void Match::pickPointsBack(int fTeamGoals, int sTeamGoals)
{
    if (fTeamGoals > sTeamGoals) {
        firstTG->increaseGames(-1);
        firstTG->increaseWins(-1);
        firstTG->increasePoints(-3);
        secondTG->increaseGames(-1);
        secondTG->increaseLoses(-1);
    }
    if (fTeamGoals < sTeamGoals) {
        firstTG->increaseGames(-1);
        firstTG->increaseLoses(-1);
        secondTG->increasePoints(-3);
        secondTG->increaseGames(-1);
        secondTG->increaseWins(-1);
    }
    if (fTeamGoals == sTeamGoals) {
        firstTG->increaseGames(-1);
        firstTG->increaseDrawns(-1);
        firstTG->increasePoints(-1);
        secondTG->increasePoints(-1);
        secondTG->increaseGames(-1);
        secondTG->increaseDrawns(-1);
    }
}

void Match::updateResult()
{
    ostringstream convert;
    convert << firstTeam.getGoals() << ':' << secondTeam.getGoals();
    result = convert.str();
}
