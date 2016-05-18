#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "createcompdialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnExit_clicked()
{
    ExitDialog *exit = new ExitDialog(this);
    exit->exec();
    delete exit;
}

void MainWindow::on_btnNewComp_clicked()
{
    this->hide();
    CreateCompDialog *createComp = new CreateCompDialog(this);
    createComp->exec();
    delete createComp;
}
