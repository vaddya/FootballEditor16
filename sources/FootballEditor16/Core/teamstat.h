#ifndef TEAMSTAT_H
#define TEAMSTAT_H

#include "team.h"

/**
 * @brief The TeamStat class
 */
class TeamStat : public Team
{
public:
    /**
     * @brief Constuctor of TeamStat
     * @param team Source object
     */
    TeamStat(Team & team);

    void setGoals(int gls = 0);
    void setPossession(int psn = 0);
    void setShots(int sts = 0);
    void setShotOnTarget(int sot = 0);
    void setYellowCards(int ycd = 0);
    void setRedCards(int rcd = 0);
    void setFouls(int fls = 0);

    int getGoals() const;
    int getPossession() const;
    int getShots() const;
    int getShotOnTarget() const;
    int getYellowCards() const;
    int getRedCards() const;
    int getFouls() const;

private:
    int goals;
    int possession;
    int shots;
    int shotsOnTarget;
    int yellowCards;
    int redCards;
    int fouls;
};

#endif // TEAMSTAT_H
