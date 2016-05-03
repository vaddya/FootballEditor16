#-------------------------------------------------
#
# Project created by QtCreator 2016-03-16T00:58:02
#
#-------------------------------------------------

QT       -= core gui

TARGET = Core
TEMPLATE = lib
CONFIG += console c++11
CONFIG += staticlib

SOURCES += competition.cpp \
    match.cpp \
    team.cpp \
    teamstat.cpp \
    idgenerator.cpp \
    randomiser.cpp \
    GroupStage/groupstage.cpp \
    GroupStage/group.cpp \
    GroupStage/teamingroup.cpp \
    GroupStage/matchingroup.cpp \
    PlayoffStage/playoffstage.cpp \
    PlayoffStage/teaminplayoff.cpp \
    PlayoffStage/matchinplayoff.cpp

HEADERS += competition.h \
    match.h \
    team.h \
    teamstat.h \
    stage.h \
    idgenerator.h \
    randomiser.h \
    GroupStage/groupstage.h \
    GroupStage/group.h \
    GroupStage/teamingroup.h \
    GroupStage/matchingroup.h \
    PlayoffStage/playoffstage.h \
    PlayoffStage/teaminplayoff.h \
    PlayoffStage/matchinplayoff.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
