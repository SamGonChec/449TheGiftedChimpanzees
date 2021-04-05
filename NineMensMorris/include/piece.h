#ifndef PIECE_H
#define PIECE_H

#include "include/space.h"

#include <QPropertyAnimation>

class Piece : public QWidget {
    Q_OBJECT
public:
    Piece(int x, int y, bool white = true);

    void paintEvent(QPaintEvent * event);
    Space *getSpace() { return inSpace; }

    void setSelectable(bool value) { selectEnabled = value; }
    void setSelected(bool value) { selected = value; }
    bool isSelected() { return selected; }
    void setCaptureEnabled(bool value) { captureEnabled = value; }
    void setCaptured(bool value) { captured = value; }
    bool isCaptured() { return captured; }
    bool isInPlay() { return inPlay; }

    void movePiece(Space *space);

    //Computer Player Functions
    void computerPlayerSelect() { emit clickSelect(this); }
    void computerPlayerCapture() { emit clickCapture(this); }

private:
    Space *inSpace;
    bool whitePiece;
    bool hover;
    bool inPlay;
    bool selectEnabled;
    bool selected;
    bool captureEnabled;
    bool captured;
    QPropertyAnimation *pieceAnimation;
protected:
    void mousePressEvent(QMouseEvent *event);
    void enterEvent(QEvent *event);
    void leaveEvent(QEvent *event);
signals:
    void clickCapture(Piece *piece);
    void clickSelect(Piece *piece);
    void turnTaken(Piece *piece);
private slots:
    void moved(Space *space);
};

#endif // PIECE_H
