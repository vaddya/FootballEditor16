#include <QString>
#include <QtTest>
#include "team.h"
#include "competition.h"

using namespace std;

class TestCore : public QObject
{
    Q_OBJECT

public:
    TestCore();

private Q_SLOTS:
    void CompetitionSettings();
    void TestGroupStage();
    //TODO other tests
};

TestCore::TestCore() {}

void TestCore::CompetitionSettings()
{
    Competition comp;
    comp.setTitle("EURO 2016");
    comp.addTeam("Russia", 1000);
    comp.addTeam("France");

    QCOMPARE(comp.getTeams()[0].getName(), string("Russia"));
    QCOMPARE(comp.getTeams()[0].getFifaPoints(), 1000);
    QCOMPARE(comp.getTeams()[1].getName(), string("France"));
    QCOMPARE(comp.getTeams()[1].getFifaPoints(), 0);

    QCOMPARE(comp.getNumberOfTeams(), (size_t)2);
    QCOMPARE(comp.getTitle().c_str(), "EURO 2016");
}

void TestCore::TestGroupStage()
{
    //TODO implement test
}

QTEST_APPLESS_MAIN(TestCore)

#include "tst_testcore.moc"
