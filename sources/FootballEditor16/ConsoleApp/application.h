#ifndef APPLICATION_H
#define APPLICATION_H

#include "competition.h"
#include "team.h"
#include "vector"
using namespace std;

/**
 * @brief The Application class
 */
class Application
{
public:
    Application();
    /**
     * @brief Display main menu
     */
    void mainMenu();

    /**
     * @brief Set title of the competition
     */
    void setTitleOfCompetition();
    /**
     * @brief Set competition setting and preferences
     */
    void settiingsMenu();
    /**
     * @brief Display menu of competition
     */
    void competitionMenu();
    /**
     * @brief Enter list of teams from console
     */
    void enterTeamsFromConsole();
    /**
     * @brief Enter list of teams from file
     */
    void enterTeamsFromFile();


    /**
     * @brief Create new competition
     */
    void createGroups();
    /**
     * @brief Set results of group stage
     */
    void setResultsOfGroupStage();
    /**
     * @brief Load competition
     */
    void loadCompetition();

    /**
     * @brief Display current settings
     */
    void showCurrentSettings();
    ~Application();
private:
    Competition * comp;
};

class WrongInput: public std::exception {};

#endif // APPLICATION_H
