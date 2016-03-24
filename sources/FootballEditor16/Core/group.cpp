#include "group.h"

void Group::createMatches()
{
    for (int i = 0; i < 4; i++) {
        for (int j = i; j < 4; j++)
            matches.push_back(Match(teams[i], teams[j]));
    }
}
