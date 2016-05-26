#ifndef EUROGROUPSWINDOW_H
#define EUROGROUPSWINDOW_H

#include <QMainWindow>
#include "QList"
#include "QListWidgetItem"
#include "competition.h"
#include "QCheckBox"
#include "QGroupBox"
#include "QVBoxLayout"
#include "warningdialog.h"
#include "europlayoffwindow.h"

namespace Ui {
class EuroGroupsWindow;
}

class EuroGroupsWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit EuroGroupsWindow(QWidget *parent = 0);
    ~EuroGroupsWindow();

    void setSettings(QString title, QList<QListWidgetItem*> teams);

private slots:

    void startGroupStage();

    void saveResults();

    void createGroup();

    void generateGroups();

    void simulateMatches();

    void simulateAllMatches();

    void backToCreate();

    void playoff();

private:
    Ui::EuroGroupsWindow *ui;

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

#endif // EUROGROUPSWINDOW_H
