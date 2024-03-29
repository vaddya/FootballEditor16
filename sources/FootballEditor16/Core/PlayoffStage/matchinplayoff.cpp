#include "PlayoffStage/matchinplayoff.h"

MatchInPlayoff::MatchInPlayoff( TeamInPlayoff &firstTeam, TeamInPlayoff &secondTeam ): Match(firstTeam, secondTeam),
    firstTeamInPlayoff(firstTeam), secondTeamInPlayoff(secondTeam), withPenalty(false) {}

void MatchInPlayoff::setResult( int firstTeamGoals, int secondTeamGoals )
{
    firstTeam.setGoals( firstTeamGoals, secondTeamGoals );
    secondTeam.setGoals( secondTeamGoals, firstTeamGoals );
    if( firstTeamGoals == secondTeamGoals )
        throw InputPenaltryScore();
    updateResult();
}

void MatchInPlayoff::setPenaltyScore( int firstTeamPenaltyScore, int secondTeamPenaltyScore )
{
    if ( firstTeamPenaltyScore == secondTeamPenaltyScore )
        throw WrongPenaltyScore();
    withPenalty = true;
    penalty.firstTeamPenaltyScore = firstTeamPenaltyScore;
    penalty.secondTeamPenaltyScore = secondTeamPenaltyScore;
    updateResult();
}

TeamInPlayoff &MatchInPlayoff::getWinner()
{
    if( firstTeam.getGoalsFor() > secondTeam.getGoalsFor() ) return firstTeamInPlayoff;
    if( firstTeam.getGoalsFor() < secondTeam.getGoalsFor() ) return secondTeamInPlayoff;
    if( firstTeam.getGoalsFor() == secondTeam.getGoalsFor() ) {
        if( penalty.firstTeamPenaltyScore > penalty.secondTeamPenaltyScore )
            return firstTeamInPlayoff;
        else
            return secondTeamInPlayoff;
    }
    return firstTeamInPlayoff; // just remove warning
}

void MatchInPlayoff::updateResult()
{
    ostringstream convert;
    convert << firstTeam.getGoalsFor() << ':' << secondTeam.getGoalsFor();
    if( withPenalty )
        convert << " (" << penalty.firstTeamPenaltyScore << ':' << penalty.secondTeamPenaltyScore << ")";
    result = convert.str();
}


string MatchInPlayoff::showFirstTeam()
{
    ostringstream convert;
    convert << firstTeam.getName();
    if( withPenalty )
        convert << setw(13-firstTeam.getName().size()) << firstTeam.getGoalsFor() << "(" << penalty.firstTeamPenaltyScore << ")";
    else
        convert << setw(16-firstTeam.getName().size()) << firstTeam.getGoalsFor();
    return convert.str();
}

string MatchInPlayoff::showSecondTeam()
{
    ostringstream convert;
    convert << secondTeam.getName();
    if( withPenalty )
        convert << setw(13-secondTeam.getName().size()) << secondTeam.getGoalsFor() << "(" << penalty.secondTeamPenaltyScore << ")";
    else
        convert << setw(16-secondTeam.getName().size()) << secondTeam.getGoalsFor();
    return convert.str();
}

bool MatchInPlayoff::isWithPenalty()
{
    return withPenalty;
}

Penalty &MatchInPlayoff::getPenalty()
{
    return penalty;
}

void MatchInPlayoff::simulate()
{
    try {
        Match::simulate();
    }
    catch( InputPenaltryScore& e ) {
        Randomiser *randomiser = Randomiser::RandomiserInstance();
        int firstTeamPenaltyScore = 0;
        int secondTeamPenaltyScore = 0;
        while( firstTeamPenaltyScore == secondTeamPenaltyScore ) {
            firstTeamPenaltyScore = randomiser->random(0, 5);
            secondTeamPenaltyScore = randomiser->random(0, 5);
        }
        setPenaltyScore( firstTeamPenaltyScore, secondTeamPenaltyScore );
    }
}
