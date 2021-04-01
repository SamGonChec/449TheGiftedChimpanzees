#ifndef SINGLEPLAYERSCREEN_H
#define SINGLEPLAYERSCREEN_H

#include <QFile>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QPushButton>
#include <QGraphicsSceneMouseEvent>
#include <QWidget>
#include "include/game.h"

class SinglePlayerScreen: public QObject {
    Q_OBJECT
private:
    QPushButton *whiteButton;
    QPushButton *blackButton;
    QGraphicsScene *scene;
public:
    SinglePlayerScreen(QGraphicsScene *scene);

    QPushButton *returnWhiteButton() {return whiteButton;}
    QPushButton *returnBlackButton() {return blackButton;}
};

#endif // SINGLEPLAYERSCREEN_H
