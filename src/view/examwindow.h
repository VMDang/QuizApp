#ifndef EXAMWINDOW_H
#define EXAMWINDOW_H

#include "questionclient.h"
#include "questionbutton.h"

#include <QMainWindow>
#include <QVector>
#include <QPair>

namespace Ui {
class ExamWindow;
}

class ExamWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ExamWindow(QWidget *parent = nullptr);
    ~ExamWindow();
    void loadQuestions();
    void setupQuestion(QuestionClient question);
    void handleSelectOption();
    void countdown();

private slots:
    void on_questionButton_clicked(int index);

    void updateCountdown();

    void on_clearButton_clicked();

    void on_nextButton_clicked();

    void on_gobackButton_clicked();

private:
    QVector<QuestionClient> questions;
    QVector<QuestionButton*> questionButtons;
    int currentIndex = 0;
    int remainingTime = 3600;
    QTimer *countdownTimer;
    Ui::ExamWindow *ui;
};

#endif // EXAMWINDOW_H
