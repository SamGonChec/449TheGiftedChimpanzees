#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include "include/splash.h"
#include "include/menu.h"
#include "include/tutorial.h"
#include "include/game.h"
#include "include/singleplayergame.h"

class GameManager : public QObject
{
   Q_OBJECT
public:
    QGraphicsScene splashScene;
    QGraphicsScene menuScene;
    QGraphicsScene gameScene;
    QGraphicsScene tutorialScene;
    QGraphicsView view;
    Game *game;
    SinglePlayerGame *computerGame;
    GameManager();
private slots:
    void switchTutorialScreen();
    void switchTwoPlayerMode();
    void switchComputerPlayerMode();
    void timerComplete();
};

#endif // GAMEMANAGER_H
