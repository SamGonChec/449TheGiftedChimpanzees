#ifndef TST_USERINTERFACE_H
#define TST_USERINTERFACE_H
#include <QtTest>
#include <QTest>
#include <QCoreApplication>

class UserInterface : public QObject
{
    Q_OBJECT

public:
    UserInterface() {}
    ~UserInterface() {}

private slots:
    void test_case1();

};
#endif // TST_USERINTERFACE_H
