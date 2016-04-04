#include "application.h"

void Application::mainMenu()
{
    cout << "Main Menu:" << endl
         << "1. Launch new competition" << endl
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
         << "2. Create groups" << endl
         << "3. Show groups" << endl
         << "4. Show matches" << endl
         << "5. Set results of the matches" << endl
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
            settiingsMenu(); competitionMenu(); cout << endl; break;
        case 2:
            createGroups(); competitionMenu(); cout << endl; break;
        case 3:
            showGroups(); competitionMenu(); cout << endl; break;
        case 4:
            showMatches(); competitionMenu(); cout << endl; break;
        case 5:
            setResultsOfGroupStage(); competitionMenu(); cout << endl; break;
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
