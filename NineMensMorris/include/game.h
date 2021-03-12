#ifndef GAME_H
#define GAME_H

#include "space.h"
#include "piece.h"
#include "board.h"

#include <vector>
#include <QObject>
#include <QGraphicsScene>
#include <QtWidgets/QGraphicsProxyWidget>


class Game : public QObject {
    Q_OBJECT
public:
    Game(QGraphicsScene * scene);
    ~Game();

    void pieceCleanup(std::vector<Piece*> &pieces);
    void boardCleanup(QGraphicsProxyWidget* proxyBoard);
    void spaceCleanup(std::vector<Space*> &spaces);

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

    //Functions for testing
    Space *getSpace(int spaceIndex) { return spaceList[spaceIndex]; }
    Piece *getWhitePiece(int pieceIndex) { return whitePieces[pieceIndex]; }
    Piece *getBlackPiece(int pieceIndex) { return blackPieces[pieceIndex]; }

    bool testWhiteTurn() { return whiteTurn; }
    bool testWhiteFlying() { return whiteFlying; }
    bool testBlackFlying() { return blackFlying; }
    bool testWhiteVictory() { return whiteVictory; }
    bool testBlackVictory() { return blackVictory; }
    void endPhaseOne();

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
