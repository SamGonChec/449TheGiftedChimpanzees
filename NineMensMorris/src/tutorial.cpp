#include <include/tutorial.h>

Tutorial::Tutorial(QGraphicsScene *scene){
    this->scene = scene;
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
    tutorialButton = new QPushButton(QString("Continue"),NULL);
    QFont titleFont("comic sans MS", 30);
    QFont tutorialFont("comic sans MS", 10);
    QFont buttonFont("comic sans MS", 14);

    //Adjust style of items
    tutorialTitleDisplay->setFont(titleFont);
    tutorialTextDisplay->setFont(tutorialFont);
    tutorialButton->setFont(buttonFont);
    tutorialButton->setStyleSheet("background-color: brown; color: #00DCDC; border-style: outset; border-width: 2px; border-radius: 3px; border-color: yellow; padding: 6px;");

    //Adjust the position
    tutorialTitleDisplay->setPos(325,0);
    tutorialTextDisplay->setPos(50,200);
    tutorialButton->setGeometry(325,650,150,70);

    //add items in the scene
    scene->addWidget(tutorialButton);
}

