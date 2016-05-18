#ifndef COMPETITIONWINDOW_H
#define COMPETITIONWINDOW_H

#include <QMainWindow>
#include "QList"
#include "QListWidgetItem"
#include "competition.h"

namespace Ui {
class CompetitionWindow;
}

class CompetitionWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CompetitionWindow(QWidget *parent = 0);
    ~CompetitionWindow();

    void setTeams(QList<QListWidgetItem*> teams);

private:
    Ui::CompetitionWindow *ui;

    Competition *comp;
};

#endif // COMPETITIONWINDOW_H
