#include "GroupStage/group.h"

Group::Group()
{
    IdGenerator *idGen = IdGenerator::IdGeneratorInstance();
    id = idGen->getGroupId();
}

char Group::getId() const
{
    return id;
}

vector<TeamInGroup>& Group::getTeams()
{
    return teams;
}

vector<MatchInGroup>& Group::getMatches()
{
    return matches;
}

vector<Team> Group::getWinners()
{
    vector<Team> winners;
    winners.push_back(teams[0]);
    winners.push_back(teams[1]);
    return winners;
}

void Group::sort()
{
    std::sort(teams.begin(), teams.end());
    std::reverse(teams.begin(), teams.end());
}

void Group::createMatches()
{
    for( unsigned i = 0; i < 4; i++ ) {
        for( unsigned j = i+1; j < 4; j++ ) {
            matches.push_back(MatchInGroup(teams[i], teams[j]));
        }
    }
}

void Group::addTeam(Team &team)
{
    teams.push_back(team);
}

ostream& operator<<(ostream &os, Group &group)
{
    group.sort();
    os << "Group " << group.getId() << endl;
    os << "N  " << "Team" << setw(38) << "M   W   D   L  GF  GA  GD   P" << endl;
    int i = 0;
    for( TeamInGroup team : group.getTeams() ) {
        os << ++i << ". " << team << setw(14-team.getName().size())
           << team.getGames() << " " << setw(3)
           << team.getWins() << " " << setw(3)
           << team.getDraws() << " " << setw(3)
           << team.getLoses() << " " << setw(3)
           << team.getGoalsFor() << " " << setw(3)
           << team.getGoalsAgainst() << " " << setw(3)
           << team.getGoalsDiffrence() << " " << setw(3)
           << team.getPoints() << endl;
    }
    return os;
}
