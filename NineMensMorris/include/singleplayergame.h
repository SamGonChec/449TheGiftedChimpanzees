#ifndef SINGLEPLAYERGAME_H
#define SINGLEPLAYERGAME_H

#include "include/game.h"
#include <stdlib.h>
#include <time.h>

class SinglePlayerGame : Game {
public:
    SinglePlayerGame(QGraphicsScene *scene, bool computerIsWhite);
    std::vector<int> possibleBlock;
    std::vector<int> possibleMill;
    void scanSpaces();
    void computerPhaseOneMove();
    void computerPhaseTwoMove();
    void computerFlyingMove();
    void computerCapture();
    void priorityScan();
    void adjacentPopulation(std::vector<int> piecesIndices, std::vector<std::vector<int>> &adjacentSpaces);
    void computerIntersectionFind(std::vector<std::vector<int>> &adjacentSpaces, std::vector<int> piecesIndices);
    void enableSelectPiece();
    void enableCapturePiece();

    void startNewTurn();
    QPushButton *returnMainMenu() {return menuButton;}
private:
    bool computerColorWhite;
    std::vector<int> availableSpaces;
    std::vector<int> availableSelect;
    std::vector<int> availableCapture;
    std::vector<std::vector<int>> priorityList;
private slots:
    void nextTurn(Piece *piece);
};



#endif // SINGLEPLAYERGAME_H
