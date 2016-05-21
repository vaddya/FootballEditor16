#include "eurowindow.h"
#include "ui_eurowindow.h"

EUROWindow::EUROWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EUROWindow)
{
    ui->setupUi(this);
}

EUROWindow::~EUROWindow()
{
    delete ui;
}
