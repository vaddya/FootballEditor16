#include "application.h"

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
    cout << "Specify the number of teams: ";
    unsigned num;
    cin >> num;
    string name;
    cout << "So now input list of " << num << " teams from console" << endl;
    for( unsigned i = 0; i < num; i++ ) {
        cout << "Name of " << i+1 << " team: ";
        cin >> name;
        comp->addTeam(name);
    }
}

void Application::enterTeamsFromFile()
{
    cout << "Write the input file (0 for \"input.txt\"): "  ;
    string filename;
    cin >> filename;
    cin.clear();
    if (filename[0] == '0')
        filename = "input.txt";
    ifstream fin(filename);
    if (!fin.is_open()) {
        cout << "Error! Cannot open input file. Input interrupted.\n";
        return;
    }
    string name;
    int rating;
    fin >> name;
    while (fin) {
        fin >> rating;
        comp->addTeam(name, rating);
        fin >> name;
    }
    fin.close();
    cout << "Data has been read" << endl;
}

void Application::createGroups()
{
    try {
        comp->startGroupStage();
    }
    catch (WrongNumberOfTeams& e) {
        cout << e.what() << endl
             << "Now it's " << e.getWrongNum() << endl
             << "Groups are not created" << endl;
        return;
    }
    cout << "Groups are created" << endl;
}

void Application::showGroups()
{
    try {
        cout << endl;
        for(Group group: comp->getGroupStage().getGroups()) {
            group.sort();
            cout << group << endl;
        }
    }
    catch (GroupAreNotCreated& e) {
           cout << e.what() << endl;
    }
}

void Application::showMatches()
{
    try {
        for(Group group: comp->getGroupStage().getGroups()) {
            cout << "Group " << group.getCharacter() << endl;
            for(Match match: group.getMatches()) {
                cout << match;
            }
            cout << endl;
        }
    }
    catch (GroupAreNotCreated& e) {
           cout << "There are no matches" << endl
                << e.what() << endl;
    }
}

void Application::setResultsOfGroupStage()
{
    try {
        int goalsOfFirstTeam, goalsOfSecondTeam;
        char separator;
        for (Group &group: comp->getGroupStage().getGroups()) {
            cout << endl << "Group " << group.getCharacter() << endl;
            for (Match &match: group.getMatches()) {
                cout << match.getFirstTeam() << " - " << match.getSecondTeam() << ": ";
                cin >> goalsOfFirstTeam >> separator >> goalsOfSecondTeam;
                match.setResult(goalsOfFirstTeam, goalsOfSecondTeam);
            }
        }
    }
    catch (GroupAreNotCreated& e) {
           cout << "There are no matches" << endl
                << e.what() << endl;
    }
}

void Application::simulateResultsOfGroupStage()
{
    try {
        for (Group &group: comp->getGroupStage().getGroups()) {
            for (Match &match: group.getMatches()) {
                match.simulate();
            }
        }
    }
    catch (GroupAreNotCreated& e) {
           cout << "There are no matches" << endl
                << e.what() << endl;
           return;
    }
    showMatches();
}

void Application::loadCompetition()
{
    //TODO implement load comp
    cout << endl << "It's coming" << endl << endl;
    mainMenu();
}

void Application::showCurrentSettings()
{
    cout << "Competition \"" << comp->getTitle() << "\"" << endl
         << "(" << comp->getNumberOfTeams() << " teams)" << endl;
    for (Team team: comp->getTeams()) {
        cout << "(" << team.getId() << ") " << team << endl;
    }
}

Application::~Application()
{
    delete comp;
}
