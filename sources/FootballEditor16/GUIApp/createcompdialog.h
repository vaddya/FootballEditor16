#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>
#include "competition.h"
#include "QListWidget"
#include "QListWidgetItem"

namespace Ui {
class CreateCompDialog;
}

class CreateCompDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CreateCompDialog(QWidget *parent = 0);
    ~CreateCompDialog();

private slots:
    void on_btnMenu_clicked();

    void on_btnCreate_clicked();

    void on_cmbPreferences_currentIndexChanged(int index);

    void on_rbtn16_clicked();

    void on_rbtn32_clicked();

    void updateProgress();

    void maximizeProgress();

    void on_lstTeams_itemClicked(QListWidgetItem *item);

private:
    Ui::CreateCompDialog *ui;
    QWidget *parent;
    Competition *comp;
};

#endif // SETTINGSDIALOG_H
