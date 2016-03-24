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
     * @param tms Vector of the teams
     */
    GroupStage(unsigned num, vector<Team> &teams);
    /**
     * @brief Create groups
     */
    void launch();

    vector<Group> & getGroups() { return groups; }

private:
    vector<Team> teams;
    void sortTeams();
    void createGroups();
    vector<Group> groups;
    size_t numberOfGroups;
};

#endif // GROUPSTAGE_H
