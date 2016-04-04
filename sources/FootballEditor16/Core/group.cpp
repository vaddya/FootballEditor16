#include "group.h"

char Group::getCharacter() const
{
    return character;
}

void Group::sort()
{
    std::sort(teams.begin(), teams.end());
    std::reverse(teams.begin(), teams.end());
}

void Group::createMatches()
{
    for (unsigned i = 0; i < 4; i++) {
        for (unsigned j = i+1; j < 4; j++) {
            matches.push_back(Match(teams[i], teams[j]));
        }
    }
}
