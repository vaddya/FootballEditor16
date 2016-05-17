#include "settingsdialog.h"
#include "ui_settingsdialog.h"

#include "competition.h"

SettingsDialog::SettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsDialog),
    parent(parent)
{
    ui->setupUi(this);

    this->setFixedSize(this->geometry().width(),this->geometry().height());
}

SettingsDialog::~SettingsDialog()
{
    delete ui;
}

void SettingsDialog::on_btnMenu_clicked()
{
    this->close();
    parent->show();
}

void SettingsDialog::on_btnSave_clicked()
{
    Competition *comp = new Competition();
    comp->setTitle(ui->editName->text().toStdString());
    QString name = "Settings of " + QString::fromStdString(comp->getTitle());
    ui->lblSettings->setText(name);
}
