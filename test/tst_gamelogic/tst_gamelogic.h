#ifndef TST_GAMELOGIC_H
#define TST_GAMELOGIC_H
#include <QtTest>
#include <QTest>
#include <QCoreApplication>

#include "include/game.h"

class GameLogic : public QObject
{
    Q_OBJECT

public:
    GameLogic() {}
    ~GameLogic() {}

private:
    QGraphicsScene testScene;

private slots:
    //AC 2.1-3
    void testSwitchingTurns();
    //AC 3.1, 3.6
    void testClickMovePhaseOne();
    //AC 3.2, 4.3, 4.7
    void testClickOccupiedSpace();
    //AC 4.2
    void testClickSelectWhitePiece();
    //AC 4.6
    void testClickSelectBlackPiece();
    //AC 4.2
    void testSelectMoveWhite();
    //AC 4.6
    void testSelectMoveBlack();

    void testSelectMoveInvalid();
    //AC 5.3
    void testWhiteCapture();
    //AC 5.4
    void testBlackCapture();
    //AC 5.4
    void testCaptureWhiteFromMill();
    //AC 5.3
    void testCaptureBlackFromMill();
    //AC 5.4
    void testCaptureWhiteInvalid();
    //AC 5.3
    void testCaptureBlackInvalid();
    //AC 6.3
    void testWhiteFlying();
    //AC 6.4
    void testBlackFlying();
    //AC 7.1
    void testWhitePieceVictory();
    //AC 7.5
    void testBlackPieceVictory();

    void testWhiteMovesVictory();
    //AC 7.6
    void testBlackMovesVictory();

};
#endif // TST_GAMELOGIC_H
