#ifndef MATCH_H
#define MATCH_H

#include "team.h"
#include "teamstat.h"
#include "teamingroup.h"
#include "string"
#include "sstream"
#include "algorithm"
#include "idgenerator.h"
#include "randomiser.h"
#include "iostream"

using namespace std;

/**
 * @brief The Match class
 */
class Match
{
public:
    /**
     * @brief Constructor of Match
     * @param firstTeam First team
     * @param secondTeam Second team
     */
    Match( TeamStat& firstTeam, TeamStat& secondTeam );
    /**
     * @brief Destructor
     */
    virtual ~Match() {}
    /**
     * @brief Set result of the match
     * @param firstTeamGoals Number of goals of first team
     * @param secondTeamGoals Number of goals of second team
     */
    virtual void setResult(int firstTeamGoals, int secondTeamGoals) = 0;
    /**
     * @brief Get result of the match
     * @return result of match in format "X:Y", where
     * X - goals of first team,
     * Y - goals of second team
     */
    string& getResult();
    /**
     * @brief Get ID of the match
     * @return ID of the match
     */
    int getId() const;

    /**
     * @brief Get reference to the first team
     * @return first team
     */
    TeamStat& getFirstTeam();
    /**
     * @brief Get reference to the second team
     * @return second team
     */
    TeamStat& getSecondTeam();

    /**
     * @brief Simulate result of the match
     * where number of goals of both teams are randomed from 0 to 4
     */
    void simulate();
    /**
     * @brief Overloading of operator <<
     * @param os Variable of type ostream
     * @param match Variable of type Match
     * @return output stream
     * Output in format: 'Team1 vs Team2' or 'Team1 X:Y Team2'
     */
    friend ostream& operator<<( ostream& os, Match &match );
    /**
     * @brief Overloading of operator >>
     * @param is Variable of type istream
     * @param match Variable of type Match
     * @return input stream
     * Input in format: 'X:Y' or 'X-Y'
     */
    friend istream& operator>>( istream& is, Match &match );

private:
    int id;

protected:
    TeamStat firstTeam;
    TeamStat secondTeam;
    string result;
    void updateResult();
};

#endif // MATCH_H
