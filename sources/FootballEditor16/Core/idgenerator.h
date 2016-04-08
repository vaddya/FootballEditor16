#ifndef IDGENERATOR_H
#define IDGENERATOR_H

class IdGenerator {
public:
    static IdGenerator *IdGeneratorInstance();
    int getFirstId();
    int getSecondId();
private:
    IdGenerator();
    int firstCount;
    int secondCount;
    static IdGenerator *idGen;
};

#endif // IDGENERATOR_H
