#include "PlayoffStage/playoffstage.h"

PlayoffStage::PlayoffStage( vector<Team> &teams ): Stage(teams)
{
    if( teams.size() == 8 ) {
        numberOfRounds = 3;
        currentRound = QUARTERFINAL;
        rounds.reserve( numberOfRounds );
        rounds.push_back( currentRound );
    }
    if( teams.size() == 16 ) {
        numberOfRounds = 4;
        currentRound = ROUNDOF16;
        rounds.reserve( numberOfRounds );
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

int PlayoffStage::getNumberOfRounds() const
{
    return numberOfRounds;
}

// Консольная графика - один большой костыль
ostream& operator<<( ostream &os, PlayoffStage &playoff )
{
    os << "Table of playoff stage:" << endl << endl;

    vector<MatchInPlayoff> &Round1 = playoff.getRounds()[0].getMatches();
    vector<MatchInPlayoff> &Round2 = playoff.getRounds()[1].getMatches();
    vector<MatchInPlayoff> &Round3 = playoff.getRounds()[2].getMatches();

    int FIRST, SECOND, THIRD;
    if( playoff.getNumberOfRounds() == 3 ) {
        FIRST = 2;
        SECOND = 1;
        THIRD = 0;
    }
    if( playoff.getNumberOfRounds() == 4 ) {
        FIRST = 4;
        SECOND = 2;
        THIRD = 1;
    }

    os << Round1[0].showFirstTeam() << " ═" << "╗" << endl;
    os << setw(21) << "║" << "══╗" << endl;
    os << Round1[0].showSecondTeam() << " ═" << "╝  ║" << endl;

    if( playoff.getCurrentRound() <= FIRST ) {
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
    if( playoff.getCurrentRound() <= FIRST ) os << setw(28) << "║";
    os << endl;
    os << setw(21) << "║" << "══╝";
    if( playoff.getCurrentRound() <= FIRST ) os << setw(28) << "║";
    os << endl;
    os << Round1[1].showSecondTeam() << " ═" << "╝";
    if( playoff.getCurrentRound() <= FIRST ) os << setw(31) << "║";
    else os << endl;
    os << endl;

    if( playoff.getCurrentRound() <= SECOND ) {
        os << setw(50) << "║" << setw(3) << " " << Round3[0].showFirstTeam() << " ═" << "╗" << endl;
        os << setw(50) << "║" << "══" << setw(22) << "║" << "══╗" << endl;
        os << setw(50) << "║" << setw(3) << " " << Round3[0].showSecondTeam() << " ═" << "╝  ║" << endl;
    }
    else if( playoff.getCurrentRound() <= FIRST ) {
        os << setw(50) << "║" << endl;
        os << setw(50) << "║" << "══" << endl;
        os << setw(50) << "║" << endl;
    }
    else {
        os << endl << endl;
    }

    os << Round1[2].showFirstTeam() << " ═" << "╗";
    if( playoff.getCurrentRound() <= FIRST ) os << setw(31) << "║";
    if( playoff.getCurrentRound() <= FIRST ) os << setw(27) << "║";
    os << endl;
    os << setw(21) << "║" << "══╗";
    if( playoff.getCurrentRound() <= FIRST )  os << setw(28) << "║" << setw(27) << "║";
    os << endl;
    os << Round1[2].showSecondTeam() << " ═" << "╝  ║" ;
    if( playoff.getCurrentRound() <= FIRST ) os << setw(28) << "║"  << setw(27) << "║" << endl;
    else os << endl;

    if( playoff.getCurrentRound() <= FIRST ) {
        os << setw(24) << "║" << setw(4) << " " << Round2[1].showFirstTeam() << " ═" << "╗  ║" << setw(27) << "║" << endl;
        os << setw(24) << "║" << "══" << setw(23) << "║" << "══╝" << setw(27) << "║" << endl;
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


    if( playoff.getNumberOfRounds() == 4) {

        vector<MatchInPlayoff> &Round4 = playoff.getRounds()[3].getMatches();

        if( playoff.getCurrentRound() <= THIRD ) {
            os << setw(75) << "║" << setw(3) << " " << Round4[0].showFirstTeam() << " ═" << "╗" << endl;
            os << setw(75) << "║" << "══" << setw(22) << "║" << "══ ";
            if( !Round4[0].isPlayed() )
                os << endl;
            else
                os << Round4[0].getWinner() << endl;
            os << setw(75) << "║" << setw(3) << " " << Round4[0].showSecondTeam() << " ═" << "╝" << endl;
        }
        else if( playoff.getCurrentRound() <= SECOND ) {
            os << setw(75) << "║" << endl;
            os << setw(75) << "║" << "══" << endl;
            os << setw(75) << "║" << endl;
        }
        else {
            os << endl << endl << endl;
        }


        os << Round1[4].showFirstTeam() << " ═" << "╗" << endl;
        os << setw(21) << "║" << "══╗" << endl;
        os << Round1[4].showSecondTeam() << " ═" << "╝  ║" << endl;

        if( playoff.getCurrentRound() <= FIRST ) {
            os << setw(24) << "║" << setw(4) << " " << Round2[2].showFirstTeam() << " ═" << "╗" << endl;
            os << setw(24) << "║" << "══" << setw(23) << "║" << "══╗"   << endl;
            os << setw(24) << "║" << setw(4) << " " << Round2[2].showSecondTeam() << " ═" << "╝  ║" << endl;
        }
        else {
            os << setw(24) << "║" << endl;
            os << setw(24) << "║" << "══" << endl;
            os << setw(24) << "║" << endl;
        }

        os << Round1[5].showFirstTeam() << " ═" << "╗  ║";
        if( playoff.getCurrentRound() <= FIRST ) os << setw(28) << "║" << setw(27) << "║";
        os << endl;
        os << setw(21) << "║" << "══╝";
        if( playoff.getCurrentRound() <= FIRST ) os << setw(28) << "║" << setw(27) << "║";
        os << endl;
        os << Round1[5].showSecondTeam() << " ═" << "╝";
        if( playoff.getCurrentRound() <= FIRST ) os << setw(31) << "║" << setw(27) << "║";
        else os << endl;
        os << endl;

        if( playoff.getCurrentRound() <= SECOND ) {
            os << setw(50) << "║" << setw(3) << " " << Round3[1].showFirstTeam() << " ═" << "╗  ║" << endl;
            os << setw(50) << "║" << "══" << setw(22) << "║" << "══╝" << endl;
            os << setw(50) << "║" << setw(3) << " " << Round3[1].showSecondTeam() << " ═" << "╝" << endl;
        }
        else if( playoff.getCurrentRound() <= FIRST ) {
            os << setw(50) << "║" << endl;
            os << setw(50) << "║" << "══" << endl;
            os << setw(50) << "║" << endl;
        }
        else {
            os << endl << endl;
        }

        os << Round1[6].showFirstTeam() << " ═" << "╗";
        if( playoff.getCurrentRound() <= FIRST ) os << setw(31) << "║";
        os << endl;
        os << setw(21) << "║" << "══╗";
        if( playoff.getCurrentRound() <= FIRST )  os << setw(28) << "║";
        os << endl;
        os << Round1[6].showSecondTeam() << " ═" << "╝  ║" ;
        if( playoff.getCurrentRound() <= FIRST ) os << setw(28) << "║" << endl;
        else os << endl;

        if( playoff.getCurrentRound() <= FIRST ) {
            os << setw(24) << "║" << setw(4) << " " << Round2[3].showFirstTeam() << " ═" << "╗  ║" << endl;
            os << setw(24) << "║" << "══" << setw(23) << "║" << "══╝"   << endl;
            os << setw(24) << "║" << setw(4) << " " << Round2[3].showSecondTeam() << " ═" << "╝" << endl;
        }
        else {
            os << setw(24) << "║" << endl;
            os << setw(24) << "║" << "══" << endl;
            os << setw(24) << "║" << endl;
        }

        os << Round1[7].showFirstTeam() << " ═" << "╗  ║" << endl;
        os << setw(21) << "║" << "══╝" << endl;
        os << Round1[7].showSecondTeam() << " ═" << "╝" << endl;


    }
    return os;
}
