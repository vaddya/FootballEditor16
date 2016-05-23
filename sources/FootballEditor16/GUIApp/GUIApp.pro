#-------------------------------------------------
#
# Project created by QtCreator 2016-05-15T15:47:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GUIApp
TEMPLATE = app
CONFIG += console c++11

SOURCES += main.cpp\
    mainmenu.cpp \
    exitdialog.cpp \
    createcompdialog.cpp \
    warningdialog.cpp \
    teamcheckboxes.cpp \
    eurogroupswindow.cpp \
    worldcupgroupswindow.cpp \
    europlayoffwindow.cpp

HEADERS  += mainmenu.h \
    exitdialog.h \
    createcompdialog.h \
    warningdialog.h \
    teamcheckboxes.h \
    eurogroupswindow.h \
    worldcupgroupswindow.h \
    europlayoffwindow.h

FORMS    += mainmenu.ui \
    exitdialog.ui \
    createcompdialog.ui \
    warningdialog.ui \
    worldcupgroupswindow.ui \
    eurogroupswindow.ui \
    europlayoffwindow.ui

RESOURCES += \
    Resources/resources.qrc

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Core/release/ -lCore
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Core/debug/ -lCore
else:unix: LIBS += -L$$OUT_PWD/../Core/ -lCore

INCLUDEPATH += $$PWD/../Core
DEPENDPATH += $$PWD/../Core

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Core/release/libCore.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Core/debug/libCore.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Core/release/Core.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Core/debug/Core.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../Core/libCore.a
