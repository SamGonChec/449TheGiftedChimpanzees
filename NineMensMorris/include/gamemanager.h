#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <QObject>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include "include/splash.h"
#include "include/menu.h"
#include "include/tutorial.h"
#include "include/game.h"
#include "include/singleplayergame.h"
#include "include/singleplayerscreen.h"

class GameManager : public QObject {
   Q_OBJECT
public:
    GameManager(bool wait = false);

    //Functions for testing
    bool testSplashSceneActive() { return view.scene() == &splashScene; }
    bool testMenuSceneActive() { return view.scene() == &menuScene; }
    bool testGameSceneActive() { return view.scene() == &gameScene; }
    bool testTutorialSceneActive() { return view.scene() == &tutorialScene; }
    bool testSinglePlayerSceneActive() { return view.scene() == &singlePlayerScene; }
    bool testQuit() {return menuScene.activeWindow() == nullptr; }
    Menu *returnMenu() { return menu; }
    QGraphicsScene *returnSinglePlayerScene() { return &singlePlayerScene; }
    QGraphicsScene *returnTwoPlayerScene() { return &gameScene; }
    void testSwitchBackToMainMenu(bool singlePlayerGame);

private:
    QGraphicsScene splashScene;
    QGraphicsScene menuScene;
    QGraphicsScene gameScene;
    QGraphicsScene tutorialScene;
    QGraphicsScene singlePlayerScene;
    QGraphicsView view;
    Menu *menu;

private slots:
    void switchTutorialScreen();
    void switchTwoPlayerMode();
    void timerComplete();
    void switchComputerPlayerModeWhite();
    void switchComputerPlayerModeBlack();
    void switchSinglePlayerScreen();
    void switchBackToMainMenu();
    void switchBackToMainMenuSinglePlayer();
    void switchBackToMainMenuTwoPlayer();
<<<<<<< HEAD
    void switchPlayAgainTwoPlayer();
=======
>>>>>>> master
};

#endif // GAMEMANAGER_H
