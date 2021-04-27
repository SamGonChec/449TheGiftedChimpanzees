#include "include/singleplayergame.h"

// Constructor for SinglePlayerGame class
SinglePlayerGame::SinglePlayerGame(QGraphicsScene *scene, bool computerIsWhite) : Game(scene) {
    computerColorWhite = computerIsWhite;
    srand(time(NULL));
    if (computerColorWhite) {
        computerPhaseOneMove();
    }
    menuButton = new QPushButton(QString("Main Menu"));
    menuButton->setGeometry(325,800,150,50);
    QFont buttonFont("comic sans MS", 14);
    menuButton->setFont(buttonFont);
    menuButton->setStyleSheet("background-color: brown; color: #00DCDC; border-style: outset; border-width: 2px; border-radius: 3px; border-color: yellow; padding: 6px;");
    scene->addWidget(menuButton);
}

// Adds unoccupied spaces to available
void SinglePlayerGame::scanSpaces() {
    unsigned int i;
    availableSpaces.clear();
    for (i = 0; i < spaceList.size(); i++) {
        if (!spaceList[i]->isOccupied()) {
            availableSpaces.push_back(i);
        }
    }
}

// Populates vector of computer piece indices
void SinglePlayerGame::getAvailablePieceIndices(){
    unsigned int i;
    availableSelectIndices.clear();
    if (computerColorWhite){
        for (i = 0; i < availableSelect.size(); i++){
            availableSelectIndices.push_back(getSpaceIndex(whitePieces[availableSelect[i]]->getSpace()));
        }
    } else {
        for (i = 0; i < availableSelect.size(); i++){
            availableSelectIndices.push_back(getSpaceIndex(blackPieces[availableSelect[i]]->getSpace()));
        }
    }
}

void SinglePlayerGame::pieceToMoveForMill(){
    unsigned int i;
    unsigned int j;
    unsigned int k;


    std::vector<std::vector<int>> updatedPriorityList;

    for (i = 0; i < priorityList.size(); i++){
        std::vector<int> validMillMove;
        for (j = 1; j < priorityList[i].size(); j++){
            std::vector<int> potentialMill;
            std::vector<int> piecesToMove;
            potentialMill.push_back(priorityList[i][0]);
            for (k = 1; k < priorityList[i].size(); k++){
                piecesToMove.push_back(availableSelectIndices[priorityList[i][k]]);
            }
            for (k = 0; k < piecesToMove.size(); k++){
                potentialMill.push_back(piecesToMove[k]);
            }
            potentialMill.erase(std::remove(potentialMill.begin(), potentialMill.end(), piecesToMove[j]));
            sort(potentialMill.begin(), potentialMill.end());
            // if the mill is made with a corner piece
            if (potentialMill.size() != 3){
                for (k = 0; k < availableSelect.size(); k++){
                    std::vector<int> cornerMill;
                    cornerMill = potentialMill;
                    cornerMill.push_back(availableSelectIndices[k]);
                    sort(cornerMill.begin(), cornerMill.end());
                    if (std::count(millList.begin(), millList.end(), potentialMill)){
                        validMillMove.push_back(priorityList[i][0]);
                        validMillMove.push_back(priorityList[i][j]);
                        updatedPriorityList.push_back(validMillMove);
                        break;
                    }
                }
            } else if (std::count(millList.begin(), millList.end(), potentialMill)){
                  validMillMove.push_back(priorityList[i][0]);
                  validMillMove.push_back(priorityList[i][j]);
                  updatedPriorityList.push_back(validMillMove);
                  break;
            }
        }
    }
    priorityList = updatedPriorityList;
}

// Computer move logic for phase two
void SinglePlayerGame::priorityScanPhaseTwo(){
    unsigned int i;
    unsigned int j;
    unsigned int k;
    std::vector<int> candidatePieceIndex;
    std::vector<int> adjacentToCandidate;

    priorityScan();
    scanSpaces();
    getAvailablePieceIndices();
    // Finds the mills it can legally make
    for (i = 0; i < possibleMill.size(); i++){
        candidatePieceIndex = {possibleMill[i]};
        for (j = 0; j < availableSelect.size(); j++){
            adjacentToCandidate = (adjacentList[availableSelectIndices[j]]);
            for (k = 0; k < adjacentToCandidate.size(); k++){
                if (adjacentToCandidate[k] == possibleMill[i]){
                    candidatePieceIndex.push_back(j);
                }
            }
        }
        if (candidatePieceIndex.size() >= 3){
            priorityList.push_back(candidatePieceIndex);
        }
    }
    if (!priorityList.empty()){
        pieceToMoveForMill();
    }
    // Finds the blocks it can legally make
    for (i = 0; i < possibleBlock.size(); i++){
        candidatePieceIndex = {possibleBlock[i]};
        for (j = 0; j < availableSelect.size(); j++){
            adjacentToCandidate = (adjacentList[availableSelectIndices[j]]);
            for (k = 0; k < adjacentToCandidate.size(); k++){
                if (adjacentToCandidate[k] == possibleBlock[i]){
                    candidatePieceIndex.push_back(j);
                }
            }
        }
        if (candidatePieceIndex.size() >= 2){
            priorityList.push_back(candidatePieceIndex);
        }
    }
}


