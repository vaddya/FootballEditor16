#include "idgenerator.h"

IdGenerator *IdGenerator::idGen = 0;

IdGenerator::IdGenerator() {
    firstCount = 0;
    secondCount = 0;
}

IdGenerator *IdGenerator::IdGeneratorInstance() {
    if( idGen == 0 )
        return idGen = new IdGenerator();
    return idGen;
}

int IdGenerator::getFirstId() {
    return ++firstCount;
}

int IdGenerator::getSecondId() {
    return ++secondCount;
}

