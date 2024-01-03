#ifndef PASSWORDDIALOG_H
#define PASSWORDDIALOG_H

#include <QDialog>
#include <QString>

namespace Ui {
class PasswordDialog;
}

class PasswordDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PasswordDialog(QWidget *parent = nullptr, const QString& correctPassword = "");
    ~PasswordDialog();

private slots:
    void on_submitPushButton_clicked();

private:
    Ui::PasswordDialog *ui;
    QString correctPassword;
};

#endif // PASSWORDDIALOG_H
