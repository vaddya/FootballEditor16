#include "team.h"

Team::Team(string tname, int tFifaPoints): name(tname), fifaPoints(tFifaPoints) {}

string & Team::getName() { return name; }

int Team::getFifaPoints() const { return fifaPoints; }
