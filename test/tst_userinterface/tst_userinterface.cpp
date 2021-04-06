#include "tst_userinterface.h"

void UserInterface::testOnePlayerScreen() {
/*Test that the user will be sent to the one player screen*/
    Menu menu(&testScene);
    QSignalSpy spy(menu.returnSinglePlayerPushButton(), SIGNAL(clicked()));
    QTest::mouseClick(menu.returnSinglePlayerPushButton(), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QCOMPARE(spy.count(), 1);
}

void UserInterface::testTwoPlayerScreen() {
/*Test that the user will be sent to the two player screen*/
    Menu menu(&testScene);
    QSignalSpy spy(menu.returnTwoPlayerPushButton(), SIGNAL(clicked()));
    QTest::mouseClick(menu.returnTwoPlayerPushButton(), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QCOMPARE(spy.count(), 1);
}

void UserInterface::testTutorialScreen() {
/*Test that the user will be sent to the tutorial screen*/
    Menu menu(&testScene);
    QSignalSpy spy(menu.returnTutorialPushButton(), SIGNAL(clicked()));
    QTest::mouseClick(menu.returnTutorialPushButton(), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QCOMPARE(spy.count(), 1);
}

void UserInterface::testQuitButton() {
/*Test that the user can quit out of the game*/
    Menu menu(&testScene);
    QSignalSpy spy(menu.returnQuitButton(), SIGNAL(clicked()));
    QTest::mouseClick(menu.returnQuitButton(), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QCOMPARE(spy.count(), 1);
}

void UserInterface::testOnePlayerMainMenuButton() {
/*Test that the user go back to the main menu from one player mode*/
    SinglePlayerGame computerGame(&testScene, true);
    QSignalSpy spy(computerGame.returnMainMenu(), SIGNAL(clicked()));
    QTest::mouseClick(computerGame.returnMainMenu(), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QCOMPARE(spy.count(), 1);
}

void UserInterface::testTwoPlayerMainMenuButton() {
/*Test that the user go back to the main menu from two player mode*/
    Game game(&testScene);
    QSignalSpy spy(game.returnMainMenu(), SIGNAL(clicked()));
    QTest::mouseClick(game.returnMainMenu(), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QCOMPARE(spy.count(), 1);
}

QTEST_MAIN(UserInterface)


