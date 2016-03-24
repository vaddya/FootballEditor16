#ifndef TEAM_H
#define TEAM_H

#include "string"
using std::string;
/**
 * @brief The Team class
 */
class Team
{
public:
    /**
     * @brief Constructor of Team without parameters
     */
    Team() {}
    /**
     * @brief Constructor of Team with parameters
     * @param tname Team name
     * @param trating Team rating
     */
    Team(string tname, int tFifaPoints = 1);
    /**
     * @brief Get name of the team
     * @return name of the team
     */
    string getName();
    /**
     * @brief Get rating of the team
     * @return rating of the team
     */
    int getFifaPoints() const;

private:
    string name;
    int fifaPoints;
};

#endif // TEAM_H
