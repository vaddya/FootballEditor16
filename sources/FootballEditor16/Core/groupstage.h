#ifndef GROUPSTAGE_H
#define GROUPSTAGE_H

#include "group.h"

/**
 * @brief The GroupStage class
 */
class GroupStage
{
public:
    /**
     * @brief Constructor of GroupStage
     * @param tms Vector of the teams
     */
    GroupStage(size_t num);
    /**
     * @brief Set the list of teams participating in this stage
     * @param teams Teams
     */
    void setListOfTeams(vector<Team> &teams);
    /**
     * @brief Launch this stage
     */
    void launch();
    /**
     * @brief Create groups
     */
private:
    void sortTeams();
    void createGroups();
    vector<Team> teams;
    vector<Group> groups;
    size_t numberOfGroups;
};

#endif // GROUPSTAGE_H
