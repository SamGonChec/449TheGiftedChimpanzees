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
    QGraphicsScene splashScene;
    QGraphicsScene menuScene;
    QGraphicsScene gameScene;
    QGraphicsScene tutorialScene;
    QGraphicsScene singlePlayerScene;
    QGraphicsView view;
    Game *game;
    SinglePlayerGame *computerGame;
    GameManager();

    bool testSplashSceneActive() { return view.scene() == &splashScene; }
    bool testMenuSceneActive() { return view.scene() == &menuScene; }

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
    void switchPlayAgainTwoPlayer();
    void switchPlayAgainSinglePlayer();
};

#endif // GAMEMANAGER_H
