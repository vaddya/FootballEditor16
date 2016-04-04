#include "teamingroup.h"

bool operator < ( const TeamInGroup &one, const TeamInGroup &another ) {
    if (one.getPoints() < another.getPoints())
        return true;
    else
        return false;
}
