#include "include/game.h"

Game::Game(QGraphicsScene *scene) {
    //Initializing data members
    whiteTurn = true;
    turnNumber = 0;
    phaseOneComplete = false;
    captureMode = false;
    whiteFlying = false;
    whiteVictory = false;
    blackFlying = false;
    blackVictory = false;
    unsigned int i;
    currentMills = {};
    this->scene = scene;

    //Vector with indices of adjacent spaces
    adjacentList = { {1,9}, {0,2,4}, {1,14}, {4,10}, {1,3,5,7}, {4,13},
                     {7,11}, {4,6,8}, {7,12}, {0,10,21}, {3,9,11,18}, {6,10,15},
                     {8,13,17}, {5,12,14,20}, {2,13,23}, {11,16}, {15,17,19}, {12,16},
                     {10,19}, {16,18,20,22}, {13,19}, {9,22}, {19,21,23}, {14,22} };

    //Vector with indices of spaces that form a mill
    millList = { {0,1,2}, {2,14,23}, {21,22,23}, {0,9,21},
                 {3,4,5}, {5,13,20}, {18,19,20}, {3,10,18},
                 {6,7,8}, {8,12,17}, {15,16,17}, {6,11,15},
                 {1,4,7}, {12,13,14}, {16,19,22}, {9,10,11} };

    //Adding board widget to scene
    board = new Board;
    scene->addWidget(board);

    //Adding spaces
    spaceList.push_back(new Space(90,640));  //Space A1
    spaceList.push_back(new Space(90,340));  //Space A4
    spaceList.push_back(new Space(90,40));   //Space A7
    spaceList.push_back(new Space(190,540)); //Space B2
    spaceList.push_back(new Space(190,340)); //Space B4
    spaceList.push_back(new Space(190,140)); //Space B6
    spaceList.push_back(new Space(290,440)); //Space C3
    spaceList.push_back(new Space(290,340)); //Space C4
    spaceList.push_back(new Space(290,240)); //Space C5
    spaceList.push_back(new Space(390,640)); //Space D1
    spaceList.push_back(new Space(390,540)); //Space D2
    spaceList.push_back(new Space(390,440)); //Space D3
    spaceList.push_back(new Space(390,240)); //Space D5
    spaceList.push_back(new Space(390,140)); //Space D6
    spaceList.push_back(new Space(390,40));  //Space D7
    spaceList.push_back(new Space(490,440)); //Space E3
    spaceList.push_back(new Space(490,340)); //Space E4
    spaceList.push_back(new Space(490,240)); //Space E5
    spaceList.push_back(new Space(590,540)); //Space F2
    spaceList.push_back(new Space(590,340)); //Space F4
    spaceList.push_back(new Space(590,140)); //Space F6
    spaceList.push_back(new Space(690,640)); //Space G1
    spaceList.push_back(new Space(690,340)); //Space G4
    spaceList.push_back(new Space(690,40));  //Space G7

    for (i = 0; i < spaceList.size(); i++) {
        spaceList[i]->setZValue(90);
        scene->addItem(spaceList[i]);
    }

    //Adding white pieces
    whitePieces.push_back(new Piece(100, 720));
    whitePieces.push_back(new Piece(150, 720));
    whitePieces.push_back(new Piece(200, 720));
    whitePieces.push_back(new Piece(250, 720));
    whitePieces.push_back(new Piece(300, 720));
    whitePieces.push_back(new Piece(125, 760));
    whitePieces.push_back(new Piece(175, 760));
    whitePieces.push_back(new Piece(225, 760));
    whitePieces.push_back(new Piece(275, 760));
    for (i = 0; i < whitePieces.size(); i++) {
        whitePieces[i]->setZValue(100);
        scene->addItem(whitePieces[i]);
    }

    //Adding black pieces
    blackPieces.push_back(new Piece(475, 720, false));
    blackPieces.push_back(new Piece(525, 720, false));
    blackPieces.push_back(new Piece(575, 720, false));
    blackPieces.push_back(new Piece(625, 720, false));
    blackPieces.push_back(new Piece(675, 720, false));
    blackPieces.push_back(new Piece(500, 760, false));
    blackPieces.push_back(new Piece(550, 760, false));
    blackPieces.push_back(new Piece(600, 760, false));
    blackPieces.push_back(new Piece(650, 760, false));
    for (i = 0; i < blackPieces.size(); i++) {
        blackPieces[i]->setZValue(100);
        scene->addItem(blackPieces[i]);
    }

    //Selecting first piece
    selectPiece(whitePieces[0]);

}

