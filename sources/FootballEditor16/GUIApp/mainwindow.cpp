#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setFixedSize(SCREEN_SIZE);
    QPixmap background("../../FootballEditor16/GUIApp/Resources/background.png");
    QPalette qPalette;
    qPalette.setBrush(this->backgroundRole(),QBrush(background));
    this->setPalette(qPalette);
}

MainWindow::~MainWindow()
{
    delete ui;
}
