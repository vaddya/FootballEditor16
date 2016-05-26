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

    connect(ui->btn_4_simulate, SIGNAL(clicked(bool)), this, SLOT(simulateMatches()));
    connect(ui->btn_2_simulate, SIGNAL(clicked(bool)), this, SLOT(simulateMatches()));
    connect(ui->btn_1_simulate, SIGNAL(clicked(bool)), this, SLOT(simulateMatches()));

    connect(ui->btn_simulate, SIGNAL(clicked(bool)), this, SLOT(simulateAllMatches()));

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
    for( Round roundd : comp->getPlayoffStage().getRounds() ) {
        int roundId = roundd.getRoundEnum();
        int matchId = 1;
        for( MatchInPlayoff match : roundd.getMatches() ) {
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
                bottom = ui->frame_bracket->findChild<QLabel*>(QString("lbl_")+QString::number(roundId)+"_bottom_score_m"+QString::number(matchId));
                if( match.isWithPenalty() ) {
                    top->setText(QString::number(match.getFirstTeam().getGoalsFor())+" ("+QString::number(match.getPenalty().firstTeamPenaltyScore)+")");
                    bottom->setText(QString::number(match.getSecondTeam().getGoalsFor())+" ("+QString::number(match.getPenalty().secondTeamPenaltyScore)+")");
                }
                else {
                    top->setText(QString::number(match.getFirstTeam().getGoalsFor()));
                    bottom->setText(QString::number(match.getSecondTeam().getGoalsFor()));
                }
            }
            matchId++;
        }
    }
}

void EuroPlayoffWindow::drawMatches()
{
    for( Round roundd : comp->getPlayoffStage().getRounds() ) {
        int roundId = roundd.getRoundEnum();
        int matchId = 1;
        QWidget *tab = ui->tabs_matches->findChild<QWidget*>(QString("tab_")+QString::number(roundId),
                                                             Qt::FindChildrenRecursively);
        for( MatchInPlayoff match : roundd.getMatches() ) {
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

void EuroPlayoffWindow::simulateMatches()
{
    int roundId = sender()->objectName()[4].digitValue();
    int matchId = 1;
    for( MatchInPlayoff &match : comp->getPlayoffStage().getRound(roundId).getMatches() ) {
        match.simulate();

        QSpinBox *left = ui->tabs_matches->findChild<QSpinBox*>(QString("spb_")+QString::number(roundId)+"_left_m"+QString::number(matchId),
                                                                Qt::FindChildrenRecursively);
        QSpinBox *right = ui->tabs_matches->findChild<QSpinBox*>(QString("spb_")+QString::number(roundId)+"_right_m"+QString::number(matchId),
                                                                 Qt::FindChildrenRecursively);
        left->setValue(match.getFirstTeam().getGoalsFor());
        right->setValue(match.getSecondTeam().getGoalsFor());

        if( match.isWithPenalty() ) {
            QSpinBox *leftPen = ui->tabs_matches->findChild<QSpinBox*>(QString("spb_")+QString::number(roundId)+"_left_pen_m"+QString::number(matchId),
                                                     Qt::FindChildrenRecursively);
            QSpinBox *rightPen = ui->tabs_matches->findChild<QSpinBox*>(QString("spb_")+QString::number(roundId)+"_right_pen_m"+QString::number(matchId),
                                                                     Qt::FindChildrenRecursively);
            leftPen->setEnabled(true);
            rightPen->setEnabled(true);
            leftPen->setValue(match.getPenalty().firstTeamPenaltyScore);
            rightPen->setValue(match.getPenalty().secondTeamPenaltyScore);
        }
        matchId++;
    }
    drawBracket();
}

void EuroPlayoffWindow::simulateAllMatches()
{
    emit ui->btn_4_simulate->clicked(true);
    emit ui->btn_4_next->clicked(true);
    emit ui->btn_2_simulate->clicked(true);
    emit ui->btn_2_next->clicked(true);
    emit ui->btn_1_simulate->clicked(true);
}

void EuroPlayoffWindow::openPenalty()
{
    int roundId = sender()->objectName()[4].digitValue();
    int matchId = sender()->objectName()[11].digitValue();
    QSpinBox *leftPen = ui->tabs_matches->findChild<QSpinBox*>(QString("spb_")+QString::number(roundId)+"_left_pen_m"+QString::number(matchId),
                                                            Qt::FindChildrenRecursively);
    QSpinBox *rightPen = ui->tabs_matches->findChild<QSpinBox*>(QString("spb_")+QString::number(roundId)+"_right_pen_m"+QString::number(matchId),
                                                             Qt::FindChildrenRecursively);
    if( leftPen->isEnabled() ) {
        leftPen->setEnabled(false);
        rightPen->setEnabled(false);
    }
    else {
        leftPen->setEnabled(true);
        rightPen->setEnabled(true);
    }
}

void EuroPlayoffWindow::saveResults()
{
    int roundId = sender()->objectName()[4].digitValue();
    int matchId = 1;
    for( MatchInPlayoff &match : comp->getPlayoffStage().getRound(roundId).getMatches() ) {
        QSpinBox *left = ui->tabs_matches->findChild<QSpinBox*>(QString("spb_")+QString::number(roundId)+"_left_m"+QString::number(matchId),
                                                                Qt::FindChildrenRecursively);
        QSpinBox *right = ui->tabs_matches->findChild<QSpinBox*>(QString("spb_")+QString::number(roundId)+"_right_m"+QString::number(matchId),
                                                                 Qt::FindChildrenRecursively);
        try {
            match.setResult(left->value(), right->value());
        }
        catch( InputPenaltryScore &p ) {
            QSpinBox *leftPen = ui->tabs_matches->findChild<QSpinBox*>(QString("spb_")+QString::number(roundId)+"_left_pen_m"+QString::number(matchId),
                                                                    Qt::FindChildrenRecursively);
            QSpinBox *rightPen = ui->tabs_matches->findChild<QSpinBox*>(QString("spb_")+QString::number(roundId)+"_right_pen_m"+QString::number(matchId),
                                                                     Qt::FindChildrenRecursively);
            if( leftPen->isEnabled() && rightPen->isEnabled() ) {
                try {
                    match.setPenaltyScore(leftPen->value(), rightPen->value());
                }
                catch( WrongPenaltyScore &w ) {
                    WarningDialog *wrongPenaltyScore = new WarningDialog(this, w.what());
                    wrongPenaltyScore->exec();
                    delete wrongPenaltyScore;
                }
            }
            else {
                WarningDialog *inputPenalty = new WarningDialog(this, QString("Input penalty score in round 1/")+QString::number(roundId)+", match "+QString::number(matchId));
                inputPenalty->exec();
                delete inputPenalty;
            }
        }

        matchId++;
    }
    drawMatches();
    drawBracket();
}
