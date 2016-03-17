#include "application.h"
#include "iostream"
#include "fstream"

Application::Application(): numberOfTeams(16) {}

void Application::mainMenu()
{
    cout << "Main Menu:" << endl
         << "1. Set settings" << endl
         << "2. Launch new competition" << endl
         << "3. Load competiton" << endl
         << "4. Show current list of teams" << endl
         << "0. Exit" << endl
         << ">>> ";
    int num;
    if (cin >> num)
    {
        switch (num)
        {
        case 0:
            break;
        case 1:
            setSettiings(); break;
        case 2:
            launchNewCompetition(); break;
        case 3:
            loadCompetition(); break;
        case 4:
            //temporary for debug
            for(size_t i = 0; i < teams.size(); i++)
            {
                cout << teams[i].getName() << " " << teams[i].getFifaPoints() << endl;
            }
            break;
        default:
            cout << "Error! Invalid number.\n" << endl;
            mainMenu(); break;
        }
    }
    else
    {
        cout << "Error! Input a number.\n" << endl;
        cin.clear();
        mainMenu();
    }
}

void Application::setSettiings()
{
       cout << "Settings:" << endl
            << "1. Set number of teams" << endl
            << "2. Enter teams from console" << endl
            << "3. Enter teams from file" << endl
            << "9. Back to main menu" << endl
            << "0. Exit" << endl
            << ">>> ";
       int num;
       if (cin >> num)
       {
           switch (num)
           {
           case 0:
               break;
           case 1:
               setNumberOfTeams(); mainMenu(); break;
           case 2:
               enterTeamsFromConsole(); mainMenu(); break;
           case 3:
               enterTeamsFromFile(); mainMenu(); break;
           case 9:
               mainMenu(); break;
           default:
               cout << "Error! Invalid number.\n" << endl;
               mainMenu(); break;
           }
       }
       else
       {
           cout << "Error! Input a number.\n" << endl;
           cin.clear();
           setSettiings();
       }
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
    cout << "okay, now number of teams = " << numberOfTeams << endl;
}

void Application::enterTeamsFromConsole()
{
    //TODO implement input
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
    if (!fin.is_open())
    {
        cout << "Error! Cannot open input file. Input interrupted.\n" << endl;
        setSettiings();
    }
    else
    {
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
    Competition comp(numberOfTeams);
    comp.setListOfTeams(teams);
    comp.launch();
}

void Application::loadCompetition()
{
    //TODO implement load comp
}

