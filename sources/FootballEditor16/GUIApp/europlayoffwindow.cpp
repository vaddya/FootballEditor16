#include "europlayoffwindow.h"
#include "ui_europlayoffwindow.h"
#include "qdebug.h"

EuroPlayoffWindow::EuroPlayoffWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::EuroPlayoffWindow)
{
    ui->setupUi(this);
    this->setFixedSize(this->geometry().width(),this->geometry().height());

    connect(ui->btn_4_pen_m1, SIGNAL(clicked(bool)), this, SLOT(openPenalty()));
    connect(ui->btn_4_pen_m2, SIGNAL(clicked(bool)), this, SLOT(openPenalty()));
    connect(ui->btn_4_pen_m3, SIGNAL(clicked(bool)), this, SLOT(openPenalty()));
    connect(ui->btn_4_pen_m4, SIGNAL(clicked(bool)), this, SLOT(openPenalty()));
    connect(ui->btn_2_pen_m1, SIGNAL(clicked(bool)), this, SLOT(openPenalty()));
    connect(ui->btn_2_pen_m2, SIGNAL(clicked(bool)), this, SLOT(openPenalty()));
    connect(ui->btn_1_pen_m1, SIGNAL(clicked(bool)), this, SLOT(openPenalty()));

    connect(ui->btn_4_save, SIGNAL(clicked(bool)), this, SLOT(saveResults()));
    connect(ui->btn_2_save, SIGNAL(clicked(bool)), this, SLOT(saveResults()));
    connect(ui->btn_1_save, SIGNAL(clicked(bool)), this, SLOT(saveResults()));

    connect(ui->btn_4_next, SIGNAL(clicked(bool)), this, SLOT(nextRound()));
    connect(ui->btn_2_next, SIGNAL(clicked(bool)), this, SLOT(nextRound()));
}

EuroPlayoffWindow::~EuroPlayoffWindow()
{
    delete ui;
}

void EuroPlayoffWindow::setCompetition(Competition *competition)
{
    comp = competition;
    ui->lbl_playoff->setText(QString::fromStdString(comp->getTitle()) + " Playoff Stage");
    drawBracket();
    drawMatches();
}

void EuroPlayoffWindow::drawBracket()
{
    for( Round round : comp->getPlayoffStage().getRounds() ) {
        int roundId = round.getRoundEnum();
        int matchId = 1;
        for( MatchInPlayoff match : round.getMatches() ) {
            QLabel *top = ui->frame_bracket->findChild<QLabel*>(QString("lbl_")+QString::number(roundId)+"_top_m"+QString::number(matchId));
            top->setText(QString::fromStdString(match.getFirstTeam().getName()));
            top = ui->frame_bracket->findChild<QLabel*>(QString("ico_")+QString::number(roundId)+"_top_m"+QString::number(matchId));
            top->setPixmap(QPixmap(":/Flags/" + QString::fromStdString(match.getFirstTeam().getName()) + ".png"));

            QLabel *bottom = ui->frame_bracket->findChild<QLabel*>(QString("lbl_")+QString::number(roundId)+"_bottom_m"+QString::number(matchId));
            bottom->setText(QString::fromStdString(match.getSecondTeam().getName()));
            bottom = ui->frame_bracket->findChild<QLabel*>(QString("ico_")+QString::number(roundId)+"_bottom_m"+QString::number(matchId));
            bottom->setPixmap(QPixmap(":/Flags/" + QString::fromStdString(match.getSecondTeam().getName()) + ".png"));

            if( match.isPlayed() ) {
                top = ui->frame_bracket->findChild<QLabel*>(QString("lbl_")+QString::number(roundId)+"_top_score_m"+QString::number(matchId));
                top->setText(QString::number(match.getFirstTeam().getGoalsFor()));

                bottom = ui->frame_bracket->findChild<QLabel*>(QString("lbl_")+QString::number(roundId)+"_bottom_score_m"+QString::number(matchId));
                bottom->setText(QString::number(match.getSecondTeam().getGoalsFor()));
            }
            matchId++;
        }
    }
}

