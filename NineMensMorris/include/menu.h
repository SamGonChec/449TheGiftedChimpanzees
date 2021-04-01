#ifndef MENU_H
#define MENU_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPushButton>
#include <QWidget>
#include <QGraphicsPixmapItem>
#include "include/game.h"

class Menu : public QObject{
    Q_OBJECT
private:
    QPushButton* twoPlayerButton;
    QPushButton* quitButton;
    QPushButton* computerButton;
    QPixmap menuBackground;
public:
    QGraphicsScene* scene;
    Menu(QGraphicsScene *scene);
    void mainMenuScreen();
    QPushButton *returnSinglePlayerPushButton() { return computerButton; }
    QPushButton *returnTwoPlayerPushButton() { return twoPlayerButton; }
    QPushButton *returnQuitButton() { return quitButton; }
protected:
     void mousePressEvent(QGraphicsSceneMouseEvent *event);

};

#endif // MENU_H
