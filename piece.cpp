#include "piece.h"

Piece::Piece(int x, int y, bool white) {
    rectangle = QRectF(x, y, 30, 30);
    setAcceptHoverEvents(true);
    whitePiece = white;
    hover = false;
    inPlay = false;
    inSpace = nullptr;
    selectEnabled = false;
    selected = false;
    captureEnabled = false;
    captured = false;
}

void Piece::paint(QPainter *painter, const QStyleOptionGraphicsItem */*option*/, QWidget */*widget*/) {
/*Overloading function for appearance*/
    if (whitePiece) {
        painter->setBrush(Qt::white);
    } else {
        painter->setBrush(Qt::black);
    }
    if (selected) {
        painter->setBrush(Qt::green);
    }
    if ((hover && selectEnabled) || (hover && captureEnabled)) {
        painter->setPen(Qt::green);
    }
    painter->drawEllipse(rectangle);
}

void Piece::mousePressEvent(QGraphicsSceneMouseEvent */*event*/) {
/*Action taken when piece clicked*/
    if (captureEnabled) {
        emit clickCapture(this);
    } else if (selectEnabled) {
        emit clickSelect(this);
    }
}

void Piece::hoverEnterEvent(QGraphicsSceneHoverEvent */*event*/) {
/*Change appearance when mouse enters rect*/
    hover = true;
    update();
}

void Piece::hoverLeaveEvent(QGraphicsSceneHoverEvent */*event*/) {
/*Change appearance when mouse leaves rect*/
    hover = false;
    update();
}

void Piece::moved(Space *space) {
/*Slot to move piece when space clicked and signal turn taken*/
    if (inPlay) {
        inSpace->setOccupied(false);
    } else {
        inPlay = true;
    }
    inSpace = space;
    space->setOccupied(true);
    space->setWhite(whitePiece);
    setPos(space->boundingRect().x() / 2 - 2.5, space->boundingRect().y() / 2 - 2.5);
    this->rectangle = QRectF(space->boundingRect().x() / 2 - 2.5, space->boundingRect().y() / 2 - 2.5, 30, 30);
    update();
    emit turnTaken(this);
}
