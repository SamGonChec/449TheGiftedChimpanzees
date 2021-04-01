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
    QPushButton* whiteButton;
    QPushButton* blackButton;
    bool againstComputer;
public:
    QString tutorialText;
    QGraphicsScene* scene;
    Tutorial(QGraphicsScene *scene, bool computer);
    void getTutorialText();
    void tutorialScreen();
    QPushButton *returnPushButton() {return tutorialButton;}
    QPushButton *returnWhiteButton() {return whiteButton;}
    QPushButton *returnBlackButton() {return blackButton;}
protected:
     void mousePressEvent(QGraphicsSceneMouseEvent *event);

};

#endif // TUTORIAL_H
