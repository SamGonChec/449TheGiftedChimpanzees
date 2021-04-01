#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <QObject>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "include/menu.h"
#include "include/tutorial.h"
#include "include/game.h"
#include "include/singleplayergame.h"
#include "include/singleplayerscreen.h"

class GameManager : public QObject {
   Q_OBJECT
public:
    QGraphicsScene menuScene;
    QGraphicsScene gameScene;
    QGraphicsScene tutorialScene;
    QGraphicsScene singlePlayerScene;
    QGraphicsView view;
    Game *game;
    SinglePlayerGame *computerGame;
    GameManager();
private slots:
    void switchTutorialScreen();
    void switchTwoPlayerMode();
    void switchComputerPlayerModeWhite();
    void switchComputerPlayerModeBlack();
    void switchSinglePlayerScreen();
    void switchBackToMainMenu();
    void switchBackToMainMenuSinglePlayer();
    void switchBackToMainMenuTwoPlayer();
};

#endif // GAMEMANAGER_H
