#ifndef MATCHINPLAYOFF_H
#define MATCHINPLAYOFF_H

#include "match.h"

class MatchInPlayoff : public Match
{
public:
    MatchInPlayoff( TeamInGroup& firstTeam, TeamInGroup& secondTeam );

};

#endif // MATCHINPLAYOFF_H