int Game::getSpaceIndex(Space *space) {
/*Returns index of given space in list of spaces*/
    unsigned int i;
    for (i = 0; i < spaceList.size(); i++) {
        if (spaceList[i] == space) {
            return i;
        }
    }
    return -1;
}

void Game::setAdjacentSpaces(Piece *piece, bool value) {
/*Sets adjacent spaces to piece as valid or invalid move*/
    unsigned int i;
    int index = getSpaceIndex(piece->getSpace());
    for (i = 0; i < adjacentList[index].size(); i++) {
        spaceList[adjacentList[index][i]]->setValid(value);
    }
}

void Game::setAllSpaceValidity(bool value) {
/*Sets all spaces as valid or invalid move*/
    unsigned int i;
    for (i = 0; i < spaceList.size(); i++) {
        spaceList[i]->setValid(value);
    }
}

bool Game::pieceInMill(Piece *piece) {
/*Returns whether piece passed is in a mill*/
    unsigned int i;
    int index = getSpaceIndex(piece->getSpace());
    for (i = 0; i < currentMills.size(); i++) {
        if (millList[currentMills[i]][0] == index || millList[currentMills[i]][1] == index || millList[currentMills[i]][2] == index) {
            return true;
        }
    }
    return false;
}

void Game::checkForNewMill() {
/*Updates list of mills and sets capture mode if new mill found*/
    unsigned int i;
    std::vector<int> newMills;
    for (i = 0; i < millList.size(); i++) { // Iterate through sets of spaces that form mills and check if occupied by all white or black pieces
        if (spaceList[millList[i][0]]->hasWhitePiece() && spaceList[millList[i][1]]->hasWhitePiece() && spaceList[millList[i][2]]->hasWhitePiece()) {
            newMills.push_back(i);
        } else if (spaceList[millList[i][0]]->hasBlackPiece() && spaceList[millList[i][1]]->hasBlackPiece() && spaceList[millList[i][2]]->hasBlackPiece()) {
            newMills.push_back(i);
        }
    }
    if (newMills != currentMills && newMills.size() >= currentMills.size()) {
        enableCapturePiece();
    }
    currentMills = newMills;
    board->updateMillLines(currentMills);
}

void Game::checkForFlying() {
/*Checks number of pieces in play and sets flying condition*/
    int count = 0;
    unsigned int i;
    if (whiteTurn) {
        for (i = 0; i < blackPieces.size(); i++) {
            if (!blackPieces[i]->isCaptured()) {
                count++;
            }
        }
        if (count == 3) {
            blackFlying = true;
        }
    } else {
        for (i = 0; i < whitePieces.size(); i++) {
            if (!whitePieces[i]->isCaptured()) {
                count++;
            }
        }
        if (count == 3) {
            whiteFlying = true;
        }
    }
}

void Game::checkForPieceVictory() {
/*Checks if opponent has less than three pieces*/
    int count = 0;
    unsigned int i;
    if (whiteTurn) {
        for (i = 0; i < blackPieces.size(); i++) {
            if (!blackPieces[i]->isCaptured()) {
                count++;
            }
        }
        if (count < 3) {
            whiteVictory = true;
        }
    } else {
        for (i = 0; i < whitePieces.size(); i++) {
            if (!whitePieces[i]->isCaptured()) {
                count++;
            }
        }
        if (count < 3) {
            blackVictory = true;
        }
    }
}

void Game::checkForMovesVictory() {
/*Checks if opponent has no more moves*/
    unsigned int i;
    unsigned int j;
    std::vector<int> adjacentSpaces;
    int count = 0;
    if (whiteTurn) { // Counting the unoccupied spaces adjacent to black pieces
        for (i = 0; i < blackPieces.size(); i++) {
            if (!blackPieces[i]->isCaptured()) {
                adjacentSpaces = adjacentList[getSpaceIndex(blackPieces[i]->getSpace())];
                for (j = 0; j < adjacentSpaces.size(); j++) {
                    if (!spaceList[adjacentSpaces[j]]->isOccupied()) {
                        count++;
                    }
                }
            }
        }
    } else { // Counting the unoccupied spaces adjacent to white pieces
        for (i = 0; i < whitePieces.size(); i++) {
            if (!whitePieces[i]->isCaptured()) {
                adjacentSpaces = adjacentList[getSpaceIndex(whitePieces[i]->getSpace())];
                for (j = 0; j < adjacentSpaces.size(); j++) {
                    if (!spaceList[adjacentSpaces[j]]->isOccupied()) {
                        count++;
                    }
                }
            }
        }
    }
    // Victory if no adjacent spaces and not flying
    if (count == 0) {
        if (whiteTurn && !blackFlying) {
            whiteVictory = true;
        }
        else if (!whiteTurn && !whiteFlying) {
            blackVictory = true;
        }
    }
}

