#include "team.h"

Team::Team(const Team &team): name(team.getName()), fifaPoints(team.getFifaPoints()) {}

Team::Team(std::string tname, int tFifaPoints): name(tname), fifaPoints(tFifaPoints) {}

string Team::getName() const { return name; }

int Team::getFifaPoints() const { return fifaPoints; }
