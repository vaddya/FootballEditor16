#ifndef APPLICATION_H
#define APPLICATION_H

#include "competition.h"
#include "team.h"
#include "vector"
#include "iostream"
#include "fstream"

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
    void isCompetitionReadyToLaunch();
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
    void showGroupsMenu();
    void showGroup(char groupCharacter);
    void showGroupMenu(char groupCharacter);
    /**
     * @brief Enter list of teams from console
     */
    void enterTeamsFromConsole();
    /**
     * @brief Enter list of teams from file
     */
    void enterTeamsFromFile();

    /**
     * @brief Launch competition menu
     */
    void launchCompetitionMenu();
    /**
     * @brief Create new competition
     */
    void createGroups();
    /**
     * @brief Show groups
     */
    void showGroups();
    /**
     * @brief Show matches
     */
    void showMatches();
    /**
     * @brief Set results of group stage
     */
    void setResultsOfGroupStage();
    /**
     * @brief Simulate results of group stage
     */
    void simulateResultsOfGroupStage();
    /**
     * @brief Load competition
     */
    void loadCompetition();

    void determineWinnersOfGroupStage();

    void createPlayoffPairs();
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
