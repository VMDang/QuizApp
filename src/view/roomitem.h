#ifndef RoomItem_H
#define RoomItem_H

#include <QWidget>

namespace Ui {
class RoomItem;
}

class RoomItem : public QWidget
{
    Q_OBJECT

public:
    explicit RoomItem(QWidget *parent = nullptr, const QString &room_id = "",
                      bool isPrivate = false, const QString& password = "");
    ~RoomItem();

signals:
    void joinPushButton_clicked(const QString& room_id, bool isPrivate, const QString& password);

private slots:
    void on_joinPushButton_clicked();

private:
    Ui::RoomItem *ui;
    QString roomId;
    bool isPrivate;
    QString password;
};

#endif // RoomItem_H
