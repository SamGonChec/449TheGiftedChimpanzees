#ifndef TST_USERINTERFACE_H
#define TST_USERINTERFACE_H
#include <QtTest>
#include <QTest>
#include <QCoreApplication>

#include "include/menu.h"
#include "include/singleplayergame.h"
#include "include/gamemanager.h"

class UserInterface : public QObject
{
    Q_OBJECT

public:
    UserInterface() {}
    ~UserInterface() {}

private slots:
    //AC 8.1
    void testMainMenuAndSplashScene();

    void testOnePlayerScreen();
    void testTwoPlayerScreen();

    //AC 8.3
    void testTutorialScreen();

    void testQuitButton();
    void testOnePlayerMainMenuButton();
    void testTwoPlayerMainMenuButton();
};
#endif // TST_USERINTERFACE_H