// Scans the board for ideal moves
void SinglePlayerGame::priorityScan() {
    unsigned int i;
    unsigned int j;
    unsigned int blackCounter;
    unsigned int whiteCounter;
    int emptyIndex;
    
    possibleMill.clear();
    possibleBlock.clear();
    priorityList.clear();
    
    // Scans the board to find possible mills and blocks
    for (i = 0; i < millList.size(); i++){
        blackCounter = 0;
        whiteCounter = 0;
        emptyIndex = -1;
        for (j = 0; j < 3; j++){
            if (spaceList[millList[i][j]]->hasWhitePiece()){
                whiteCounter++;
            } else if (spaceList[millList[i][j]]->hasBlackPiece()){
                blackCounter++;
            } else{
              emptyIndex = millList[i][j];
            }
            // If there's no empty spaces, the line is ignored
            if (whiteCounter == 2 && emptyIndex != -1){
                (computerColorWhite) ? possibleMill.push_back(emptyIndex) : possibleBlock.push_back(emptyIndex);
            }
            if (blackCounter == 2 && emptyIndex != -1) {
                (!computerColorWhite) ? possibleMill.push_back(emptyIndex) : possibleBlock.push_back(emptyIndex);
            }
        }
    }
}


// Chooses an available space and moves in first phase
void SinglePlayerGame::computerPhaseOneMove() {
    priorityScan();
    /* Going to want to prioritize mills over blocks.
     * If no mill, find blocks. If no blocks or mills,
     * find a random space*/
    if (!possibleMill.empty()){
        spaceList[possibleMill[0]]->computerClickSpace();
    } else if (!possibleBlock.empty()){
        spaceList[possibleBlock[0]]->computerClickSpace();
    } else {
        scanSpaces();
        int randIndex = rand() % availableSpaces.size();
        spaceList[availableSpaces[randIndex]]->computerClickSpace();
    }
}


// Chooses a piece and moves to an open space
void SinglePlayerGame::computerPhaseTwoMove() {
    unsigned int i;
    bool validMove = false;
    Piece *chosenPiece;
    int moveSpaceIndex;

    priorityScanPhaseTwo();
    if (!priorityList.empty()){
        validMove = true;
        int pieceIndex = availableSelect[priorityList[0][1]];
        if (computerColorWhite) {
            chosenPiece = whitePieces[pieceIndex];
        } else {
            chosenPiece = blackPieces[pieceIndex];
        }
        moveSpaceIndex = priorityList[0][0];
    }
    while (!validMove) {
           //Choosing a piece
           int randIndex = rand() % availableSelect.size();
           int pieceIndex = availableSelect[randIndex];
           if (computerColorWhite) {
               chosenPiece = whitePieces[pieceIndex];
           } else {
               chosenPiece = blackPieces[pieceIndex];
           }
           //Choosing a space to move to
           availableSpaces.clear();
           int startSpaceIndex = getSpaceIndex(chosenPiece->getSpace());
           for (i = 0; i < adjacentList[startSpaceIndex].size(); i++) {
               if (!spaceList[adjacentList[startSpaceIndex][i]]->isOccupied()) {
                   availableSpaces.push_back(adjacentList[startSpaceIndex][i]);
                   validMove = true;
               }
           }
           if (validMove){
               //Pick a random adjacent space
               moveSpaceIndex = availableSpaces[rand() % availableSpaces.size()];
           }
       }      
       //Select piece and move to space
       chosenPiece->computerPlayerSelect();
       spaceList[moveSpaceIndex]->computerClickSpace();
}

//Selects piece and moves to available space
void SinglePlayerGame::computerFlyingMove() {
    Piece *chosenPiece;
    scanSpaces();
    priorityScan();
    int randIndex = rand() % availableSpaces.size();
    int spaceIndex = availableSpaces[randIndex];
    randIndex = rand() % availableSelect.size();
    int pieceIndex = availableSelect[randIndex];
    if (computerColorWhite) {
        chosenPiece = whitePieces[pieceIndex];
    } else {
        chosenPiece = blackPieces[pieceIndex];
    }
    chosenPiece->computerPlayerSelect();
    if (!possibleMill.empty()){
        spaceList[possibleMill[0]]->computerClickSpace();
    } else if (!possibleBlock.empty()){
        spaceList[possibleBlock[0]]->computerClickSpace();
    } else{
        spaceList[spaceIndex]->computerClickSpace();
    }
}

