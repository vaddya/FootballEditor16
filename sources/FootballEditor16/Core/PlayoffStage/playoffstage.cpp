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
    if ( currentRound == FINAL ) {
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

    os << Round1[0].getFirstTeam() << setw(13-Round1[0].getFirstTeam().getName().size())
            << Round1[0].getFirstTeam().getGoalsFor() << " ═" << "╗" << endl;
    os << setw(18) << "║" << "══╗" << endl;
    os << Round1[0].getSecondTeam() << setw(13-Round1[0].getSecondTeam().getName().size())
            << Round1[0].getSecondTeam().getGoalsFor() << " ═" << "╝  ║" << endl;

    if( playoff.getCurrentRound() <= 2 ) {
        os << setw(21) << "║" << setw(4) << " " << Round2[0].getFirstTeam() << setw(13-Round2[0].getFirstTeam().getName().size())
           << Round2[0].getFirstTeam().getGoalsFor() << " ═" << "╗" << endl;
        os << setw(21) << "║" << "══" << setw(20) << "║" << "══╗"   << endl;
        os << setw(21) << "║" << setw(4) << " " << Round2[0].getSecondTeam() << setw(13-Round2[0].getSecondTeam().getName().size())
           << Round2[0].getSecondTeam().getGoalsFor() << " ═" << "╝  ║" << endl;
    }
    else {
        os << setw(21) << "║" << endl;
        os << setw(21) << "║" << "══" << endl;
        os << setw(21) << "║" << endl;
    }

    os << Round1[1].getFirstTeam() << setw(13-Round1[1].getFirstTeam().getName().size())
            << Round1[1].getFirstTeam().getGoalsFor() << " ═" << "╗  ║";
    if( playoff.getCurrentRound() <= 2 ) os << setw(25) << "║";
    os << endl;
    os << setw(18) << "║" << "══╝";
    if( playoff.getCurrentRound() <= 2 ) os << setw(25) << "║";
    os << endl;
    os << Round1[1].getSecondTeam() << setw(13-Round1[1].getSecondTeam().getName().size())
            << Round1[1].getSecondTeam().getGoalsFor() << " ═" << "╝";
    if( playoff.getCurrentRound() <= 2 ) os << setw(28) << "║";
    else os << endl;
    os << endl;

    if( playoff.getCurrentRound() == 1 ) {
        os << setw(44) << "║" << setw(4) << " " << Round3[0].getFirstTeam() << setw(13-Round3[0].getFirstTeam().getName().size())
           << Round3[0].getFirstTeam().getGoalsFor() << " ═" << "╗" << endl;
        os << setw(44) << "║" << "══" << setw(20) << "║" << "══ ";
        if( Round3[0].getResult() == "Hasn't started yet" )
            os << endl;
        else
            os << Round3[0].getWinner() << endl;
        os << setw(44) << "║" << setw(4) << " " << Round3[0].getSecondTeam() << setw(13-Round3[0].getSecondTeam().getName().size())
           << Round3[0].getSecondTeam().getGoalsFor() << " ═" << "╝" << endl;
    }
    else if ( playoff.getCurrentRound() <= 2 ) {
        os << setw(44) << "║" << endl;
        os << setw(44) << "║" << "══" << endl;
        os << setw(44) << "║" << endl;
    }
    else {
        os << endl << endl;
    }

    os << Round1[2].getFirstTeam() << setw(13-Round1[2].getFirstTeam().getName().size())
            << Round1[2].getFirstTeam().getGoalsFor() << " ═" << "╗";
    if( playoff.getCurrentRound() <= 2 ) os << setw(28) << "║";
    os << endl;
    os << setw(18) << "║" << "══╗";
    if( playoff.getCurrentRound() <= 2 )  os << setw(25) << "║";
    os << endl;
    os << Round1[2].getSecondTeam() << setw(13-Round1[2].getSecondTeam().getName().size())
            << Round1[2].getSecondTeam().getGoalsFor() << " ═" << "╝  ║" ;
    if( playoff.getCurrentRound() <= 2 ) os << setw(25) << "║" << endl;
    else os << endl;

    if( playoff.getCurrentRound() <= 2 ) {
        os << setw(21) << "║" << setw(4) << " " << Round2[1].getFirstTeam() << setw(13-Round2[1].getFirstTeam().getName().size())
           << Round2[1].getFirstTeam().getGoalsFor() << " ═" << "╗  ║" << endl;
        os << setw(21) << "║" << "══" << setw(20) << "║" << "══╝"   << endl;
        os << setw(21) << "║" << setw(4) << " " << Round2[1].getSecondTeam() << setw(13-Round2[1].getSecondTeam().getName().size())
           << Round2[1].getSecondTeam().getGoalsFor() << " ═" << "╝" << endl;
    }
    else {
        os << setw(21) << "║" << endl;
        os << setw(21) << "║" << "══" << endl;
        os << setw(21) << "║" << endl;
    }

    os << Round1[3].getFirstTeam() << setw(13-Round1[3].getFirstTeam().getName().size())
            << Round1[3].getFirstTeam().getGoalsFor() << " ═" << "╗  ║" << endl;
    os << setw(18) << "║" << "══╝" << endl;
    os << Round1[3].getSecondTeam() << setw(13-Round1[3].getSecondTeam().getName().size())
            << Round1[3].getSecondTeam().getGoalsFor() << " ═" << "╝" << endl;

    return os;
}
