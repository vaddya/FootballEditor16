#ifndef TEAMINGROUP_H
#define TEAMINGROUP_H

#include "teamstat.h"

class TeamInGroup : public TeamStat
{
public:
    TeamInGroup( Team & team ): TeamStat( team ), points( 0 ), games( 0 ), wins( 0 ), drawns( 0 ), loses( 0 ) {}

    void increasePoints( int points_ );
    void increaseGames( int games_ = 1 );
    void increaseWins( int wins_ = 1 );
    void increaseDrawns( int drawn_ = 1 );
    void increaseLoses( int loses_ = 1 );

    int getPoints() const;
    int getGames() const;
    int getWins() const;
    int getDrawns() const;
    int getLoses() const;

    friend bool operator<( const TeamInGroup& one, const TeamInGroup& another );
private:
    int points;
    int games;
    int wins;
    int drawns;
    int loses;
};

#endif // TEAMINGROUP_H
