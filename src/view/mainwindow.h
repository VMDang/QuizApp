#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

//QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
//QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QWidget* createUserItem();
    QWidget* createResultItem();

public slots:
    void redirectToWaittingRoom();

    void checkRoomAcceptPms(const QString& room_id, bool isPrivate, const QString& password);
    // void* onlyReceiveThread(void* arg);

private slots:
    void on_createExamButton_clicked();

    void on_leaveButton_clicked();

    void on_examPushButton_clicked();

    void on_practicePushButton_clicked();

    void on_historyPushButton_clicked();

    void on_dashboardButton_clicked();

    void on_readyButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
