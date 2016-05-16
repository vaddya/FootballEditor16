#include "application.h"

void Application::showPlayoffMenu()
{
    cout << endl
         << "Playoff of " << comp->getTitle() << ":" << endl
         << "1. Show table" << endl
         << "2. Show matches" << endl
         << "3. Enter the results of the matches" << endl
         << "4. Simulate the results of the matches" << endl
         << "5. Next round" << endl
         << "9. Back to groups menu" << endl
         << "0. Exit" << endl
         << ">>> ";
    string badStr;
    int num;
    cin >> num;
    if( cin.good() )
    {
        switch( num )
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
        case 5:
            createNewRound(); showPlayoffMenu(); break;
        case 9:
            launchCompetitionMenu(); break;
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
    try {
        vector<int> teamIDs;
        for( Team &team: comp->getGroupStage().getWinners() )
            cout << "(" << team.getId() << ") " << team << endl;
        int teamID;
        int pairID = 0;
        for( size_t i = 0; i < comp->getGroupStage().getWinners().size() / 2; i++ ) {
            cout << "Enter 2 team's ID for " << ++pairID << " playoff pair: " << endl << ">>> ";
            for( size_t j = 0; j < 2; j++) {
                cin >> teamID;
                teamIDs.push_back( teamID );
            }
        }
        comp->startPlayOffStage( teamIDs );
    }
    catch( WrongID& e ) {
        cout << "#" << e.getWrongID() << " " << e.what() << endl
             << "Input interrupted. Create pairs again." << endl;
        launchCompetitionMenu();
        return;
    }
    catch( GroupStageIsNotOver& e ) {
        cout << e.what() << endl;
        return;
    }
    cout << "Pairs are created" << endl;
    showPlayoffMenu();
}

void Application::showPlayoffTable()
{
    try {
        cout << endl << comp->getPlayoffStage();
    }
    catch( GroupStageIsNotOver& e ) {
        cout << e.what() << endl;
    }
}

void Application::showPlayoffMatches()
{
    try {
        switch( comp->getPlayoffStage().getCurrentRound() ) {
            case 0:
            case 1: cout << "Final" << endl; break;
            case 2: cout << "Semi-finals" << endl; break;
            case 4: cout << "Quarter-finals" << endl; break;
            case 8: cout << "Round of 16" << endl; break;
        }
        for( Match &match: comp->getPlayoffStage().getMatches() )
            cout << match << endl;
    }
    catch( GroupStageIsNotOver& e ) {
        cout << e.what() << endl;
    }
}

void Application::setResultsOfPlayoffMatches()
{
    try {
        cout << endl << "1/" << comp->getPlayoffStage().getCurrentRound() << endl;
        for( MatchInPlayoff &match: comp->getPlayoffStage().getMatches() ) {
            try {
                cout << match << ": ";
                cin >> match;
            }
            catch( InputPenaltryScore& e ) {
                cout << e.what() << ": ";
                int penaltyOfFirstTeam, penaltyOfSecondTeam;
                char separator;
                cin >> penaltyOfFirstTeam >> separator >> penaltyOfSecondTeam;
                try {
                    match.setPenaltyScore( penaltyOfFirstTeam, penaltyOfSecondTeam );
                }
                catch( WrongPenaltyScore& e ) {
                    cout << e.what() << endl << "Input interrupted." << endl;
                    return;
                }
            }
        }
    }
    catch( GroupStageIsNotOver& e ) {
        cout << e.what() << endl;
    }
}


void Application::simulateResultsOfPlayoffMatches()
{
    try {
        for( Match &match: comp->getPlayoffStage().getMatches() )
            match.simulate();
        showPlayoffMatches();
    }
    catch( GroupStageIsNotOver& e ) {
        cout << e.what() << endl;
    }
}

void Application::createNewRound()
{
    try {
        comp->getPlayoffStage().createNewMatches();
        showPlayoffMatches();
    }
    catch( CompetitionIsOver& e ) {
        cout << e.what() << endl;
    }
    catch( GroupStageIsNotOver& e ) {
        cout << e.what() << endl;
    }
}
