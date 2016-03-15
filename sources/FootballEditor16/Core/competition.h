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
     * @param num The number of team participating in the competition
     */
    Competition(int num = 16);
    /**
     * @brief Set the title of the competition
     * @param name Competition name
     */
    void setTitle(string &name);
    /**
     * @brief Set the list of teams participating in the competition
     * @param teams Vector of the teams
     */
    void setListOfTeams(vector<Team> &teams);
    /**
     * @brief Get title of the competition
     * @return title of the competition
     */
    string& getTitle();
    /**
     * @brief Get number of teams participating in the competition
     * @return number of teams
     */
    int getNumberOfTeams();
    /**
     * @brief Get vector of teams participating in the competition
     * @return vector of teams
     */
    vector<Team> & getTeams();
    /**
     * @brief Start group stage
     */
    void startGroupStage();
    /**
     * @brief Start play-off stage
     */
    void startPlayOffStage();
    /**
     * @brief Save the current competition
     */
    void saveCurrentCompetition();
    /**
     * @brief Load the competition
     */
    void loadCompetition();

private:
    string title;
    int numberOfTeams;
    vector<Team> listOfTeams;

};

#endif // COMPETITON_H
