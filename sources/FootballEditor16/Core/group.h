#ifndef GROUP_H
#define GROUP_H

#include "team.h"
#include "vector"
#include "match.h"

using namespace std;

class Group
{
public:
    /**
     * @brief Constructor of Group
     * @param teams Vector of teams
     * @param character 'Name' of the group (A, B, C,...)
     */
    Group(vector<Team>& teams, char character): character(character), teams(teams) {}
    /**
     * @brief Create matches between members of groups
     */
    void createMatches();
    //TODO setMatches();
    /**
     * @brief Get group 'name'
     * @return group 'name' (A, B, C,...)
     */
    char getCharacter() const;
    /**
     * @brief Get vector of created matches
     * @return vector of matches
     */
    vector<Match> & getMatches() { return matches; }
private:
    char character;
    vector<Team> teams;
    vector<Match> matches;
};

#endif // GROUP_H
