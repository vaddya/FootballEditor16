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
     * @brief Constructor of Team
     * @param name Team name with deafaul value "Team"
     * @param rating Team rating wtih default value 0
     * @param coach Team coach with default value "Coach"
     */
    Team(string name = "Team", string coach = "Coach");
    /**
     * @brief Copy constructor of Team
     * @param other Variable of type Team
     */
    Team(const Team& other);
    /**
     * @brief Get team ID
     * @return team ID
     */
    int getId() const;
    /**
     * @brief Get name of the team
     * @return name of the team
     */
    string& getName();
    /**
     * @brief Get name of the coach
     * @return Name of the coach
     */
    string& getCoach();

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
    string coach;
};

#endif // TEAM_H
