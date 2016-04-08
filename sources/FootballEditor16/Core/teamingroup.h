#ifndef TEAMINGROUP_H
#define TEAMINGROUP_H

#include "teamstat.h"

class TeamInGroup : public TeamStat
{
public:
    TeamInGroup( Team & team ): TeamStat( team ), points( 0 ) {}
    void setPoints( int points_ );
    void increasePoints( int points_ );
    int getPoints() const;

    friend bool operator < ( const TeamInGroup& one, const TeamInGroup& another );
private:
    int points;
};

#endif // TEAMINGROUP_H
