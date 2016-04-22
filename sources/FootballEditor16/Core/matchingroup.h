#ifndef MATCHINGROUP_H
#define MATCHINGROUP_H

#include "match.h"

class MatchInGroup : public Match
{
public:
    MatchInGroup( TeamInGroup& firstTeam, TeamInGroup& secondTeam );
    void setResult(int firstTeamGoals, int secondTeamGoals);
    void clear();
private:
    TeamInGroup *firstTeamInGroup;
    TeamInGroup *secondTeamInGroup;

    void updatePoints( int fTeamGoals, int sTeamGoals );
    void pickPointsBack( int fTeamGoals, int sTeamGoals );
};

#endif // MATCHINGROUP_H
