#-------------------------------------------------
#
# Project created by QtCreator 2016-03-16T00:58:02
#
#-------------------------------------------------

QT       -= core gui

TARGET = Core
TEMPLATE = lib
CONFIG += staticlib

SOURCES += competition.cpp \
    groupstage.cpp \
    match.cpp \
    team.cpp \
    teamstat.cpp

HEADERS += competition.h \
    groupstage.h \
    match.h \
    team.h \
    teamstat.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
