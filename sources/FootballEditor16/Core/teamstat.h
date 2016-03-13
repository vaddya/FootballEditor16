#ifndef TEAMSTAT_H
#define TEAMSTAT_H

#include "team.h"

class TeamStat : public Team
{
public:
    void setGoals(int gls);
    void setPossession(int psn);
    void setShots(int sts);
    void setShotOnTarget(int sot);
    void setYellowCards(int ycd);
    void setRedCards(int rcd);
    void setFouls(int fls);

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
