#-------------------------------------------------
#
# Project created by QtCreator 2016-05-15T15:47:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GUIApp
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    exitdialog.cpp

HEADERS  += mainwindow.h \
    exitdialog.h

FORMS    += mainwindow.ui \
    exitdialog.ui

RESOURCES += \
    Resources/resources.qrc
