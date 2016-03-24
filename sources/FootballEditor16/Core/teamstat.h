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

    void setGoals(int mgoals = 0) { goals = mgoals; }
    void setPossession(int mpossession = 0) { possession = mpossession; }
    void setShots(int mshots = 0) { shots = mshots; }
    void setShotOnTarget(int mshotsOnTarget = 0) { shotsOnTarget = mshotsOnTarget; }
    void setYellowCards(int myellowCards = 0) { yellowCards = myellowCards; }
    void setRedCards(int mredCards = 0) { redCards = mredCards; }
    void setFouls(int mfouls = 0) { fouls = mfouls; }

    int getGoals() const { return goals; }
    int getPossession() const { return possession; }
    int getShots() const { return shots; }
    int getShotOnTarget() const { return shotsOnTarget; }
    int getYellowCards() const { return yellowCards; }
    int getRedCards() const { return redCards; }
    int getFouls() const { return fouls; }

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
