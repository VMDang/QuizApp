#include "roomitem.h"
#include "ui_roomitem.h"
#include "lobbywindow.h"
#include "roomhandler.h"

#include <iostream>
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
    int id = 4; // This is room_id when click. Emulate is interger but room_id now is QString. Need convert to int
    RoomHandler roomhandler;
    roomhandler.requestDetailRoom(id);
    json detailRoom = roomhandler.responseDetailRoom();     // Data room information and table users ready, not yet qusestions info
    std::cout << detailRoom.dump() << std::endl;
    if (detailRoom["body"]["is_owner"] == true) {
        // Go to view room owmer
    } else {
        // Go to view exam participants
    }

    emit joinPushButton_clicked(room_id);
}
