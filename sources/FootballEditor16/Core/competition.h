#ifndef COMPETITION_H
#define COMPETITION_H

#include "string"
#include "vector"
#include "team.h"
#include "group.h"
#include "playoffstage.h"
#include "groupstage.h"

using std::string;
using std::vector;

/**
 * @brief The Competition class
 */
class Competition
{
public:
    Competition();
    /**
     * @brief Set the title of the competition
     * @param title Competition name
     */
    void setTitle(string title);
    /**
     * @brief Set the list of teams participating in the competition
     * @param teams Vector of the teams
     */
    void setListOfTeams(vector<Team> &teams);
    /**
     * @brief Add the team to the current competition
     * @param name Name of the team
     * @param fifaRating Rating of the team in the FIFA World Ranking
     */
    void addTeam(string name, int fifaRating = 0);

    /**
     * @brief Get title of the competition
     * @return title of the competition
     */
    string& getTitle();
    /**
     * @brief Get number of teams participating in the competition
     * @return number of teams
     */
    unsigned getNumberOfTeams() const;
    /**
     * @brief Get vector of teams participating in the competition
     * @return vector of teams
     */
    vector<Team>& getTeams();
    /**
     * @brief Save the current competition
     */
    void saveCurrentCompetition();
    /**
     * @brief Load the competition
     */
    void loadCompetition();
    /**
     * @brief Launch group stage
     */
    void startGroupStage();
    /**
     * @brief Get group stage
     * @return group stage
     */
    GroupStage & getGroupStage();
    /**
     * @brief Launch playoff stage
     */
    void startPlayOffStage();

    ~Competition();

private:
    string title;
    unsigned numberOfTeams;
    vector<Team> teams;

    // There are 2 stages in a football competition
    GroupStage * groupStage;
    PlayoffStage * playoffStage;
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

#endif // COMPETITION_H
