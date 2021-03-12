#include "tst_gamelogic.h"

void GameLogic::testSwitchingTurns() {
/*Tests turn switches from white to black to white*/
    Game game(&testScene);
    QCOMPARE(game.testWhiteTurn(), true);
    QTest::mousePress(game.getSpace(0), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QCOMPARE(game.testWhiteTurn(), false);
    QTest::mousePress(game.getSpace(23), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QCOMPARE(game.testWhiteTurn(), true);
}

void GameLogic::testClickMovePhaseOne() {
/*Tests that pieces go to clicked spaces*/
    Game game(&testScene);
    QCOMPARE(game.getSpace(0)->isOccupied(), false);
    QCOMPARE(game.getSpace(23)->isOccupied(), false);
    QTest::mousePress(game.getSpace(0), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QTest::mousePress(game.getSpace(23), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QCOMPARE(game.getSpace(0)->hasWhitePiece(), true);
    QCOMPARE(game.getSpace(23)->hasBlackPiece(), true);
}

void GameLogic::testClickOccupiedSpace() {
/*Tests nothing happens when an occupied space is clicked*/
    Game game(&testScene);
    QSignalSpy spy(game.getSpace(23), SIGNAL(clicked(Space*)));
    QTest::mousePress(game.getSpace(0), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QTest::mousePress(game.getSpace(23), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QCOMPARE(game.getSpace(23)->hasBlackPiece(), true);
    QCOMPARE(spy.count(), 1);
    QTest::mousePress(game.getSpace(23), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QCOMPARE(game.getSpace(23)->hasBlackPiece(), true);
    QCOMPARE(spy.count(), 1);
}

void GameLogic::testClickSelectWhitePiece() {
/*Tests that a white piece is selected when clicked and previous selection cleared*/
    Game game(&testScene);
    QTest::mousePress(game.getSpace(0), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QTest::mousePress(game.getSpace(1), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QTest::mousePress(game.getSpace(2), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QTest::mousePress(game.getSpace(3), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    game.deselectPiece(game.getWhitePiece(2));
    game.endPhaseOne();
    //Click first piece
    QCOMPARE(game.getWhitePiece(0)->isSelected(), false);
    QTest::mousePress(game.getWhitePiece(0), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QCOMPARE(game.getWhitePiece(0)->isSelected(), true);
    QCOMPARE(game.getWhitePiece(1)->isSelected(), false);
    //Tested first piece selected, now click second piece
    QTest::mousePress(game.getWhitePiece(1), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QCOMPARE(game.getWhitePiece(0)->isSelected(), false);
    QCOMPARE(game.getWhitePiece(1)->isSelected(), true);
    //Tested first piece unselected, second piece selected
}

void GameLogic::testClickSelectBlackPiece() {
/*Tests that a black piece is selected when clicked and previous selection cleared*/
    Game game(&testScene);
    QTest::mousePress(game.getSpace(0), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QTest::mousePress(game.getSpace(1), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QTest::mousePress(game.getSpace(2), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QTest::mousePress(game.getSpace(3), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QTest::mousePress(game.getSpace(4), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    game.deselectPiece(game.getBlackPiece(2));
    game.endPhaseOne();
    QCOMPARE(game.getBlackPiece(0)->isSelected(), false);
    //Click first piece
    QTest::mousePress(game.getBlackPiece(0), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QCOMPARE(game.getBlackPiece(0)->isSelected(), true);
    QCOMPARE(game.getBlackPiece(1)->isSelected(), false);
    //Tested first piece selected, now click second piece
    QTest::mousePress(game.getBlackPiece(1), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QCOMPARE(game.getBlackPiece(0)->isSelected(), false);
    QCOMPARE(game.getBlackPiece(1)->isSelected(), true);
    //Tested first piece unselected, second piece selected
}

void GameLogic::testSelectMoveWhite() {
/*Tests that white can be selected and moved in phase two*/
    Game game(&testScene);
    QSignalSpy spy(game.getWhitePiece(0), SIGNAL(turnTaken(Piece*)));
    QTest::mousePress(game.getSpace(0), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QTest::mousePress(game.getSpace(23), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    game.deselectPiece(game.getWhitePiece(1));
    game.endPhaseOne();
    QCOMPARE(spy.count(), 1);
    QCOMPARE(game.getSpace(1)->isOccupied(), false);
    //Selects and moves piece
    QTest::mousePress(game.getWhitePiece(0), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QTest::mousePress(game.getSpace(1), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    //Checks that piece has moved to new space
    QCOMPARE(spy.count(), 2);
    QCOMPARE(game.getSpace(1)->hasWhitePiece(), true);
}

void GameLogic::testSelectMoveBlack() {
/*Tests that white can be selected and moved in phase two*/
    Game game(&testScene);
    QSignalSpy spy(game.getBlackPiece(0), SIGNAL(turnTaken(Piece*)));
    QTest::mousePress(game.getSpace(0), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QTest::mousePress(game.getSpace(23), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QTest::mousePress(game.getSpace(1), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    game.deselectPiece(game.getBlackPiece(1));
    game.endPhaseOne();
    QCOMPARE(spy.count(), 1);
    QCOMPARE(game.getSpace(22)->isOccupied(), false);
    //Selects and moves piece
    QTest::mousePress(game.getBlackPiece(0), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QTest::mousePress(game.getSpace(22), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    //Checks that piece has moved to new space
    QCOMPARE(spy.count(), 2);
    QCOMPARE(game.getSpace(22)->hasBlackPiece(), true);
}

void GameLogic::testSelectMoveInvalid() {
/*Attempts an invalid move and checks that it does not succeed*/
    Game game(&testScene);
    QSignalSpy spy(game.getWhitePiece(0), SIGNAL(turnTaken(Piece*)));
    QTest::mousePress(game.getSpace(0), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QTest::mousePress(game.getSpace(1), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    game.deselectPiece(game.getWhitePiece(1));
    game.endPhaseOne();
    QCOMPARE(spy.count(), 1);
    QCOMPARE(game.getSpace(23)->isOccupied(), false);
    QCOMPARE(game.testWhiteTurn(), true);
    //Selects piece and clicks space
    QTest::mousePress(game.getWhitePiece(0), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QTest::mousePress(game.getSpace(23), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    //Verifies piece has not moved and turn has not changed
    QCOMPARE(spy.count(), 1);
    QCOMPARE(game.getSpace(23)->isOccupied(), false);
    QCOMPARE(game.testWhiteTurn(), true);
}

void GameLogic::testWhiteCapture() {
/*Forms a white mill and checks that a black piece is captured*/
    Game game(&testScene);
    QSignalSpy spy(game.getBlackPiece(1), SIGNAL(clickCapture(Piece*)));
    //Playing the game to form a mill
    QTest::mousePress(game.getSpace(0), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QTest::mousePress(game.getSpace(23), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QTest::mousePress(game.getSpace(1), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QTest::mousePress(game.getSpace(22), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QTest::mousePress(game.getSpace(2), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QCOMPARE(game.getSpace(22)->isOccupied(), true);
    QCOMPARE(spy.count(), 0);
    QCOMPARE(game.testWhiteTurn(), true);
    //Clicks to capture black piece and verifies capture and turn change
    QTest::mousePress(game.getBlackPiece(1), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QCOMPARE(game.getSpace(22)->isOccupied(), false);
    QCOMPARE(spy.count(), 1);
    QCOMPARE(game.testWhiteTurn(), false);
}

void GameLogic::testBlackCapture() {
/*Forms a black mill and checks that a white piece is captured*/
    Game game(&testScene);
    QSignalSpy spy(game.getWhitePiece(1), SIGNAL(clickCapture(Piece*)));
    //Playing the game to form a mill
    QTest::mousePress(game.getSpace(21), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QTest::mousePress(game.getSpace(0), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QTest::mousePress(game.getSpace(18), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QTest::mousePress(game.getSpace(1), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QTest::mousePress(game.getSpace(22), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QTest::mousePress(game.getSpace(2), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QCOMPARE(game.getSpace(18)->isOccupied(), true);
    QCOMPARE(spy.count(), 0);
    QCOMPARE(game.testWhiteTurn(), false);
    //Clicks to capture white piece and verifies capture and turn change
    QTest::mousePress(game.getWhitePiece(1), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QCOMPARE(game.getSpace(18)->isOccupied(), false);
    QCOMPARE(spy.count(), 1);
    QCOMPARE(game.testWhiteTurn(), true);
}

void GameLogic::testCaptureWhiteFromMill() {
/*Tests that white piece can be captured from mill if no other pieces*/
    Game game(&testScene);
    QSignalSpy spy(game.getWhitePiece(0), SIGNAL(clickCapture(Piece*)));
    //Playing the game so that a mill is formed when white has only pieces in mill
    QTest::mousePress(game.getSpace(0), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QTest::mousePress(game.getSpace(21), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QTest::mousePress(game.getSpace(1), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QTest::mousePress(game.getSpace(22), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QTest::mousePress(game.getSpace(2), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QTest::mousePress(game.getBlackPiece(1), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QTest::mousePress(game.getSpace(23), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QTest::mousePress(game.getSpace(4), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QTest::mousePress(game.getSpace(19), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QTest::mousePress(game.getSpace(7), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QTest::mousePress(game.getBlackPiece(3), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QTest::mousePress(game.getSpace(22), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QCOMPARE(spy.count(), 0);
    QCOMPARE(game.testWhiteTurn(), false);
    //Click piece and verify captured and turn changes
    QTest::mousePress(game.getWhitePiece(0), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QCOMPARE(spy.count(), 1);
    QCOMPARE(game.testWhiteTurn(), true);
}

void GameLogic::testCaptureBlackFromMill() {
/*Tests that black piece can be captured from mill if no other pieces*/
    Game game(&testScene);
    QSignalSpy spy(game.getBlackPiece(0), SIGNAL(clickCapture(Piece*)));
    //Playing the game so that a mill is formed when black has only pieces in mill
    QTest::mousePress(game.getSpace(4), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QTest::mousePress(game.getSpace(21), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QTest::mousePress(game.getSpace(0), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QTest::mousePress(game.getSpace(22), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QTest::mousePress(game.getSpace(1), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QTest::mousePress(game.getSpace(23), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QTest::mousePress(game.getWhitePiece(0), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QTest::mousePress(game.getSpace(2), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QCOMPARE(spy.count(), 0);
    QCOMPARE(game.testWhiteTurn(), true);
    //Click piece and verify captured and turn changes
    QTest::mousePress(game.getBlackPiece(0), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QCOMPARE(spy.count(), 1);
    QCOMPARE(game.testWhiteTurn(), false);
}

void GameLogic::testCaptureWhiteInvalid() {
/*Tests that white piece cannot be captured from mill if other pieces*/
    Game game(&testScene);
    QSignalSpy spy(game.getWhitePiece(0), SIGNAL(clickCapture(Piece*)));
    //Playing the game to form a mill and place another piece
    QTest::mousePress(game.getSpace(0), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QTest::mousePress(game.getSpace(21), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QTest::mousePress(game.getSpace(1), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QTest::mousePress(game.getSpace(22), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QTest::mousePress(game.getSpace(2), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QTest::mousePress(game.getBlackPiece(1), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QTest::mousePress(game.getSpace(22), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QTest::mousePress(game.getSpace(4), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QTest::mousePress(game.getSpace(23), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QCOMPARE(spy.count(), 0);
    QCOMPARE(game.testWhiteTurn(), false);
    //Click piece in mill and verify not captured and turn not changed
    QTest::mousePress(game.getWhitePiece(0), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QCOMPARE(spy.count(), 0);
    QCOMPARE(game.testWhiteTurn(), false);
}

void GameLogic::testCaptureBlackInvalid() {
/*Tests that black piece cannot be captured from mill if other pieces*/
    Game game(&testScene);
    QSignalSpy spy(game.getBlackPiece(0), SIGNAL(clickCapture(Piece*)));
    //Playing the game to form a mill and place another piece
    QTest::mousePress(game.getSpace(0), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QTest::mousePress(game.getSpace(21), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QTest::mousePress(game.getSpace(1), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QTest::mousePress(game.getSpace(22), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QTest::mousePress(game.getSpace(4), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QTest::mousePress(game.getSpace(23), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QTest::mousePress(game.getWhitePiece(2), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QTest::mousePress(game.getSpace(4), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QTest::mousePress(game.getSpace(12), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QTest::mousePress(game.getSpace(2), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QCOMPARE(spy.count(), 0);
    QCOMPARE(game.testWhiteTurn(), true);
    //Click piece in mill and verify not captured and turn not changed
    QTest::mousePress(game.getBlackPiece(0), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QCOMPARE(spy.count(), 0);
    QCOMPARE(game.testWhiteTurn(), true);
}

void GameLogic::testWhiteFlying() {
/*Test that white flying is set when white has three pieces*/
    Game game(&testScene);
    QSignalSpy spy(game.getWhitePiece(1), SIGNAL(turnTaken(Piece*)));
    //Artificially capture five white pieces
    for (int i = 4; i < 9; i++) {
        game.getWhitePiece(i)->setCaptured(true);
    }
    //Playing the game to form a mill and capture the sixth white piece
    QTest::mousePress(game.getSpace(23), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QTest::mousePress(game.getSpace(0), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QTest::mousePress(game.getSpace(17), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QTest::mousePress(game.getSpace(1), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QTest::mousePress(game.getSpace(6), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QTest::mousePress(game.getSpace(14), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QTest::mousePress(game.getSpace(20), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    game.deselectPiece(game.getBlackPiece(3));
    game.endPhaseOne();
    QTest::mousePress(game.getBlackPiece(2), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QCOMPARE(game.testWhiteFlying(), false);
    //Capture piece and verify flying set
    QTest::mousePress(game.getSpace(2), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QTest::mousePress(game.getWhitePiece(0), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QCOMPARE(game.testWhiteFlying(), true);
    //Verify piece moves to nonadjacent square
    QCOMPARE(spy.count(), 1);
    QTest::mousePress(game.getWhitePiece(1), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QTest::mousePress(game.getSpace(3), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QCOMPARE(spy.count(), 2);
}

void GameLogic::testBlackFlying() {
/*Test that black flying is set when black has three pieces*/
    Game game(&testScene);
    QSignalSpy spy(game.getBlackPiece(1), SIGNAL(turnTaken(Piece*)));
    //Artificially capture five black pieces
    for (int i = 4; i < 9; i++) {
        game.getBlackPiece(i)->setCaptured(true);
    }
    //Playing the game to form a mill and capture the sixth black piece
    QTest::mousePress(game.getSpace(0), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QTest::mousePress(game.getSpace(23), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QTest::mousePress(game.getSpace(1), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QTest::mousePress(game.getSpace(17), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QTest::mousePress(game.getSpace(14), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QTest::mousePress(game.getSpace(6), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    game.deselectPiece(game.getWhitePiece(3));
    game.endPhaseOne();
    QTest::mousePress(game.getWhitePiece(2), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QCOMPARE(game.testBlackFlying(), false);
    //Capture piece and verify flying set
    QTest::mousePress(game.getSpace(2), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QTest::mousePress(game.getBlackPiece(0), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QCOMPARE(game.testBlackFlying(), true);
    //Verify piece moves to nonadjacent square
    QCOMPARE(spy.count(), 1);
    QTest::mousePress(game.getBlackPiece(1), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QTest::mousePress(game.getSpace(3), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QCOMPARE(spy.count(), 2);
}

void GameLogic::testWhitePieceVictory() {
/*Test that white wins when black reduced to two pieces*/
    Game game(&testScene);
    //Artificially capture six black pieces
    for (int i = 3; i < 9; i++) {
        game.getBlackPiece(i)->setCaptured(true);
    }
    //Play the game to form a mill
    QTest::mousePress(game.getSpace(0), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QTest::mousePress(game.getSpace(23), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QTest::mousePress(game.getSpace(1), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QTest::mousePress(game.getSpace(17), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QTest::mousePress(game.getSpace(14), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QTest::mousePress(game.getSpace(6), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    game.deselectPiece(game.getWhitePiece(3));
    game.endPhaseOne();
    QTest::mousePress(game.getWhitePiece(2), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QCOMPARE(game.testWhiteVictory(), false);
    //Capture final piece and verify white has won
    QTest::mousePress(game.getSpace(2), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QTest::mousePress(game.getBlackPiece(0), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QCOMPARE(game.testWhiteVictory(), true);
}

void GameLogic::testBlackPieceVictory() {
/*Test that black wins when white reduced to two pieces*/
    Game game(&testScene);
    //Artificially capture six white pieces
    for (int i = 3; i < 9; i++) {
        game.getWhitePiece(i)->setCaptured(true);
    }
    //Play the game to form a mill
    QTest::mousePress(game.getSpace(23), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QTest::mousePress(game.getSpace(0), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QTest::mousePress(game.getSpace(17), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QTest::mousePress(game.getSpace(1), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QTest::mousePress(game.getSpace(6), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QTest::mousePress(game.getSpace(14), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QTest::mousePress(game.getSpace(20), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    game.deselectPiece(game.getBlackPiece(3));
    game.endPhaseOne();
    QTest::mousePress(game.getBlackPiece(2), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QCOMPARE(game.testBlackVictory(), false);
    //Capture final piece and verify black has won
    QTest::mousePress(game.getSpace(2), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QTest::mousePress(game.getWhitePiece(0), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QCOMPARE(game.testBlackVictory(), true);
}

void GameLogic::testWhiteMovesVictory() {
/*Test that white wins when black has no moves*/
    Game game(&testScene);
    //Playing the game so that black will have no moves
    QTest::mousePress(game.getSpace(4), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QTest::mousePress(game.getSpace(8), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QTest::mousePress(game.getSpace(12), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QTest::mousePress(game.getSpace(17), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QTest::mousePress(game.getSpace(16), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QTest::mousePress(game.getSpace(15), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QTest::mousePress(game.getSpace(11), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QTest::mousePress(game.getSpace(6), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    //Artificially ending phase one, pieces not in play disregarded
    game.deselectPiece(game.getWhitePiece(4));
    game.endPhaseOne();
    QTest::mousePress(game.getWhitePiece(0), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QCOMPARE(game.testWhiteVictory(), false);
    //Moving the final piece into place and verifying white win
    QTest::mousePress(game.getSpace(7), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QCOMPARE(game.testWhiteVictory(), true);
}

void GameLogic::testBlackMovesVictory() {
/*Test that black wins when white has no moves*/
    Game game(&testScene);
    //Playing the game so that white will have no moves
    QTest::mousePress(game.getSpace(7), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QTest::mousePress(game.getSpace(12), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QTest::mousePress(game.getSpace(17), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QTest::mousePress(game.getSpace(16), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QTest::mousePress(game.getSpace(15), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QTest::mousePress(game.getSpace(11), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QTest::mousePress(game.getSpace(6), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QTest::mousePress(game.getSpace(4), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    //Artificially ending phase one, pieces not in play disregarded
    game.deselectPiece(game.getWhitePiece(4));
    game.endPhaseOne();
    QTest::mousePress(game.getWhitePiece(0), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QTest::mousePress(game.getSpace(8), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QTest::mousePress(game.getBlackPiece(3), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QCOMPARE(game.testBlackVictory(), false);
    //Moving the final piece into place and verifying black win
    QTest::mousePress(game.getSpace(7), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QCOMPARE(game.testBlackVictory(), true);
}

QTEST_MAIN(GameLogic)
