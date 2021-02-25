#ifndef SPACE_H
#define SPACE_H

#include <QGraphicsItem>
#include <QPainter>

class Space : public QObject, public QGraphicsItem {
    Q_OBJECT
public:
    Space(int x, int y);
    QRectF boundingRect() const { return rectangle; }
    void paint(QPainter * painter, const QStyleOptionGraphicsItem *option = 0, QWidget *widget = 0);

    bool isOccupied() { return occupied; }
    void setOccupied(bool value) { occupied = value; }
    void setWhite(bool value) { white = value; }
    void setValid(bool value) { validMove = value; }

    bool hasWhitePiece() { return (occupied && white); }
    bool hasBlackPiece() { return (occupied && !white); }
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
private:
    bool hover;
    bool occupied;
    bool white;
    bool validMove;
    QRectF rectangle;
signals:
    void clicked(Space * space);
};

#endif // SPACE_H
