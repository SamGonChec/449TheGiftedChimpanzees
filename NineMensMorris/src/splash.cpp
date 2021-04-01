#include "include/splash.h"

Splash::Splash(QGraphicsScene *scene){
    this->scene = scene;
    splashScreen();
}

void Splash::splashScreen()
{
    // Declaring background image and text.
    QGraphicsTextItem* teamName = new QGraphicsTextItem(QString("The Gifted Chimpanzees"));
    QFont nameFont("comic sans MS", 50);
    splashBackground = QPixmap(":/images/media/chimp.jpg");
    int height = 250;
    int width = scene->width()/2 - teamName->boundingRect().width()/2 + 300;

    // sets the font, style, and color of the text
    teamName->setFont(nameFont);
    teamName->setDefaultTextColor(QColor("#00DCDC"));

    // sets the background and text positionining. Will change later after
    // proper testing and display
    splashBackground = splashBackground.scaled(1100,900, Qt::IgnoreAspectRatio);
    teamName->setPos(width,height);


    // adds the items to the scene
    scene->addPixmap(splashBackground);
    // scene->setBackgroundBrush(QBrush("Blue"));
    scene->addItem(teamName);
}
