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
    groupstage.cpp \
    match.cpp \
    team.cpp \
    teamstat.cpp \
    group.cpp \
    playoffstage.cpp \
    teamingroup.cpp \
    idgenerator.cpp \
    randomiser.cpp \
    teaminplayoff.cpp \
    matchinplayoff.cpp \
    matchingroup.cpp

HEADERS += competition.h \
    groupstage.h \
    match.h \
    team.h \
    teamstat.h \
    group.h \
    playoffstage.h \
    stage.h \
    teamingroup.h \
    idgenerator.h \
    randomiser.h \
    teaminplayoff.h \
    matchinplayoff.h \
    matchingroup.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
