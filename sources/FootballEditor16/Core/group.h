#ifndef GROUP_H
#define GROUP_H

#include "team.h"
#include "vector"

using namespace std;

class Group
{
public:
    Group(vector<Team> &teams): teams(teams) {}

private:
    vector<Team> teams;
};

#endif // GROUP_H
