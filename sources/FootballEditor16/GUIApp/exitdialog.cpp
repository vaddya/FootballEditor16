#include "exitdialog.h"
#include "ui_exitdialog.h"

ExitDialog::ExitDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ExitDialog)
{
    ui->setupUi(this);
    this->parent = parent;
}

void ExitDialog::on_btnYes_clicked()
{
    this->close();
    this->parent->close();
}

void ExitDialog::on_btnCancel_clicked()
{
    this->close();
}

ExitDialog::~ExitDialog()
{
    delete ui;
}
