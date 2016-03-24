#include "application.h"
#include "iostream"
#include "fstream"

Application::Application(): numberOfTeams(16), titleOfCompetition("Championat") {}

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
            launchNewCompetition(); break;
        case 2:
            loadCompetition(); break;
        case 3:
            setSettiings(); break;
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
            << "2. Set number of teams" << endl
            << "3. Enter teams from console" << endl
            << "4. Enter teams from file" << endl
            << "5. Show current settings" << endl
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
               setTitleOfCompetition(); mainMenu(); break;
           case 2:
               setNumberOfTeams(); mainMenu(); break;
           case 3:
               enterTeamsFromConsole(); mainMenu(); break;
           case 4:
               enterTeamsFromFile(); mainMenu(); break;
           case 5:
               showCurrentSettings(); mainMenu(); break;
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
    cin >> title;
    //getline(cin, title);
    titleOfCompetition = title;
}

void Application::setNumberOfTeams()
{
    cout << "Enter the number of teams:" << endl
         << ">>> ";
    size_t num;
    if (cin >> num)
        numberOfTeams = num;
    else
        throw WrongInput();
}

void Application::enterTeamsFromConsole()
{
    cout << "Input list of " << numberOfTeams << " teams from console" << endl;
    string team;
    int rating;
    for (size_t i = 0; i < numberOfTeams; i++)
    {
        cout << "Name of " << i+1 << " team: ";
        cin >> team;
        cout << "FIFA Rating: ";
        cin >> rating;
        teams.push_back(Team(team, rating));
    }
}

void Application::enterTeamsFromFile()
{
    cout << "Write the input file (0 for \"input.txt\"): " << endl;
    string filename;
    cin >> filename;
    cin.clear();
    if (filename[0] == '0')
        filename = "input.txt";
    ifstream fin(filename);
    if (!fin.is_open()) {
        cout << "Error! Cannot open input file. Input interrupted.\n" << endl;
    }
    else {
        string team;
        int rating;
        fin >> team;
        while (fin)
        {
            fin >> rating;
            teams.push_back(Team(team, rating));
            fin >> team;
        }

    }
    fin.close();
}

void Application::launchNewCompetition()
{
    comp = new Competition (numberOfTeams);
    comp->setTitle(titleOfCompetition);
    comp->setListOfTeams(teams);
    comp->startGroupStage();
    setResultsOfGroupStage();
}

void Application::setResultsOfGroupStage()
{
    for (Group group: comp->getGroupStage().getGroups()) {
        for (Match match: group.getMatches()) {
            cout << "First team: " << match.getFirstTeam() << endl;
        }
    }
}

void Application::loadCompetition()
{
    //TODO implement load comp
}

void Application::showCurrentSettings()
{
    cout << "Competition \"" << titleOfCompetition << "\" (" << numberOfTeams << " teams)" << endl;
    for (size_t i = 0; i < teams.size(); i++) {
        cout << i+1 << ". " << teams[i].getName() << " " << teams[i].getFifaPoints() << endl;
        //TODO implement overload << for class Team
    }
}

Application::~Application()
{
    delete comp;
}

