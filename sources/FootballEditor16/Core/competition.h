#ifndef COMPETITION_H
#define COMPETITION_H

#include "string"
#include "vector"
#include "team.h"
#include "GroupStage/groupstage.h"
#include "GroupStage/group.h"
#include "PlayoffStage/playoffstage.h"

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
    void setTitle( string title );
    /**
     * @brief Add the team to the current competition
     * @param name Name of the team
     */
    void addTeam( string name );

    /**
     * @brief Get title of the competition
     * @return title of the competition
     */
    string &getTitle();
    /**
     * @brief Get number of teams participating in the competition
     * @return number of teams
     */
    unsigned getNumberOfTeams() const;
    /**
     * @brief Get vector of teams participating in the competition
     * @return vector of teams
     */
    vector<Team> &getTeams();
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
    void startGroupStage( vector<int> teamIDs );
    /**
     * @brief Get group stage
     * @return group stage
     */
    GroupStage &getGroupStage();
    /**
     * @brief Get playoff stage
     * @return playoff stage
     */
    PlayoffStage &getPlayoffStage();
    /**
     * @brief Launch playoff stage
     */
    void startPlayOffStage();
    void startPlayOffStage( vector<int> teamIDs );
    ~Competition();

private:
    string title;
    unsigned numberOfTeams;
    vector<Team> teams;

    // There are 2 stages in a football competition
    GroupStage* groupStage;
    PlayoffStage* playoffStage;
};


class WrongNumberOfTeams: public std::exception
{
public:
    WrongNumberOfTeams(int number): wrongNumber(number) {}
    int getWrongNum() const { return wrongNumber; }
    const char * what() { return "The number of teams should be a multiple of 8!"; }
private:
    int wrongNumber;
};

class WrongListOfTeams: public std::exception
{
public:
    WrongListOfTeams();
    const char * what() { return ""; }
};

class GroupAreNotCreated: public std::exception
{
public:
    const char * what() { return "Groups are not created yet"; }
};

#endif // COMPETITION_H
