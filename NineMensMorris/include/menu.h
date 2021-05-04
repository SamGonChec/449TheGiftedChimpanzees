#ifndef MENU_H
#define MENU_H

#include <QGraphicsScene>
#include <QPushButton>
#include <QWidget>
#include <QGraphicsPixmapItem>
#include "include/game.h"

class Menu : public QObject {
    Q_OBJECT
private:
    QGraphicsScene *scene;
    QPushButton *twoPlayerButton;
    QPushButton *quitButton;
    QPushButton *computerButton;
    QPushButton *tutorialButton;
    QPixmap menuBackground;
public:
    Menu(QGraphicsScene *scene);
    void mainMenuScreen();
    QPushButton *returnSinglePlayerPushButton() { return computerButton; }
    QPushButton *returnTwoPlayerPushButton() { return twoPlayerButton; }
    QPushButton *returnQuitButton() { return quitButton; }
    QPushButton *returnTutorialPushButton() { return tutorialButton; }

};

#endif // MENU_H
