/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QWidget *widget_2;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton;
    QWidget *widget_5;
    QLabel *label_5;
    QWidget *widget_3;
    QLineEdit *emailLineEdit;
    QLabel *label_3;
    QWidget *widget_4;
    QLabel *label_4;
    QLineEdit *passwordLineEdit;
    QPushButton *loginPushButton;

    void setupUi(QMainWindow *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName("LoginWindow");
        LoginWindow->resize(1280, 720);
        LoginWindow->setStyleSheet(QString::fromUtf8("#centralwidget {\n"
"	background-image: url(/home/tiendat/Downloads/Frame2.png);\n"
"}\n"
"#label_2, #label {\n"
"	color: rgba(255,255,255,0.9);\n"
"}"));
        centralwidget = new QWidget(LoginWindow);
        centralwidget->setObjectName("centralwidget");
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(30, 39, 1220, 641));
        widget_2 = new QWidget(widget);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(0, 0, 471, 641));
        label = new QLabel(widget_2);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 210, 421, 31));
        QFont font;
        font.setFamilies({QString::fromUtf8("Source Sans 3")});
        font.setPointSize(36);
        font.setBold(true);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8(""));
        label_2 = new QLabel(widget_2);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(40, 280, 361, 51));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Source Sans 3")});
        font1.setPointSize(14);
        label_2->setFont(font1);
        label_2->setCursor(QCursor(Qt::UpArrowCursor));
        label_2->setLineWidth(1);
        label_2->setAlignment(Qt::AlignCenter);
        label_2->setWordWrap(true);
        pushButton = new QPushButton(widget_2);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(130, 370, 190, 50));
        QFont font2;
        font2.setPointSize(12);
        pushButton->setFont(font2);
        pushButton->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: 2px solid rgba(255,255,255,0.9);\n"
"	color: rgba(255,255,255,0.9);	\n"
"	border-radius: 25px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: rgba(255,255,255,0.9);\n"
"	color: #009E7F;\n"
"}"));
        widget_5 = new QWidget(widget);
        widget_5->setObjectName("widget_5");
        widget_5->setGeometry(QRect(470, -30, 751, 641));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget_5->sizePolicy().hasHeightForWidth());
        widget_5->setSizePolicy(sizePolicy);
        label_5 = new QLabel(widget_5);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(180, 170, 381, 70));
        label_5->setFont(font);
        label_5->setStyleSheet(QString::fromUtf8("color: #009E7F;"));
        label_5->setAlignment(Qt::AlignCenter);
        widget_3 = new QWidget(widget_5);
        widget_3->setObjectName("widget_3");
        widget_3->setGeometry(QRect(140, 240, 481, 111));
        widget_3->setMaximumSize(QSize(16777215, 16777215));
        emailLineEdit = new QLineEdit(widget_3);
        emailLineEdit->setObjectName("emailLineEdit");
        emailLineEdit->setGeometry(QRect(10, 40, 461, 51));
        emailLineEdit->setMinimumSize(QSize(0, 50));
        emailLineEdit->setMaximumSize(QSize(16777215, 16777215));
        emailLineEdit->setStyleSheet(QString::fromUtf8("border: 1px solid rgba(0,0,0,0.2);\n"
"border-radius: 4px;\n"
"padding-left: 10px;\n"
""));
        emailLineEdit->setEchoMode(QLineEdit::Normal);
        label_3 = new QLabel(widget_3);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 10, 61, 20));
        label_3->setMaximumSize(QSize(16777215, 20));
        label_3->setFont(font1);
        label_3->setStyleSheet(QString::fromUtf8("color: #000;"));
        widget_4 = new QWidget(widget_5);
        widget_4->setObjectName("widget_4");
        widget_4->setGeometry(QRect(140, 350, 481, 101));
        label_4 = new QLabel(widget_4);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 0, 91, 22));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Source Sans 3 Medium")});
        font3.setPointSize(14);
        label_4->setFont(font3);
        label_4->setStyleSheet(QString::fromUtf8("color: #000;"));
        passwordLineEdit = new QLineEdit(widget_4);
        passwordLineEdit->setObjectName("passwordLineEdit");
        passwordLineEdit->setGeometry(QRect(10, 30, 461, 51));
        passwordLineEdit->setStyleSheet(QString::fromUtf8("border: 1px solid rgba(0,0,0,0.2);\n"
"border-radius: 4px;\n"
"padding-left: 10px;"));
        passwordLineEdit->setEchoMode(QLineEdit::Password);
        loginPushButton = new QPushButton(widget_5);
        loginPushButton->setObjectName("loginPushButton");
        loginPushButton->setGeometry(QRect(290, 470, 190, 50));
        loginPushButton->setMinimumSize(QSize(0, 50));
        loginPushButton->setMaximumSize(QSize(190, 16777215));
        loginPushButton->setFont(font2);
        loginPushButton->setCursor(QCursor(Qt::PointingHandCursor));
        loginPushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: rgba(255,255,255,0.9);\n"
"	background-color: #009E7F;\n"
"	border-radius: 25px;\n"
"}\n"
"\n"
"QPushButton:hover 	{\n"
"	border: 2px solid #009E7F;\n"
"	color: #009E7F;	\n"
"	background-color: rgba(255,255,255,0.9);\n"
"}\n"
"\n"
""));
        LoginWindow->setCentralWidget(centralwidget);

        retranslateUi(LoginWindow);

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QMainWindow *LoginWindow)
    {
        LoginWindow->setWindowTitle(QCoreApplication::translate("LoginWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("LoginWindow", "Create Account", nullptr));
        label_2->setText(QCoreApplication::translate("LoginWindow", "Efficient and Convenient Exam Experience Like Never Before", nullptr));
        pushButton->setText(QCoreApplication::translate("LoginWindow", "SIGN UP", nullptr));
        label_5->setText(QCoreApplication::translate("LoginWindow", "Welcom Back!", nullptr));
        emailLineEdit->setPlaceholderText(QString());
        label_3->setText(QCoreApplication::translate("LoginWindow", "Email", nullptr));
        label_4->setText(QCoreApplication::translate("LoginWindow", "Password", nullptr));
        passwordLineEdit->setText(QString());
        loginPushButton->setText(QCoreApplication::translate("LoginWindow", "SIGN IN", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
