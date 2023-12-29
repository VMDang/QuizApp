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
    explicit RoomItem(QWidget *parent = nullptr, const QString &room_id = "");
    ~RoomItem();

signals:
    void joinPushButton_clicked(const QString &room_id);

private slots:
    void on_joinPushButton_clicked();

private:
    Ui::RoomItem *ui;
    QString room_id;
};

#endif // RoomItem_H
