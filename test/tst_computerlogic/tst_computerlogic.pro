QT += testlib
QT += gui core widgets
CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app

INCDIR = ../../NineMensMorris

INCLUDEPATH += $$INCDIR

SOURCES += \
    tst_computerlogic.cpp \
    $$INCDIR/src/game.cpp \
    $$INCDIR/src/singleplayergame.cpp \
    $$INCDIR/src/singleplayerscreen.cpp \
    $$INCDIR/src/board.cpp \
    $$INCDIR/src/piece.cpp \
    $$INCDIR/src/space.cpp \

HEADERS += \
    tst_computerlogic.h \
    $$INCDIR/include/game.h \
    $$INCDIR/include/singleplayergame.h \
    $$INCDIR/include/singleplayerscreen.h \
    $$INCDIR/include/board.h \
    $$INCDIR/include/piece.h \
    $$INCDIR/include/space.h \
