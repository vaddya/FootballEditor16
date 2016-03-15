#ifndef GROUPSTAGE_H
#define GROUPSTAGE_H

#include "competition.h"

class GroupStage
{
public:
    GroupStage(vector<Team> & teams);

private:
    vector<Team> teams;
};

#endif // GROUPSTAGE_H
