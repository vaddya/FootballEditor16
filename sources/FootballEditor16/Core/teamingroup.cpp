#include "teamingroup.h"

bool TeamInGroup::operator<(const TeamInGroup &another) {
    if (points_ < another.getPoints())
        return true;
    else
        return false;
}
