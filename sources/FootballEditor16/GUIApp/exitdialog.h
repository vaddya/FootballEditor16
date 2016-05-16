#ifndef EXITDIALOG_H
#define EXITDIALOG_H

#include <QDialog>

namespace Ui {
class ExitDialog;
}

class ExitDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ExitDialog(QWidget *parent = 0);
    ~ExitDialog();

private slots:
    void on_btnYes_clicked();
    void on_btnCancel_clicked();

private:
    Ui::ExitDialog *ui;
    QWidget* parent;
};

#endif // EXITDIALOG_H
