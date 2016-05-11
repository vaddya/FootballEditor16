#include "PlayoffStage/playoffstage.h"

PlayoffStage::PlayoffStage( vector<Team> &teams ): Stage(teams)
{
    if( teams.size() == 8 ) {
        numberOfRounds = 4;
        currentRound = QUARTERFINAL;
    }
    if( teams.size() == 16 ) {
        numberOfRounds = 5;
        currentRound = ROUNDOF16;
    }
}

void PlayoffStage::launch()
{
    //TODO implement start
}

void PlayoffStage::createMatches( vector<int> teamIDs )
{
    int num = -1;
    for( unsigned i = 0; i < teams.size()/2; i++ ) {
        TeamInPlayoff first = findTeam( teamIDs[++num] );
        TeamInPlayoff second = findTeam( teamIDs[++num] );
        matches.push_back( MatchInPlayoff( currentRound, first, second ));
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

RoundEnum PlayoffStage::getRound() const
{
    return currentRound;
}

RoundEnum PlayoffStage::nextStage()
{
    switch( currentRound ) {
        case ROUNDOF16: currentRound = QUARTERFINAL; break;
        case QUARTERFINAL: currentRound = SEMIFINAL; break;
        case SEMIFINAL: currentRound = FINAL; break;
        case FINAL: currentRound = END; break;
        case END: break;
    }
    return currentRound;
}

void PlayoffStage::createNewMatches()
{
}

ostream& operator<<( ostream &os, PlayoffStage &playoff )
{
    os << "Table of playoff stage:" << endl << endl;

    os << playoff.matches[0].getFirstTeam() << setw(13-playoff.matches[0].getFirstTeam().getName().size())
            << playoff.matches[0].getFirstTeam().getGoalsFor() << " ═" << "╗" << endl;
    os << setw(18) << "║" << "══╗" << endl;
    os << playoff.matches[0].getSecondTeam() << setw(13-playoff.matches[0].getSecondTeam().getName().size())
            << playoff.matches[0].getSecondTeam().getGoalsFor() << " ═" << "╝  ║" << endl;

    if( playoff.matches.size() > 4 ) {
        os << setw(21) << "║" << setw(4) << " " << "Russia" << setw(13-6) << "1" << " ═" << "╗" << endl;
        os << setw(21) << "║" << "══" << setw(20) << "║" << "══╗"   << endl;
        os << setw(21) << "║" << setw(4) << " " << "Germany" << setw(13-7) << "4" << " ═" << "╝  ║" << endl;
    }
    else {
        os << setw(21) << "║" << endl;
        os << setw(21) << "║" << "══" << endl;
        os << setw(21) << "║" << endl;
    }

    os << playoff.matches[1].getFirstTeam() << setw(13-playoff.matches[1].getFirstTeam().getName().size())
            << playoff.matches[1].getFirstTeam().getGoalsFor() << " ═" << "╗  ║";
    if( playoff.matches.size() > 4 ) os << setw(25) << "║";
    os << endl;
    os << setw(18) << "║" << "══╝";
    if( playoff.matches.size() > 4 )  os << setw(25) << "║";
    os << endl;
    os << playoff.matches[1].getSecondTeam() << setw(13-playoff.matches[1].getSecondTeam().getName().size())
            << playoff.matches[1].getSecondTeam().getGoalsFor() << " ═" << "╝";
    if( playoff.matches.size() > 4 ) os << setw(28) << "║";
    os << endl;
    os << endl;

    if( playoff.matches.size() > 6 ) {
        os << setw(44) << "║" << setw(4) << " " << "Germany" << setw(13-7) << "2" << " ═" << "╗" << endl;
        os << setw(44) << "║" << "══" << setw(20) << "║" << "══ Germany" << endl;
        os << setw(44) << "║" << setw(4) << " " << "Spain" << setw(13-5) << "0" << " ═" << "╝" << endl;
    }
    else if ( playoff.matches.size() > 4 ) {
        os << setw(44) << "║" << endl;
        os << setw(44) << "║" << "══" << endl;
        os << setw(44) << "║" << endl;
    }
    else {
        os << endl << endl;
    }

    os << playoff.matches[2].getFirstTeam() << setw(13-playoff.matches[2].getFirstTeam().getName().size())
            << playoff.matches[2].getFirstTeam().getGoalsFor() << " ═" << "╗";
    if( playoff.matches.size() > 4 ) os << setw(28) << "║";
    os << endl;
    os << setw(18) << "║" << "══╗";
    if( playoff.matches.size() > 4 )  os << setw(25) << "║";
    os << endl;
    os << playoff.matches[2].getSecondTeam() << setw(13-playoff.matches[2].getSecondTeam().getName().size())
            << playoff.matches[2].getSecondTeam().getGoalsFor() << " ═" << "╝  ║" ;
    if( playoff.matches.size() > 4 ) os << setw(25) << "║" << endl;
    os << endl;

    if( playoff.matches.size() > 6 ) {
        os << setw(21) << "║" << setw(4) << " " << "Spain" << setw(13-5) << "3" << " ═" << "╗  ║" << endl;
        os << setw(21) << "║" << "══" << setw(20) << "║" << "══╝" << endl;
        os << setw(21) << "║" << setw(4) << " " << "Switherland" << setw(13-11) << "1" << " ═" << "╝" << endl;
    }
    else {
        os << setw(21) << "║" << endl;
        os << setw(21) << "║" << "══" << endl;
        os << setw(21) << "║" << endl;
    }

    os << playoff.matches[3].getFirstTeam() << setw(13-playoff.matches[3].getFirstTeam().getName().size())
            << playoff.matches[3].getFirstTeam().getGoalsFor() << " ═" << "╗  ║" << endl;
    os << setw(18) << "║" << "══╝" << endl;
    os << playoff.matches[3].getSecondTeam() << setw(13-playoff.matches[3].getSecondTeam().getName().size())
            << playoff.matches[3].getSecondTeam().getGoalsFor() << " ═" << "╝" << endl;
    return os;
}
