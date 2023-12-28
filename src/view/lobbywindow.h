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

private:
    Ui::LobbyWindow *ui;
};

#endif // LOBBYWINDOW_H
