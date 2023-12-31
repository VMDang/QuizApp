#ifndef LOBBYWINDOW_H
#define LOBBYWINDOW_H

#include <QMainWindow>

namespace Ui {
class LobbyWindow;
}

class LobbyWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit LobbyWindow(QWidget *parent = nullptr, const QString &room_id = nullptr);
    ~LobbyWindow();

private slots:
    void on_startExamButton_clicked();

    void on_readyExamButton_clicked();

    void on_unReadyExamButton_clicked();

private:
    Ui::LobbyWindow *ui;
};

#endif // LOBBYWINDOW_H
