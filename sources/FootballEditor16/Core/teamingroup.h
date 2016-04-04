#ifndef TEAMINGROUP_H
#define TEAMINGROUP_H

#include "teamstat.h"

class TeamInGroup : public TeamStat
{
public:
    TeamInGroup(Team & team): TeamStat(team), points_(0) {}
    void setPoints(int points) { points_ = points; }
    int getPoints() const { return points_; }
    bool operator < ( const TeamInGroup& another );
private:
    int points_;
};

#endif // TEAMINGROUP_H
