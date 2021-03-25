QT += testlib
QT += gui core widgets
CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app

INCDIR = ../../NineMensMorris

INCLUDEPATH += $$INCDIR

SOURCES +=  tst_userinterface.cpp

HEADERS += \
    tst_userinterface.h
