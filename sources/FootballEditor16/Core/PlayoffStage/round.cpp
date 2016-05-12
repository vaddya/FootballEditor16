#include "round.h"

Round::Round( RoundEnum round ): round(round)
{
    winners.reserve(round*2);
    matches.reserve(round);
}

void Round::addPair(TeamInPlayoff &first, TeamInPlayoff &second )
{
    matches.push_back( MatchInPlayoff( first, second ) );
}

RoundEnum Round::getRound() const
{
    return round;
}

void Round::addTeams( vector<TeamInPlayoff> &teams_ )
{
    teams = teams_;
    for( size_t i = 0; i < teams.size(); i+=2 )
        addPair( teams[i], teams[i+1] );
}

vector<MatchInPlayoff> &Round::getMatches()
{
    return matches;
}

vector<TeamInPlayoff> &Round::getTeams()
{
    return teams;
}

vector<TeamInPlayoff> &Round::getWinners()
{
    for( MatchInPlayoff match: matches )
        winners.push_back( *match.getWinner() );
    return winners;
}
