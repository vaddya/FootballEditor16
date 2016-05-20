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

class CompetitionWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CompetitionWindow(QWidget *parent = 0);
    ~CompetitionWindow();

    void setSettings(QString title, QList<QListWidgetItem*> teams);

private slots:

    void on_btn_CG4_Create_clicked();

    void on_btn_CG4_Start_clicked();

    void on_btn_CG4_Generate_clicked();

private:
    Ui::CompetitionWindow *ui;

    Competition *comp;
    QVector<QString> teams;

    void drawCreateGroups();
    void drawGroupStage16();
    bool isMax;

};

#endif // COMPETITIONWINDOW_H
