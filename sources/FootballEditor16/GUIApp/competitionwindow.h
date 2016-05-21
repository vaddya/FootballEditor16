#ifndef COMPETITIONWINDOW_H
#define COMPETITIONWINDOW_H

#include <QMainWindow>
#include "QList"
#include "QListWidgetItem"
#include "competition.h"
#include "QCheckBox"
#include "QGroupBox"
#include "QVBoxLayout"
#include "warningdialog.h"

namespace Ui {
class CompetitionWindow;
}

enum TeamNum { EURO = 16, WORLDCUP = 32 };

class CompetitionWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CompetitionWindow(QWidget *parent = 0);
    ~CompetitionWindow();

    void setSettings(QString title, QList<QListWidgetItem*> teams);

private slots:

    void startGroupStage();

    void saveResults();

    void createGroup();

    void generateGroups();

private:
    Ui::CompetitionWindow *ui;

    Competition *comp;
    QVector<QString> teams;

    void drawCreateGroups();
    void drawCreate8Groups();

    void drawGroupStage();
    void sizeTableGroupStage();
    void drawTablesGroupStage();
    void drawMatchesGroupStage();
    void redrawTableGroupStage(char groupId);

    bool isGenerated;
    TeamNum teamNum;
};

#endif // COMPETITIONWINDOW_H
