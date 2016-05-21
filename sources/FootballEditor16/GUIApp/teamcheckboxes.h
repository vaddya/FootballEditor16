#ifndef TEAMCHECKBOXES_H
#define TEAMCHECKBOXES_H

#include <QGroupBox>
#include <QList>
#include <QCheckBox>

enum Mode { EU = 0, WC = 16 };

class TeamCheckBoxes : public QGroupBox {
        Q_OBJECT
public:
    TeamCheckBoxes(QWidget *parent = 0);
    void setMode(bool);
    QList<QCheckBox *> selectedItems() const;

    QCheckBox *item(int id) const;

public slots:
    void checkMax();

private:
    Mode mode;
};

#endif // TEAMCHECKBOXES_H
