#include "application.h"



void Application::showPlayoffMenu()
{
    cout << endl
         << "Playoff of " << comp->getTitle() << ":" << endl
         << "1. Show table" << endl
         << "2. Show matches" << endl
         << "3. Enter the results of the matches" << endl
         << "4. Simulate the results of the matches" << endl
         << "9. Back to groups menu" << endl
         << "0. Exit" << endl
         << ">>> ";
    string badStr;
    int num;
    cin >> num;
    if (cin.good())
    {
        switch (num)
        {
        case 0:
            break;
        case 1:
            showPlayoffTable(); showPlayoffMenu(); break;
        case 2:
            showPlayoffMatches(); showPlayoffMenu(); break;
        case 3:
            setResultsOfPlayoffMatches(); showPlayoffMenu(); break;
        case 4:
            simulateResultsOfPlayoffMatches(); showPlayoffMenu(); break;
        case 9:
            showGroupsMenu(); break;
        default:
            cout << "Error! Invalid number." << endl;
            cin.clear();
            getline(cin, badStr);
            showPlayoffMenu(); break;
        }
    }
    else
    {
        cout << "Error! Input a number." << endl;
        cin.clear();
        getline(cin, badStr);
        showPlayoffMenu();
        cout << endl;
    }
}

void Application::createPlayoffPairs()
{
    comp->startPlayOffStage();
    try {
        vector<int> teamIDs;
        for( Team team: comp->getGroupStage().getWinners() )
            cout << "(" << team.getId() << ") " << team << endl;
        int teamID;
        int pairID = 0;
        for( unsigned i = 0; i < comp->getTeams().size() / 4; i++ ) {
            cout << "Enter 2 team's ID for " << ++pairID << " playoff pair: " << endl << ">>> ";
            for( unsigned j = 0; j < 2; j++) {
                cin >> teamID;
                teamIDs.push_back(teamID);
            }
        }
        comp->startPlayOffStage(teamIDs);
    }
    catch (...) {
        //TODO exeptions
    }

    cout << comp->getPlayoffStage();
}

void Application::showPlayoffTable()
{
    cout << endl << comp->getPlayoffStage();
}

void Application::showPlayoffMatches()
{
    for( MatchInPlayoff match: comp->getPlayoffStage().getMatches() )
        cout << match << endl;
}

void Application::setResultsOfPlayoffMatches()
{
    try {
        cout << endl << "1/" << comp->getPlayoffStage().getCurrentRound() << endl;
        for( Match &match: comp->getPlayoffStage().getMatches() ) {
            cout << match << ": ";
            cin >> match;
        }
    }
    catch (GroupAreNotCreated& e) {
           cout << "There are no matches" << endl
                << e.what() << endl;
    }
}

void Application::simulateResultsOfPlayoffMatches()
{

}
