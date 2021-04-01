#include "include/gamemanager.h"

GameManager::GameManager() {
    //setting up the splash screen scene
    Splash splash(&splashScene);
    view.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view.resize(1100,900);
    view.setScene(&splashScene);
    view.show();



    //setting up the menu scene
    QTimer::singleShot(5000, this, SLOT(timerComplete()));
}

void GameManager::switchTutorialScreen() {
    Tutorial tutorial(&tutorialScene);

    view.setScene(&tutorialScene);
    view.show();

    connect(tutorial.returnPushButton(),SIGNAL(clicked()),this,SLOT(switchTwoPlayerMode()));
}

void GameManager::switchTwoPlayerMode() {
    //instantiating the game with scene
    game = new Game(&gameScene);
    view.setScene(&gameScene);
}

void GameManager::switchComputerPlayerMode() {
    //instantiating the single player game with scene
    computerGame = new SinglePlayerGame(&gameScene, true);
    view.setScene(&gameScene);
}

void GameManager::timerComplete(){
    Menu menu(&menuScene);
    view.setScene(&menuScene);
    view.show();

    //Connecting the button to the library signal clicked, along with the slot switchTwoPlayerMode
    connect(menu.returnTwoPlayerPushButton(),SIGNAL(clicked()),this,SLOT(switchTutorialScreen()));
    connect(menu.returnSinglePlayerPushButton(), SIGNAL(clicked()), this, SLOT(switchComputerPlayerMode()));
    connect(menu.returnQuitButton(),SIGNAL(clicked()),qApp,SLOT(quit()));
}
