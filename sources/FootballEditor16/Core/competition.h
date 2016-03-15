#ifndef COMPETITON_H
#define COMPETITON_H

#include "team.h"
#include "string"
#include "vector"
using std::string;
using std::vector;
/**
 * @brief The Competition class
 */
class Competition
{
public:
    /**
     * @brief Constructor of Competition
     * @param The number of team participating in the competition
     */
    Competition(int num = 16);
    /**
     * @brief Set the title of the competition
     * @param Competition name
     */
    void setTitle(string &name);
    /**
     * @brief Set the list of team participating in the competition
     * @param teams
     */
    void setListOfTeams(vector<Team> &teams);

    string& getTitle();
    int getNumberOfTeams();
    vector<Team> & getTeams();

    void startGroupStage();
    void startPlayOffGames();

    void saveCurrentCompetition();
    void loadCompetition();

private:
    string title;
    int numberOfTeams;
    vector<Team> listOfTeams;

};

#endif // COMPETITON_H
