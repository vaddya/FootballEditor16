#include "competitionwindow.h"
#include "ui_competitionwindow.h"
#include "QDebug"
#include "Exceptions/wrongid.h"

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

void CompetitionWindow::drawGroupStage16()
{
    for( char groupId = 'A'; groupId < 'E'; groupId++ )
    {
        QTreeWidget *table = ui->frame_GS16->findChild<QTreeWidget*>(QString("tree_Group")+groupId);
        table->header()->resizeSection(0, 30);
        table->header()->resizeSection(1, 275);
        table->header()->resizeSection(2, 40);
        table->header()->resizeSection(3, 40);
        table->header()->resizeSection(4, 40);
        table->header()->resizeSection(5, 40);
        table->header()->resizeSection(6, 40);
        table->header()->resizeSection(7, 40);
        table->header()->resizeSection(8, 40);
        table->header()->resizeSection(9, 40);
        table->header()->resizeSection(10, 40);

        for( TeamInGroup &team : comp->getGroupStage().getGroup(groupId).getTeams() ) {
            QTreeWidgetItem *item = new QTreeWidgetItem(table);
            item->setText(1, QString::fromStdString(team.getName()));
            item->setIcon(1, QPixmap(":/Flags/" + item->text(1) + ".png"));
            if( item->icon(1).isNull() ) item->setIcon(1, QPixmap(":/Flags/Unknown.png"));
            item->setText(2, QString::number(team.getGames()));
            item->setText(3, QString::number(team.getWins()));
            item->setText(4, QString::number(team.getDraws()));
            item->setText(5, QString::number(team.getLoses()));
            item->setText(6, QString::number(team.getGoalsFor()));
            item->setText(7, QString::number(team.getGoalsAgainst()));
            item->setText(8, QString::number(team.getGoalsDiffrence()));
            item->setText(9, QString::number(team.getPoints()));
        }

        int i = 1;
        for( MatchInGroup &match : comp->getGroupStage().getGroup(groupId).getMatches() ) {
            QLabel *left = ui->frame_GS16->findChild<QLabel*>(QString("lbl_GS16_GroupA_left_m")+QString::number(i));
            left->setText(QString::fromStdString(match.getFirstTeam().getName()));
            left = new QLabel(ui->tab_GS16_GroupA_Matches);
            left->setPixmap(QPixmap(":/Flags/" + QString::fromStdString(match.getFirstTeam().getName()) + ".png"));
            left->setGeometry(265, -10+40*i, 16, 16);
            left->show();
            QLabel *right = ui->frame_GS16->findChild<QLabel*>(QString("lbl_GS16_GroupA_right_m")+QString::number(i));
            right->setText(QString::fromStdString(match.getSecondTeam().getName()));
            right = new QLabel(ui->tab_GS16_GroupA_Matches);
            right->setPixmap(QPixmap(":/Flags/" + QString::fromStdString(match.getSecondTeam().getName()) + ".png"));
            right->setGeometry(389, -10+40*i, 16, 16);
            right->show();
            i++;
        }
    }
}

void CompetitionWindow::on_btn_CG4_Generate_clicked()
{
    for( int i = 1; i < teams.size()+1; i++ ) {
        char groupId = 'A' + ((i - 1) % 4);
        QCheckBox *item = ui->grbTeams->item(i);
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
    comp->startGroupStage();
    ui->stackedWidget->setCurrentWidget(ui->pgGroupStage16);
        drawGroupStage16();
}

void CompetitionWindow::on_btn_CG4_Create_clicked()
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

void CompetitionWindow::on_btn_CG4_Start_clicked()
{
    if( (int)comp->getNumberOfTeams() == teams.size() ) {
        ui->stackedWidget->setCurrentWidget(ui->pgGroupStage16);
        comp->createGroups();
        drawGroupStage16();
    }
    else {
        WarningDialog *needCreateFourGroups = new WarningDialog(this, "You need to create four groups!");
        needCreateFourGroups->exec();
        delete needCreateFourGroups;
    }
}
