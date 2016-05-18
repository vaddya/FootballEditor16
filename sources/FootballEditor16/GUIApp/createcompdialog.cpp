#include "createcompdialog.h"
#include "ui_createcompdialog.h"
#include "exitdialog.h"
#include "qpixmap.h"

CreateCompDialog::CreateCompDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateCompDialog),
    parent(parent),
    comp(new Competition)
{
    ui->setupUi(this);

    this->setFixedSize(this->geometry().width(),this->geometry().height());

    for( QListWidgetItem* listItem : ui->lstTeams->findItems("*", Qt::MatchWildcard) ) {
        listItem->setIcon(QPixmap(":/Flags/" + listItem->text() + ".png"));
    }
    connect(ui->lstTeams, SIGNAL(itemSelectionChanged()), this, SLOT(updateProgress()));
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

}

void CreateCompDialog::on_cmbPreferences_currentIndexChanged(int index)
{
    if( index == 1 ) {
        comp->setTitle("UEFA EURO 2016");
        ui->edtTitle->setText(QString::fromStdString(comp->getTitle()));
        ui->rbtn16->setChecked(true);
        ui->lstTeams->setEnabled(true);
    }
    if( index == 2 ) {
        comp->setTitle("FIFA World Cup 2016");
        ui->edtTitle->setText(QString::fromStdString(comp->getTitle()));
        ui->rbtn32->setChecked(true);
        ui->lstTeams->setEnabled(true);
    }
}

void CreateCompDialog::on_rbtn16_clicked()
{
    ui->lstTeams->setEnabled(true);
}

void CreateCompDialog::on_rbtn32_clicked()
{
    ui->lstTeams->setEnabled(true);
}

void CreateCompDialog::updateProgress()
{
    double value = ui->lstTeams->selectedItems().count() / 32.0;
    if( ui->rbtn16->isChecked() == true ) value *= 2;
    ui->prbTeams->setValue( value * 100 );
}

void CreateCompDialog::maximizeProgress()
{
    if( ui->prbTeams->value() == 100 )
        ui->lstTeams->currentItem()->setCheckState(Qt::CheckState::Unchecked);
    qDebug() << ui->prbTeams->value();
}

void CreateCompDialog::on_lstTeams_itemClicked(QListWidgetItem *item)
{
    if( ui->prbTeams->value() == 100 )
        item->setCheckState(Qt::CheckState::Unchecked);
        qDebug() << ui->prbTeams->value();
}
