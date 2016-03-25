#ifndef GROUP_H
#define GROUP_H

#include "team.h"
#include "vector"
#include "match.h"

using namespace std;

class Group
{
public:
    Group(vector<Team>& teams2): teams(teams2) {}
    vector<Match> & getMatches() { return matches; }
    void createMatches();
private:
    vector<Team> teams;
    vector<Match> matches;
};

#endif // GROUP_H
