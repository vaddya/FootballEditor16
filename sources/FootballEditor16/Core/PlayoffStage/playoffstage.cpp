#include "PlayoffStage/playoffstage.h"

PlayoffStage::PlayoffStage( vector<Team> &teams ): Stage(teams)
{
    if( teams.size() == 8 ) {
        numberOfRounds = 3;
        currentRound = QUARTERFINAL;
        rounds.push_back( currentRound );
    }
    if( teams.size() == 16 ) {
        numberOfRounds = 4;
        currentRound = ROUNDOF16;
        rounds.push_back( currentRound );
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
        rounds.back().addPair( first, second );
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
        return rounds.back().getMatches();
}

RoundEnum PlayoffStage::getCurrentRound() const
{
    return currentRound;
}

vector<Round> &PlayoffStage::getRounds()
{
    return rounds;
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
    rounds.back().updateWinners();
    if( currentRound == FINAL ) {
        throw CompetitionIsOver();
    }
    else {
        nextStage();
        rounds.push_back( currentRound );
        rounds.back().addTeams( rounds[rounds.size()-2].getWinners() );
    }
}

// Консольная графика - один большой костыль
ostream& operator<<( ostream &os, PlayoffStage &playoff )
{
    os << "Table of playoff stage:" << endl << endl;

    vector<MatchInPlayoff> &Round1 = playoff.getRounds()[0].getMatches();
    vector<MatchInPlayoff> &Round2 = playoff.getRounds()[1].getMatches();
    vector<MatchInPlayoff> &Round3 = playoff.getRounds()[2].getMatches();

    os << Round1[0].showFirstTeam() << " ═" << "╗" << endl;
    os << setw(21) << "║" << "══╗" << endl;
    os << Round1[0].showSecondTeam() << " ═" << "╝  ║" << endl;

    if( playoff.getCurrentRound() <= 2 ) {
        os << setw(24) << "║" << setw(4) << " " << Round2[0].showFirstTeam() << " ═" << "╗" << endl;
        os << setw(24) << "║" << "══" << setw(23) << "║" << "══╗"   << endl;
        os << setw(24) << "║" << setw(4) << " " << Round2[0].showSecondTeam() << " ═" << "╝  ║" << endl;
    }
    else {
        os << setw(24) << "║" << endl;
        os << setw(24) << "║" << "══" << endl;
        os << setw(24) << "║" << endl;
    }

    os << Round1[1].showFirstTeam() << " ═" << "╗  ║";
    if( playoff.getCurrentRound() <= 2 ) os << setw(28) << "║";
    os << endl;
    os << setw(21) << "║" << "══╝";
    if( playoff.getCurrentRound() <= 2 ) os << setw(28) << "║";
    os << endl;
    os << Round1[1].showSecondTeam() << " ═" << "╝";
    if( playoff.getCurrentRound() <= 2 ) os << setw(31) << "║";
    else os << endl;
    os << endl;

    if( playoff.getCurrentRound() == 1 ) {
        os << setw(50) << "║" << setw(3) << " " << Round3[0].showFirstTeam() << " ═" << "╗" << endl;
        os << setw(50) << "║" << "══" << setw(22) << "║" << "══ ";
        if( !Round3[0].isPlayed() )
            os << endl;
        else
            os << Round3[0].getWinner() << endl;
        os << setw(50) << "║" << setw(3) << " " << Round3[0].showSecondTeam() << " ═" << "╝" << endl;
    }
    else if( playoff.getCurrentRound() <= 2 ) {
        os << setw(50) << "║" << endl;
        os << setw(50) << "║" << "══" << endl;
        os << setw(50) << "║" << endl;
    }
    else {
        os << endl << endl;
    }

    os << Round1[2].showFirstTeam() << " ═" << "╗";
    if( playoff.getCurrentRound() <= 2 ) os << setw(31) << "║";
    os << endl;
    os << setw(21) << "║" << "══╗";
    if( playoff.getCurrentRound() <= 2 )  os << setw(28) << "║";
    os << endl;
    os << Round1[2].showSecondTeam() << " ═" << "╝  ║" ;
    if( playoff.getCurrentRound() <= 2 ) os << setw(28) << "║" << endl;
    else os << endl;

    if( playoff.getCurrentRound() <= 2 ) {
        os << setw(24) << "║" << setw(4) << " " << Round2[1].showFirstTeam() << " ═" << "╗  ║" << endl;
        os << setw(24) << "║" << "══" << setw(23) << "║" << "══╝"   << endl;
        os << setw(24) << "║" << setw(4) << " " << Round2[1].showSecondTeam() << " ═" << "╝" << endl;
    }
    else {
        os << setw(24) << "║" << endl;
        os << setw(24) << "║" << "══" << endl;
        os << setw(24) << "║" << endl;
    }

    os << Round1[3].showFirstTeam() << " ═" << "╗  ║" << endl;
    os << setw(21) << "║" << "══╝" << endl;
    os << Round1[3].showSecondTeam() << " ═" << "╝" << endl;

    return os;
}
