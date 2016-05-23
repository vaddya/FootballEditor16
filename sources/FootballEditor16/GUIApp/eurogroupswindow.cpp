#include "eurogroupswindow.h"
#include "ui_eurogroupswindow.h"

EuroGroupsWindow::EuroGroupsWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::EuroGroupsWindow),
    comp(new Competition),
    isGenerated(false)
{
    ui->setupUi(this);
    this->setFixedSize(this->geometry().width(),this->geometry().height());

    connect(ui->btn_GS16_GroupA_Save, SIGNAL(clicked(bool)), this, SLOT(saveResults()));
    connect(ui->btn_GS16_GroupB_Save, SIGNAL(clicked(bool)), this, SLOT(saveResults()));
    connect(ui->btn_GS16_GroupC_Save, SIGNAL(clicked(bool)), this, SLOT(saveResults()));
    connect(ui->btn_GS16_GroupD_Save, SIGNAL(clicked(bool)), this, SLOT(saveResults()));

    connect(ui->btn_GS16_GroupA_Simulate, SIGNAL(clicked(bool)), this, SLOT(simulateMatches()));
    connect(ui->btn_GS16_GroupB_Simulate, SIGNAL(clicked(bool)), this, SLOT(simulateMatches()));
    connect(ui->btn_GS16_GroupC_Simulate, SIGNAL(clicked(bool)), this, SLOT(simulateMatches()));
    connect(ui->btn_GS16_GroupD_Simulate, SIGNAL(clicked(bool)), this, SLOT(simulateMatches()));

    connect(ui->btn_CG4_Create, SIGNAL(clicked(bool)), this, SLOT(createGroup()));
    connect(ui->btn_CG4_Generate, SIGNAL(clicked(bool)), this, SLOT(generateGroups()));
    connect(ui->btn_CG4_Start, SIGNAL(clicked(bool)), this, SLOT(startGroupStage()));

    connect(ui->btn_GS16_Simulate, SIGNAL(clicked(bool)), this, SLOT(simulateAllMatches()));
    connect(ui->btn_GS16_Back, SIGNAL(clicked(bool)), this, SLOT(backToCreate()));
    connect(ui->btn_GS16_Playoff, SIGNAL(clicked(bool)), this, SLOT(playoff()));
}

EuroGroupsWindow::~EuroGroupsWindow()
{
    delete ui;
}

void EuroGroupsWindow::setSettings(QString title, QList<QListWidgetItem *> teams)
{
    comp->setTitle(title.toStdString());
    for( QListWidgetItem * lsWidget: teams )
        this->teams.push_back(lsWidget->text());
    drawCreateGroups();
}

void EuroGroupsWindow::startGroupStage()
{
    if( (int)comp->getNumberOfTeams() == teams.size() ) {
        ui->stackedWidget->setCurrentWidget(ui->pgGroupStage16);
        if( isGenerated )
            comp->startGroupStage();
        else
            comp->createGroups();
        drawGroupStage();
        ui->lbl_GS16_GroupStage->setText(QString::fromStdString(comp->getTitle()) + " Group Stage");
    }
    else {
        WarningDialog *needCreateFourGroups = new WarningDialog(this, "You need to create four groups!");
        needCreateFourGroups->exec();
        delete needCreateFourGroups;
    }
}

void EuroGroupsWindow::drawCreateGroups()
{
    ui->stackedWidget->setCurrentWidget(ui->pgCreateGroups4);
    for( int i = 0; i < teams.size(); i++ ) {
        QCheckBox *item = ui->grbTeams->item(i+1);
        item->setText(teams[i]);
        item->setIcon(QPixmap(":/Flags/" + teams[i] + ".png"));
        if( item->icon().isNull() ) item->setIcon(QPixmap(":/Flags/Unknown.png"));
        connect(item, SIGNAL(clicked()), ui->grbTeams, SLOT(checkMax()));
        if( isGenerated ) {
            item->setStyleSheet("QCheckBox {"
                                "rgb(255, 255, 255)"
                                "}"
                                "QCheckBox::indicator::checked{ "
                                "border: 2px solid #d9b900;"
                                "background-color: #ffd800;"
                                "}");
            item->setEnabled(true);
            item->setText(teams[i]);
        }
    }
    isGenerated = false;
}

void EuroGroupsWindow::drawGroupStage()
{
    sizeTableGroupStage();
    drawTablesGroupStage();
    drawMatchesGroupStage();
}

