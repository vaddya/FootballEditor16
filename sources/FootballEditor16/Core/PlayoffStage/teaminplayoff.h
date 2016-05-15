#ifndef TEAMINPLAYOFF_H
#define TEAMINPLAYOFF_H

#include "../teamstat.h"

/**
 * @brief The TeamInPlayoff class
 */
class TeamInPlayoff : public TeamStat
{
public:
    TeamInPlayoff( Team &team );
};

#endif // TEAMINPLAYOFF_H
