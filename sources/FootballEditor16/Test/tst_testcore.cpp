#include <QString>
#include <QtTest>

class TestCore : public QObject
{
    Q_OBJECT

public:
    TestCore();

private Q_SLOTS:
    void testCase1();
};

TestCore::TestCore()
{
}

void TestCore::testCase1()
{
    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(TestCore)

#include "tst_testcore.moc"
