#include "application.h"
#include "iostream"
#include "fstream"

Application::Application()
{
    comp = new Competition;
}

void Application::mainMenu()
{
    cout << "Main Menu:" << endl
         << "1. Launch new competition" << endl
         << "2. Load competiton" << endl
         << "3. Set settings" << endl
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
            launchNewCompetition(); cout << endl; break;
        case 2:
            loadCompetition(); cout << endl; break;
        case 3:
            setSettiings(); cout << endl; break;
        default:
            cout << "Error! Invalid number." << endl << endl;
            cin.clear();
            getline(cin, badStr);
            mainMenu(); break;
        }
    }
    else
    {
        cout << "Error! Input a number." << endl << endl;
        cin.clear();
        getline(cin, badStr);
        mainMenu();
    }
}

void Application::setSettiings()
{
       cout << endl
            << "Competition settings:" << endl
            << "1. Set title of the competition" << endl
            << "2. Enter teams from console" << endl
            << "3. Enter teams from file" << endl
            << "4. Show current settings" << endl
            << "9. Back to main menu" << endl
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
               setTitleOfCompetition(); cout << endl; mainMenu(); break;
           case 2:
               enterTeamsFromConsole(); cout << endl; mainMenu(); break;
           case 3:
               enterTeamsFromFile(); cout << endl; mainMenu(); break;
           case 4:
               showCurrentSettings(); cout << endl; mainMenu(); break;
           case 9:
               mainMenu(); break;
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
           cout << "Error! Input a number." << endl << endl;
           cin.clear();
           getline(cin, badStr);
           mainMenu();
           cout << endl;
       }
}

void Application::setTitleOfCompetition()
{
    string title;
    cout << "Title: ";
    getline(cin, title);
    getline(cin, title);
    comp->setTitle(title);
}

void Application::enterTeamsFromConsole()
{
    cout << "Specify the number of teams: " << endl << ">>> ";
    size_t num;
    cin >> num;
    cout << "So now input list of " << num << " teams from console" << endl;
    string name;
    int rating;
    for (size_t i = 0; i < num; i++)
    {
        cout << "Name of " << i+1 << " team: " << endl << ">>> ";
        cin >> name;
        cout << "FIFA Rating: " << endl << ">>> ";
        cin >> rating;
        comp->addTeam(name, rating);
    }
}

void Application::enterTeamsFromFile()
{
    cout << "Write the input file (0 for \"input.txt\"): "  << endl << ">>> ";
    string filename;
    cin >> filename;
    cin.clear();
    if (filename[0] == '0')
        filename = "input.txt";
    ifstream fin(filename);
    if (!fin.is_open()) {
        cout << "Error! Cannot open input file. Input interrupted.\n";
    }
    else {
        string name;
        int rating;
        fin >> name;
        while (fin)
        {
            fin >> rating;
            comp->addTeam(name, rating);
            fin >> name;
        }
        fin.close();
    }
}

void Application::launchNewCompetition()
{
    comp->startGroupStage();
    setResultsOfGroupStage();
}

void Application::setResultsOfGroupStage()
{
    int goalsOfFirstTeam, goalsOfSecondTeam;
    char separator;
    cout << "Enter results of the matches: " << endl;
    for (Group group: comp->getGroupStage().getGroups()) {
        for (Match match: group.getMatches()) {
            cout << match.getFirstTeam() << " - " << match.getSecondTeam() << ": " << endl << ">>> ";
            cin >> goalsOfFirstTeam >> separator >> goalsOfSecondTeam;
            //TODO implement set results
            //cout << goalsOfFirstTeam << ":" << goalsOfSecondTeam << endl;
        }
    }
}

void Application::loadCompetition()
{
    //TODO implement load comp
    cout << endl;
    mainMenu();
}

void Application::showCurrentSettings()
{
    cout << "Competition \"" << comp->getTitle() << "\"" << endl
         << "(" << comp->getNumberOfTeams() << " teams)" << endl;
    for (size_t i = 0; i < comp->getTeams().size(); i++) {
        cout << i+1 << ". " << comp->getTeams()[i].getName() << " " << comp->getTeams()[i].getFifaPoints() << endl;
        //TODO implement overload << for class Team
    }
}

Application::~Application()
{
    delete comp;
}

