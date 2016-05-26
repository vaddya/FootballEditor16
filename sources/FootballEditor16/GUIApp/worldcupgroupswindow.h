#ifndef WORLDCUPGROUPSWINDOW_H
#define WORLDCUPGROUPSWINDOW_H

#include <QMainWindow>
#include "QList"
#include "QListWidgetItem"
#include "competition.h"
#include "QCheckBox"
#include "QGroupBox"
#include "QVBoxLayout"
#include "warningdialog.h"

namespace Ui {
class WorldCupGroupsWindow;
}

class WorldCupGroupsWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit WorldCupGroupsWindow(QWidget *parent = 0);
    ~WorldCupGroupsWindow();

    void setSettings(QString title, QList<QListWidgetItem*> teams);

private slots:

    void startGroupStage();

    void saveResults();

    void createGroup();

    void generateGroups();

    void simulateMatches();

    void simulateAllMatches();

private:
    Ui::WorldCupGroupsWindow *ui;

    Competition *comp;
    QVector<QString> teams;
    bool isGenerated;

    void drawCreateGroups();
    void drawGroupStage();
    void sizeTableGroupStage();
    void drawTablesGroupStage();
    void drawMatchesGroupStage();
    void redrawTableGroupStage(char groupId);
};

#endif // WORLDCUPGROUPSWINDOW_H
