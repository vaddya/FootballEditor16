#include <QString>
#include <QtTest>

class Test : public QObject
{
    Q_OBJECT

public:
    Test();

private Q_SLOTS:
    void testCase1();
};

Test::Test()
{
}

void Test::testCase1()
{
    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(Test)

#include "tst_test.moc"
