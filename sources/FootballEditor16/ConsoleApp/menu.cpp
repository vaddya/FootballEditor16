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
    if (cin.good())
    {
        switch (num)
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
            createPlayoffPairs(); launchCompetitionMenu(); break;
        case 5:
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

void Application::showGroupsMenu()
{
    vector<Group> *groups = &(comp->getGroupStage().getGroups());
    cout << endl
         << "Select group:" << endl;
    for( Group group: *groups )
        cout << group.getId() << ". Group " << group.getId() << endl;
    cout << "8. Show tables of all groups" << endl;
    cout << "9. Back to competition menu" << endl
         << "0. Exit" << endl
         << ">>> ";
    string badStr;
    char ch;
    cin >> ch;
    if (cin.good())
    {
        if (ch == '0')
            return;
        else if (ch == '8') {
                showGroups();
                showGroupsMenu();
                return;
             }
        else if (ch == '9') {
                launchCompetitionMenu();
                return;
             }
        else if (ch >= 'A' && ch <= groups->back().getId())
            showGroupMenu(ch);
        else {
            cout << "Error! Invalid choise." << endl;
            cin.clear();
            getline(cin, badStr);
            cout << endl;
            showGroupsMenu();
            return;
        }
    }
    else
    {
        cout << "Error! Input a symbol." << endl;
        cin.clear();
        getline(cin, badStr);
        showGroupsMenu();
        cout << endl;
    }
}

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
            showTable(groupCharacter); showGroupMenu(groupCharacter); break;
        case 2:
            showMatches(groupCharacter); showGroupMenu(groupCharacter); break;
        case 3:
            setResultsOfMatches(groupCharacter); showGroupMenu(groupCharacter); break;
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