void EuroPlayoffWindow::drawMatches()
{
    for( Round round : comp->getPlayoffStage().getRounds() ) {
        int roundId = round.getRoundEnum();
        int matchId = 1;
        QWidget *tab = ui->tabs_matches->findChild<QWidget*>(QString("tab_")+QString::number(roundId), Qt::FindChildrenRecursively);

        for( MatchInPlayoff match : round.getMatches() ) {
            QLabel *left = tab->findChild<QLabel*>(QString("lbl_")+QString::number(roundId)+"_left_m"+QString::number(matchId));
            left->setText(QString::fromStdString(match.getFirstTeam().getName()));
            left = tab->findChild<QLabel*>(QString("ico_")+QString::number(roundId)+"_left_m"+QString::number(matchId));
            left->setPixmap(QPixmap(":/Flags/" + QString::fromStdString(match.getFirstTeam().getName()) + ".png"));

            QLabel *right = tab->findChild<QLabel*>(QString("lbl_")+QString::number(roundId)+"_right_m"+QString::number(matchId));
            right->setText(QString::fromStdString(match.getSecondTeam().getName()));
            right = tab->findChild<QLabel*>(QString("ico_")+QString::number(roundId)+"_right_m"+QString::number(matchId));
            right->setPixmap(QPixmap(":/Flags/" + QString::fromStdString(match.getSecondTeam().getName()) + ".png"));
            matchId++;
        }
    }
}

void EuroPlayoffWindow::nextRound()
{

    comp->getPlayoffStage().createNewMatches();
    drawBracket();
    drawMatches();
}

void EuroPlayoffWindow::openPenalty()
{
    char round = sender()->objectName()[4].toLatin1();
    if( round == 'q' ) {
        qDebug() << sender()->objectName()[17].toLatin1();
        char matchNum = sender()->objectName()[17].toLatin1();
        QSpinBox *left = ui->tabs_matches->findChild<QSpinBox*>(QString("spb_4_left_pen_m")+matchNum);
        QSpinBox *right = ui->tabs_matches->findChild<QSpinBox*>(QString("spb_4_right_pen_m")+matchNum);
        left->setEnabled(true);
        right->setEnabled(true);
    }
    else if( round == 's' ) {
        char matchNum = sender()->objectName()[14].toLatin1();
        QSpinBox *left = ui->tabs_matches->findChild<QSpinBox*>(QString("spb_2_left_pen_m")+matchNum);
        QSpinBox *right = ui->tabs_matches->findChild<QSpinBox*>(QString("spb_2_right_pen_m")+matchNum);
        left->setEnabled(true);
        right->setEnabled(true);
    }
    else {
        ui->spb_1_left_pen_m1->setEnabled(true);
        ui->spb_1_right_pen_m1->setEnabled(true);
    }
}

void EuroPlayoffWindow::saveResults()
{
    //char round = sender()->objectName()[4].toLatin1();
    //int roundId;
    int round = sender()->objectName()[4].digitValue();
//    if( round == '4' ) roundId = 4;
//    if( round == '2' ) roundId = 2;
//    if( round == '1' ) roundId = 1;

    int i = 1;
    for( MatchInPlayoff &match : comp->getPlayoffStage().getRound(round).getMatches() ) {
        QSpinBox *left = ui->tabs_matches->findChild<QSpinBox*>(QString("spb_4_left_m")+QString::number(i), Qt::FindChildrenRecursively);
        QSpinBox *right = ui->tabs_matches->findChild<QSpinBox*>(QString("spb_4_right_m")+QString::number(i), Qt::FindChildrenRecursively);
        match.setResult(left->value(), right->value());
        i++;
    }
    drawMatches();
    drawBracket();
}
