#include "application.h"

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

void Application::isCompetitionReadyToLaunch()
{
    if( comp->getTeams().size() == 16 || comp->getTeams().size() == 32 )
        launchCompetitionMenu();
    else {
        cout << "Number of teams could be 16 or 32!" << endl
             << "Now it's " << comp->getTeams().size() << endl;
        competitionMenu();
    }
}

void Application::setTitleOfCompetition()
{
    string title;
    cout << "Title: ";
    getline(cin, title);
    getline(cin, title);
    comp->setTitle(title);
    cout << " ";
}

void Application::enterTeamsFromConsole()
{
    cout << "Specify the number of teams: ";
    unsigned num;
    cin >> num;
    if( num != 16 && num != 32 ) {
        cout << "Number of teams could be 16 or 32!" << endl;
        enterTeamsFromConsole();
        return;
    }
    string name;
    cout << "Input list of " << num << " teams from console" << endl;
    for( unsigned i = 0; i < num; i++ ) {
        cout << "Name of " << i+1 << " team: ";
        cin >> name;
        comp->addTeam(name);
    }
}

void Application::enterTeamsFromFile()
{
    cout << "Write the input file (default 16 or 32): "  ;
    string filename;
    cin >> filename;
    cin.clear();
    ifstream fin(filename);
    if (!fin.is_open()) {
        cout << "Error! Cannot open input file. Input interrupted.\n";
        return;
    }
    string name;
    fin >> name;
    while (fin) {
        comp->addTeam(name);
        fin >> name;
    }
    fin.close();
    cout << "Data has been read" << endl;
}

void Application::showCurrentSettings()
{
    cout << "Competition \"" << comp->getTitle() << "\"" << endl
         <<  comp->getNumberOfTeams() << " teams:" << endl;
    for (Team team: comp->getTeams()) {
        cout << "(" << team.getId() << ") " << team << endl;
    }
}
