#include "worldcupgroupswindow.h"
#include "ui_worldcupgroupswindow.h"

WorldCupGroupsWindow::WorldCupGroupsWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WorldCupGroupsWindow),
    comp(new Competition),
    isGenerated(false)
{
    ui->setupUi(this);
    this->setFixedSize(this->geometry().width(),this->geometry().height());

    connect(ui->btn_GS32_GroupA_Save, SIGNAL(clicked(bool)), this, SLOT(saveResults()));
    connect(ui->btn_GS32_GroupB_Save, SIGNAL(clicked(bool)), this, SLOT(saveResults()));
    connect(ui->btn_GS32_GroupC_Save, SIGNAL(clicked(bool)), this, SLOT(saveResults()));
    connect(ui->btn_GS32_GroupD_Save, SIGNAL(clicked(bool)), this, SLOT(saveResults()));
    connect(ui->btn_GS32_GroupE_Save, SIGNAL(clicked(bool)), this, SLOT(saveResults()));
    connect(ui->btn_GS32_GroupF_Save, SIGNAL(clicked(bool)), this, SLOT(saveResults()));
    connect(ui->btn_GS32_GroupG_Save, SIGNAL(clicked(bool)), this, SLOT(saveResults()));
    connect(ui->btn_GS32_GroupH_Save, SIGNAL(clicked(bool)), this, SLOT(saveResults()));
    connect(ui->btn_CG8_Create, SIGNAL(clicked(bool)), this, SLOT(createGroup()));
    connect(ui->btn_CG8_Generate, SIGNAL(clicked(bool)), this, SLOT(generateGroups()));
    connect(ui->btn_CG8_Start, SIGNAL(clicked(bool)), this, SLOT(startGroupStage()));
}

WorldCupGroupsWindow::~WorldCupGroupsWindow()
{
    delete ui;
}

void WorldCupGroupsWindow::setSettings(QString title, QList<QListWidgetItem *> teams)
{
    comp->setTitle(title.toStdString());
    for( QListWidgetItem * lsWidget: teams )
        this->teams.push_back(lsWidget->text());
    ui->stackedWidget->setCurrentWidget(ui->pgCreateGroups8);
    drawCreateGroups();
}

void WorldCupGroupsWindow::startGroupStage()
{
    if( (int)comp->getNumberOfTeams() == teams.size() ) {
        ui->stackedWidget->setCurrentWidget(ui->pgGroupStage32);
        if( isGenerated )
            comp->startGroupStage();
        else
            comp->createGroups();
        drawGroupStage();
    }
    else {
        WarningDialog *needCreateFourGroups = new WarningDialog(this, "You need to create eight groups!");
        needCreateFourGroups->exec();
        delete needCreateFourGroups;
    }
}

void WorldCupGroupsWindow::drawCreateGroups()
{
    for( int i = 0; i < teams.size(); i++ ) {
        QCheckBox *item = ui->grbTeams->item(i+1);
        item->setText(teams[i]);
        item->setIcon(QPixmap(":/Flags/" + teams[i] + ".png"));
        if( item->icon().isNull() ) item->setIcon(QPixmap(":/Flags/Unknown.png"));
        connect(item, SIGNAL(clicked()), ui->grbTeams, SLOT(checkMax()));
    }
}

void WorldCupGroupsWindow::drawGroupStage()
{
    sizeTableGroupStage();
    drawTablesGroupStage();
    drawMatchesGroupStage();
}

void WorldCupGroupsWindow::sizeTableGroupStage()
{
    for( Group group: comp->getGroupStage().getGroups() )
    {
        QTreeWidget *table = ui->stackedWidget->findChild<QTreeWidget*>(QString("tree_GS32_Group")+group.getId(), Qt::FindChildrenRecursively);
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
    }
}

void WorldCupGroupsWindow::drawTablesGroupStage()
{
    for( Group &group : comp->getGroupStage().getGroups() )
    {
        QTreeWidget *table = ui->stackedWidget->findChild<QTreeWidget*>(QString("tree_GS32_Group")+group.getId(), Qt::FindChildrenRecursively);
        for( TeamInGroup &team : group.getTeams() ) {
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
    }
}

void WorldCupGroupsWindow::drawMatchesGroupStage()
{
    for( Group &group : comp->getGroupStage().getGroups() )
    {
        QWidget *tabMatches = ui->stackedWidget->findChild<QWidget*>(QString("tab_GS32_Group")+group.getId()+"_Matches", Qt::FindChildrenRecursively);
        int i = 1;
        for( MatchInGroup &match : group.getMatches() ) {
            QLabel *left = tabMatches->findChild<QLabel*>(QString("lbl_GS32_Group")+group.getId()+"_left_m"+QString::number(i));
            left->setText(QString::fromStdString(match.getFirstTeam().getName()));
            left = new QLabel(tabMatches);
            left->setPixmap(QPixmap(":/Flags/" + QString::fromStdString(match.getFirstTeam().getName()) + ".png"));
            left->setGeometry(265, -10+40*i, 16, 16);
            left->show();


            QLabel *right = tabMatches->findChild<QLabel*>(QString("lbl_GS32_Group")+group.getId()+"_right_m"+QString::number(i));
            right->setText(QString::fromStdString(match.getSecondTeam().getName()));
            right = new QLabel(tabMatches);
            right->setPixmap(QPixmap(":/Flags/" + QString::fromStdString(match.getSecondTeam().getName()) + ".png"));
            right->setGeometry(395, -10+40*i, 16, 16);
            right->show();
            i++;
        }
    }
    ui->tab_GS32_Groups->setCurrentIndex(0);
    ui->tab_GS32_GroupA->setCurrentIndex(0);
}

void WorldCupGroupsWindow::redrawTableGroupStage(char groupId)
{
    QTreeWidget *table = ui->stackedWidget->findChild<QTreeWidget*>(QString("tree_GS32_Group")+groupId, Qt::FindChildrenRecursively);
    int i = 0;
    for( TeamInGroup &team : comp->getGroupStage().getGroup(groupId).getTeams() ) {
        QTreeWidgetItem *item = table->topLevelItem(i);
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
        i++;
    }
}

void WorldCupGroupsWindow::saveResults()
{
    char groupId = sender()->objectName()[14].toLatin1();
    int i = 1;
    for( MatchInGroup &match : comp->getGroupStage().getGroup(groupId).getMatches() ) {
        QSpinBox *left = ui->frame_GS32->findChild<QSpinBox*>(QString("spb_GS32_Group")+groupId+"_left_m"+QString::number(i));
        QSpinBox *right = ui->frame_GS32->findChild<QSpinBox*>(QString("spb_GS32_Group")+groupId+"_right_m"+QString::number(i));
        match.setResult(left->value(), right->value());
        i++;
    }
    redrawTableGroupStage(groupId);
}

void WorldCupGroupsWindow::createGroup()
{
    if( ui->grbTeams->selectedItems().size() == 4 ) {
        char groupId = 'A' + comp->getTeams().size()/4;
        for( QCheckBox *item : ui->grbTeams->selectedItems() ) {
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

void WorldCupGroupsWindow::generateGroups()
{
    isGenerated = true;
    for( int i = 0; i < teams.size(); i++ ) {
        char groupId = 'A' + i % 8;
        QCheckBox *item = ui->grbTeams->item(i+1);
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
