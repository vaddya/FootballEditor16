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
            competitionMenu(); cout << endl; break;
        case 2:
            loadCompetition(); cout << endl; break;
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
         << comp->getTitle() << endl
         << "1. Settings" << endl
         << "2. Launch" << endl
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
            settiingsMenu(); cout << endl;  competitionMenu(); break;
        case 2:
            launchCompetitionMenu(); cout << endl; competitionMenu(); break;
        case 9:
            mainMenu(); cout << endl; break;
        default:
            cout << "Error! Invalid number." << endl << endl;
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

void Application::settiingsMenu()
{
       cout << endl
            << "Competition settings:" << endl
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
       cout << endl;
       if (cin.good())
       {
           switch (num)
           {
           case 0:
                  break;
           case 1:
               setTitleOfCompetition(); cout << endl; settiingsMenu(); break;
           case 2:
               enterTeamsFromConsole(); cout << endl; settiingsMenu(); break;
           case 3:
               enterTeamsFromFile(); cout << endl; settiingsMenu(); break;
           case 4:
               showCurrentSettings(); cout << endl; settiingsMenu(); break;
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
         << comp->getTitle() << endl
         << "1. Create groups" << endl
         << "2. Show groups" << endl
         << "3. Show matches" << endl
         << "4. Set results of the matches" << endl
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
            createGroups(); launchCompetitionMenu(); cout << endl; break;
        case 2:
            showGroups(); launchCompetitionMenu(); cout << endl; break;
        case 3:
            showMatches(); launchCompetitionMenu(); cout << endl; break;
        case 4:
            setResultsOfGroupStage(); launchCompetitionMenu(); cout << endl; break;
        case 9:
            mainMenu(); cout << endl; break;
        default:
            cout << "Error! Invalid number." << endl << endl;
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
        launchCompetitionMenu();
        cout << endl;
    }
}
