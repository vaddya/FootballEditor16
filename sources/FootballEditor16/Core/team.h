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
     * @param Team name
     * @param Team rating
     */
    Team(string &tname, int trating = 1);

    string& getName();
    int getRating() const;

private:
    string name;
    int rating;

};

#endif // TEAM_H