//Selects capturable piece and captures it
void SinglePlayerGame::computerCapture() {
    int randIndex = rand() % availableCapture.size();
    int pieceIndex = availableCapture[randIndex];
    if (computerColorWhite) {
        blackPieces[pieceIndex]->computerPlayerCapture();
    } else {
        whitePieces[pieceIndex]->computerPlayerCapture();
    }
}

//In addition to base functionality, adds selectable piece indices to available vector
void SinglePlayerGame::enableSelectPiece() {
    unsigned int i;
    availableSelect.clear();
    if (whiteTurn) {
        for (i = 0; i < whitePieces.size(); i++) {
            if (!whitePieces[i]->isCaptured()) {
                connect(whitePieces[i], SIGNAL(clickSelect(Piece*)), this, SLOT(pieceSelectAction(Piece*)));
                whitePieces[i]->setSelectable(true);
                availableSelect.push_back(i);
            }
        }
    } else {
        for (i = 0; i < blackPieces.size(); i++) {
            if (!blackPieces[i]->isCaptured()) {
                connect(blackPieces[i], SIGNAL(clickSelect(Piece*)), this, SLOT(pieceSelectAction(Piece*)));
                blackPieces[i]->setSelectable(true);
                availableSelect.push_back(i);
            }
        }
    }
    if ((whiteTurn && whiteFlying) || (!whiteTurn && blackFlying)) {
        setAllSpaceValidity(true);
    }
}

//In addition to base functionality, adds pieces available to capture to vector
void SinglePlayerGame::enableCapturePiece() {
    unsigned int i;
    int count = 0;
    captureMode = true;
    setInstructionText(turnNumber, captureMode);
    availableCapture.clear();
    if (whiteTurn) {
        //First pass selects pieces not in a mill
        for (i = 0; i < blackPieces.size(); i++) {
            if (!pieceInMill(blackPieces[i]) && !blackPieces[i]->isCaptured() && blackPieces[i]->isInPlay()) {
                connect(blackPieces[i], SIGNAL(clickCapture(Piece*)), this, SLOT(pieceCaptureAction(Piece*)));
                blackPieces[i]->setCaptureEnabled(true);
                availableCapture.push_back(i);
                count++;
            }
        }
        //Optional second pass if all pieces in mill, selects pieces in mill
        if (count == 0) {
            for (i = 0; i < blackPieces.size(); i++) {
                if (blackPieces[i]->isInPlay()) {
                    connect(blackPieces[i], SIGNAL(clickCapture(Piece*)), this, SLOT(pieceCaptureAction(Piece*)));
                    blackPieces[i]->setCaptureEnabled(true);
                    availableCapture.push_back(i);
                }
            }
        }
    } else {
        //First pass selects pieces not in a mill
        for (i = 0; i < whitePieces.size(); i++) {
            if (!pieceInMill(whitePieces[i]) && !whitePieces[i]->isCaptured() && whitePieces[i]->isInPlay()) {
                connect(whitePieces[i], SIGNAL(clickCapture(Piece*)), this, SLOT(pieceCaptureAction(Piece*)));
                whitePieces[i]->setCaptureEnabled(true);
                availableCapture.push_back(i);
                count++;
            }
        }
        //Optional second pass if all pieces in mill, selects pieces in mill
        if (count == 0) {
            for (i = 0; i < whitePieces.size(); i++) {
                if (whitePieces[i]->isInPlay()) {
                    connect(whitePieces[i], SIGNAL(clickCapture(Piece*)), this, SLOT(pieceCaptureAction(Piece*)));
                    whitePieces[i]->setCaptureEnabled(true);
                    availableCapture.push_back(i);
                }
            }
        }
    }
}

//Overrides function to add computer move functionality
void SinglePlayerGame::startNewTurn() {
    Game::startNewTurn();
    if (whiteTurn == computerColorWhite) {
        if (!phaseOneComplete) {
            computerPhaseOneMove();
        } else if ((!whiteFlying && computerColorWhite) || (!blackFlying && !computerColorWhite)) {
            computerPhaseTwoMove();
        } else if ((whiteFlying && computerColorWhite) || (blackFlying && !computerColorWhite)) {
            computerFlyingMove();
        }
    }
}

void SinglePlayerGame::nextTurn(Piece *piece) {
    endTurn(piece);
    checkForNewMill();
    if (!captureMode) {
        evaluateVictoryConditions();
    } else if (whiteTurn == computerColorWhite) {
        computerCapture();
    }
}
