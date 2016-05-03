#ifndef TEAMSTAT_H
#define TEAMSTAT_H

#include "team.h"

/**
 * @brief The TeamStat class
 */
class TeamStat : public Team
{
public:
    TeamStat();
    /**
     * @brief TeamStat
     * @param team
     */
    TeamStat( Team &team );

    /**
     * @brief Increase goals
     * @param goalsFor_ Goals scored team
     * @param goalsAgainst_ Goals scored rivals
     */
    void increaseGoals( int goalsFor_, int goalsAgainst_ );
    /**
     * @brief Decrease goals
     * @param goalsFor_ Goals scored team
     * @param goalsAgainst_ Goals scored rivals
     */
    void decreaseGoals( int goalsFor_, int goalsAgainst_ );
    /**
     * @brief Set the number of goals
     * @param goals_ Number of goals
     */
    void setGoals( int goalsFor_, int goalsAgainst_ );
    /**
     * @brief Set possession
     * @param possession_ Possession
     */
    void setPossession( int possession_ );
    /**
     * @brief Set the number of shots
     * @param shots_ Number of shots
     */
    void setShots( int shots_ );
    /**
     * @brief Set the number of shots on target
     * @param shotsOnTarget_ Number of shots on target
     */
    void setShotOnTarget( int shotsOnTarget_ );
    /**
     * @brief Set the number of yellow cards
     * @param yellowCards_ Number of yellow cards
     */
    void setYellowCards( int yellowCards_ );
    /**
     * @brief Set the number of red cards
     * @param redCards_ Number of red cards
     */
    void setRedCards( int redCards_ );
    /**
     * @brief Set the number of fouls
     * @param fouls_ Number of fouls
     */
    void setFouls( int fouls_ );


    /**
     * @brief Get the number of goals
     * @return goals for
     */
    int getGoalsFor() const;
    /**
     * @brief Get goals against
     * @return goals aginst
     */
    int getGoalsAgainst() const;
    /**
     * @brief Get goals diffrence (goals for minus goals against)
     * @return goals diffrence
     */
    int getGoalsDiffrence() const;
    /**
     * @brief Get possession
     * @return Possession
     */
    int getPossession() const;
    /**
     * @brief Get number of shots
     * @return Number of shots
     */
    int getShots() const;
    /**
     * @brief Get number of shots on target
     * @return Number of shots of target
     */
    int getShotOnTarget() const;
    /**
     * @brief Get number of yellow cards
     * @return Number of yellow cards
     */
    int getYellowCards() const;
    /**
     * @brief Get number of red cards
     * @return Number of red cards
     */
    int getRedCards() const;
    /**
     * @brief Get number of fouls
     * @return Number of fouls
     */
    int getFouls() const;

private:
    int goalsFor;
    int goalsAgainst;
    int possession;
    int shots;
    int shotsOnTarget;
    int yellowCards;
    int redCards;
    int fouls;
};

#endif // TEAMSTAT_H
