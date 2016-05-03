#ifndef IDGENERATOR_H
#define IDGENERATOR_H

/**
 * @brief The IdGenerator class
 */
class IdGenerator
{
public:
    /**
     * @brief Instance ID Generator
     * @return pointer to ID Generator
     */
    static IdGenerator *IdGeneratorInstance();
    /**
     * @brief Get ID for team
     * @return Generated ID
     */
    int getTeamId();
    /**
     * @brief Get ID for match
     * @return Generated ID
     */
    int getMatchId();
    /**
     * @brief Get ID for group
     * @return Generated ID
     */
    char getGroupId();

private:
    IdGenerator();
    int teamCount;
    int matchCount;
    char groupCount;
    static IdGenerator *idGen;
};

#endif // IDGENERATOR_H
