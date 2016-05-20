#ifndef GROUP_H
#define GROUP_H

#include "team.h"
#include "teamingroup.h"
#include "matchingroup.h"
#include "vector"
#include "iostream"
#include "iomanip"

using std::vector;
using std::endl;
using std::setw;

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
    vector<MatchInGroup> &getMatches();
    /**
     * @brief Get winners of the stage
     * @return vector of winners (1 and 2 place of each group)
     */
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
    vector<string> table();

private:
    char id;
    vector<TeamInGroup> teams;
    vector<MatchInGroup> matches;
};

#endif // GROUP_H
