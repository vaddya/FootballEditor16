#include "round.h"

Round::Round( RoundEnum round ): round(round)
{
    winners.reserve(round*2);
}


RoundEnum Round::getRound() const
{
    return round;
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
