#include "board.h"
#include "piece.h"
#include "space.h"
#include "game.h"

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsEllipseItem>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QGraphicsScene scene;
    QGraphicsView view;
    Game g(&scene);

    //Adjusting the view, setting the scene
    view.resize(800,800);
    view.setScene(&scene);
    view.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    view.show();
    return a.exec();
}
