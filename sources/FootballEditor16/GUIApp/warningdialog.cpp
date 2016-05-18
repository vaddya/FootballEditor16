#include "warningdialog.h"
#include "ui_warningdialog.h"

WarningDialog::WarningDialog(QWidget *parent, const QString text) :
    QDialog(parent),
    ui(new Ui::WarningDialog)
{
    ui->setupUi(this);
    ui->lblText->setText(text);

    this->setFixedSize(this->geometry().width(),this->geometry().height());

    connect(ui->btnOk, SIGNAL(clicked()), this, SLOT(close()));
}

WarningDialog::~WarningDialog()
{
    delete ui;
}
