#include "tst_userinterface.h"

void UserInterface::testMainMenuAndSplashScene() {
/*Test that the main menu is the active scene*/
    GameManager manager;
    QCOMPARE(manager.testSplashSceneActive(), true);
    QTest::qWait(5500);
    QCOMPARE(manager.testMenuSceneActive(), true);
}

void UserInterface::testOnePlayerScreen() {
/*Test that the user will be sent to the one player screen*/
    Menu menu(&testScene);
    QSignalSpy spy(menu.returnSinglePlayerPushButton(), SIGNAL(clicked()));
    QCOMPARE(spy.count(), 0);
    QTest::mouseClick(menu.returnSinglePlayerPushButton(), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QCOMPARE(spy.count(), 1);
}

void UserInterface::testTwoPlayerScreen() {
/*Test that the user will be sent to the two player screen*/
    Menu menu(&testScene);
    QSignalSpy spy(menu.returnTwoPlayerPushButton(), SIGNAL(clicked()));
    QCOMPARE(spy.count(), 0);
    QTest::mouseClick(menu.returnTwoPlayerPushButton(), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QCOMPARE(spy.count(), 1);
}

void UserInterface::testTutorialScreen() {
/*Test that the user will be sent to the tutorial screen*/
    Menu menu(&testScene);
    QSignalSpy spy(menu.returnTutorialPushButton(), SIGNAL(clicked()));
    QCOMPARE(spy.count(), 0);
    QTest::mouseClick(menu.returnTutorialPushButton(), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QCOMPARE(spy.count(), 1);
}

void UserInterface::testQuitButton() {
/*Test that the user can quit out of the game*/
    Menu menu(&testScene);
    QSignalSpy spy(menu.returnQuitButton(), SIGNAL(clicked()));
    QCOMPARE(spy.count(), 0);
    QTest::mouseClick(menu.returnQuitButton(), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QCOMPARE(spy.count(), 1);
}

void UserInterface::testOnePlayerMainMenuButton() {
/*Test that the user go back to the main menu from one player mode*/
    SinglePlayerGame computerGame(&testScene, true);
    QSignalSpy spy(computerGame.returnMainMenu(), SIGNAL(clicked()));
    QCOMPARE(spy.count(), 0);
    QTest::mouseClick(computerGame.returnMainMenu(), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QCOMPARE(spy.count(), 1);
}

void UserInterface::testTwoPlayerMainMenuButton() {
/*Test that the user go back to the main menu from two player mode*/
    Game game(&testScene);
    QSignalSpy spy(game.returnMainMenu(), SIGNAL(clicked()));
    QCOMPARE(spy.count(), 0);
    QTest::mouseClick(game.returnMainMenu(), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QCOMPARE(spy.count(), 1);
}

QTEST_MAIN(UserInterface)


