#ifndef MATCHINGROUP_H
#define MATCHINGROUP_H

#include "match.h"

class MatchInGroup : public Match
{
public:
    MatchInGroup( TeamInGroup& firstTeam, TeamInGroup& secondTeam );
    void setResult( int firstTeamGoals, int secondTeamGoals );
    void clear();

    /**
     * @brief Overloading of operator <<
     * @param os Variable of type ostream
     * @param match Variable of type Match
     * @return output stream
     * Output in format: 'Team1 vs Team2' or 'Team1 X:Y Team2'
     */
    friend ostream& operator<<( ostream& os, MatchInGroup &match );
    /**
     * @brief Overloading of operator >>
     * @param is Variable of type istream
     * @param match Variable of type Match
     * @return input stream
     * Input in format: 'X:Y' or 'X-Y'
     */
    friend istream& operator>>( istream& is, MatchInGroup &match );

private:
    TeamInGroup *firstTeamInGroup;
    TeamInGroup *secondTeamInGroup;

    void updatePoints( int fTeamGoals, int sTeamGoals );
    void pickPointsBack( int fTeamGoals, int sTeamGoals );
};

#endif // MATCHINGROUP_H
