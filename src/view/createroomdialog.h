#ifndef CREATEROOMDIALOG_H
#define CREATEROOMDIALOG_H

#include <QDialog>

namespace Ui {
class createRoomDialog;
}

class createRoomDialog : public QDialog
{
    Q_OBJECT

public:
    explicit createRoomDialog(QWidget *parent = nullptr);
    ~createRoomDialog();

private slots:
    void on_nextButton_clicked();

    void on_createButton_clicked();

    void on_backButton_clicked();

    void on_privateRadioButton_clicked();

private:
    Ui::createRoomDialog *ui;
};

#endif // CREATEROOMDIALOG_H
