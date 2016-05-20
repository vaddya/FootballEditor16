#include "competitionwindow.h"
#include "ui_competitionwindow.h"

CompetitionWindow::CompetitionWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CompetitionWindow),
    comp(new Competition)
{
    ui->setupUi(this);
    this->setFixedSize(this->geometry().width(),this->geometry().height());
    ui->stackedWidget->setCurrentWidget(ui->pgCreateGroups4);
}

CompetitionWindow::~CompetitionWindow()
{
    delete ui;
}

void CompetitionWindow::setSettings(QString title, QList<QListWidgetItem *> teams)
{
    comp->setTitle(title.toStdString());

    for( QListWidgetItem * lsWidget: teams )
        this->teams.push_back(lsWidget->text());
    drawCreateGroups();
}

void CompetitionWindow::drawCreateGroups()
{
    for( int i = 0; i < teams.size(); i++ ) {
        QCheckBox *item = ui->grbTeams->item(i+1);
        item->setText(teams[i]);
        item->setIcon(QPixmap(":/Flags/" + teams[i] + ".png"));
        if( item->icon().isNull() ) item->setIcon(QPixmap(":/Flags/Unknown.png"));
        connect(item, SIGNAL(clicked()), ui->grbTeams, SLOT(checkMax()));
    }
}

void CompetitionWindow::on_btnCreate_clicked()
{
    if( ui->grbTeams->selectedItems().size() == 4 ) {
        char groupId = 'A' + comp->getTeams().size()/4;
        for( QCheckBox * item : ui->grbTeams->selectedItems() ) {
            comp->addTeam(item->text().toStdString());
            item->setStyleSheet("QCheckBox {"
                                "color: #6c6c6c"
                                "}"
                                "QCheckBox::indicator::checked{ "
                                "border: 2px solid #555555;"
                                "background-color: #6c6c6c;"
                                "}");
            item->setEnabled(false);
            item->setText(item->text() + " (" + groupId + ")");
        }
    }
    else {
        WarningDialog *needSelecetFourTeams = new WarningDialog(this, "You need to selecet four teams!");
        needSelecetFourTeams->exec();
        delete needSelecetFourTeams;
    }
}

void CompetitionWindow::on_btnStart_clicked()
{
    if( (int)comp->getNumberOfTeams() == teams.size() ) {
        ui->stackedWidget->setCurrentWidget(ui->pgGroupStage16);
        comp->createGroups();
    }
    else {
        WarningDialog *needCreateFourGroups = new WarningDialog(this, "You need to create four groups!");
        needCreateFourGroups->exec();
        delete needCreateFourGroups;
    }
}
