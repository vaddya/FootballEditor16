#ifndef APPLICATION_H
#define APPLICATION_H

#include "competition.h"
#include "team.h"
/**
 * @brief The Application class
 */
class Application
{
public:
    Application();
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

#endif // APPLICATION_H
