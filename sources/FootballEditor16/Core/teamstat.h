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

    void setGoals(int goals = 0) { goals_ = goals; }
    void setPossession(int possession = 0) { possession_ = possession; }
    void setShots(int shots = 0) { shots_ = shots; }
    void setShotOnTarget(int shotsOnTarget = 0) { shotsOnTarget_ = shotsOnTarget; }
    void setYellowCards(int yellowCards = 0) { yellowCards_ = yellowCards; }
    void setRedCards(int redCards = 0) { redCards_ = redCards; }
    void setFouls(int fouls = 0) { fouls_ = fouls; }

    int getGoals() const { return goals_; }
    int getPossession() const { return possession_; }
    int getShots() const { return shots_; }
    int getShotOnTarget() const { return shotsOnTarget_; }
    int getYellowCards() const { return yellowCards_; }
    int getRedCards() const { return redCards_; }
    int getFouls() const { return fouls_; }

private:
    int goals_;
    int possession_;
    int shots_;
    int shotsOnTarget_;
    int yellowCards_;
    int redCards_;
    int fouls_;
};

#endif // TEAMSTAT_H
