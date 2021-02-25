#ifndef PIECE_H
#define PIECE_H

#include "space.h"

#include <QGraphicsItem>
#include <QPainter>
#include <QPaintEvent>

class Piece : public QObject, public QGraphicsItem {
    Q_OBJECT
public:
    Piece(int x, int y, bool white = true);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option = 0, QWidget *widget = 0);
    QRectF boundingRect() const { return rectangle; }
    Space *getSpace() { return inSpace; }

    void setSelectable(bool value) { selectEnabled = value; }
    void setSelected(bool value) { selected = value; }
    bool isSelected() { return selected; }
    void setCaptureEnabled(bool value) { captureEnabled = value; }
    void setCaptured(bool value) { captured = value; }
    bool isCaptured() { return captured; }
    bool isInPlay() { return inPlay; }

private:
    QRectF rectangle;
    Space *inSpace;
    bool whitePiece;
    bool hover;
    bool inPlay;
    bool selectEnabled;
    bool selected;
    bool captureEnabled;
    bool captured;
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
signals:
    void clickCapture(Piece *piece);
    void clickSelect(Piece *piece);
    void turnTaken(Piece *piece);
private slots:
    void moved(Space *space);
};

#endif // PIECE_H
