#ifndef SINGLEPLAYERGAME_H
#define SINGLEPLAYERGAME_H

#include "include/game.h"
#include <stdlib.h>
#include <time.h>

class SinglePlayerGame : Game {
public:
    SinglePlayerGame(QGraphicsScene *scene, bool computerIsWhite);
    void scanSpaces();
    void computerPhaseOneMove();
    void computerPhaseTwoMove();
    void computerFlyingMove();
    void computerCapture();
    void priorityScan();
    void priorityScanPhaseTwo();
    void getAvailablePieceIndices();
    void enableSelectPiece();
    void enableCapturePiece();
    void pieceToMoveForMill();
    void priorityScanPopulation(std::vector<int> possiblePriorityMoves, bool isPossibleMills);
    void startNewTurn();
    QPushButton *returnMainMenu() {return menuButton;}
    QPushButton *returnForfeitButton() {return forfeitButton;}
private:
    bool computerColorWhite;
    std::vector<int> possibleBlock;
    std::vector<int> possibleMill;
    std::vector<int> availableSpaces;
    std::vector<int> availableSelect;
    std::vector<int> availableCapture;
    std::vector<int> availableSelectIndices;
    std::vector<std::vector<int>> priorityList;
private slots:
    void nextTurn(Piece *piece);
};



#endif // SINGLEPLAYERGAME_H
