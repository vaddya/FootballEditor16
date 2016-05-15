#include "round.h"

Round::Round( RoundEnum round ): round(round)
{
    winners.reserve(round*2);
    matches.reserve(round);
}

void Round::addPair(TeamInPlayoff &first, TeamInPlayoff &second )
{
    teams.push_back( first );
    teams.push_back( second );
    matches.push_back( MatchInPlayoff( first, second ) );
}

RoundEnum Round::getRoundEnum() const
{
    return round;
}

void Round::addTeams( vector<TeamInPlayoff> &teams_ )
{
    for( std::vector<TeamInPlayoff>::iterator it = teams_.begin(); it != teams_.end(); it+=2 )
        addPair( *it, *(it+1) );
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
    return winners;
}

void Round::updateWinners()
{
    winners.clear();
    winners.reserve( matches.size() );
    for( MatchInPlayoff &match: matches )
        winners.push_back( match.getWinner() );
}
