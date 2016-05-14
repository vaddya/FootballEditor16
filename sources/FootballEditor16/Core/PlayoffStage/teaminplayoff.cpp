#include "PlayoffStage/teaminplayoff.h"

TeamInPlayoff::TeamInPlayoff(Team &team): TeamStat(team)
{

}

/*ostream &operator<<( ostream &os, TeamInPlayoff &team )
{
    os << team << setw(13-team.getName().size()) << team.getGoalsFor();
    return os;
}*/
