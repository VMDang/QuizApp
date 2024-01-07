#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "roomitem.h"
#include "lobbywindow.h"
#include "createroomdialog.h"
#include "passworddialog.h"
#include "styles.h"
#include "examwindow.h"
#include "component.h"
#include "roomhandler.h"
#include "resulthandler.h"
#include "clientmanager.h"
#include "practicehandler.h"
#include "../app/comunicate/client.h"

#include <iostream>
#include <pthread.h>
#include <QWidget>
#include <QDebug>
#include <QString>

void* onlyReceiveThread(void* arg);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->waitingLabel->hide();
    ui->userList->setAlignment(Qt::AlignTop);
    ui->resultList->layout()->setAlignment(Qt::AlignTop);
    ui->resultList->layout()->setSpacing(12);

    json userLogged = ClientManager::authUser;
    int user_id = userLogged["id"];
    if(user_id == 5) {
        ui->readyButton->setText("START");
    }

    RoomHandler roomHandler;
    roomHandler.requestListRoom(2, "");

    json responseListRoom = roomHandler.responseListRoom();

    std::cout << responseListRoom.dump(4) << std::endl;
    for(auto& jObject : responseListRoom["body"]["rooms"]) {
        std::cout << jObject["status"] << " -- " << jObject["capacity"] << std::endl;
    }
    QVBoxLayout *roomList = new QVBoxLayout(ui->roomList);


    // Thêm các item vào roomList
    RoomItem *item1 = new RoomItem(this, "123456", true, "123");

    roomList->setAlignment(Qt::AlignTop | Qt::AlignHCenter);
    roomList->addWidget(item1);

    // Kết nối tới signal joinPushButton_clicked của room item
    connect(item1, &RoomItem::joinPushButton_clicked, this, &MainWindow::checkRoomAcceptPms);
}

// kiểm tra mật khẩu của room
void MainWindow::checkRoomAcceptPms(const QString& room_id, bool isPrivate, const QString& password)
{
    if(!isPrivate){
        redirectToWaittingRoom();
    } else {
        PasswordDialog *pd = new PasswordDialog(this, password);
        pd->show();
        if(pd->exec() == QDialog::Accepted) {
            redirectToWaittingRoom();
        }
    }
}

// Di chuyển tới màn hình waitting room (signals)
void MainWindow::redirectToWaittingRoom() {
    ui->stackedWidget->setCurrentIndex(1);

    // Thiết lập giao diện của waiting room
    QWidget *user1 = Component::userInRoomItem();
    ui->userList->addWidget(user1);
}

// open model tạo exam
void MainWindow::on_createExamButton_clicked()
{
    createRoomDialog *crd = new createRoomDialog(this);
    crd->show();
}

// handle leave room
void MainWindow::on_leaveButton_clicked()
{
    // xử lý xóa user khỏi danh sách nếu user đã ready

    // chuyển về page room list
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_readyButton_clicked()
{
    QString buttonText = ui->readyButton->text();
    if(buttonText == "READY"){
        ui->readyButton->setText("UNREADY");
        ui->waitingLabel->show();
        Styles::unReadyButton(ui->readyButton);

        RoomHandler roomHandler;
        roomHandler.requestReadyRoom(4);     // get room id run owner before
        json response = roomHandler.responseReadyRoom();
        std::cout << response.dump() << std::endl;

        pthread_t tid;
        pthread_create(&tid, NULL, &onlyReceiveThread, (void*)ClientManager::client_sock);
    } else if(buttonText == "UNREADY"){
        ui->readyButton->setText("READY");
        ui->waitingLabel->hide();
        Styles::readyButton(ui->readyButton);

        RoomHandler roomHandler;
        roomHandler.requestUnReadyRoom(4);     // get room id run owner before
        json response = roomHandler.responseUnReadyRoom();
        std::cout << response.dump() << std::endl;
    } else {
        RoomHandler roomHandler;
        roomHandler.requestStartRoom(4);
    }
}


// xử lý click vào sidbar item
void MainWindow::on_examPushButton_clicked()
{
    Styles::activeSidebarItem(ui->examPushButton);
    Styles::disableSidebarItem(ui->practicePushButton);
    Styles::disableSidebarItem(ui->historyPushButton);
    Styles::disableSidebarItem(ui->dashboardButton);
}

void MainWindow::on_practicePushButton_clicked()
{
    // Styles::activeSidebarItem(ui->practicePushButton);
    // Styles::disableSidebarItem(ui->examPushButton);
    // Styles::disableSidebarItem(ui->historyPushButton);
    // Styles::disableSidebarItem(ui->dashboardButton);

    PracticeHandler practiceHandler;
    practiceHandler.requestCreatePractice();

    json response1 = practiceHandler.responseCreatePractice();
    std::cout << response1.dump() << std::endl;

    practiceHandler.requestStartPractice(7);

    json response2 = practiceHandler.responseCreatePractice();
    std::cout << response2.dump() << std::endl;
}

void MainWindow::on_historyPushButton_clicked()
{
    // Styles::activeSidebarItem(ui->historyPushButton);
    // Styles::disableSidebarItem(ui->examPushButton);
    // Styles::disableSidebarItem(ui->practicePushButton);
    // Styles::disableSidebarItem(ui->dashboardButton);

    ResultHandler resulttHandler;
    resulttHandler.requestHistoryResult();
    json response = resulttHandler.responseHistoryResult();

    std::cout << response.dump(4) << std::endl;
}

void MainWindow::on_dashboardButton_clicked()
{
    Styles::activeSidebarItem(ui->dashboardButton);
    Styles::disableSidebarItem(ui->examPushButton);
    Styles::disableSidebarItem(ui->practicePushButton);
    Styles::disableSidebarItem(ui->historyPushButton);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void* onlyReceiveThread(void* arg) {
    char buff[BUFF_SIZE];

    json response;
    while (1) {
        recvFromServer(buff);
        response = json::parse(buff);
        std::cout << response.dump()  << std::endl;
        if (response["url"] == ResponseReadyRoomRouter)     // Have a person ready
        {
            // std::cout << response.dump()  << std::endl;   // List users ready in here (if donot have participate, response["usersReady"] = null)
        }else if (response["url"] == ResponseUnReadyRoomRouter ) {     // Have a person unready
            // std::cout << response.dump()  << std::endl;   // List users ready in here --> update table participants
        } else if (response["url"] == ResponseStartRoomRouter) {    // Break if ownner start
            std::cout << " -----Start Room ---- "  << std::endl;
            // std::cout << response.dump()  << std::endl;          // List question& option and room information
            // Change view to examwindow
            break;
        }
    }

    json reponseStartRoom = response;
    ExamWindow *ew = new ExamWindow();
    ew->show();
    pthread_exit(NULL);
}
