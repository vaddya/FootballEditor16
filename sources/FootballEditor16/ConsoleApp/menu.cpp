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
         //<< "5. Playoff" << endl
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
    int num = 0;
    for( Group group: *groups )
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
    if (cin.good())
    {
        if (digit == 0)
            return;
        else if (digit == numberOfGroups+1) {
                simulateResultsOfGroupStage();
                showGroupsMenu();
                return;
             }
        else if (digit == numberOfGroups+2) {
                showGroups();
                showGroupsMenu();
                return;
             }
        else if (digit == numberOfGroups+3) {
                launchCompetitionMenu();
                return;
             }
        else if (digit >= 1 && digit <= groups->back().getId() - 'A') {
            showGroupMenu('A' + digit - 1);
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
