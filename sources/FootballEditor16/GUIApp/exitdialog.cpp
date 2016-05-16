#include "exitdialog.h"
#include "ui_exitdialog.h"

ExitDialog::ExitDialog(QWidget *parent) :
    QDialog(parent, Qt::WindowTitleHint),
    ui(new Ui::ExitDialog)
{
    ui->setupUi(this);
    this->parent = parent;
    connect(ui->btnCancel,SIGNAL(clicked(bool)),this,SLOT(close()));
    connect(ui->btnYes,SIGNAL(clicked(bool)),this,SLOT(close()));
    connect(ui->btnYes,SIGNAL(clicked(bool)),parent,SLOT(close()));
}

ExitDialog::~ExitDialog()
{
    delete ui;
}
