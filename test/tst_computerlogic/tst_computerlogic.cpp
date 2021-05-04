#include "tst_computerlogic.h"

void ComputerLogic::testComputerPlacePiece() {
    SinglePlayerGame game(&testScene, true);
    std::vector<Space*> spaceList = game.getSpaceList();
    for(int i = 0; i < 24; i++) {
        if(spaceList[i]->isOccupied() == true && spaceList[i]->hasWhitePiece() == true)
            QCOMPARE(game.getSpace(i)->isOccupied(), true);
    }
}

void ComputerLogic::testComputerPlayerBlock() {
    SinglePlayerGame game(&testScene, false);
    int blockSpace;
    QTest::mousePress(game.getSpace(22), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    if(game.getSpace(21)->isOccupied() == true) {
        QTest::mousePress(game.getSpace(18), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
        blockSpace = 16;
    }
    else {
        QTest::mousePress(game.getSpace(23), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
        blockSpace = 21;
    }
    QCOMPARE(game.getSpace(blockSpace)->hasBlackPiece(), true);
}


QTEST_MAIN(ComputerLogic)