void Game::evaluateVictoryConditions() {
/*Evaluates if the game has ended or else starts a new turn*/
    if (phaseOneComplete) {
        checkForMovesVictory();
        checkForPieceVictory();
    }
    if (whiteVictory) {
        scene->addText("White Wins!");
    } else if (blackVictory) {
        scene->addText("Black Wins!");
    }
    else {
        startNewTurn();
    }
}

void Game::selectPiece(Piece *piece) {
/*Selects a piece*/
    unsigned int i;
    connect(piece, SIGNAL(turnTaken(Piece*)), this, SLOT(nextTurn(Piece*)));
    for (i = 0; i < spaceList.size(); i++) { // Iterates through space vector and connects the piece to all spaces
        connect(spaceList[i], SIGNAL(clicked(Space*)), piece, SLOT(moved(Space*)));
    }
    piece->setSelected(true);
    piece->update();
}

void Game::deselectPiece(Piece *piece) {
/*Deselects a piece*/
    unsigned int i;
    disconnect(piece, SIGNAL(turnTaken(Piece*)), this, SLOT(nextTurn(Piece*)));
    for (i = 0; i < spaceList.size(); i++) { // Iterates through spaces and disconnects from piece
        disconnect(spaceList[i], SIGNAL(clicked(Space*)), piece, SLOT(moved(Space*)));
    }
    piece->setSelected(false);
    piece->update();
}

void Game::enableSelectPiece() {
/*Allows one side's pieces to be selected*/
    unsigned int i;
    if (whiteTurn) {
        for (i = 0; i < whitePieces.size(); i++) {
            connect(whitePieces[i], SIGNAL(clickSelect(Piece*)), this, SLOT(pieceSelectAction(Piece*)));
            whitePieces[i]->setSelectable(true);
        }
    } else {
        for (i = 0; i < blackPieces.size(); i++) {
            connect(blackPieces[i], SIGNAL(clickSelect(Piece*)), this, SLOT(pieceSelectAction(Piece*)));
            blackPieces[i]->setSelectable(true);
        }
    }
    if ((whiteTurn && whiteFlying) || (!whiteTurn && blackFlying)) {
        setAllSpaceValidity(true);
    }
}

void Game::disableSelectPiece() {
/*Disables piece selection for a side*/
    unsigned int i;
    if (whiteTurn) {
        for (i = 0; i < whitePieces.size(); i++) {
            disconnect(whitePieces[i], SIGNAL(clickSelect(Piece*)), this, SLOT(pieceSelectAction(Piece*)));
            whitePieces[i]->setSelectable(false);
        }
    } else {
        for (i = 0; i < blackPieces.size(); i++) {
            disconnect(blackPieces[i], SIGNAL(clickSelect(Piece*)), this, SLOT(pieceSelectAction(Piece*)));
            blackPieces[i]->setSelectable(false);
        }
    }
    setAllSpaceValidity(false);
}

