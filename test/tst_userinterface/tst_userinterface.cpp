#include "tst_userinterface.h"

void UserInterface::testMainMenuAndSplashScene() {
/*Test that the main menu is the active scene*/
    GameManager manager(true);
    QCOMPARE(manager.testSplashSceneActive(), true);
    QTest::qWait(1);
    QCOMPARE(manager.testMenuSceneActive(), true);
}

void UserInterface::testOnePlayerScreen() {
/*Test that the user will be sent to the one player screen*/
    GameManager manager(true);
    QTest::qWait(1);
    QSignalSpy spy(manager.returnMenu()->returnSinglePlayerPushButton(), SIGNAL(clicked()));
    QCOMPARE(manager.testMenuSceneActive(), true);
    QCOMPARE(spy.count(), 0);
    QTest::mouseClick(manager.returnMenu()->returnSinglePlayerPushButton(), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QCOMPARE(spy.count(), 1);
    QCOMPARE(manager.testSinglePlayerSceneActive(), true);
}

void UserInterface::testTwoPlayerScreen() {
/*Test that the user will be sent to the two player screen*/
    GameManager manager(true);
    QTest::qWait(1);
    QSignalSpy spy(manager.returnMenu()->returnTwoPlayerPushButton(), SIGNAL(clicked()));
    QCOMPARE(manager.testMenuSceneActive(), true);
    QCOMPARE(spy.count(), 0);
    QTest::mouseClick(manager.returnMenu()->returnTwoPlayerPushButton(), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QCOMPARE(spy.count(), 1);
    QCOMPARE(manager.testGameSceneActive(), true);
}


void UserInterface::testTutorialScreen() {
/*Test that the user will be sent to the tutorial screen*/
    GameManager manager(true);
    QTest::qWait(1);
    QSignalSpy spy(manager.returnMenu()->returnTutorialPushButton(), SIGNAL(clicked()));
    QCOMPARE(manager.testMenuSceneActive(), true);
    QCOMPARE(spy.count(), 0);
    QTest::mouseClick(manager.returnMenu()->returnTutorialPushButton(), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QCOMPARE(spy.count(), 1);
    QCOMPARE(manager.testTutorialSceneActive(), true);
}

void UserInterface::testQuitButton() {
/*Test that the user can quit out of the game*/
    GameManager manager(true);
    QTest::qWait(1);
    QSignalSpy spy(manager.returnMenu()->returnQuitButton(), SIGNAL(clicked()));
    QCOMPARE(manager.testMenuSceneActive(), true);
    QCOMPARE(spy.count(), 0);
    QTest::mouseClick(manager.returnMenu()->returnQuitButton(), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QCOMPARE(spy.count(), 1);
    QCOMPARE(manager.testQuit(), true);
}

void UserInterface::testOnePlayerMainMenuButton() {
/*Test that the user go back to the main menu from one player mode*/
    GameManager manager(true);
    QTest::qWait(1);
    QCOMPARE(manager.testMenuSceneActive(), true);
    QTest::mouseClick(manager.returnMenu()->returnSinglePlayerPushButton(), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QCOMPARE(manager.testSinglePlayerSceneActive(), true);
    SinglePlayerGame computerGame(manager.returnSinglePlayerScene(), true);
    QSignalSpy spy(computerGame.returnMainMenu(), SIGNAL(clicked()));
    QCOMPARE(spy.count(), 0);
    QTest::mouseClick(computerGame.returnMainMenu(), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QCOMPARE(spy.count(), 1);
    manager.testSwitchBackToMainMenu(true);
    QCOMPARE(manager.testMenuSceneActive(), true);
}

void UserInterface::testTwoPlayerMainMenuButton() {
/*Test that the user go back to the main menu from two player mode*/
    GameManager manager(true);
    QTest::qWait(1);
    QCOMPARE(manager.testMenuSceneActive(), true);
    QTest::mouseClick(manager.returnMenu()->returnTwoPlayerPushButton(), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QCOMPARE(manager.testGameSceneActive(), true);
    Game game(manager.returnTwoPlayerScene());
    QSignalSpy spy(game.returnMainMenu(), SIGNAL(clicked()));
    QCOMPARE(spy.count(), 0);
    QTest::mouseClick(game.returnMainMenu(), Qt::LeftButton, Qt::KeyboardModifiers(), QPoint(10, 10));
    QCOMPARE(spy.count(), 1);
    manager.testSwitchBackToMainMenu(false);
    QCOMPARE(manager.testMenuSceneActive(), true);
}

QTEST_MAIN(UserInterface)

