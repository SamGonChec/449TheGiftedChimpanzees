QT += core gui
QT += multimedia
QT += multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/board.cpp \
    src/game.cpp \
    src/gamemanager.cpp \
    src/main.cpp \
    src/menu.cpp \
    src/piece.cpp \
    src/singleplayergame.cpp \
    src/singleplayerscreen.cpp \
    src/space.cpp \
    src/splash.cpp \
    src/tutorial.cpp

HEADERS += \
    include/board.h \
    include/game.h \
    include/gamemanager.h \
    include/menu.h \
    include/piece.h \
    include/singleplayergame.h \
    include/singleplayerscreen.h \
    include/space.h \
    include/splash.h \
    include/tutorial.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    src/res.qrc
