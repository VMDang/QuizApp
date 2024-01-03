#ifndef COMPONENT_H
#define COMPONENT_H

#include <QWidget>

class Component
{
public:
    Component();
    static QWidget *userInRoomItem();
    static QWidget *userResultItem(QString id);
};

#endif // COMPONENT_H
