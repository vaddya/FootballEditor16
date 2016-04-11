#ifndef IDGENERATOR_H
#define IDGENERATOR_H

/**
 * @brief The IdGenerator class
 */
class IdGenerator {
public:
    /**
     * @brief Instance ID Generator
     * @return pointer to ID Generator
     */
    static IdGenerator *IdGeneratorInstance();
    /**
     * @brief Get ID from first counter
     * @return Generated ID
     */
    int getFirstId();
    /**
     * @brief Get ID from second counter
     * @return Generated ID
     */
    int getSecondId();
private:
    IdGenerator();
    int firstCount;
    int secondCount;
    static IdGenerator *idGen;
};

#endif // IDGENERATOR_H
