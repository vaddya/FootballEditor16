#ifndef APPLIACATION_H
#define APPLIACATION_H

#include "competition.h"
#include "team.h"

class Appliacation
{
public:
    Appliacation();
    /**
     * @brief Create new competition
     */
    void startNewCompetition();
    /**
     * @brief Load competition
     */
    void loadCompetition();
    /**
     * @brief Set competition setting and preferences
     */
    void setSettiings();
};

#endif // APPLIACATION_H
