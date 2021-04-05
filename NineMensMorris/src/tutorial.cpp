#include "include/tutorial.h"

Tutorial::Tutorial(QGraphicsScene *scene){
/* Constructor for Tutorial class */
    this->scene = scene;
    tutorialScreen();
}

void Tutorial::tutorialScreen() {
    /* Declaring the button, title, and tutorial text */
    QFile file(":/text/tutorial.txt");
    file.open(QFile::ReadOnly | QFile::Text);

    //Instantiate items
    QGraphicsTextItem* tutorialTitleDisplay = scene->addText("Tutorial");
    QGraphicsTextItem* tutorialTextDisplay = scene->addText(file.readAll());
    QFont titleFont("comic sans MS", 30);
    QFont tutorialFont("comic sans MS", 10);
    QFont buttonFont("comic sans MS", 14);

    //set background color
    scene->setBackgroundBrush(QBrush(Qt::darkGray));

    //set tutorial text font
    tutorialTitleDisplay->setFont(titleFont);
    tutorialTextDisplay->setFont(tutorialFont);

    //set tutorial text position
    tutorialTitleDisplay->setPos(325,0);
    tutorialTextDisplay->setPos(50,200);


    //declare button in two players
    tutorialButton = new QPushButton(QString("Main Menu"),NULL);
    tutorialButton->setFont(buttonFont);
    tutorialButton->setStyleSheet("background-color: brown; color: #00DCDC; border-style: outset; border-width: 2px; border-radius: 3px; border-color: yellow; padding: 6px;");
    tutorialButton->setGeometry(325,650,150,70);
    scene->addWidget(tutorialButton);

}

