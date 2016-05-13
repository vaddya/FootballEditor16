#ifndef TEAMINPLAYOFF_H
#define TEAMINPLAYOFF_H

#include "../teamstat.h"
#include "iomanip"

using std::setw;

/**
 * @brief The TeamInPlayoff class
 */
class TeamInPlayoff : public TeamStat
{
public:
    TeamInPlayoff( Team &team );
    //friend ostream& operator<<( ostream& os, TeamInPlayoff &match );
private:

};

#endif // TEAMINPLAYOFF_H
