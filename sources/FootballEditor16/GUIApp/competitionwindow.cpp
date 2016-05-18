#include "competitionwindow.h"
#include "ui_competitionwindow.h"

CompetitionWindow::CompetitionWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CompetitionWindow),
    comp(new Competition)
{
    ui->setupUi(this);
    this->setFixedSize(this->geometry().width(),this->geometry().height());
}

CompetitionWindow::~CompetitionWindow()
{
    delete ui;
}

void CompetitionWindow::setTeams(QList<QListWidgetItem*> teams)
{

}
