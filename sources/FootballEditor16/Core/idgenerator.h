#ifndef IDGENERATOR_H
#define IDGENERATOR_H

class IdGenerator {
public:
    static IdGenerator *IdGeneratorInstance();
    int getId();
private:
    IdGenerator();
    int count;
    static IdGenerator *idGen;
};

#endif // IDGENERATOR_H
