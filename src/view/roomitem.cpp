#include "roomitem.h"
#include "ui_roomitem.h"
#include "lobbywindow.h"

#include <QDebug>

RoomItem::RoomItem(QWidget *parent, const QString &room_id) :
    QWidget(parent),
    ui(new Ui::RoomItem),
    room_id(room_id)
{
    ui->setupUi(this);
}

RoomItem::~RoomItem()
{
    delete ui;
}

void RoomItem::on_joinPushButton_clicked()
{
    emit joinPushButton_clicked(room_id);
}
