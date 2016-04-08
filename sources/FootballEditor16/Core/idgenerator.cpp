#include "idgenerator.h"

IdGenerator *IdGenerator::idGen = 0;

IdGenerator::IdGenerator() {
    count = 0;
}

IdGenerator *IdGenerator::IdGeneratorInstance() {
    if( idGen == 0 )
        return idGen = new IdGenerator();
    return idGen;
}

int IdGenerator::getId() {
    return ++count;
}
