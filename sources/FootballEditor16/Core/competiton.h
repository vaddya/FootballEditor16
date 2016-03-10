#ifndef COMPETITON_H
#define COMPETITON_H

#include "team.h"
#include "string"
#include "vector"
using std::string;
using std::vector;

class Competiton
{
public:
    Competiton(int num);
    void setTitle(string &name);
    void setListOfTeams();

    string& getTitle();
    int getNumberOfTeams();
    void getTeams();

    void startGroupStage();
    void startPlayOffGames();

    void simulateCompetition();

    void saveCurrentCompetition();
    void loadCompetition();

private:
    string title;
    int numberOfTeams;
    vector<Team> listOfTeams;

};

#endif // COMPETITON_H
