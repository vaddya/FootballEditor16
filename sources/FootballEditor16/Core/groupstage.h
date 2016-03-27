#ifndef GROUPSTAGE_H
#define GROUPSTAGE_H

#include "stage.h"
#include "group.h"

/**
 * @brief The GroupStage class
 */
class GroupStage : public Stage
{
public:
    /**
     * @brief Constructor of GroupStage
     * @param teams Vector of the teams
     */
    GroupStage(vector<Team> &teams);
    /**
     * @brief Create groups
     */
    void launch();
    /**
     * @brief Get vector of teams participating in the competition
     * @return vector of teams
     */
    vector<Group> & getGroups();
    unsigned getNumberOfGroups() { return numberOfGroups; }
private:
    vector<Team> teams;
    void sortTeams();
    void createGroups();
    vector<Group> groups;
    unsigned numberOfGroups;
};

#endif // GROUPSTAGE_H
