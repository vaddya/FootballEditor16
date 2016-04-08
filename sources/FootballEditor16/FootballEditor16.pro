TEMPLATE = subdirs

CONFIG += c++11
CONFIG += c++11

ConsoleApp.depends = Core
Test.depends = Core

SUBDIRS += \
    Core \
    ConsoleApp \
    Test
