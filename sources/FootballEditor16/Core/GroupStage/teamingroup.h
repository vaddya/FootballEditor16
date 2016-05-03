#ifndef TEAMINGROUP_H
#define TEAMINGROUP_H

#include "teamstat.h"

/**
 * @brief The TeamInGroup class
 */
class TeamInGroup : public TeamStat
{
public:
    /**
     * @brief Constructor of TeamInGroup
     * @param team Object of type Team
     */
    TeamInGroup( Team &team ): TeamStat( team ), points( 0 ), games( 0 ), wins( 0 ), draws( 0 ), loses( 0 ) {}

    /**
     * @brief Increase games and wins by 1 & increase points by 3
     */
    void win();
    /**
     * @brief Increase games and draws by 1 & increase points by 1
     */
    void draw();
    /**
     * @brief Increase games and loses by 1
     */
    void lose();

    /**
     * @brief Decrease games and wins by 1 & decrease points by 3
     */
    void unWin();
    /**
     * @brief Decrease games and draws by 1 & decrease points by 1
     */
    void unDraw();
    /**
     * @brief Decrease games and loses by 1
     */
    void unLose();

    /**
     * @brief Get number of points
     * @return points
     */
    int getPoints() const;
    /**
     * @brief Get number of games
     * @return games
     */
    int getGames() const;
    /**
     * @brief Get number of wins
     * @return wins
     */
    int getWins() const;
    /**
     * @brief Get number of draws
     * @return draws
     */
    int getDraws() const;
    /**
     * @brief Get number of loses
     * @return loses
     */
    int getLoses() const;

    /**
     * @brief Overloading of operator <
     * @param one Variable of type TeamInGroup
     * @param another Variable of type TeamInGroup
     * @return true, if points of one is less than points of second
     * false, if points of one is greater than or equal of points of second
     */
    friend bool operator<( const TeamInGroup& one, const TeamInGroup& another );

private:
    int points;
    int games;
    int wins;
    int draws;
    int loses;
};

#endif // TEAMINGROUP_H
