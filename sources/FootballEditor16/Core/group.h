#ifndef GROUP_H
#define GROUP_H

#include "team.h"
#include "vector"
#include "match.h"

using namespace std;

class Group
{
public:
    Group(vector<Team> &teams): teams(teams) {}
    vector<Match> & getMatches() { return matches; }
    void createMatches();
    int getSmth() { return 5; }
private:
    vector<Team> teams;
    vector<Match> matches;
};

#endif // GROUP_H
