#include "include/gamemanager.h"

GameManager::GameManager(bool wait) {
    int waitTime = 5000;
    //setting up the splash screen scene
    Splash splash(&splashScene);
    view.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view.resize(1920,1080);
    view.setScene(&splashScene);
    view.show();
    if (wait) {
        waitTime = 0;
    }
    //switches to the menu scene when splash completed
    QTimer::singleShot(waitTime, this, SLOT(timerComplete()));

}

//this method handles switching to the single player prompt to asking about what color to play
void GameManager::switchSinglePlayerScreen() {
    SinglePlayerScreen singlePlayer(&singlePlayerScene);

    view.setScene(&singlePlayerScene);
    view.show();

    //these connect handle which game mode to play, as a white player or black
    connect(singlePlayer.returnWhiteButton(),SIGNAL(clicked()),this,SLOT(switchComputerPlayerModeWhite()));
    connect(singlePlayer.returnBlackButton(),SIGNAL(clicked()),this,SLOT(switchComputerPlayerModeBlack()));
}

//this method displays the tutorial screen
void GameManager::switchTutorialScreen() {
    Tutorial tutorial(&tutorialScene);

    view.setScene(&tutorialScene);
    view.show();

    connect(tutorial.returnPushButton(),SIGNAL(clicked()),this,SLOT(switchBackToMainMenu()));
}

//this method sets the game mode to two players
void GameManager::switchTwoPlayerMode() {
    //instantiating the game with scene
    game = new Game(&gameScene);
    view.setScene(&gameScene);
    connect(game->returnMainMenu(),SIGNAL(clicked()),this,SLOT(switchBackToMainMenuTwoPlayer()));
}

//this method begins a single player game with the user being white
void GameManager::switchComputerPlayerModeWhite() {
    //instantiating the single player game with scene
    computerGame = new SinglePlayerGame(&gameScene,false);
    view.setScene(&gameScene);

    //this connect catches the signal if the main menu button is clicked during the game
    connect(computerGame->returnMainMenu(),SIGNAL(clicked()),this,SLOT(switchBackToMainMenuSinglePlayer()));
}

void GameManager::switchComputerPlayerModeBlack() {
    //instantiating the single player game with scene
    computerGame = new SinglePlayerGame(&gameScene,true);
    view.setScene(&gameScene);

    //this connect catches the signal if the main menu button is clicked during the game
    connect(computerGame->returnMainMenu(),SIGNAL(clicked()),this,SLOT(switchBackToMainMenuSinglePlayer()));
}

//during the tutorial screen this method is called to switch back to the main menu
void GameManager::switchBackToMainMenu() {
    //set the scene back to the menu scene
    view.setScene(&menuScene);
}

//during two player mode this method is called to switch back to the main menu
void GameManager::switchBackToMainMenuTwoPlayer() {
    //set the scene back to the menu scene
    view.setScene(&menuScene);
    delete game;
}

//during single player mode this method is called to switch back to the main menu
void GameManager::switchBackToMainMenuSinglePlayer() {
    //set the scene back to the menu scene
    view.setScene(&menuScene);
    delete computerGame;
}

//this method is specifically for first run to allow the splash screen to be visible
void GameManager::timerComplete(){
    menu = new Menu(&menuScene);
    view.setScene(&menuScene);
    view.show();

    //Connecting the button to the library signal clicked, along with the slot switchTwoPlayerMode
    connect(menu->returnTwoPlayerPushButton(),SIGNAL(clicked()),this,SLOT(switchTwoPlayerMode()));
    connect(menu->returnSinglePlayerPushButton(), SIGNAL(clicked()), this, SLOT(switchSinglePlayerScreen()));
    connect(menu->returnTutorialPushButton(), SIGNAL(clicked()), this, SLOT(switchTutorialScreen()));
    connect(menu->returnQuitButton(),SIGNAL(clicked()),qApp,SLOT(quit()));
}

//Used to test the switch back to the main menu
void GameManager::testSwitchBackToMainMenu(bool singlePlayerGame){
    view.setScene(&menuScene);
    //true deletes the computer game and false deletes the two player game
    if (singlePlayerGame) {
        delete computerGame;
    }
    else {
        delete game;
    }
}
