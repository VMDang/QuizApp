#include "examwindow.h"
#include "ui_examwindow.h"

#include <QPushButton>

ExamWindow::ExamWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ExamWindow)
{
    ui->setupUi(this);

    // Khởi tạo danh sách câu hỏi
    QGridLayout *questionList = ui->gridLayout;
    for(int row = 0; row < 5; row++){
        for(int col = 0; col < 5; col++){
            QPushButton *button = new QPushButton(QString::number(row * 5 + col + 1));
            button->setStyleSheet("background-color: red; border: none; min-height: 50px; max-width: 50px;");
            questionList->addWidget(button, row, col);
        }
    }
}

ExamWindow::~ExamWindow()
{
    delete ui;
}
