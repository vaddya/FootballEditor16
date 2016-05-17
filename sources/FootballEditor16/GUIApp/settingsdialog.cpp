#include "settingsdialog.h"
#include "ui_settingsdialog.h"

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

void SettingsDialog::on_pushButton_2_clicked()
{
    this->close();
    parent->show();
}
