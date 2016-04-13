#include "application.h"

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
    if (cin.good())
    {
        switch (num)
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

void Application::isCompetitionReadyToLaunch()
{
    if (comp->getTeams().size() > 0)
        launchCompetitionMenu();
    else {
        cout << "Add teams to the competition!" << endl;
        competitionMenu();
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
    if (cin.good())
    {
        switch (num)
        {
        case 0:
            break;
        case 1:
            isCompetitionReadyToLaunch(); break;
        case 2:
            settiingsMenu(); break;
        case 3:
            showGroupsMenu(); break;
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

void Application::showGroupsMenu()
{
    cout << endl
         << "Groups:" << endl;
    int i = 0;
        for( Group group: comp->getGroupStage().getGroups() )
            cout << ++i << ". Group " << group.getCharacter() << endl;
         cout << "9. Back to competition menu" << endl
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
            setTitleOfCompetition(); settiingsMenu(); break;
        case 2:
            enterTeamsFromConsole(); settiingsMenu(); break;
        case 3:
            enterTeamsFromFile(); settiingsMenu(); break;
        case 4:
            showCurrentSettings(); settiingsMenu(); break;
        case 9:
            competitionMenu(); break;
        default:
            cout << "Error! Invalid number." << endl;
            cin.clear();
            getline(cin, badStr);
            cout << endl;
            settiingsMenu(); break;
        }
    }
    else
    {
        cout << "Error! Input a number." << endl;
        cin.clear();
        getline(cin, badStr);
        settiingsMenu();
        cout << endl;
    }
}

void Application::settiingsMenu()
{
       cout << endl
            << comp->getTitle() << " settings:" << endl
            << "1. Set title of the competition" << endl
            << "2. Enter teams from console" << endl
            << "3. Enter teams from file" << endl
            << "4. Show current settings" << endl
            << "9. Back to competition menu" << endl
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
               setTitleOfCompetition(); settiingsMenu(); break;
           case 2:
               enterTeamsFromConsole(); settiingsMenu(); break;
           case 3:
               enterTeamsFromFile(); settiingsMenu(); break;
           case 4:
               showCurrentSettings(); settiingsMenu(); break;
           case 9:
               competitionMenu(); break;
           default:
               cout << "Error! Invalid number." << endl;
               cin.clear();
               getline(cin, badStr);
               cout << endl;
               settiingsMenu(); break;
           }
       }
       else
       {
           cout << "Error! Input a number." << endl;
           cin.clear();
           getline(cin, badStr);
           settiingsMenu();
           cout << endl;
       }
}


void Application::launchCompetitionMenu()
{
    cout << endl
         << comp->getTitle() << ":" << endl
         << "1. Create groups" << endl
         << "2. Show groups" << endl
         << "3. Show matches" << endl
         << "4. Enter the results of the group stage matches" << endl
         << "5. Simulate the results of the group stage matches" << endl
         << "6. Determine winners of group stage" << endl
         << "7. Create playoff pairs" << endl
         << "9. Back to competition menu" << endl
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
            createGroups(); launchCompetitionMenu(); break;
        case 2:
            showGroups(); launchCompetitionMenu(); break;
        case 3:
            showMatches(); launchCompetitionMenu(); break;
        case 4:
            setResultsOfGroupStage(); launchCompetitionMenu(); break;
        case 5:
            simulateResultsOfGroupStage(); launchCompetitionMenu(); break;
        case 6:
            determineWinnersOfGroupStage(); launchCompetitionMenu(); break;
        case 7:
            createPlayoffPairs(); launchCompetitionMenu(); break;
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
