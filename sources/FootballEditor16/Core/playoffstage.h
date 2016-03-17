#ifndef PLAYOFFSTAGE_H
#define PLAYOFFSTAGE_H

#include "stage.h"

/**
 * @brief The PlayoffStage class
 */
class PlayoffStage : public Stage
{
public:
    /**
     * @brief Constructor of PlayoffStage
     */
    PlayoffStage();
    /**
     * @brief Set the list of teams participating in this stage
     * @param teams Teams
     */
    void setListOfTeams(vector<Team> &teams);
    /**
     * @brief Launch this stage
     */
    void launch();

private:
    vector<Team> teams;
};

#endif // PLAYOFFSTAGE_H
