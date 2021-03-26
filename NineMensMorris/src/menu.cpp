#include <include/menu.h>

Menu::Menu(QGraphicsScene *scene){
    this->scene = scene;
    mainMenuScreen();
}
void Menu::mainMenuScreen()
{
    //Declaring the button and title and background
    QGraphicsTextItem* gameTitle = new QGraphicsTextItem(QString("Nine Mens Morris"));
    QFont titleFont("comic sans MS", 50);
    QFont buttonFont("comic sans MS", 14);
    QPixmap pizmap(":/images/media/chimp.jpg");
    int height = 250;
    int width = scene->width()/2 - gameTitle->boundingRect().width()/2 + 300;

    //instantiate the items
    twoPlayerButton = new QPushButton(QString("2-Player"),NULL);
    computerButton = new QPushButton(QString("1-Player"), NULL);
    quitButton = new QPushButton(QString("Quit"),NULL);

    //set the font of the graphics items
    gameTitle->setFont(titleFont);
    computerButton->setFont(buttonFont);
    twoPlayerButton->setFont(buttonFont);
    quitButton->setFont(buttonFont);

    //set the positioning of each item
    pizmap = pizmap.scaled(1100,900, Qt::IgnoreAspectRatio);
    gameTitle->setPos(width,height);
    twoPlayerButton->setStyleSheet("background-color: brown; border-style: outset; border-width: 2px; border-radius: 3px; border-color: yellow; padding: 6px;");
    computerButton->setStyleSheet("background-color: brown; border-style: outset; border-width: 2px; border-radius: 3px; border-color: yellow; padding: 6px;");
    quitButton->setStyleSheet("background-color: brown; border-style: outset; border-width: 2px; border-radius: 3px; border-color: yellow; padding: 6px;");
    computerButton->setGeometry(width+200,height+150,150,70);
    twoPlayerButton->setGeometry(width+200,height+225,150,70);
    quitButton->setGeometry(width+200,height+300,150,70);

    //add items to the scene
    scene->addPixmap(pizmap);
    scene->addItem(gameTitle);
    scene->addWidget(twoPlayerButton);
    scene->addWidget(quitButton);
    scene->addWidget(computerButton);
}
