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
};

TestCore::TestCore() {}

void TestCore::TestCompetition()
{
    vector<Team> teams(1);
    string teamname = "Russia";
    string compname = "EURO 2016";
    teams[0] = Team(teamname, 3);

    Competition competition(16);
    competition.setTitle(compname);
    competition.setListOfTeams(teams);

    QCOMPARE(competition.getTitle(), compname);
}

QTEST_APPLESS_MAIN(TestCore)

#include "tst_testcore.moc"
