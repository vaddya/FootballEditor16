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
    // App
    Application();
    void loadCompetition();
    void mainMenu();
    void competitionMenu();
    void launchCompetitionMenu();
    ~Application();

    // Settings
    void settiingsMenu();
    void isCompetitionReadyToLaunch();
    void setTitleOfCompetition();
    void enterTeamsFromConsole();
    void enterTeamsFromFile();
    void showCurrentSettings();

    // Groups
    void showGroupsMenu();
    void generateGroups();
    void createGroups();
    void showGroups();
    void showGroupMatches();
    void setResultsOfGroupMatches();
    void simulateResultsOfGroupStage();

    // Group
    void showGroupMenu( char groupId );
    void showGroupTable( char groupId );
    void showGroupMatches( char groupId );
    void setResultsOfGroupMatches( char groupId );

    // Playoff
    void showPlayoffMenu();
    void createPlayoffPairs();
    void showPlayoffTable();
    void showPlayoffMatches();
    void setResultsOfPlayoffMatches();
    void simulateResultsOfPlayoffMatches();

private:
    Competition * comp;
};

#endif // APPLICATION_H
