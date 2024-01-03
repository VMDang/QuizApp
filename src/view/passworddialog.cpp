#include "passworddialog.h"
#include "ui_passworddialog.h"
#include "animations.h"
#include "roomhandler.h"
#include "../app/request/type.h"

#include <QString>
#include <iostream>

PasswordDialog::PasswordDialog(QWidget *parent, const QString& correctPassword) :
    QDialog(parent),
    ui(new Ui::PasswordDialog),
    correctPassword(correctPassword)
{
    setModal(true);
    ui->setupUi(this);
    setWindowTitle("Room Password");
}

void PasswordDialog::on_submitPushButton_clicked()
{
    QString enteredPassword = ui->passwordLineEdit->text();
    RoomHandler roomHandler;
    roomHandler.requestJoinRoom(6, true, "1234");
    json response = roomHandler.responseJoinRoom();
    std::cout << response.dump(4) << std::endl;
    std::string status = response["status"];
    // if (status == SUCCESS)

    if(enteredPassword == correctPassword) {
        accept();
    } else {
        Animations::moveBothX(ui->lockIcon, 50, 20);
    }
}

PasswordDialog::~PasswordDialog()
{
    delete ui;
}


