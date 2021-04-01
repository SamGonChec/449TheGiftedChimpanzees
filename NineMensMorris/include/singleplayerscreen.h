#ifndef SINGLEPLAYERSCREEN_H
#define SINGLEPLAYERSCREEN_H

#include <QFile>
#include <QApplication>
#include <QGraphicsScene>
#include <QPushButton>
#include "include/game.h"

class SinglePlayerScreen{
private:
    QPushButton *whiteButton;
    QPushButton *blackButton;
public:
    QString tutorialText;
    QGraphicsScene *scene;
    SinglePlayerScreen(QGraphicsScene *scene);
    void displaySinglePlayerScreen();
    QPushButton *returnWhiteButton() {return whiteButton;}
    QPushButton *returnBlackButton() {return blackButton;}
};

#endif // SINGLEPLAYERSCREEN_H
