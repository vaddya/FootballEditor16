#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>
#include "competition.h"

namespace Ui {
class SettingsDialog;
}

class SettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SettingsDialog(QWidget *parent = 0);
    ~SettingsDialog();

private slots:
    void on_btnMenu_clicked();

    void on_btnCreate_clicked();

    void on_cmbPreferences_currentIndexChanged(int index);

private:
    Ui::SettingsDialog *ui;
    QWidget *parent;
    Competition *comp;
};

#endif // SETTINGSDIALOG_H
