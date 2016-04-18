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
    fin >> name;
    while (fin) {
        comp->addTeam(name);
        fin >> name;
    }
    fin.close();
    cout << "Data has been read" << endl;
}

void Application::isCompetitionReadyToLaunch()
{
    if( comp->getTeams().size() > 0 )
        launchCompetitionMenu();
    else {
        cout << "Add teams to the competition!" << endl;
        competitionMenu();
    }
}

void Application::createGroups()
{
    try {
        comp->startGroupStage();
    }
    catch( WrongNumberOfTeams& e ) {
        cout << e.what() << " (now " << e.getWrongNum() << ")" << endl
             << "Groups are not created" << endl;
        return;
    }
    cout << "Groups are created" << endl;
}

void Application::showTable( char groupId )
{
    try {
        cout << endl;
        cout << comp->getGroupStage().getGroup(groupId) ;
    }
    catch( GroupAreNotCreated& e ) {
           cout << e.what() << endl;
           return;
    }
}

void Application::showGroups()
{
    try {
        cout << endl;
        for(Group group: comp->getGroupStage().getGroups()) {
            group.sort();
            cout << group;
        }
    }
    catch( GroupAreNotCreated& e ) {
           cout << e.what() << endl;
    }
    try {
        cout << endl;
        for( Group group: comp->getGroupStage().getGroups() ) {

            for( Match match: group.getMatches() ) {
                cout << match;
            }
            cout << endl;
        }
    }
    catch( GroupAreNotCreated& e ) {
           cout << "There are no matches" << endl
                << e.what() << endl;
    }
}

void Application::showMatches()
{
    try {
        cout << endl;
        for(Group group: comp->getGroupStage().getGroups()) {
            cout << "Group " << group.getId() << endl;
            for(Match match: group.getMatches()) {
                cout << match << endl;
            }
            cout << endl;
        }
    }
    catch (GroupAreNotCreated& e) {
           cout << "There are no matches" << endl
                << e.what() << endl;
    }
}

void Application::showMatches( char groupId )
{
    try {
        cout << endl;
        cout << "Group " << groupId << endl;
        cout << "Matches:" << endl;
        for( Match match: comp->getGroupStage().getGroup(groupId).getMatches() ) {
            cout << match << endl;
        }
    }
    catch( GroupAreNotCreated& e ) {
           cout << "There are no matches" << endl
                << e.what() << endl;
    }
}

void Application::setResultsOfMatches()
{
    try {
        for (Group &group: comp->getGroupStage().getGroups()) {
            cout << endl << "Group " << group.getId() << endl;
            for (Match &match: group.getMatches()) {
                cout << match.getFirstTeam() << " - " << match.getSecondTeam() << ": ";
                cin >> match;
            }
        }
    }
    catch (GroupAreNotCreated& e) {
           cout << "There are no matches" << endl
                << e.what() << endl;
    }
}

void Application::setResultsOfMatches( char groupId )
{
    try {
        cout << endl << "Group " << groupId << endl;
        for (Match &match: comp->getGroupStage().getGroup(groupId).getMatches()) {
            //match.clear();
            cout << match << ": ";
            cin >> match;
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

void Application::determineWinnersOfGroupStage()
{
    for( Team team :comp->getGroupStage().getWinners() )
        cout << team << endl;
    cout << endl;
}

void Application::createPlayoffPairs()
{
    comp->startPlayOffStage();
    cout << comp->getPlayoffStage();
}

void Application::showCurrentSettings()
{
    cout << "Competition \"" << comp->getTitle() << "\"" << endl
         <<  comp->getNumberOfTeams() << " teams:" << endl;
    for (Team team: comp->getTeams()) {
        cout << "(" << team.getId() << ") " << team << endl;
    }
}

Application::~Application()
{
    delete comp;
}
