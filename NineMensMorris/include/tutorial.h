#ifndef TUTORIAL_H
#define TUTORIAL_H

#include <QFile>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QPushButton>
#include <QGraphicsSceneMouseEvent>
#include <QWidget>
#include "include/game.h"

class Tutorial : public QObject{
    Q_OBJECT
private:
    QPushButton* tutorialButton;
    QPushButton* singlePlayerButton;
    QPushButton* twoPlayerButton;
public:
    QString tutorialText;
    QGraphicsScene* scene;
    Tutorial(QGraphicsScene *scene);
    void tutorialScreen();
    QPushButton *returnPushButton() {return tutorialButton;}
    QPushButton *returnSinglePlayerButton() {return singlePlayerButton;}
    QPushButton *returnTwoPlayerButton() {return twoPlayerButton;}
};

#endif // TUTORIAL_H
