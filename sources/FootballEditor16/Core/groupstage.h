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
     * @brief Get vector of groups
     * @return vector of groups
     */
    vector<Group> &getGroups();
    /**
     * @brief Get number of groups
     * @return number of groups
     */
    unsigned getNumberOfGroups() const;
    /**
     * @brief Create groups
     */
    void createGroups();
    /**
     * @brief Get winners of the group stage
     * @return vector of winners
     */
    vector<Team> &getWinners();
private:
    void determineWinners();
    void sortTeams();
    vector<Group> groups;
    unsigned numberOfGroups;

    vector<Team> winners;
};

#endif // GROUPSTAGE_H
