#ifndef TEAM_H
#define TEAM_H
#include "iostream"
#include "string"
using std::string;
using std::ostream;
/**
 * @brief The Team class
 */
class Team
{
public:
    /**
     * @brief Constructor of Team without parameters
     */
    Team();
    Team(const Team& other);
    /**
     * @brief Constructor of Team with parameters
     * @param tname Team name
     * @param trating Team rating
     */
    Team(string name, int FifaPoints = 0);
    /**
     * @brief Get name of the team
     * @return name of the team
     */
    string & getName();
    /**
     * @brief Get rating of the team
     * @return rating of the team
     */
    int getFifaPoints() const;

    friend ostream& operator<<(ostream& os, const Team& team);

private:
    string name;
    int fifaPoints;
};

#endif // TEAM_H
