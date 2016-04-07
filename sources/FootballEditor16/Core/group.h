#ifndef GROUP_H
#define GROUP_H

#include "team.h"
#include "teamingroup.h"
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
    Group(char character): character(character) {}
    /**
     * @brief Create matches between members of groups
     */
    void createMatches();
    //TODO setMatches();
    void addTeam(Team& team) { teams.push_back(team); }
    /**
     * @brief Get group 'name'
     * @return group 'name' (A, B, C,...)
     */
    char getCharacter() const;
    vector<TeamInGroup>& getTeams() { return teams; }
    /**
     * @brief Get vector of created matches
     * @return vector of matches
     */
    vector<Match> & getMatches() { return matches; }
    void sort();
private:
    char character;
    vector<TeamInGroup> teams;
    vector<Match> matches;
};

#endif // GROUP_H
