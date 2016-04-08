#ifndef TEAM_H
#define TEAM_H

#include "iostream"
#include "string"
#include "idgenerator.h"

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
    /**
     * @brief Copy constructor of Team
     * @param other Variable of type Team
     */
    Team(const Team& other);
    /**
     * @brief Constructor of Team with parameters
     * @param name Team name
     * @param rating Team rating
     */
    Team(string name, int FifaPoints = 0, string coach = "Coach");
    /**
     * @brief Get name of the team
     * @return name of the team
     */
    string& getName();
    /**
     * @brief Get rating of the team
     * @return rating of the team
     */
    int getFifaPoints() const;
    /**
     * @brief Get name of the coach
     * @return Name of the coach
     */
    string& getCoach();
    /**
     * @brief Get team ID
     * @return team ID
     */
    int getId() const;
    /**
     * @brief Overloading of operator <<
     * @param os Variable of type ostream
     * @param team Variable of type Team
     * @return output stream
     */
    friend ostream& operator<<(ostream& os, const Team& team);

private:
    int id;
    string name;
    int fifaPoints;
    string coach;
};

#endif // TEAM_H
