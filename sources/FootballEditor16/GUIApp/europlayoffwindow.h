#ifndef EUROPLAYOFFWINDOW_H
#define EUROPLAYOFFWINDOW_H

#include <QMainWindow>
#include "competition.h"

namespace Ui {
class EuroPlayoffWindow;
}

class EuroPlayoffWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit EuroPlayoffWindow(QWidget *parent = 0);
    ~EuroPlayoffWindow();

    void setCompetition(Competition *);
    void drawFirstRound();
    void drawQuarterFinals();

private slots:
    void openPenalty();

    void saveResults();

private:
    Ui::EuroPlayoffWindow *ui;
    Competition *comp;
};

#endif // EUROPLAYOFFWINDOW_H
