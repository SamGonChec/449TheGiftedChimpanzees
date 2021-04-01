#include "include/singleplayerscreen.h"

SinglePlayerScreen::SinglePlayerScreen(QGraphicsScene *scene) {
    this->scene = scene;
    SinglePlayerScene();
}

void SinglePlayerScreen::SinglePlayerScene() {
    /* Declaring the button, title, and tutorial text */
    QFile file(":/text/tutorial.txt");
    file.open(QFile::ReadOnly | QFile::Text);

    //Instantiate items
    QGraphicsTextItem* tutorialTitleDisplay = scene->addText("Tutorial");
    QGraphicsTextItem* tutorialTextDisplay = scene->addText(file.readAll());
    whiteButton = new QPushButton(QString("White"),NULL);
    whiteButton = new QPushButton(QString("Black"),NULL);
    QFont titleFont("comic sans MS", 30);
    QFont tutorialFont("comic sans MS", 10);
    QFont buttonFont("comic sans MS", 14);

    whiteButton->setFont(buttonFont);
    blackButton->setFont(buttonFont);
    whiteButton->setStyleSheet("background-color: brown; color: #00DCDC; border-style: outset; border-width: 2px; border-radius: 3px; border-color: yellow; padding: 6px;");
    blackButton->setStyleSheet("background-color: brown; color: #00DCDC; border-style: outset; border-width: 2px; border-radius: 3px; border-color: yellow; padding: 6px;");
    whiteButton->setGeometry(325,650,150,70);
    blackButton->setGeometry(525,650,150,70);

    scene->addWidget(whiteButton);
    scene->addWidget(blackButton);
}
