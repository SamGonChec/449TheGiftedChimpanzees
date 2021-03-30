#include "include/space.h"

Space::Space(int x, int y) {
    resize(21,21);
    move(x,y);
    setAttribute(Qt::WA_NoSystemBackground);
    hover = false;
    white = true;
    occupied = false;
    validMove = true;
}

void Space::paintEvent(QPaintEvent */*event*/) {
/*Overloading function to implement appearance*/
    QPainter painter(this);
    if (hover) {
        //Green fill if mouse hover and valid move
        if (validMove) {
            painter.setBrush(Qt::green);
        //Red fill if mouse hover and invalid move
        } else {
            painter.setBrush(Qt::red);
        }
    }
    painter.setPen(QPen(Qt::black,2));
    painter.drawEllipse(0,0,20,20);
}

void Space::mousePressEvent(QMouseEvent */*event*/) {
/*Signals mouse clicked on space if not occupied*/
    if (!occupied && validMove) {
        emit clicked(this);
    }
}

void Space::enterEvent(QEvent */*event*/) {
/*Changes appearance when mouse enters rect*/
    hover = true;
    update();
}

void Space::leaveEvent(QEvent */*event*/) {
/*Reverts appearance when mouse leaves rect*/
    hover = false;
    update();
}
