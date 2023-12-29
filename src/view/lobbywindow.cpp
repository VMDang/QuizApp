#include "lobbywindow.h"
#include "ui_lobbywindow.h"

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
}

LobbyWindow::~LobbyWindow()
{
    delete ui;
}