void Game::enableCapturePiece() {
/*Enables piece capture if not in mill or no other pieces left*/
    unsigned int i;
    int count = 0;
    captureMode = true;
    if (whiteTurn) {
        for (i = 0; i < blackPieces.size(); i++) { // First pass selects pieces not in a mill
            if (!pieceInMill(blackPieces[i]) && !blackPieces[i]->isCaptured() && blackPieces[i]->isInPlay()) {
                connect(blackPieces[i], SIGNAL(clickCapture(Piece*)), this, SLOT(pieceCaptureAction(Piece*)));
                blackPieces[i]->setCaptureEnabled(true);
                count++;
            }
        }
        if (count == 0) {
            for (i = 0; i < blackPieces.size(); i++) { // Optional second pass if all pieces in mill, selects pieces in mill
                if (blackPieces[i]->isInPlay()) {
                    connect(blackPieces[i], SIGNAL(clickCapture(Piece*)), this, SLOT(pieceCaptureAction(Piece*)));
                    blackPieces[i]->setCaptureEnabled(true);
                }
            }
        }
    } else {
        for (i = 0; i < whitePieces.size(); i++) { // First pass selects pieces not in a mill
            if (!pieceInMill(whitePieces[i]) && !whitePieces[i]->isCaptured() && whitePieces[i]->isInPlay()) {
                connect(whitePieces[i], SIGNAL(clickCapture(Piece*)), this, SLOT(pieceCaptureAction(Piece*)));
                whitePieces[i]->setCaptureEnabled(true);
                count++;
            }
        }
        if (count == 0) {
            for (i = 0; i < whitePieces.size(); i++) { // Optional second pass if all pieces in mill, selects pieces in mill
                if (whitePieces[i]->isInPlay()) {
                    connect(whitePieces[i], SIGNAL(clickCapture(Piece*)), this, SLOT(pieceCaptureAction(Piece*)));
                    whitePieces[i]->setCaptureEnabled(true);
                }
            }
        }
    }
}

void Game::disableCapturePiece() {
/*Disables piece capture for a side*/
    unsigned int i;
    captureMode = false;
    if (whiteTurn) {
        for (i = 0; i < blackPieces.size(); i++) {
            disconnect(blackPieces[i], SIGNAL(clickCapture(Piece*)), this, SLOT(pieceCaptureAction(Piece*)));
            blackPieces[i]->setCaptureEnabled(false);
        }
    } else {
        for (i = 0; i < whitePieces.size(); i++) {
            disconnect(whitePieces[i], SIGNAL(clickCapture(Piece*)), this, SLOT(pieceCaptureAction(Piece*)));
            whitePieces[i]->setCaptureEnabled(false);
        }
    }
}

void Game::endTurn(Piece *piece) {
/*Ends turn by deselecting and disabling selection*/
    deselectPiece(piece);
    if (phaseOneComplete) {
        disableSelectPiece();
    }
}

void Game::startNewTurn() {
/*Starts a new turn in accordance with game phase*/
    if (!whiteTurn) {
        turnNumber++;
    }
    whiteTurn = !whiteTurn;
    if (!phaseOneComplete) {
        if (turnNumber < 9) {
            // Selects the next unplayed piece in first phase of game
            if (whiteTurn) {
                selectPiece(whitePieces[turnNumber]);
            } else {
                selectPiece(blackPieces[turnNumber]);
            }
        } else {
            // Ends first phase of game
            phaseOneComplete = true;
            setAllSpaceValidity(false);
            enableSelectPiece();
        }
    } else {
        // Enables appropriate side to select and move a piece
        enableSelectPiece();
    }
}

void Game::pieceCaptureAction(Piece *piece) {
/*Slot for action taken when capturable piece clicked*/
    scene->removeItem(piece);
    piece->getSpace()->setOccupied(false);
    piece->setCaptured(true);
    disableCapturePiece();
    checkForNewMill();
    checkForFlying();
    evaluateVictoryConditions();
}

void Game::pieceSelectAction(Piece *piece) {
/*Slot for action taken when selectable piece clicked*/
    unsigned int i;
    if (whiteTurn) { // Iterates through white piece vector and deselects any previously selected pieces
        for (i = 0; i < whitePieces.size(); i++) {
            if (whitePieces[i]->isSelected()) {
                deselectPiece(whitePieces[i]);
                if (!whiteFlying) {
                    setAdjacentSpaces(whitePieces[i], false);
                }
            }
        }
    } else { // Iterates through black piece vector and deselects any previously selected pieces
        for (i = 0; i < blackPieces.size(); i++) {
            if (blackPieces[i]->isSelected()) {
                deselectPiece(blackPieces[i]);
                if (!blackFlying) {
                    setAdjacentSpaces(blackPieces[i], false);
                }
            }
        }
    }
    // Selects chosen piece and sets adjacent squares as valid moves
    selectPiece(piece);
    setAdjacentSpaces(piece, true);
}

void Game::nextTurn(Piece *piece) {
/*Slot to change the player turn after a move*/
    endTurn(piece);
    checkForNewMill();
    if (!captureMode) {
        evaluateVictoryConditions();
    }
}
