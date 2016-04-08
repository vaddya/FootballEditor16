#include "application.h"
#include "iostream"
#include "fstream"

Application::Application()
{
    comp = new Competition;
}

void Application::setTitleOfCompetition()
{
    string title;
    cout << "Title: ";
    getline(cin, title);
    getline(cin, title);
    comp->setTitle(title);
    cout << " ";
}

void Application::enterTeamsFromConsole()
{
    cout << "Specify the number of teams: " << endl << ">>> ";
    unsigned num;
    cin >> num;
    string name;
    cout << "So now input list of " << num << " teams from console" << endl;
    for( unsigned i = 0; i < num; i++ ) {
        cout << "Name of " << i+1 << " team: " << endl << ">>> ";
        cin >> name;
        comp->addTeam(name);
    }
}

void Application::enterTeamsFromFile()
{
    cout << "Write the input file (0 for \"input.txt\"): "  << endl << ">>> ";
    string filename;
    cin >> filename;
    cin.clear();
    if (filename[0] == '0')
        filename = "input.txt";
    ifstream fin(filename);
    if (!fin.is_open()) {
        cout << "Error! Cannot open input file. Input interrupted.\n";
    }
    else {
        string name;
        int rating;
        fin >> name;
        while (fin) {
            fin >> rating;
            comp->addTeam(name, rating);
            fin >> name;
        }
        fin.close();
    }
}

void Application::createGroups()
{
    try {
        comp->startGroupStage();
    }
    catch (WrongNumberOfTeams& e) {
        cout << e.getWrongNum() <<  " number of teams are illegal!" << endl
             << "Groups are not created" << endl;
        return;
    }
    cout << "Groups are created" << endl;
}

void Application::showGroups()
{
    try {
        for(Group group: comp->getGroupStage().getGroups()) {
           group.sort();
           cout << "Group " << group.getCharacter() << endl;
           int i = 0;
           for( TeamInGroup team : group.getTeams() )
                   cout << ++i << ". " << team << " " << team.getPoints() << " points" << endl;
           cout << endl;
        }
    }
    catch (GroupStageAreNotCreated& e) {
           cout << "Groups are not yet created" << endl;
    }
}

void Application::showMatches()
{
    try {
            for(Group group: comp->getGroupStage().getGroups()) {
                cout << "Group " << group.getCharacter() << endl;
//                int i = 0;
                for(Match match: group.getMatches())
                        cout << "(" << match.getId() << ") " << match.getFirstTeam() << " - " << match.getSecondTeam() << endl;
        }
    }
    catch (GroupStageAreNotCreated& e) {
           cout << "There are no matches" << endl
                << "Groups are not yet created" << endl;
    }
}

void Application::setResultsOfGroupStage()
{
    try {
        int goalsOfFirstTeam, goalsOfSecondTeam;
        char separator;
        for (Group group: comp->getGroupStage().getGroups()) {
            cout << endl << "Group " << group.getCharacter() << endl;
            for (Match match: group.getMatches()) {
                cout << match.getFirstTeam() << " - " << match.getSecondTeam() << ": " << endl << ">>> ";
                cin >> goalsOfFirstTeam >> separator >> goalsOfSecondTeam;
                match.setResult(goalsOfFirstTeam, goalsOfSecondTeam);
                cout << match.getResult() << endl;
                //TODO implement exeption
            }
        }
    }
    catch (GroupStageAreNotCreated& e) {
           cout << "There are no matches" << endl
                << "Groups are not yet created" << endl;
    }
}

void Application::loadCompetition()
{
    //TODO implement load comp
    cout << endl;
    mainMenu();
}

void Application::showCurrentSettings()
{
    cout << "Competition \"" << comp->getTitle() << "\"" << endl
         << "(" << comp->getNumberOfTeams() << " teams)" << endl;
    for (unsigned i = 0; i < comp->getTeams().size(); i++) {
        cout << i+1 << ". " << comp->getTeams()[i] << endl;
    }
}

Application::~Application()
{
    delete comp;
}

