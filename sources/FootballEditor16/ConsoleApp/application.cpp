#include "application.h"

Application::Application()
{
    comp = new Competition;
}

void Application::loadCompetition()
{
    //TODO implement load comp
    cout << endl << "Is coming" << endl << endl;
    mainMenu();
}

void Application::mainMenu()
{
    cout << "Main Menu:" << endl
         << "1. New competition" << endl
         << "2. Load competiton" << endl
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
            competitionMenu(); break;
        case 2:
            loadCompetition(); break;
        default:
            cout << "Error! Invalid number." << endl;
            cin.clear();
            getline(cin, badStr);
            cout << endl;
            mainMenu(); break;
        }
    }
    else
    {
        cout << "Error! Input a number." << endl ;
        cin.clear();
        getline(cin, badStr);
        cout << endl;
        mainMenu();
    }
}

void Application::competitionMenu()
{
    cout << endl
         << comp->getTitle() << ":" << endl
         << "1. Launch" << endl
         << "2. Settings" << endl
         << "9. Back to main menu" << endl
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
            isCompetitionReadyToLaunch(); break;
        case 2:
            settiingsMenu(); break;
        case 9:
            cout << endl; mainMenu(); break;
        default:
            cout << "Error! Invalid number." << endl;
            cin.clear();
            getline(cin, badStr);
            competitionMenu(); break;
        }
    }
    else
    {
        cout << "Error! Input a number." << endl;
        cin.clear();
        getline(cin, badStr);
        competitionMenu();
        cout << endl;
    }
}

void Application::launchCompetitionMenu()
{
    cout << endl
         << comp->getTitle() << ":" << endl
         << "1. Generate groups" << endl
         << "2. Create groups" << endl
         << "3. Groups" << endl
         << "4. Create playoff pairs" << endl
         << "5. Playoff" << endl
         << "9. Back to competition menu" << endl
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
            generateGroups(); launchCompetitionMenu(); break;
        case 2:
            createGroups(); launchCompetitionMenu(); break;
        case 3:
            showGroupsMenu(); break;
        case 4:
            createPlayoffPairs(); showPlayoffMenu(); break;
        case 5:
            showPlayoffMenu(); break;
        case 9:
            competitionMenu(); break;
        default:
            cout << "Error! Invalid number." << endl;
            cin.clear();
            getline(cin, badStr);
            launchCompetitionMenu(); break;
        }
    }
    else
    {
        cout << "Error! Input a number." << endl;
        cin.clear();
        getline(cin, badStr);
        launchCompetitionMenu();
        cout << endl;
    }
}

Application::~Application()
{
    delete comp;
}
