#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

//QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
//QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void openWaittingRoom(const QString &room_id);

private slots:
    void on_loggoutButton_clicked();

    void on_createRoomButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
