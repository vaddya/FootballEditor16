#include "createcompdialog.h"
#include "ui_createcompdialog.h"
#include "qdebug.h"

CreateCompDialog::CreateCompDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateCompDialog),
    parent(parent)
{
    ui->setupUi(this);
    ui->rbtn16->setChecked(true);
    this->setFixedSize(this->geometry().width(),this->geometry().height());

    for( QListWidgetItem* item : ui->lstTeams->findItems("*", Qt::MatchWildcard) ) {
        item->setIcon(QPixmap(":/Flags/" + item->text() + ".png"));
        if( item->icon().isNull() ) item->setIcon(QPixmap(":/Flags/Unknown.png"));
    }

    connect(ui->lstTeams, SIGNAL(itemSelectionChanged()), this, SLOT(updateProgress()));
    connect(ui->lstTeams, SIGNAL(itemSelectionChanged()), this, SLOT(checkMax()));
    connect(ui->rbtn16, SIGNAL(clicked()), this, SLOT(updateProgress()));
    connect(ui->rbtn32, SIGNAL(clicked()), this, SLOT(updateProgress()));
}

CreateCompDialog::~CreateCompDialog()
{
    delete ui;
}

void CreateCompDialog::on_btnMenu_clicked()
{
    this->close();
    parent->show();
}

void CreateCompDialog::on_btnCreate_clicked()
{
    if( isReadyToCreate() ) {
        CompetitionWindow *comp = new CompetitionWindow();
        comp->setTeams(ui->lstTeams->selectedItems());
        this->hide();
        comp->show();
    }
    else {
        WarningDialog *fillOut = new WarningDialog(this, "Please fill out all required fields!");
        fillOut->show();
        fillOut->exec();
        delete fillOut;
    }
}

void CreateCompDialog::on_cmbPreferences_currentIndexChanged(int index)
{
    if( index == 1 ) {
        ui->edtTitle->setText(QString::fromStdString("UEFA EURO 2016"));
        ui->rbtn16->setChecked(true);
    }
    if( index == 2 ) {
        ui->edtTitle->setText(QString::fromStdString("FIFA World Cup 2016"));
        ui->rbtn32->setChecked(true);
    }
}

void CreateCompDialog::updateProgress()
{
    double value = ui->lstTeams->selectedItems().count() / 32.0;
    if( ui->rbtn16->isChecked() == true ) value *= 2;
    ui->prbTeams->setValue( value * 100 );
}

void CreateCompDialog::on_lstTeams_itemClicked(QListWidgetItem *item)
{
    if( isMax )
        item->setSelected(false);
    isMax = isMaxProgress();
}

void CreateCompDialog::checkMax()
{
    int maxNum = ui->rbtn16->isChecked() ? 16 : 32;
    if( ui->lstTeams->selectedItems().count() > maxNum )
        for( int i = ui->lstTeams->count()-1; ui->lstTeams->selectedItems().count() != maxNum; i-- )
            ui->lstTeams->item(i)->setSelected(false);
}

bool CreateCompDialog::isReadyToCreate()
{
    return isMaxProgress() && (ui->edtTitle->text() != "");
}

bool CreateCompDialog::isMaxProgress()
{
    return ui->prbTeams->value() == 100;
}
