#ifndef TST_COMPUTERLOGIC_H
#define TST_COMPUTERLOGIC_H

#include <QtTest>
#include <QTest>
#include <QCoreApplication>

#include "include/singleplayergame.h"

class ComputerLogic : public QObject
{
    Q_OBJECT

public:
    ComputerLogic() {}
    ~ComputerLogic() {}

private:
    QGraphicsScene testScene;

private slots:
    void testComputerPlacePiece();
    void testComputerPlayerBlock();
};
#endif // TST_COMPUTERLOGIC_H