void EuroGroupsWindow::sizeTableGroupStage()
{
    for( Group group: comp->getGroupStage().getGroups() )
    {
        QTreeWidget *table = ui->stackedWidget->findChild<QTreeWidget*>(QString("tree_GS16_Group")+group.getId(), Qt::FindChildrenRecursively);
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

void EuroGroupsWindow::drawTablesGroupStage()
{
    for( Group &group : comp->getGroupStage().getGroups() )
    {
        QTreeWidget *table = ui->stackedWidget->findChild<QTreeWidget*>(QString("tree_GS16_Group")+group.getId(), Qt::FindChildrenRecursively);
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

void EuroGroupsWindow::drawMatchesGroupStage()
{
    for( Group &group : comp->getGroupStage().getGroups() )
    {
        QWidget *tabMatches = ui->stackedWidget->findChild<QWidget*>(QString("tab_GS16_Group")+group.getId()+"_Matches", Qt::FindChildrenRecursively);
        int i = 1;
        for( MatchInGroup &match : group.getMatches() ) {
            QLabel *left = tabMatches->findChild<QLabel*>(QString("lbl_GS16_Group")+group.getId()+"_left_m"+QString::number(i));
            left->setText(QString::fromStdString(match.getFirstTeam().getName()));
            left = new QLabel(tabMatches);
            left->setPixmap(QPixmap(":/Flags/" + QString::fromStdString(match.getFirstTeam().getName()) + ".png"));
            left->setGeometry(265, -10+40*i, 16, 16);
            left->show();

            QLabel *right = tabMatches->findChild<QLabel*>(QString("lbl_GS16_Group")+group.getId()+"_right_m"+QString::number(i));
            right->setText(QString::fromStdString(match.getSecondTeam().getName()));
            right = new QLabel(tabMatches);
            right->setPixmap(QPixmap(":/Flags/" + QString::fromStdString(match.getSecondTeam().getName()) + ".png"));
            right->setGeometry(395, -10+40*i, 16, 16);
            right->show();
            i++;
        }
    }
    ui->tab_GS16_Groups->setCurrentIndex(0);
    ui->tab_GS16_GroupA->setCurrentIndex(0);
}

void EuroGroupsWindow::redrawTableGroupStage(char groupId)
{
    QTreeWidget *table = ui->stackedWidget->findChild<QTreeWidget*>(QString("tree_GS16_Group")+groupId, Qt::FindChildrenRecursively);
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

void EuroGroupsWindow::saveResults()
{
    char groupId = sender()->objectName()[14].toLatin1();
    int i = 1;
    for( MatchInGroup &match : comp->getGroupStage().getGroup(groupId).getMatches() ) {
        QSpinBox *left = ui->frame_GS16->findChild<QSpinBox*>(QString("spb_GS16_Group")+groupId+"_left_m"+QString::number(i));
        QSpinBox *right = ui->frame_GS16->findChild<QSpinBox*>(QString("spb_GS16_Group")+groupId+"_right_m"+QString::number(i));
        match.setResult(left->value(), right->value());
        i++;
    }
    redrawTableGroupStage(groupId);
}

void EuroGroupsWindow::createGroup()
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

void EuroGroupsWindow::generateGroups()
{
    isGenerated = true;
    for( int i = 0; i < teams.size(); i++ ) {
        char groupId = 'A' + i % 4;
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

void EuroGroupsWindow::simulateMatches()
{
    char groupId = sender()->objectName()[14].toLatin1();
    int i = 1;
    for( MatchInGroup &match : comp->getGroupStage().getGroup(groupId).getMatches() ) {
        match.simulate();
        QSpinBox *left = ui->frame_GS16->findChild<QSpinBox*>(QString("spb_GS16_Group")+groupId+"_left_m"+QString::number(i));
        left->setValue(match.getFirstTeam().getGoalsFor());
        QSpinBox *right = ui->frame_GS16->findChild<QSpinBox*>(QString("spb_GS16_Group")+groupId+"_right_m"+QString::number(i));
        right->setValue(match.getSecondTeam().getGoalsFor());
        i++;
    }
    redrawTableGroupStage(groupId);
}

void EuroGroupsWindow::simulateAllMatches()
{
    emit ui->btn_GS16_GroupA_Simulate->clicked(true);
    emit ui->btn_GS16_GroupB_Simulate->clicked(true);
    emit ui->btn_GS16_GroupC_Simulate->clicked(true);
    emit ui->btn_GS16_GroupD_Simulate->clicked(true);
}

void EuroGroupsWindow::backToCreate()
{
    //TODO not now
    //comp->restartGroupStage();
    //comp->clearTeams();
    //drawCreateGroups();
}

void EuroGroupsWindow::playoff()
{
    if( comp->getGroupStage().isGroupStageOver() ) {
        EuroPlayoffWindow *playoff = new EuroPlayoffWindow();
        comp->startPlayOffStage();
        playoff->setCompetition(comp);
        playoff->show();
        this->hide();
    }
    else {
        WarningDialog *groupStageIsNotOver = new WarningDialog(this, "Group stage isn't over!");
        groupStageIsNotOver->exec();
        delete groupStageIsNotOver;
    }
}
