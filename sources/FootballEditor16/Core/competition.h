#ifndef COMPETITON_H
#define COMPETITON_H

#include "team.h"
#include "string"
#include "vector"
#include "groupstage.h"
#include "playoffstage.h"

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
    Competition(size_t num = 16);
    /**
     * @brief Set the title of the competition
     * @param name Competition name
     */
    void setTitle(string title);
    /**
     * @brief Set the list of teams participating in the competition
     * @param teams Vector of the teams
     */
    void setListOfTeams(vector<Team> &teams);
    /**
     * @brief Get title of the competition
     * @return title of the competition
     */


    string getTitle();
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
     * @brief Save the current competition
     */
    void saveCurrentCompetition();
    /**
     * @brief Load the competition
     */
    void loadCompetition();
    ~Competition();
private:
    void startGroupStage();
    void startPlayOffStage();

    string title;
    size_t numberOfTeams;
    vector<Team> teams;

    GroupStage * groupstage;
    PlayoffStage * playoffstage;

};

class WrongNumberOfTeams: public std::exception
{
public:
    WrongNumberOfTeams(int number): wrongNumber(number) {}
    int getWrongNum() const {
        return wrongNumber;
    }
private:
    int wrongNumber;
};

class WrongListOfTeams: public std::exception {};

#endif // COMPETITON_H
