#include "include/board.h"
#include "include/piece.h"
#include "include/space.h"
#include "include/game.h"
#include "include/gamemanager.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsEllipseItem>

int main(int argc, char *argv[]) {
    QApplication application(argc, argv);

    /* calling the class in charge of the menu and changing scenes*/
    GameManager manager;

    return application.exec();
}
