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

    void enableSelectPiece();
    void enableCapturePiece();
    void checkForNewMill();

    void startNewTurn();
    QPushButton *returnMainMenu() {return menuButton;}
private:
    bool computerColorWhite;
    std::vector<int> availableSpaces;
    std::vector<int> availableSelect;
    std::vector<int> availableCapture;
};



#endif // SINGLEPLAYERGAME_H
