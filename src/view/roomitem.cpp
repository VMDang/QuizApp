#include "roomitem.h"
#include "ui_roomitem.h"


RoomItem::RoomItem(QWidget *parent, const QString &roomId,
                   bool isPrivate, const QString& password) :
    QWidget(parent),
    ui(new Ui::RoomItem),
    roomId(roomId),
    isPrivate(isPrivate),
    password(password)
{
    if (!isPrivate) ui->lockLabel->hide();
    ui->setupUi(this);
}

void RoomItem::on_joinPushButton_clicked()
{
    emit joinPushButton_clicked(roomId, isPrivate, password);
}

RoomItem::~RoomItem()
{
    delete ui;
}

