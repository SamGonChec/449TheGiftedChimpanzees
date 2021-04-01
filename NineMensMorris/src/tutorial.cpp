#include "include/tutorial.h"

Tutorial::Tutorial(QGraphicsScene *scene, bool computer){
    this->scene = scene;
    this->againstComputer = computer;
    tutorialScreen();
}

void Tutorial::tutorialScreen()
{
    /* Declaring the button, title, and tutorial text */
    QFile file(":/text/tutorial.txt");
    file.open(QFile::ReadOnly | QFile::Text);

    //Instantiate items
    QGraphicsTextItem* tutorialTitleDisplay = scene->addText("Tutorial");
    QGraphicsTextItem* tutorialTextDisplay = scene->addText(file.readAll());
    QFont titleFont("comic sans MS", 30);
    QFont tutorialFont("comic sans MS", 10);
    QFont buttonFont("comic sans MS", 14);

    //set tutorial text font
    tutorialTitleDisplay->setFont(titleFont);
    tutorialTextDisplay->setFont(tutorialFont);

    //set tutorial text position
    tutorialTitleDisplay->setPos(325,0);
    tutorialTextDisplay->setPos(50,200);

    if(againstComputer==true) {

        //declare buttons
        whiteButton = new QPushButton(QString("White"),NULL);
        blackButton = new QPushButton(QString("Black"),NULL);

        //declare the choose color text
        QGraphicsTextItem *chooseColor = scene->addText("Choose the piece color to play");
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
    else {
        //declare button in two players
        tutorialButton = new QPushButton(QString("Continue"),NULL);
        tutorialButton->setFont(buttonFont);
        tutorialButton->setStyleSheet("background-color: brown; color: #00DCDC; border-style: outset; border-width: 2px; border-radius: 3px; border-color: yellow; padding: 6px;");
        tutorialButton->setGeometry(325,650,150,70);
        scene->addWidget(tutorialButton);
    }

}

