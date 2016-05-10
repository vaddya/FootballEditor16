#include "application.h"

void Application::showGroupMenu(char groupCharacter)
{
    cout << endl
         << "Group " << groupCharacter << ":" << endl
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
            showGroupTable(groupCharacter); showGroupMenu(groupCharacter); break;
        case 2:
            showGroupMatches(groupCharacter); showGroupMenu(groupCharacter); break;
        case 3:
            setResultsOfGroupMatches(groupCharacter); showGroupMenu(groupCharacter); break;
        case 4:
            simulateResultsOfGroupStage(); showGroupMenu(groupCharacter); break;
        case 9:
            showGroupsMenu(); break;
        default:
            cout << "Error! Invalid number." << endl;
            cin.clear();
            getline(cin, badStr);
            showGroupMenu(groupCharacter); break;
        }
    }
    else
    {
        cout << "Error! Input a number." << endl;
        cin.clear();
        getline(cin, badStr);
        showGroupMenu(groupCharacter);
        cout << endl;
    }
}

void Application::showGroupTable( char groupId )
{
    try {
        cout << endl << comp->getGroupStage().getGroup(groupId) ;
    }
    catch( GroupAreNotCreated& e ) {
           cout << e.what() << endl;
           return;
    }
}

void Application::showGroupMatches( char groupId )
{
    try {
        cout << endl;
        cout << "Group " << groupId << endl;
        cout << "Matches:" << endl;
        for( MatchInGroup match: comp->getGroupStage().getGroup(groupId).getMatches() ) {
            cout << match << endl;
        }
    }
    catch( GroupAreNotCreated& e ) {
           cout << "There are no matches" << endl
                << e.what() << endl;
    }
}

void Application::setResultsOfGroupMatches( char groupId )
{
    try {
        cout << endl << "Group " << groupId << endl;
        for (Match &match: comp->getGroupStage().getGroup(groupId).getMatches()) {
            cout << match << ": ";
            cin >> match;
        }
    }
    catch (GroupAreNotCreated& e) {
           cout << "There are no matches" << endl
                << e.what() << endl;
    }
}

