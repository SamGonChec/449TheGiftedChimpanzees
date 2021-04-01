#include "include/gamemanager.h"

GameManager::GameManager() {
    //setting up the menu scene
    Menu menu(&menuScene);

    view.resize(1100,900);
    view.setScene(&menuScene);
    view.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view.show();

    //Connecting the button to the library signal clicked, along with the slot switchTwoPlayerMode
    connect(menu.returnTwoPlayerPushButton(),SIGNAL(clicked()),this,SLOT(switchTwoPlayerMode()));
    connect(menu.returnSinglePlayerPushButton(), SIGNAL(clicked()), this, SLOT(switchSinglePlayerScreen()));
    connect(menu.returnTutorialPushButton(), SIGNAL(clicked()), this, SLOT(switchTutorialScreen()));
    connect(menu.returnQuitButton(),SIGNAL(clicked()),qApp,SLOT(quit()));
}

void GameManager::switchSinglePlayerScreen() {
    SinglePlayerScreen singlePlayer(&singlePlayerScene);

    view.setScene(&singlePlayerScene);
    view.show();

    connect(singlePlayer.returnWhiteButton(),SIGNAL(clicked()),this,SLOT(switchComputerPlayerModeWhite()));
    connect(singlePlayer.returnBlackButton(),SIGNAL(clicked()),this,SLOT(switchComputerPlayerModeBlack()));
}
void GameManager::switchTutorialScreen() {
    Tutorial tutorial(&tutorialScene);

    view.setScene(&tutorialScene);
    view.show();

    connect(tutorial.returnPushButton(),SIGNAL(clicked()),this,SLOT(switchBackToMainMenu()));
}

void GameManager::switchTwoPlayerMode() {
    //instantiating the game with scene
    game = new Game(&gameScene);
    view.setScene(&gameScene);
    connect(game->returnMainMenu(),SIGNAL(clicked()),this,SLOT(switchBackToMainMenuTwoPlayer()));

}

void GameManager::switchComputerPlayerModeWhite() {
    //instantiating the single player game with scene
    computerGame = new SinglePlayerGame(&gameScene,false);
    view.setScene(&gameScene);
    connect(computerGame->returnMainMenu(),SIGNAL(clicked()),this,SLOT(switchBackToMainMenuSinglePlayer()));
}

void GameManager::switchComputerPlayerModeBlack() {
    //instantiating the single player game with scene
    computerGame = new SinglePlayerGame(&gameScene,true);
    view.setScene(&gameScene);
    connect(computerGame->returnMainMenu(),SIGNAL(clicked()),this,SLOT(switchBackToMainMenuSinglePlayer()));
}

void GameManager::switchBackToMainMenu() {
    //set the scene back to the menu scene
    view.setScene(&menuScene);
}
void GameManager::switchBackToMainMenuTwoPlayer() {
    //set the scene back to the menu scene
    view.setScene(&menuScene);
    delete game;
}
void GameManager::switchBackToMainMenuSinglePlayer() {
    //set the scene back to the menu scene
    view.setScene(&menuScene);
    delete computerGame;
}
