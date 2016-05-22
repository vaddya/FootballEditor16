#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>
#include <QListWidget>
#include <QListWidgetItem>
#include "warningdialog.h"
#include "eurogroupswindow.h"
#include "worldcupgroupswindow.h"

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

    void updateProgress();

    void on_lstTeams_itemClicked(QListWidgetItem *item);

    void checkMax();

private:
    Ui::CreateCompDialog *ui;
    QWidget *parent;
    bool isMax;

    bool isReadyToCreate();

    bool isMaxProgress();
};

#endif // SETTINGSDIALOG_H
