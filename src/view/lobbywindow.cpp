#include "lobbywindow.h"
#include "ui_lobbywindow.h"
#include "../app/comunicate/client.h"
#include "clientmanager.h"
#include "../app/request/room.h"
#include "roomhandler.h"
#include <pthread.h>
#include <iostream>

void* onlyReceiveThread(void* arg);

LobbyWindow::LobbyWindow(QWidget *parent, const QString &room_id) :
    QMainWindow(parent),
    ui(new Ui::LobbyWindow)
{
    ui->setupUi(this);
    ui->examNameLabel->setText(room_id);

    // load user in room data to table
    ui->tableWidget->setItem(0,0, new QTableWidgetItem("1"));
    ui->tableWidget->setItem(0,1, new QTableWidgetItem("Nguyen Tien Dat"));
    ui->tableWidget->setItem(0,2, new QTableWidgetItem("1440"));

    ui->tableWidget->setItem(1,0, new QTableWidgetItem("2"));
    ui->tableWidget->setItem(1,1, new QTableWidgetItem("Nguyen Van A"));
    ui->tableWidget->setItem(1,2, new QTableWidgetItem("1000"));

    // Only listen have a person ready --> update table
    pthread_t tid;
    pthread_create(&tid, NULL, &onlyReceiveThread, (void*)ClientManager::client_sock);
}

LobbyWindow::~LobbyWindow()
{
    delete ui;
}

void LobbyWindow::on_startExamButton_clicked()
{
    int room_id = 4;
    RoomHandler roomhandler;
    roomhandler.requestStartRoom(room_id);
}


void LobbyWindow::on_readyExamButton_clicked()
{
    int room_id = 4;
    RoomHandler roomhandler;
    roomhandler.requestReadyRoom(room_id);
}

void LobbyWindow::on_unReadyExamButton_clicked()
{
    int room_id = 4;
    RoomHandler roomhandler;
    roomhandler.requestUnReadyRoom(room_id);
}

void* onlyReceiveThread(void* arg) {
    char buff[BUFF_SIZE];

    while (1) {
        recvFromServer(buff);
        json response = json::parse(buff);
        std::cout << response.dump()  << std::endl;
        if (response["url"] == ResponseReadyRoomRouter)     // Have a person ready
        {
            // std::cout << response.dump()  << std::endl;   // List users ready in here (if donot have participate, response["usersReady"] = null)
        }else if (response["url"] == ResponseUnReadyRoomRouter ) {     // Have a person unready
            // std::cout << response.dump()  << std::endl;   // List users ready in here --> update table participants
        } else if (response["url"] == ResponseStartRoomRouter) {    // Break if ownner start
            std::cout << " -----Start Room ---- "  << std::endl;
            // std::cout << response.dump()  << std::endl;
            // Change view to examwindow
            break;
        }
    }

    pthread_exit(NULL);
}


