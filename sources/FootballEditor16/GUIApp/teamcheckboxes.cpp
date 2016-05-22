#include "teamcheckboxes.h"

TeamCheckBoxes::TeamCheckBoxes(QWidget *parent):
    QGroupBox(parent)
{

}

QList<QCheckBox *> TeamCheckBoxes::selectedItems() const
{
    QList<QCheckBox *> lst;
    for( int i = 0; i < this->children().size(); i++ ) {
        QCheckBox *item = findChild<QCheckBox *>("checkBox_" + QString::number(i+1), Qt::FindChildrenRecursively);
        if( item->isChecked() && item->isEnabled() )
            lst << item;
    }
    return lst;
}

QCheckBox *TeamCheckBoxes::item(int id) const
{
    return findChild<QCheckBox *>("checkBox_" + QString::number(id), Qt::FindChildrenRecursively);
}

void TeamCheckBoxes::checkMax()
{
    if( selectedItems().count() > 4 )
        qobject_cast<QCheckBox*>(sender())->setChecked(false);
}
