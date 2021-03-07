#include <include/menu.h>

Menu::Menu(QGraphicsScene *scene){
    this->scene = scene;
    mainMenuScreen();
}
void Menu::mainMenuScreen()
{
    /* Declaring the button and title */
    QGraphicsTextItem* gameTitle = new QGraphicsTextItem(QString("Nine Mens Morris"));
    QFont titleFont("comic sans", 50);
    QFont buttonFont("comic sans", 14);
    gameTitle->setFont(titleFont);
    gameTitle->setPos(500,50);
    twoPlayerButton = new QPushButton(QString("2-Players"),NULL);
    twoPlayerButton->setFont(buttonFont);
    twoPlayerButton->setGeometry(670,275,150,70);
    scene->addItem(gameTitle);
    scene->addWidget(twoPlayerButton);

}
void Menu::mousePressEvent(QGraphicsSceneMouseEvent *event){
    emit buttonClicked();
}
