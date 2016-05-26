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

Round &PlayoffStage::getRound(int roundId)
{
    for( Round &round : rounds )
        if( round.getRoundEnum() == roundId )
            return round;
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
    int ROUNDS = playoff.getNumberOfRounds();
    RoundEnum CURRENT = playoff.getCurrentRound();
    RoundEnum FIRST = playoff.getRounds()[0].getRoundEnum();
    RoundEnum SECOND = FINAL;
    if( CURRENT < FIRST )
        SECOND = playoff.getRounds()[1].getRoundEnum();
    RoundEnum THIRD = FINAL;
    if( CURRENT < SECOND )
        THIRD = playoff.getRounds()[2].getRoundEnum();

    os << Round1[0].showFirstTeam() << " ═" << "╗" << endl;
    os << setw(21) << "║" << "══╗" << endl;
    os << Round1[0].showSecondTeam() << " ═" << "╝  ║" << endl;

    if( CURRENT <= SECOND ) {
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
    if( CURRENT <= SECOND ) os << setw(28) << "║";
    os << endl;
    os << setw(21) << "║" << "══╝";
    if( CURRENT <= SECOND ) os << setw(28) << "║";
    os << endl;
    os << Round1[1].showSecondTeam() << " ═" << "╝";
    if( CURRENT <= SECOND ) os << setw(31) << "║";
    else os << endl;
    os << endl;

    if( CURRENT <= THIRD ) {
        os << setw(50) << "║" << setw(3) << " " << Round3[0].showFirstTeam() << " ═" << "╗" << endl;
        os << setw(50) << "║" << "══" << setw(22) << "║" << "══";
        if( ROUNDS == 3 && Round3[0].isPlayed() ) os << " " << Round3[0].getWinner();
        if( ROUNDS == 3 ) os << endl;
        if( ROUNDS == 4 ) os << "╗" << endl;
        os << setw(50) << "║" << setw(3) << " " << Round3[0].showSecondTeam() << " ═" << "╝";
        if( ROUNDS == 4 ) os << "  ║";
        os << endl;
    }
    else if( CURRENT <= SECOND ) {
        os << setw(50) << "║" << endl;
        os << setw(50) << "║" << "══" << endl;
        os << setw(50) << "║" << endl;
    }
    else {
        os << endl << endl;
    }

    os << Round1[2].showFirstTeam() << " ═" << "╗";
    if( CURRENT <= SECOND ) os << setw(31) << "║";
    if( ROUNDS == 4 && CURRENT <= THIRD ) os << setw(27) << "║";
    os << endl;
    os << setw(21) << "║" << "══╗";
    if( CURRENT <= SECOND ) os << setw(28) << "║";
    if( ROUNDS == 4 && CURRENT <= THIRD ) os << setw(27) << "║";
    os << endl;
    os << Round1[2].showSecondTeam() << " ═" << "╝  ║" ;
    if( CURRENT <= SECOND ) os << setw(28) << "║";
    if( ROUNDS == 4 && CURRENT <= THIRD ) os << setw(27) << "║";
    os << endl;

    if( CURRENT <= SECOND ) {
        os << setw(24) << "║" << setw(4) << " " << Round2[1].showFirstTeam() << " ═" << "╗  ║";
        if( ROUNDS == 4 && CURRENT <= THIRD ) os << setw(27) << "║";
        os << endl;
        os << setw(24) << "║" << "══" << setw(23) << "║" << "══╝";
        if( ROUNDS == 4 && CURRENT <= THIRD ) os << setw(27) << "║";
        os << endl;
        os << setw(24) << "║" << setw(4) << " " << Round2[1].showSecondTeam() << " ═" << "╝";
        if( ROUNDS == 4 && CURRENT <= THIRD ) os << setw(30) << "║";
        os << endl;
    }
    else {
        os << setw(24) << "║" << endl;
        os << setw(24) << "║" << "══" << endl;
        os << setw(24) << "║" << endl;
    }

    os << Round1[3].showFirstTeam() << " ═" << "╗  ║";
    if( ROUNDS == 4 && CURRENT <= THIRD ) os << setw(53) << "║";
    os << endl;
    os << setw(21) << "║" << "══╝";
    if( ROUNDS == 4 && CURRENT <= THIRD ) os << setw(53) << "║";
    os << endl;
    os << Round1[3].showSecondTeam() << " ═" << "╝";
    if( ROUNDS == 4 && CURRENT <= THIRD ) os << setw(56) << "║";
    os << endl;


    if( ROUNDS == 4 ) {
        vector<MatchInPlayoff> &Round4 = playoff.getRounds()[3].getMatches();

        if( CURRENT < THIRD ) {
            os << setw(75) << "║" << setw(3) << " " << Round4[0].showFirstTeam() << " ═" << "╗" << endl;
            os << setw(75) << "║" << "══" << setw(22) << "║" << "══ ";
            if( Round4[0].isPlayed() )
                os << Round4[0].getWinner();
            os << endl;
            os << setw(75) << "║" << setw(3) << " " << Round4[0].showSecondTeam() << " ═" << "╝" << endl;
        }
        else if( CURRENT <= THIRD ) {
            os << setw(75) << "║" << endl;
            os << setw(75) << "║" << "══" << endl;
            os << setw(75) << "║" << endl;
        }
        else {
            os << endl << endl << endl;
        }


        os << Round1[4].showFirstTeam() << " ═" << "╗";
        if(CURRENT <= THIRD ) os << setw(56) << "║";
        os << endl;
        os << setw(21) << "║" << "══╗";
        if(CURRENT <= THIRD ) os << setw(53) << "║";
        os << endl;
        os << Round1[4].showSecondTeam() << " ═" << "╝  ║";
        if(CURRENT <= THIRD ) os << setw(53) << "║";
        os << endl;

        if( CURRENT <= SECOND ) {
            os << setw(24) << "║" << setw(4) << " " << Round2[2].showFirstTeam() << " ═" << "╗";
            if( CURRENT <= THIRD ) os << setw(30) << "║";
            os << endl;
            os << setw(24) << "║" << "══" << setw(23) << "║" << "══╗";
            if( CURRENT <= THIRD ) os << setw(27) << "║";
            os << endl;
            os << setw(24) << "║" << setw(4) << " " << Round2[2].showSecondTeam() << " ═" << "╝  ║";
            if( CURRENT <= THIRD ) os << setw(27) << "║";
            os << endl;
        }
        else {
            os << setw(24) << "║" << endl;
            os << setw(24) << "║" << "══" << endl;
            os << setw(24) << "║" << endl;
        }

        os << Round1[5].showFirstTeam() << " ═" << "╗  ║";
        if( CURRENT <= SECOND ) os << setw(28) << "║";
        if( CURRENT <= THIRD ) os << setw(27) << "║";
        os << endl;
        os << setw(21) << "║" << "══╝";
        if( CURRENT <= SECOND ) os << setw(28) << "║";
        if( CURRENT <= THIRD ) os << setw(27) << "║";
        os << endl;
        os << Round1[5].showSecondTeam() << " ═" << "╝";
        if( CURRENT <= SECOND ) os << setw(31) << "║";
        if( CURRENT <= THIRD ) os << setw(27) << "║";
        os << endl;

        if( CURRENT <= THIRD ) {
            os << setw(50) << "║" << setw(3) << " " << Round3[1].showFirstTeam() << " ═" << "╗  ║" << endl;
            os << setw(50) << "║" << "══" << setw(22) << "║" << "══╝" << endl;
            os << setw(50) << "║" << setw(3) << " " << Round3[1].showSecondTeam() << " ═" << "╝" << endl;
        }
        else if( CURRENT <= SECOND ) {
            os << setw(50) << "║" << endl;
            os << setw(50) << "║" << "══" << endl;
            os << setw(50) << "║" << endl;
        }
        else {
            os << endl << endl;
        }

        os << Round1[6].showFirstTeam() << " ═" << "╗";
        if( CURRENT <= SECOND ) os << setw(31) << "║";
        os << endl;
        os << setw(21) << "║" << "══╗";
        if( CURRENT <= SECOND )  os << setw(28) << "║";
        os << endl;
        os << Round1[6].showSecondTeam() << " ═" << "╝  ║" ;
        if( CURRENT <= SECOND ) os << setw(28) << "║" << endl;
        else os << endl;

        if( CURRENT <= SECOND ) {
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
