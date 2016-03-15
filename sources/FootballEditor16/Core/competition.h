#ifndef COMPETITON_H
#define COMPETITON_H

#include "team.h"
#include "string"
#include "vector"
using std::string;
using std::vector;

class Competition
{
public:
    Competition(int num = 16);
    void setTitle(string &name);
    void setListOfTeams(vector<Team> &teams);

    string& getTitle();
    int getNumberOfTeams();
    vector<Team> & getTeams();

    void startGroupStage();
    void startPlayOffGames();

    void saveCurrentCompetition();
    void loadCompetition();

private:
    string title;
    int numberOfTeams;
    vector<Team> listOfTeams;

};

#endif // COMPETITON_H
