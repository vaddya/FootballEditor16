#include "team.h"

Team::Team(std::string tname, int tFifaPoints): name(tname), fifaPoints(tFifaPoints) {}

string Team::getName() { return name; }

int Team::getFifaPoints() const { return this->fifaPoints; }
