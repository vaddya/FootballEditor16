#include "createcompdialog.h"
#include "ui_settingsdialog.h"

CreateCompDialog::CreateCompDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateCompDialog),
    parent(parent),
    comp(new Competition)
{
    ui->setupUi(this);

    this->setFixedSize(this->geometry().width(),this->geometry().height());
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
    comp->setTitle(ui->edtTitle->text().toStdString());
    ui->lblSettings->setText(QString::fromStdString(comp->getTitle()));
}

void CreateCompDialog::on_cmbPreferences_currentIndexChanged(int index)
{
    if( index == 1 ) {
        comp->setTitle("UEFA EURO 2016");
        ui->edtTitle->setText(QString::fromStdString(comp->getTitle()));
        ui->lblSettings->setText(QString::fromStdString(comp->getTitle()));
        ui->rbtn16->setChecked(true);
    }
    if( index == 2 ) {
        comp->setTitle("FIFA World Cup 2016");
        ui->edtTitle->setText(QString::fromStdString(comp->getTitle()));
        ui->lblSettings->setText(QString::fromStdString(comp->getTitle()));
        ui->rbtn32->setChecked(true);
    }
}
