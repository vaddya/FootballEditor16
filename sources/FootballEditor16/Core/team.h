#ifndef TEAM_H
#define TEAM_H

#include "string"
using std::string;

class Team
{
public:
    Team() {}
    Team(string &tname, int trating = 1);

    string& getName();
    int getRating() const;

private:
    string name;
    int rating;

};

#endif // TEAM_H
