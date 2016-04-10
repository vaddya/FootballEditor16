#include "group.h"

char Group::getCharacter() const
{
    return character;
}

vector<TeamInGroup>& Group::getTeams()
{
    return teams;
}

vector<Match>& Group::getMatches()
{
    return matches;
}

vector<Team> Group::determineWiners()
{
    sort();
    vector<Team> winers;
    if (teams[1] < teams[0])
        winers.push_back(teams[0]);
    return winers;
}

ostream& operator<<(ostream &os, Group &group)
{
    cout << "Group " << group.getCharacter() << endl;
    cout << "N  " << "Team" << setw(26) << "G   W   D   L   P" << endl;
    int i = 0;
    for( TeamInGroup team : group.getTeams() )
        cout << ++i << ". " << team << setw(14-team.getName().size())
             << team.getGames() << "   "
             << team.getWins() << "   "
             << team.getDrawns() << "   "
             << team.getLoses() << "   "
             << team.getPoints() << endl;
    return os;
}

void Group::sort()
{
    std::sort(teams.begin(), teams.end());
    std::reverse(teams.begin(), teams.end());
}

void Group::createMatches()
{
    for (unsigned i = 0; i < 4; i++) {
        for (unsigned j = i+1; j < 4; j++) {
            matches.push_back(Match(teams[i], teams[j]));
        }
    }
}

void Group::addTeam(Team &team)
{
    teams.push_back(team);
}
