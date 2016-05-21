#ifndef EUROWINDOW_H
#define EUROWINDOW_H

#include <QWidget>

namespace Ui {
class EUROWindow;
}

class EUROWindow : public QWidget
{
    Q_OBJECT

public:
    explicit EUROWindow(QWidget *parent = 0);
    ~EUROWindow();

private:
    Ui::EUROWindow *ui;
};

#endif // EUROWINDOW_H
