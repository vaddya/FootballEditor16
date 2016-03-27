#ifndef GROUP_H
#define GROUP_H

#include "team.h"
#include "vector"
#include "match.h"

using namespace std;

class Group
{
public:
    Group(vector<Team>& teams, char character): character(character), teams(teams) {}
    char getCharacter() const;
    vector<Match> & getMatches() { return matches; }
    void createMatches();
private:
    char character;
    vector<Team> teams;
    vector<Match> matches;
};

#endif // GROUP_H
