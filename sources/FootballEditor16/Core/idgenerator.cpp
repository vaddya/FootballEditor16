#include "idgenerator.h"

IdGenerator *IdGenerator::idGen = 0;

IdGenerator::IdGenerator() {
    teamCount = 1;
    matchCount = 1;
    groupCount = 'A';
}

IdGenerator *IdGenerator::IdGeneratorInstance() {
    if( idGen == 0 )
        return idGen = new IdGenerator();
    return idGen;
}

int IdGenerator::getTeamId() {
    return teamCount++;
}

int IdGenerator::getMatchId() {
    return matchCount++;
}

char IdGenerator::getGroupId()
{
    return groupCount++;
}

