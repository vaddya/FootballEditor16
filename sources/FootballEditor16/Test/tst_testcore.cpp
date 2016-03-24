#include <QString>
#include <QtTest>
#include "vector"
#include "team.h"
#include "competition.h"

using namespace std;

class TestCore : public QObject
{
    Q_OBJECT

public:
    TestCore();

private Q_SLOTS:
    void TestCompetition();
    void TestGroupStage();
    //TODO other tests
};

TestCore::TestCore() {}

void TestCore::TestCompetition()
{
    vector<Team> teams;
    teams.push_back(Team("Russia", 892));
    teams.push_back(Team("France", 872));

    Competition comp(2);
    comp.setTitle("EURO 2016");
    comp.setListOfTeams(teams);

    QCOMPARE(comp.getTeams()[0].getName().c_str(), "Russia");
    QCOMPARE(comp.getTeams()[0].getFifaPoints(), 892);
    QCOMPARE(comp.getTeams()[1].getName().c_str(), "France");
    QCOMPARE(comp.getTeams()[1].getFifaPoints(), 872);
    QCOMPARE(comp.getNumberOfTeams(), 2);
    QCOMPARE(comp.getTitle().c_str(), "EURO 2016");
}

void TestCore::TestGroupStage()
{
    //TODO implement test
}

QTEST_APPLESS_MAIN(TestCore)

#include "tst_testcore.moc"
