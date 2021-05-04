#include <QtTest>

// add necessary includes here

class computerlogic : public QObject
{
    Q_OBJECT

public:
    computerlogic();
    ~computerlogic();

private slots:
    void test_case1();

};

computerlogic::computerlogic()
{

}

computerlogic::~computerlogic()
{

}

void computerlogic::test_case1()
{

}

QTEST_APPLESS_MAIN(computerlogic)

#include "tst_computerlogic.moc"
