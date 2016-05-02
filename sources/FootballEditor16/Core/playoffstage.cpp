#include "playoffstage.h"

PlayoffStage::PlayoffStage( vector<Team> &teams ): Stage(teams)
{
    if( teams.size() == 8 ) numberOfRounds = 3;
    if( teams.size() == 16 ) numberOfRounds = 4;
    if( teams.size() == 32 ) numberOfRounds = 5;
}

void PlayoffStage::launch()
{
    //TODO implement start
}

void PlayoffStage::createMatches( vector<int> teamIDs )
{
    int num = -1;
    for( unsigned i = 0; i < teams.size()/2; i++ ) {
        TeamInPlayoff first = findTeam( (teamIDs[++num]) );
        TeamInPlayoff second = findTeam( (teamIDs[++num]) );
        matches.push_back( MatchInPlayoff( first, second ));
    }
}

Team &PlayoffStage::findTeam( int id )
{
    for( Team &team: teams )
        if( team.getId() == id )
            return team;
    throw WrongID( id );
}

vector<MatchInPlayoff> &PlayoffStage::getMatches()
{
    return matches;
}

ostream& operator<<( ostream &os, PlayoffStage &playoff )
{
    for( MatchInPlayoff match: playoff.getMatches() )
        os << match << endl;
    os << endl;

    os << "Russia"<< setw(13-6) << "2" << " ═" << "╗" << endl;
    os << setw(18) << "║" << "══╗" << endl;
    os << "France"<< setw(13-6) << "1" << " ═" << "╝  ║" << endl;

    os << setw(21) << "║" << setw(4) << " " << "Russia" << setw(13-6) << "1" << " ═" << "╗" << endl;
    os << setw(21) << "║" << "══" << setw(20) << "║" << "══╗" << endl;
    os << setw(21) << "║" << setw(4) << " " << "Germany" << setw(13-7) << "4" << " ═" << "╝  ║" << endl;

    os << "Netherlands"<< setw(13-11) << "0" << " ═" << "╗  ║" << setw(25) << "║" << endl;
    os << setw(18) << "║" << "══╝" << setw(25) << "║" << endl;
    os << "Germany"<< setw(13-7) << "3" << " ═" << "╝" << setw(28) << "║" << endl;

    os << setw(44) << "║" << setw(4) << " " << "Germany" << setw(13-7) << "2" << " ═" << "╗" << endl;
    os << setw(44) << "║" << "══" << setw(20) << "║" << "══ Germany" << endl;
    os << setw(44) << "║" << setw(4) << " " << "Spain" << setw(13-5) << "0" << " ═" << "╝" << endl;

    os << "Spain"<< setw(13-5) << "2" << " ═" << "╗" << setw(28) << "║" << endl;
    os << setw(18) << "║" << "══╗" << setw(25) << "║" << endl;
    os << "Italy"<< setw(13-5) << "1" << " ═" << "╝  ║" << setw(25) << "║" << endl;

    os << setw(21) << "║" << setw(4) << " " << "Spain" << setw(13-5) << "3" << " ═" << "╗  ║" << endl;
    os << setw(21) << "║" << "══" << setw(20) << "║" << "══╝" << endl;
    os << setw(21) << "║" << setw(4) << " " << "Switherland" << setw(13-11) << "1" << " ═" << "╝" << endl;

    os << "Switherland"<< setw(13-11) << "1" << " ═" << "╗  ║" << endl;
    os << setw(18) << "║" << "══╝" << endl;
    os << "Denmark"<< setw(13-7) << "0" << " ═" << "╝" << endl;
    return os;
}
