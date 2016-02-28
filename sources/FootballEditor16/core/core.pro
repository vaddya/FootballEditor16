#-------------------------------------------------
#
# Project created by QtCreator 2016-02-28T12:42:13
#
#-------------------------------------------------

QT       -= core gui

TARGET = core
TEMPLATE = lib
CONFIG += staticlib

SOURCES += core.cpp

HEADERS += core.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
