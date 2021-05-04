#ifndef TUTORIAL_H
#define TUTORIAL_H

#include <QFile>
#include <QGraphicsScene>
#include <QPushButton>
#include "include/game.h"

class Tutorial : public QObject {
    Q_OBJECT
private:
    QPushButton* tutorialButton;
    QPushButton* singlePlayerButton;
    QPushButton* twoPlayerButton;
    QGraphicsScene* scene;
public:
    Tutorial(QGraphicsScene *scene);
    void tutorialScreen();
    QPushButton *returnPushButton() {return tutorialButton;}
    QPushButton *returnSinglePlayerButton() {return singlePlayerButton;}
    QPushButton *returnTwoPlayerButton() {return twoPlayerButton;}
};

#endif // TUTORIAL_H
