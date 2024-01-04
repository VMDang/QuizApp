#include "createroomdialog.h"
#include "ui_createroomdialog.h"
#include "../app/request/room.h"
#include "roomhandler.h"

#include <vector>

createRoomDialog::createRoomDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::createRoomDialog)
{
    ui->setupUi(this);
    setModal(true);
    setWindowTitle("Create Room");

    ui->passwordInput->hide();
    QStringList categories = QStringList() << "caterogy 1" << "category 2" << "category 3";
    ui->categoryComboBox->addItems(categories);
}

void createRoomDialog::on_nextButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void createRoomDialog::on_createButton_clicked()
{
    QString name = ui->nameLineEdit->text();
    int time_limit = ui->timeSpinBox->value();
    int capacity = ui->capacitySpinBox->value();
    bool is_private = false;
    if(ui->privateRadioButton->isChecked()) is_private = true;
    QString password = ui->passwordLineEdit->text();
    int category_id = ui->categoryComboBox->currentIndex();

    std::vector<int> question_config;
    question_config.push_back(ui->level1SpinBox->value());
    question_config.push_back(ui->level2SpinBox->value());
    question_config.push_back(ui->level3SpinBox->value());
    question_config.push_back(ui->level4SpinBox->value());
    question_config.push_back(ui->level5SpinBox->value());


    QuestionsExam questions_exam;
    questions_exam.category_id = category_id;     // Fake
    questions_exam.question_config = question_config;

    RequestCreateRoomBody body;
    body.name = name.toStdString();
    body.capacity = capacity;
    body.time_limit = time_limit;
    body.is_private = is_private;
    body.password = password.toStdString();
    body.type = ROOM_EXAM_TYPE;

    RoomHandler roomHandler;
    roomHandler.requestCreateRoom(body, questions_exam);
    json response = roomHandler.responseCreateRoom();

    std::cout << response.dump() << std::endl;
}

void createRoomDialog::on_backButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void createRoomDialog::on_privateRadioButton_clicked()
{
    if(ui->privateRadioButton->isChecked()){
        ui->passwordInput->show();
    } else {
        ui->passwordInput->hide();
    }
}


createRoomDialog::~createRoomDialog()
{
    delete ui;
}
