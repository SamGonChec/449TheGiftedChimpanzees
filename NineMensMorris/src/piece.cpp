#include "include/piece.h"

Piece::Piece(int x, int y, bool white) {
    resize(31,31);
    move(x, y);
    setAttribute(Qt::WA_NoSystemBackground);
    whitePiece = white;
    hover = false;
    inPlay = false;
    inSpace = nullptr;
    selectEnabled = false;
    selected = false;
    captureEnabled = false;
    captured = false;
}

void Piece::paintEvent(QPaintEvent */*event*/) {
/*Overloading function for appearance*/
    QPainter painter(this);
    //White fill for white piece
    if (whitePiece) {
        painter.setBrush(Qt::white);
    //Black fill for black piece
    } else {
        painter.setBrush(Qt::black);
    }
    //Green fill for selected piece
    if (selected) {
        painter.setBrush(Qt::green);
    }
    //Green outline on clickable pieces when the mouse hovers
    if ((hover && selectEnabled) || (hover && captureEnabled)) {
        painter.setPen(Qt::green);
    }
    painter.drawEllipse(0,0,30,30);
}

void Piece::mousePressEvent(QMouseEvent */*event*/) {
/*Action taken when piece clicked*/
    if (captureEnabled) {
        emit clickCapture(this);
    } else if (selectEnabled) {
        emit clickSelect(this);
    }
}

void Piece::hoverEnterEvent(QEvent */*event*/) {
/*Change appearance when mouse enters rect*/
    hover = true;
    update();
}

void Piece::hoverLeaveEvent(QEvent */*event*/) {
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
    move(space->x() - 5, space->y() - 5);
    update();
    emit turnTaken(this);
}
