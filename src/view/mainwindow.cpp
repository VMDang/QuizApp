#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "roomitem.h"
#include "lobbywindow.h"

#include <QWidget>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QVBoxLayout *roomList = new QVBoxLayout(ui->roomList);

    // Tạo một item exam
    RoomItem *item1 = new RoomItem(this, "123456");

    // Thêm item1 vào examList
    roomList->setAlignment(Qt::AlignTop | Qt::AlignHCenter);
    roomList->addWidget(item1);

    // Kết nối tới signal của ExamItem
    connect(item1, &RoomItem::joinPushButton_clicked, this, &MainWindow::openWaittingRoom);
}

// Di chuyển tới màn hình waiting room
void MainWindow::openWaittingRoom(const QString &room_id) {
    MainWindow::hide();
    LobbyWindow *lb = new LobbyWindow(this, room_id);
    lb->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

