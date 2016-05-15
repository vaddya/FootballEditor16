#include "application.h"

void Application::showGroupsMenu()
{
    try {
        vector<Group> *groups = &(comp->getGroupStage().getGroups());
        cout << endl
             << "Select group:" << endl;
        int num = 0;
        for( Group &group: *groups )
            cout << ++num << ". Group " << group.getId() << endl;
        int numberOfGroups = num;
        cout << ++num << ". Simulate results" << endl;
        cout << ++num << ". Show tables of all groups" << endl;
        cout << ++num << ". Back to competition menu" << endl
             << "0. Exit" << endl
             << ">>> ";
        string badStr;
        int digit;
        cin >> digit;
        if( cin.good() )
        {
            if( digit == 0 )
                return;
            else if( digit == numberOfGroups+1 ) {
                    simulateResultsOfGroupStage();
                    showGroupsMenu();
                    return;
                 }
            else if( digit == numberOfGroups+2 ) {
                    showGroups();
                    showGroupsMenu();
                    return;
                 }
            else if( digit == numberOfGroups+3 ) {
                    launchCompetitionMenu();
                    return;
                 }
            else if( digit >= 1 && digit <= numberOfGroups ) {
                showGroupMenu( 'A' + digit - 1 );
                return;
            }
            else {
                cout << "Error! Invalid number." << endl;
                cin.clear();
                getline(cin, badStr);
                showGroupsMenu();
                return;
            }
        }
        else
        {
            cout << "Error! Input a number." << endl;
            cin.clear();
            getline(cin, badStr);
            showGroupsMenu();
            cout << endl;
        }
    }
    catch( GroupsAreNotCreated& e ) {
        cout << "Groups are not created!" << endl;
        launchCompetitionMenu();
    }
}

void Application::generateGroups()
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

void Application::createGroups()
{
    try {
        vector<int> teamIDs;
        showCurrentSettings();
        int teamID;
        char groupID = 'A';
        for( unsigned i = 0; i < comp->getTeams().size() / 4; i++ ) {
            cout << "Enter 4 team's ID for " << groupID++ << " group: " << endl << ">>> ";
            for( unsigned j = 0; j < 4; j++) {
                cin >> teamID;
                teamIDs.push_back(teamID-1);
            }
        }
        try {
            comp->startGroupStage(teamIDs);
        }
        catch( WrongID& e ) {
            cout << "#" << e.getWrongID() << " " << e.what() << endl
                 << "Input interrupted." << endl;
            launchCompetitionMenu();
            return;
        }
    }
    catch( WrongNumberOfTeams& e ) {
        cout << e.what() << " (now " << e.getWrongNum() << ")" << endl
             << "Groups are not created" << endl;
        launchCompetitionMenu();
        return;
    }
    cout << "Groups are created" << endl;
    showGroupsMenu();
}

void Application::showGroups()
{
    try {
        cout << endl;
        for( Group &group: comp->getGroupStage().getGroups() ) {
            group.sort();
            cout << group << endl;
        }
    }
    catch( GroupsAreNotCreated& e ) {
           cout << e.what() << endl;
    }
}

void Application::showGroupMatches()
{
    try {
        cout << endl;
        for( Group &group: comp->getGroupStage().getGroups() ) {
            cout << "Group " << group.getId() << endl;
            for( MatchInGroup &match: group.getMatches() ) {
                cout << match << endl;
            }
            cout << endl;
        }
    }
    catch( GroupsAreNotCreated& e ) {
           cout << "There are no matches" << endl
                << e.what() << endl;
    }
}

void Application::setResultsOfGroupMatches()
{
    try {
        for( Group &group: comp->getGroupStage().getGroups() ) {
            cout << endl << "Group " << group.getId() << endl;
            for( MatchInGroup &match: group.getMatches() ) {
                cout << match.getFirstTeam() << " - " << match.getSecondTeam() << ": ";
                cin >> match;
            }
        }
    }
    catch( GroupsAreNotCreated& e ) {
           cout << "There are no matches" << endl
                << e.what() << endl;
    }
}

void Application::simulateResultsOfGroupStage()
{
    try {
        for( Group &group: comp->getGroupStage().getGroups() ) {
            for( MatchInGroup &match: group.getMatches() ) {
                match.simulate();
            }
        }
    }
    catch( GroupsAreNotCreated& e ) {
           cout << "There are no matches" << endl
                << e.what() << endl;
           return;
    }
    showGroupMatches();
}
