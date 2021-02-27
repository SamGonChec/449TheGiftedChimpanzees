#include "include/board.h"


Board::Board() {
    resize(800,800);
}

void Board::paintEvent(QPaintEvent */*event*/) {
/*Overloading virtual function to implement board appearance*/
    QPainter painter(this);

    painter.setBrush(QColor(200,200,115));
    painter.drawRect(QRect(50, 0, 700, 700));
    //Outer square
    chooseLineColor(&painter, 0);
    painter.drawLine(100,650,100,50);
    chooseLineColor(&painter, 1);
    painter.drawLine(100,50,700,50);
    chooseLineColor(&painter, 2);
    painter.drawLine(700,50,700,650);
    chooseLineColor(&painter, 3);
    painter.drawLine(700,650,100,650);
    //Middle square
    chooseLineColor(&painter, 4);
    painter.drawLine(200,550,200,150);
    chooseLineColor(&painter, 5);
    painter.drawLine(200,150,600,150);
    chooseLineColor(&painter, 6);
    painter.drawLine(600,150,600,550);
    chooseLineColor(&painter, 7);
    painter.drawLine(600,550,200,550);
    //Inner square
    chooseLineColor(&painter, 8);
    painter.drawLine(300,450,300,250);
    chooseLineColor(&painter, 9);
    painter.drawLine(300,250,500,250);
    chooseLineColor(&painter, 10);
    painter.drawLine(500,250,500,450);
    chooseLineColor(&painter, 11);
    painter.drawLine(500,450,300,450);
    //Crossing lines
    chooseLineColor(&painter, 12);
    painter.drawLine(100,350,300,350);
    chooseLineColor(&painter, 13);
    painter.drawLine(400,50,400,250);
    chooseLineColor(&painter, 14);
    painter.drawLine(500,350,700,350);
    chooseLineColor(&painter, 15);
    painter.drawLine(400,450,400,650);

}

void Board::chooseLineColor(QPainter *painter, int millIndex) {
    unsigned int i;
    painter->setPen(Qt::black);
    for (i = 0; i < currentMills.size(); i++) {
        if (currentMills[i] == millIndex) {
            painter->setPen(Qt::blue);
        }
    }

}

void Board::updateMillLines(std::vector<int> &millVector) {
    currentMills = millVector;
    update();
}



