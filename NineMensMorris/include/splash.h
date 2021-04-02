#ifndef SPLASH_H
#define SPLASH_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include "include/game.h"

class Splash: public QObject{
    Q_OBJECT
private:
    QPixmap splashBackground;
public:
    QGraphicsScene* scene;
    Splash(QGraphicsScene *scene);
    void splashScreen();
};

#endif // SPLASH_H
