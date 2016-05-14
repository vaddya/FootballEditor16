#include "GroupStage/teamingroup.h"

TeamInGroup::TeamInGroup( Team &team ): TeamStat( team ), points( 0 ), games( 0 ), wins( 0 ), draws( 0 ), loses( 0 ) {}

void TeamInGroup::win()
{
    ++games;
    ++wins;
    points += 3;
}

void TeamInGroup::draw()
{
    ++games;
    ++draws;
    ++points;
}

void TeamInGroup::lose()
{
    ++games;
    ++loses;
}

void TeamInGroup::unWin()
{
    --games;
    --wins;
    points -= 3;
}

void TeamInGroup::unDraw()
{
    --games;
    --draws;
    --points;
}

void TeamInGroup::unLose()
{
    --games;
    --loses;
}

int TeamInGroup::getPoints() const
{
    return points;
}

int TeamInGroup::getGames() const
{
    return games;
}

int TeamInGroup::getWins() const
{
    return wins;
}

int TeamInGroup::getDraws() const
{
    return draws;
}

int TeamInGroup::getLoses() const
{
    return loses;
}

bool operator<( const TeamInGroup &one, const TeamInGroup &another )
{
    if( one.getPoints() < another.getPoints() ) return true;
    if( one.getPoints() > another.getPoints() ) return false;
    if( one.getPoints() == another.getPoints() ) {
        if( one.getGoalsDiffrence() < another.getGoalsDiffrence() ) return true;
        if( one.getGoalsDiffrence() > another.getGoalsDiffrence() ) return false;
        if( one.getGoalsDiffrence() == another.getGoalsDiffrence() ) {
            if( one.getGoalsFor() < another.getGoalsFor() ) return true;
            if( one.getGoalsFor() > another.getGoalsFor() ) return false;
            if( one.getGoalsFor() == another.getGoalsFor() ) {
                //Randomiser *randomiser = Randomiser::RandomiserInstance();
                //return (bool)randomiser->random(0,1);
                //return true;
                return bool(one.getId()%2); // kind of random
            }
        }
    }
    //return true; // just remove warning
        //return one.getPoints() < another.getPoints();
}
