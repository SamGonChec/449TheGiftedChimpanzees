#include "include/singleplayerscreen.h"

//constructor for the class single player screen.
SinglePlayerScreen::SinglePlayerScreen(QGraphicsScene *scene) {
    this->scene = scene;
    displaySinglePlayerScreen();
}

//Method that displays the scene with a prompt to choose which color to play.
void SinglePlayerScreen::displaySinglePlayerScreen() {

    //Instantiate items
    QFont buttonFont("comic sans MS", 14);
    whiteButton = new QPushButton(QString("White"),NULL);
    blackButton = new QPushButton(QString("Black"),NULL);

    //declare the choose color text
    QGraphicsTextItem *chooseColor = scene->addText("Choose Color: ");
    QFont chooseFont("comic sans MS", 14);
    chooseColor->setFont(chooseFont);
    chooseColor->setPos(275,550);

    //set the font for the buttons
    whiteButton->setFont(buttonFont);
    blackButton->setFont(buttonFont);

    //set the style for the buttons
    whiteButton->setStyleSheet("background-color: brown; color: #00DCDC; border-style: outset; border-width: 2px; border-radius: 3px; border-color: yellow; padding: 6px;");
    blackButton->setStyleSheet("background-color: brown; color: #00DCDC; border-style: outset; border-width: 2px; border-radius: 3px; border-color: yellow; padding: 6px;");

    //set the position for the buttons
    whiteButton->setGeometry(225,650,150,70);
    blackButton->setGeometry(425,650,150,70);

    //add buttons to the scene
    scene->addWidget(whiteButton);
    scene->addWidget(blackButton);
}
