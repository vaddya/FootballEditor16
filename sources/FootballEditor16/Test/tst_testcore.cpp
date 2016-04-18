#include <QString>
#include <QtTest>
#include "vector"

#include "competition.h"
#include "groupstage.h"
#include "group.h"
#include "team.h"
#include "teamingroup.h"
#include "teamstat.h"
#include "match.h"

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
    Competition *comp = new Competition();
    comp->setTitle("EURO 2016");
    comp->addTeam("France");

    QCOMPARE(comp->getTeams()[0].getName().c_str(), "France");
    QVERIFY(comp->getNumberOfTeams() == (unsigned)1);
    QCOMPARE(comp->getTitle().c_str(), "EURO 2016");

    delete comp;
}

void TestCore::groupStageTest()
{
    GroupStage *groupstage = new GroupStage(teams);
    groupstage->launch();
    QVERIFY(groupstage->getNumberOfGroups() == (unsigned)4);
    QVERIFY(groupstage->getGroups().size() == (unsigned long)4);

    delete groupstage;
}

void TestCore::teamTest()
{
    // not existed team
    Team *team = new Team("Ukraine");
    QCOMPARE(team->getName().c_str(), "Ukraine");

    // existed team
    Team *team2 = new Team(*team);
    QCOMPARE(team2->getName().c_str(), "Ukraine");

    delete team;
    delete team2;
}

void TestCore::teamStatTest()
{
    TeamStat *teamstat = new TeamStat(teams[0]);
    teamstat->setGoalsFor(3);
    QVERIFY(teamstat->getGoalsFor() == 3);
    teamstat->setPossession(67);
    QVERIFY(teamstat->getPossession() == 67);

    delete teamstat;
}

void TestCore::teamInGroupTest()
{
    TeamInGroup *teamInGroup = new TeamInGroup(teams[0]);
    teamInGroup->win();
    QVERIFY(teamInGroup->getPoints() == 3);

    delete teamInGroup;
}

void TestCore::groupTest()
{
    // Test initialisation
    Group *group = new Group();
    group->addTeam(teams[0]);
    group->addTeam(teams[1]);
    group->addTeam(teams[2]);
    group->addTeam(teams[3]);
    group->createMatches();
    QVERIFY(group->getMatches().size() == (unsigned long)6);

    // Test sorting
    int i = 0;
    for( TeamInGroup &team: group->getTeams() ) {
        for( int j = 0; j < i; j++ )
            team.win(); // 0 3 6 9
        ++i;
    }
    QVERIFY(group->getTeams()[0].getPoints() == 0);
    group->sort(); // now 9 6 3 0
    QVERIFY(group->getTeams()[0].getPoints() == 9);
    QVERIFY(group->getTeams()[0].getGames() == 3);
    QVERIFY(group->getTeams()[0].getWins() == 3);
    QVERIFY(group->getTeams()[2].getWins() == 1);

    delete group;
}

void TestCore::matchTest()
{
    TeamInGroup *firstTeam = new TeamInGroup(teams[0]);
    TeamInGroup *secondTeam = new TeamInGroup(teams[1]);
    Match *match = new Match(*firstTeam, *secondTeam);

    QCOMPARE(match->getFirstTeam().getName().c_str(), teams[0].getName().c_str());
    QCOMPARE(match->getSecondTeam().getName().c_str(), teams[1].getName().c_str());
    match->setResult(3, 2);
    QVERIFY(match->getFirstTeam().getGoalsFor() == 3);
    QVERIFY(match->getSecondTeam().getGoalsFor() == 2);
    QCOMPARE(match->getResult().c_str(), "3:2");

    delete firstTeam;
    delete secondTeam;
    delete match;
}

QTEST_APPLESS_MAIN(TestCore)

#include "tst_testcore.moc"
