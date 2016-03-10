#ifndef TEAM_H
#define TEAM_H

#include "string"
using std::string;

class Team
{
public:
    Team(string &tname, int traiting = 1);

    string& getName();
    int getRating();

private:
    string name;
    int rating;

};

#endif // TEAM_H
