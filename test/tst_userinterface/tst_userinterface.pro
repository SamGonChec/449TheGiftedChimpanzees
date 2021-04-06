QT += testlib
QT += gui core widgets
CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app

INCDIR = ../../NineMensMorris

INCLUDEPATH += $$INCDIR

SOURCES += \
    tst_userinterface.cpp \
    $$INCDIR/src/game.cpp \
    $$INCDIR/src/gamemanager.cpp \
    $$INCDIR/src/singleplayergame.cpp \
    $$INCDIR/src/singleplayerscreen.cpp \
    $$INCDIR/src/menu.cpp \
    $$INCDIR/src/board.cpp \
    $$INCDIR/src/piece.cpp \
    $$INCDIR/src/space.cpp \
    $$INCDIR/src/splash.cpp \
    $$INCDIR/src/tutorial.cpp \

HEADERS += \
    tst_userinterface.h \
    $$INCDIR/include/game.h \
    $$INCDIR/include/gamemanager.h \
    $$INCDIR/include/singleplayergame.h \
    $$INCDIR/include/singleplayerscreen.h \
    $$INCDIR/include/menu.h \
    $$INCDIR/include/board.h \
    $$INCDIR/include/piece.h \
    $$INCDIR/include/space.h \
    $$INCDIR/include/splash.h \
    $$INCDIR/include/tutorial.h \

RESOURCES += \
    $$INCDIR/src/res.qrc
