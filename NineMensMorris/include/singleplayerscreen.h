#ifndef SINGLEPLAYERSCREEN_H
#define SINGLEPLAYERSCREEN_H

#include <QGraphicsScene>
#include <QPushButton>
#include "include/game.h"

class SinglePlayerScreen{
private:
    QPushButton *whiteButton;
    QPushButton *blackButton;
    QGraphicsScene *scene;
public:
    SinglePlayerScreen(QGraphicsScene *scene);
    void displaySinglePlayerScreen();
    QPushButton *returnWhiteButton() {return whiteButton;}
    QPushButton *returnBlackButton() {return blackButton;}
};

#endif // SINGLEPLAYERSCREEN_H
