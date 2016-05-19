#ifndef TEAMCHECKBOXES_H
#define TEAMCHECKBOXES_H

#include <QGroupBox>
#include <QList>
#include <QCheckBox>

class TeamCheckBoxes : public QGroupBox {
        Q_OBJECT
public:
    TeamCheckBoxes(QWidget *parent = 0);

    QList<QCheckBox *> selectedItems() const;

    QCheckBox *item(int id) const;

public slots:
    void checkMax();

};

#endif // TEAMCHECKBOXES_H
