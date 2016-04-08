#include <QString>
#include <QtTest>
#include "vector"

#include "team.h"
#include "competition.h"
#include "groupstage.h"
#include "group.h"
#include "teamingroup.h"

using namespace std;

class TestCore : public QObject
{
    Q_OBJECT

public:
    TestCore();
    vector<Team> teams { Team("Belgium"), Team("Spain"), Team("Germany"), Team("Portugal"),
                         Team("England"), Team("Austria"), Team("Switzerland"), Team("Italy"),
                         Team("Netherlands"), Team("Romania"), Team("Croatia"), Team("Hungary"),
                         Team("Turkey"), Team("Russia"), Team("France"), Team("Slovakia") };
private Q_SLOTS:
    void competitionTest();
    void groupStageTest();
    void teamTest();
    void teamStatTest();
    void teamInGroupTest();
    void groupTest();
    void matchTest();

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
    TeamStat teamstat(teams[0]);
    teamstat.setGoals(3);
    QVERIFY(teamstat.getGoals() == 3);
    teamstat.setPossession(67);
    QVERIFY(teamstat.getPossession() == 67);
}

void TestCore::teamInGroupTest()
{
    TeamInGroup teamInGroup(teams[0]);
    teamInGroup.setPoints(9);
    QVERIFY(teamInGroup.getPoints() == 9);
    teamInGroup.increasePoints(3);
    QVERIFY(teamInGroup.getPoints() == 12);
}

void TestCore::groupTest()
{
    // Test initialisation
    Group group('A');
    group.addTeam(teams[0]);
    group.addTeam(teams[1]);
    group.addTeam(teams[2]);
    group.addTeam(teams[3]);
    group.createMatches();
    QVERIFY(group.getMatches().size() == (unsigned long)6);

    // Test sorting
    int points = 0;
    for( TeamInGroup &team: group.getTeams() ) {
        team.setPoints(points);
        points += 3; // 4 teams with 0 3 6 and 9 points
    }
    QCOMPARE(group.getTeams()[0].getPoints(), 0);
    group.sort();
    QCOMPARE(group.getTeams()[0].getPoints(), 9);
}

void TestCore::matchTest()
{
    TeamInGroup firstTeam(teams[0]);
    TeamInGroup secondTeam(teams[1]);
    Match match(firstTeam, secondTeam);
    QCOMPARE(match.getFirstTeam().getName().c_str(), teams[0].getName().c_str());
    QCOMPARE(match.getSecondTeam().getName().c_str(), teams[1].getName().c_str());
    match.setResult(3, 2);
    QVERIFY(match.getFirstTeam().getGoals() == 3);
    QVERIFY(match.getSecondTeam().getGoals() == 2);
    QCOMPARE(match.getResult().c_str(), "3:2");
}

QTEST_APPLESS_MAIN(TestCore)

#include "tst_testcore.moc"
