#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "mainwindow.h"

#include "../app/comunicate/client.h"
#include "../app/request/login.h"
#include "../../library/json.hpp"
#include "clientmanager.h"

#include <QString>
#include <QMessageBox>

using json = nlohmann::json;

LoginWindow::LoginWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    setWindowTitle("Login");
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_loginPushButton_clicked()
{
    if(ui->emailLineEdit->text().isEmpty()) {
        QMessageBox::warning(this, "Login Failed", "Email required");
        return;
    } else if(ui->passwordLineEdit->text().isEmpty()) {
        QMessageBox::warning(this, "Login Failed", "Password required");
        return;
    } else {
        RequestLoginBody LoginBody;
        LoginBody.email = ui->emailLineEdit->text().toUtf8().constData();
        LoginBody.password = ui->passwordLineEdit->text().toUtf8().constData();

        RequestLogin login;
        login.body = LoginBody;

        int bytes_sent;
        int bytes_received;
        char buff[BUFF_SIZE];

        std::string dataTemp = login.toJson().dump();

        const char* sendData = dataTemp.c_str();

        bytes_sent = sendToServer(sendData);

        bytes_received = recvFromServer(buff);
        json responseLogin = json::parse(buff);

        std::string status = responseLogin["status"];

        if (status == FAILURE) {
            QMessageBox::warning(this, "Login Failed", QString::fromStdString(responseLogin["body"]["message"]));
        } else if (status == SUCCESS) {
            json user = responseLogin["body"]["user"];
            ClientManager::authUser = user;

            LoginWindow::hide();
            MainWindow *mainWindow = new MainWindow(this);
            mainWindow->show();
        } else {
            QMessageBox::warning(this, "ERROR", "Error system");
        }
    }

}
