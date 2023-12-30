#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "roomitem.h"
#include "lobbywindow.h"
#include "loginwindow.h"
#include "../app/comunicate/client.h"
#include "clientmanager.h"
#include "../app/request/logout.h"

#include <iostream>
#include <QWidget>
#include <QDebug>
#include <QMessageBox>

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

    json auth = ClientManager::authUser;

    std::string name = auth["name"];
    std::string email = auth["email"];
    ui->nameInfoLabel->setText(name.c_str());
    ui->emailInfoLabel->setText(email.c_str());
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


void MainWindow::on_loggoutButton_clicked()
{
    json authUser = ClientManager::authUser;
    RequestLogout requestLogout;
    requestLogout.header = authUser;

    sendToServer(requestLogout.toJson().dump().c_str());


    char buff[BUFF_SIZE];
    recvFromServer(buff);

    json reponseLogout = json::parse(buff);
    std::string status = reponseLogout["status"];
    std::cout << status << std::endl;
    if (status != SUCCESS) {
        QMessageBox::warning(this, "ERROR", "Error in system");
    } else {
        ClientManager::authUser = json{};

        MainWindow::hide();
        LoginWindow *loginWindow = new LoginWindow(this);
        loginWindow->show();
    }

}
