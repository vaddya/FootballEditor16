#ifndef GROUP_H
#define GROUP_H

#include "team.h"
#include "teamingroup.h"
#include "vector"
#include "match.h"
#include "iostream"
#include "iomanip"

using namespace std;

/**
 * @brief The Group class
 */
class Group
{
public:
    /**
     * @brief Constructor of Group
     * @param character 'Name' of the group (A, B, C,...)
     */
    Group();
    /**
     * @brief Create matches between members of groups
     */
    void createMatches();
    //TODO setMatches();
    /**
     * @brief Add a team to this group
     * @param team Team
     */
    void addTeam(Team& team);
    /**
     * @brief Get group 'name'
     * @return group 'name' (A, B, C, etc.)
     */
    char getId() const;
    /**
     * @brief Get vector of teams
     * @return vector of teams
     */
    vector<TeamInGroup>& getTeams();
    /**
     * @brief Get vector of created matches
     * @return vector of matches
     */
    vector<Match>& getMatches();
    vector<Team> getWinners();
    /**
     * @brief Overloading of operator <<
     * @param os Variable of type ostream
     * @param group Variable of type Group
     * @return output stream
     */
    friend ostream& operator<<(ostream& os, Group &group);
    /**
     * @brief Sort teams by number of points
     */
    void sort();

private:
    char id;
    vector<TeamInGroup> teams;
    vector<Match> matches;
};

#endif // GROUP_H
