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
    explicit PlayoffStage(unsigned num);
    /**
     * @brief Launch this stage
     */
    void launch();

private:
    vector<Team> teams;
};

#endif // PLAYOFFSTAGE_H
