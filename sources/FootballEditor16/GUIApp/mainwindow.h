#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    const QSize SCREEN_SIZE{1090, 647};
    const QSize BUTTON_SIZE{150, 50};

    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
