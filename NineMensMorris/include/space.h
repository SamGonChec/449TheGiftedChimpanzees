#ifndef SPACE_H
#define SPACE_H

#include <QWidget>
#include <QPainter>

class Space : public QWidget {
    Q_OBJECT
public:
    Space(int x, int y);
    //void paint(QPainter * painter, const QStyleOptionGraphicsItem *option = 0, QWidget *widget = 0);
    void paintEvent(QPaintEvent * event);

    bool isOccupied() { return occupied; }
    void setOccupied(bool value) { occupied = value; }
    void setWhite(bool value) { white = value; }
    void setValid(bool value) { validMove = value; }

    bool hasWhitePiece() { return (occupied && white); }
    bool hasBlackPiece() { return (occupied && !white); }
protected:
    void mousePressEvent(QMouseEvent *event);
    void enterEvent(QEvent *event);
    void leaveEvent(QEvent *event);
private:
    bool hover;
    bool occupied;
    bool white;
    bool validMove;
signals:
    void clicked(Space *space);
};

#endif // SPACE_H
