#ifndef GAME_H
#define GAME_H

#include "include/space.h"
#include "include/piece.h"
#include "include/board.h"

#include <vector>
#include <QObject>
#include <QGraphicsScene>
#include <QLabel>
#include <QString>
#include <QFont>
#include <QPushButton>
#include <QtWidgets/QGraphicsProxyWidget>


class Game : public QObject {
    Q_OBJECT
public:
    Game(QGraphicsScene * scene);
    ~Game();
    void pieceCleanup(std::vector<Piece*> &pieces);
    void boardCleanup(QGraphicsProxyWidget* proxyBoard);
    void spaceCleanup(std::vector<Space*> &spaces);
    void textItemCleanup();

    int getSpaceIndex(Space *space);
    void setAdjacentSpaces(Piece *piece, bool value);
    void setAllSpaceValidity(bool value);
    bool pieceInMill(Piece *piece);

    void setTurnCountText(int turn);
    void setPlayerTurnText(bool whitePiece);
    void setInstructionText(int turnNumber, bool captureMode = false);

    void checkForNewMill();
    void checkForFlying();
    void checkForPieceVictory();
    void checkForMovesVictory();
    void evaluateVictoryConditions();

    void selectPiece(Piece *piece);
    void deselectPiece(Piece *piece);
    virtual void enableSelectPiece();
    void disableSelectPiece();
    virtual void enableCapturePiece();
    void disableCapturePiece();

    void endTurn(Piece *piece);
    virtual void startNewTurn();


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

    QString testTurnText() { return turnText->toPlainText(); }
    QString testWhitePieceText() { return whitePieceText->toPlainText(); }
    QString testBlackPieceText() { return blackPieceText->toPlainText(); }
    QString testInstructionText() { return instructionText->toPlainText(); }

    QPushButton *returnMainMenu() {return menuButton;}
    QPushButton *returnForfeitButton() {return forfeitButton;}
    QPushButton *returnPlayAgainButton() {return playAgainButton;}
protected:
    QPushButton *menuButton;
    QPushButton *forfeitButton;
    QPushButton *playAgainButton;
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

    QGraphicsTextItem *titleText;
    QGraphicsTextItem *turnText;
    QGraphicsTextItem *whitePieceText;
    QGraphicsTextItem *blackPieceText;
    QGraphicsTextItem *instructionText;

private slots:
    void pieceCaptureAction(Piece *piece);
    void pieceSelectAction(Piece *piece);
    virtual void nextTurn(Piece *piece);
    void forfeit();
};

#endif // GAME_H
