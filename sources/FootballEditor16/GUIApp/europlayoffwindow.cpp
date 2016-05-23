#include "europlayoffwindow.h"
#include "ui_europlayoffwindow.h"

EuroPlayoffWindow::EuroPlayoffWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::EuroPlayoffWindow)
{
    ui->setupUi(this);
    this->setFixedSize(this->geometry().width(),this->geometry().height());

    connect(ui->btn_quarter_pen_m1, SIGNAL(clicked(bool)), this, SLOT(openPenalty()));
    connect(ui->btn_quarter_pen_m2, SIGNAL(clicked(bool)), this, SLOT(openPenalty()));
    connect(ui->btn_quarter_pen_m3, SIGNAL(clicked(bool)), this, SLOT(openPenalty()));
    connect(ui->btn_quarter_pen_m4, SIGNAL(clicked(bool)), this, SLOT(openPenalty()));
    connect(ui->btn_semi_pen_m1, SIGNAL(clicked(bool)), this, SLOT(openPenalty()));
    connect(ui->btn_semi_pen_m2, SIGNAL(clicked(bool)), this, SLOT(openPenalty()));
    connect(ui->btn_final_pen_m1, SIGNAL(clicked(bool)), this, SLOT(openPenalty()));

    connect(ui->btn_quarter_save, SIGNAL(clicked(bool)), this, SLOT(saveResults()));
    connect(ui->btn_semi_save, SIGNAL(clicked(bool)), this, SLOT(saveResults()));
    connect(ui->btn_final_save, SIGNAL(clicked(bool)), this, SLOT(saveResults()));
}

EuroPlayoffWindow::~EuroPlayoffWindow()
{
    delete ui;
}

void EuroPlayoffWindow::setCompetition(Competition *competition)
{
    comp = competition;
    ui->lbl_playoff->setText(QString::fromStdString(comp->getTitle()) + " Playoff Stage");
    drawFirstRound();
    drawQuarterFinals();
}

void EuroPlayoffWindow::drawFirstRound()
{
    int i = 1;
    for( MatchInPlayoff match : comp->getPlayoffStage().getMatches() ) {
        QLabel *top = ui->frame_bracket->findChild<QLabel*>(QString("lbl_quarter_top_m")+QString::number(i));
        top->setText(QString::fromStdString(match.getFirstTeam().getName()));
        top = new QLabel(ui->frame_bracket);
        top->setPixmap(QPixmap(":/Flags/" + QString::fromStdString(match.getFirstTeam().getName()) + ".png"));
        top->setGeometry(35, -46+80*i, 16, 16);
        top->show();

        QLabel *bottom = ui->frame_bracket->findChild<QLabel*>(QString("lbl_quarter_bottom_m")+QString::number(i));
        bottom->setText(QString::fromStdString(match.getSecondTeam().getName()));
        bottom = new QLabel(ui->frame_bracket);
        bottom->setPixmap(QPixmap(":/Flags/" + QString::fromStdString(match.getSecondTeam().getName()) + ".png"));
        bottom->setGeometry(35, -18+80*i, 16, 16);
        bottom->show();
        i++;
    }
}

void EuroPlayoffWindow::drawQuarterFinals()
{
    int i = 1;
    for( MatchInPlayoff match : comp->getPlayoffStage().getMatches() ) {
        QLabel *left = ui->tab_quarter->findChild<QLabel*>(QString("lbl_quarter_left_m")+QString::number(i));
        left->setText(QString::fromStdString(match.getFirstTeam().getName()));
        left = new QLabel(ui->tab_quarter);
        left->setPixmap(QPixmap(":/Flags/" + QString::fromStdString(match.getFirstTeam().getName()) + ".png"));
        left->setGeometry(268, -43+72*i, 16, 16);
        left->show();

        QLabel *right = ui->tab_quarter->findChild<QLabel*>(QString("lbl_quarter_right_m")+QString::number(i));
        right->setText(QString::fromStdString(match.getSecondTeam().getName()));
        right = new QLabel(ui->tab_quarter);
        right->setPixmap(QPixmap(":/Flags/" + QString::fromStdString(match.getSecondTeam().getName()) + ".png"));
        right->setGeometry(392, -43+72*i, 16, 16);
        right->show();
        i++;
    }
}

void EuroPlayoffWindow::openPenalty()
{
    char round = sender()->objectName()[4].toLatin1();
    if( round == 'q' ) {
        char matchNum = sender()->objectName()[17].toLatin1();
        QSpinBox *left = ui->tabs_matches->findChild<QSpinBox*>(QString("spb_quarter_left_pen_m")+matchNum);
        QSpinBox *right = ui->tabs_matches->findChild<QSpinBox*>(QString("spb_quarter_right_pen_m")+matchNum);
        left->setEnabled(true);
        right->setEnabled(true);
    }
    else if( round == 's' ) {
        char matchNum = sender()->objectName()[14].toLatin1();
        QSpinBox *left = ui->tabs_matches->findChild<QSpinBox*>(QString("spb_semi_left_pen_m")+matchNum);
        QSpinBox *right = ui->tabs_matches->findChild<QSpinBox*>(QString("spb_semi_right_pen_m")+matchNum);
        left->setEnabled(true);
        right->setEnabled(true);
    }
    else {
        ui->spb_final_left_pen_m1->setEnabled(true);
        ui->spb_final_right_pen_m1->setEnabled(true);
    }
}

void EuroPlayoffWindow::saveResults()
{
    char round = sender()->objectName()[4].toLatin1();
    vector<MatchInPlayoff> *matches;
    if( round == 'q' ) matches = &comp->getPlayoffStage().getRound(0).getMatches();
    if( round == 's' ) matches = &comp->getPlayoffStage().getRound(1).getMatches();
    if( round == 'f' ) matches = &comp->getPlayoffStage().getRound(2).getMatches();

    int i = 1;
    for( MatchInPlayoff match : *matches ) {
        QSpinBox *left = ui->tabs_matches->findChild<QSpinBox*>(QString("spb_quarter_left_m")+QString::number(i), Qt::FindChildrenRecursively);
        QSpinBox *right = ui->tabs_matches->findChild<QSpinBox*>(QString("spb_quarter_right_m")+QString::number(i), Qt::FindChildrenRecursively);
        match.setResult(left->value(), right->value());
        i++;
    }
    ui->statusBar->showMessage(QString("Saved."));
}
