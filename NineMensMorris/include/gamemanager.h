#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "include/menu.h"
#include "include/tutorial.h"
#include "include/game.h"

class GameManager : public QObject
{
   Q_OBJECT
public:
    QGraphicsScene menuScene;
    QGraphicsScene gameScene;
    QGraphicsScene tutorialScene;
    QGraphicsView view;
    Game* game;
    GameManager();
private slots:
    void switchTutorialScreen();
    void switchTwoPlayerMode();

};

#endif // GAMEMANAGER_H
