#include "application.h"
#include "iostream"

Application::Application() {}

void Application::startNewCompetition()
{
    Competition comp;
    comp.startGroupStage();
    comp.startPlayOffStage();
    //TODO stat
}

