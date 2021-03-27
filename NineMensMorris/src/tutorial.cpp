#include "include/tutorial.h"

Tutorial::Tutorial(QGraphicsScene *scene){
    this->scene = scene;
    tutorialScreen();
}

void Tutorial::tutorialScreen()
{
    /* Declaring the button, title, and tutorial text */
    QFile file(":/text/tutorial.txt");
    file.open(QFile::ReadOnly | QFile::Text);

    QGraphicsTextItem* tutorialTitleDisplay = scene->addText("Tutorial");
    QGraphicsTextItem* tutorialTextDisplay = scene->addText(file.readAll());

    QFont titleFont("comic sans MS", 30);
    QFont tutorialFont("comic sans MS", 10);
    QFont buttonFont("comic sans MS", 14);

    tutorialTitleDisplay->setFont(titleFont);
    tutorialTitleDisplay->setPos(325,0);

    tutorialTextDisplay->setFont(tutorialFont);
    tutorialTextDisplay->setPos(50,200);

    tutorialButton = new QPushButton(QString("Exit Tutorial"),NULL);
    tutorialButton->setFont(buttonFont);
    tutorialButton->setGeometry(325,650,150,70);
    scene->addWidget(tutorialButton);
}

