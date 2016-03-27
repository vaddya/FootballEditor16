#include <QString>
#include <QtTest>
#include "vector"

#include "team.h"
#include "competition.h"
#include "groupstage.h"
#include "group.h"

using namespace std;

class TestCore : public QObject
{
    Q_OBJECT

public:
    TestCore();
    vector<Team> teams { Team("Belgium", 1506), Team("Spain", 1374), Team("Germany", 1355), Team("Portugal", 1234),
                         Team("England", 1112), Team("Austria", 1095), Team("Switzerland", 1070), Team("Italy", 999),
                         Team("Netherlands", 997), Team("Romania", 990), Team("Croatia", 965), Team("Hungary", 951),
                         Team("Turkey", 943), Team("Russia", 892), Team("France", 871), Team("Slovakia", 858) };
private Q_SLOTS:
    void competitionTest();
    void groupStageTest();
    void groupTest();
    void matchTest();
    void teamTest();
    void teamStatTest();

    //TODO other tests
};

TestCore::TestCore() {}

void TestCore::competitionTest()
{
    Competition comp;
    comp.setTitle("EURO 2016");
    comp.addTeam("Russia", 892);
    comp.addTeam("France");

    QCOMPARE(comp.getTeams()[0].getName().c_str(), "Russia");
    QVERIFY(comp.getTeams()[0].getFifaPoints() == 892);
    QCOMPARE(comp.getTeams()[1].getName().c_str(), "France");
    QVERIFY(comp.getTeams()[1].getFifaPoints() == 0);
    QVERIFY(comp.getNumberOfTeams() == (unsigned)2);
    QCOMPARE(comp.getTitle().c_str(), "EURO 2016");
}

void TestCore::groupStageTest()
{
    GroupStage groupstage(teams);
    groupstage.launch();
    QVERIFY(groupstage.getNumberOfGroups() == (unsigned)4);
    QVERIFY(groupstage.getGroups().size() == (unsigned long)4);
}

void TestCore::groupTest()
{
    vector<Team> fourteams { teams[0], teams[1], teams[2], teams[3] };
    QVERIFY(fourteams.size() == (unsigned long)4);
    Group group(fourteams, 'A');
    group.createMatches();
    QVERIFY(group.getMatches().size() == (unsigned long)6);
}

void TestCore::matchTest()
{
    Match match(teams[0], teams[1]);
    QCOMPARE(match.getFirstTeam().getName().c_str(), teams[0].getName().c_str());
    QCOMPARE(match.getSecondTeam().getName().c_str(), teams[1].getName().c_str());
    match.getFirstTeam().setGoals(3);
    match.getSecondTeam().setGoals(2);
    QVERIFY(match.getFirstTeam().getGoals() == 3);
    QVERIFY(match.getSecondTeam().getGoals() == 2);
    //TODO class match will expand
}

void TestCore::teamTest()
{
    Team team("Ukraine", 900);
    QCOMPARE(team.getName().c_str(), "Ukraine");
    QVERIFY(team.getFifaPoints() == 900);
    Team team2(team);
    QCOMPARE(team2.getName().c_str(), "Ukraine");
    QVERIFY(team2.getFifaPoints() == 900);
}

void TestCore::teamStatTest()
{
    //TODO implement
}

QTEST_APPLESS_MAIN(TestCore)

#include "tst_testcore.moc"
