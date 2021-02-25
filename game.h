#ifndef GAME_H
#define GAME_H

#include "space.h"
#include "piece.h"
#include "board.h"

#include <vector>
#include <QObject>
#include <QGraphicsScene>

class Game : public QObject {
    Q_OBJECT
public:
    Game(QGraphicsScene * scene);

    int getSpaceIndex(Space *space);
    void setAdjacentSpaces(Piece *piece, bool value);
    void setAllSpaceValidity(bool value);
    bool pieceInMill(Piece *piece);

    void checkForNewMill();
    void checkForFlying();
    void checkForPieceVictory();
    void checkForMovesVictory();
    void evaluateVictoryConditions();

    void selectPiece(Piece *piece);
    void deselectPiece(Piece *piece);
    void enableSelectPiece();
    void disableSelectPiece();
    void enableCapturePiece();
    void disableCapturePiece();

    void endTurn(Piece *piece);
    void startNewTurn();

private:
    QGraphicsScene *scene;
    Board *board;
    bool whiteTurn;
    int turnNumber;

    bool phaseOneComplete;
    bool captureMode;
    bool whiteFlying;
    bool whiteVictory;
    bool blackFlying;
    bool blackVictory;

    std::vector<std::vector<int>> adjacentList;
    std::vector<std::vector<int>> millList;
    std::vector<int> currentMills;
    std::vector<Space*> spaceList;
    std::vector<Piece*> whitePieces;
    std::vector<Piece*> blackPieces;

signals:

private slots:
    void pieceCaptureAction(Piece *piece);
    void pieceSelectAction(Piece *piece);
    void nextTurn(Piece *piece);

};

#endif // GAME_H
