#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <QPainter>
#include <QMainWindow>

class Board : public QWidget {

public:
    Board();
    virtual void paintEvent(QPaintEvent * event);
    void chooseLineColor(QPainter *painter, int millIndex);
    void updateMillLines(std::vector<int> &millVector);
private:
    std::vector<int> currentMills;
};
#endif // BOARD_H
