/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QWidget *widget_6;
    QLabel *label;
    QLabel *emailInfoLabel;
    QLabel *nameInfoLabel;
    QWidget *widget_3;
    QLabel *label_4;
    QLabel *label_5;
    QWidget *widget_4;
    QLabel *label_8;
    QLabel *label_9;
    QWidget *widget_5;
    QLabel *label_12;
    QLabel *label_13;
    QSpacerItem *verticalSpacer;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_6;
    QWidget *widget_10;
    QPushButton *pushButton;
    QStackedWidget *stackedWidget;
    QWidget *page_1;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget_7;
    QHBoxLayout *horizontalLayout_2;
    QWidget *widget_8;
    QLineEdit *lineEdit;
    QWidget *widget_9;
    QScrollArea *scrollArea;
    QWidget *roomList;
    QWidget *page_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1316, 740);
        QFont font;
        font.setFamilies({QString::fromUtf8("Source Sans 3")});
        MainWindow->setFont(font);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color:rgb(242, 242, 242);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(2);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        widget->setMinimumSize(QSize(0, 0));
        widget->setMaximumSize(QSize(16777215, 16777215));
        widget->setContextMenuPolicy(Qt::ActionsContextMenu);
        widget->setLayoutDirection(Qt::LeftToRight);
        widget->setStyleSheet(QString::fromUtf8("background-color: #082540;"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        widget_6 = new QWidget(widget);
        widget_6->setObjectName("widget_6");
        widget_6->setMinimumSize(QSize(0, 80));
        widget_6->setMaximumSize(QSize(16777215, 60));
        widget_6->setStyleSheet(QString::fromUtf8("background: none;"));
        label = new QLabel(widget_6);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 0, 40, 40));
        label->setStyleSheet(QString::fromUtf8("background: none;"));
        label->setPixmap(QPixmap(QString::fromUtf8("../Downloads/Group 1.svg")));
        label->setScaledContents(true);
        emailInfoLabel = new QLabel(widget_6);
        emailInfoLabel->setObjectName("emailInfoLabel");
        emailInfoLabel->setGeometry(QRect(60, 0, 75, 22));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Source Sans 3 Medium")});
        font1.setBold(false);
        emailInfoLabel->setFont(font1);
        emailInfoLabel->setStyleSheet(QString::fromUtf8("font-size: 16px;\n"
"background: none;\n"
"color: #fff;"));
        nameInfoLabel = new QLabel(widget_6);
        nameInfoLabel->setObjectName("nameInfoLabel");
        nameInfoLabel->setGeometry(QRect(60, 20, 131, 22));
        nameInfoLabel->setFont(font1);
        nameInfoLabel->setStyleSheet(QString::fromUtf8("font-size: 14px;\n"
"background: none;\n"
"color: #fff;"));

        verticalLayout->addWidget(widget_6);

        widget_3 = new QWidget(widget);
        widget_3->setObjectName("widget_3");
        widget_3->setMinimumSize(QSize(0, 46));
        widget_3->setMaximumSize(QSize(16777215, 46));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Source Sans 3 Medium")});
        widget_3->setFont(font2);
        widget_3->setAutoFillBackground(false);
        widget_3->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 191, 154);\n"
"border-radius: 8px;\n"
"border: none;"));
        label_4 = new QLabel(widget_3);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(20, 10, 21, 20));
        label_4->setPixmap(QPixmap(QString::fromUtf8("../Downloads/svgexport-7.svg")));
        label_4->setScaledContents(true);
        label_5 = new QLabel(widget_3);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(50, 10, 75, 22));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Source Sans 3")});
        font3.setBold(true);
        font3.setItalic(false);
        label_5->setFont(font3);
        label_5->setStyleSheet(QString::fromUtf8("border: none;\n"
"color: #fff;\n"
"width: 100%;"));

        verticalLayout->addWidget(widget_3);

        widget_4 = new QWidget(widget);
        widget_4->setObjectName("widget_4");
        widget_4->setMinimumSize(QSize(0, 46));
        widget_4->setMaximumSize(QSize(16777215, 46));
        widget_4->setStyleSheet(QString::fromUtf8("background: none;\n"
"border-radius: 8px;"));
        label_8 = new QLabel(widget_4);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(20, 10, 20, 20));
        label_8->setPixmap(QPixmap(QString::fromUtf8("../Downloads/svgexport-18.svg")));
        label_8->setScaledContents(true);
        label_9 = new QLabel(widget_4);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(50, 10, 75, 22));
        label_9->setFont(font2);
        label_9->setStyleSheet(QString::fromUtf8("border: none;\n"
"color: #fff;"));

        verticalLayout->addWidget(widget_4);

        widget_5 = new QWidget(widget);
        widget_5->setObjectName("widget_5");
        widget_5->setMinimumSize(QSize(0, 46));
        widget_5->setMaximumSize(QSize(16777215, 46));
        widget_5->setStyleSheet(QString::fromUtf8("background: none;\n"
"border-radius: 8px;"));
        label_12 = new QLabel(widget_5);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(20, 10, 20, 20));
        label_12->setPixmap(QPixmap(QString::fromUtf8("../Downloads/svgexport-17.svg")));
        label_12->setScaledContents(true);
        label_13 = new QLabel(widget_5);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(50, 10, 75, 22));
        label_13->setFont(font2);
        label_13->setStyleSheet(QString::fromUtf8("border: none;\n"
"color: #fff;"));

        verticalLayout->addWidget(widget_5);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addWidget(widget);

        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName("widget_2");
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(10);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy1);
        widget_2->setAutoFillBackground(false);
        verticalLayout_2 = new QVBoxLayout(widget_2);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(10, 4, 10, 0);
        label_6 = new QLabel(widget_2);
        label_6->setObjectName("label_6");
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Source Sans 3 SemiBold")});
        font4.setPointSize(20);
        label_6->setFont(font4);
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(9, 44, 76);"));

        verticalLayout_2->addWidget(label_6);

        widget_10 = new QWidget(widget_2);
        widget_10->setObjectName("widget_10");
        widget_10->setMinimumSize(QSize(0, 50));
        pushButton = new QPushButton(widget_10);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(900, 0, 140, 40));
        pushButton->setMinimumSize(QSize(140, 40));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(9, 44, 76, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush2(QColor(255, 255, 255, 128));
        brush2.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush2);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        QBrush brush3(QColor(255, 255, 255, 128));
        brush3.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush3);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        QBrush brush4(QColor(255, 255, 255, 128));
        brush4.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush4);
#endif
        pushButton->setPalette(palette);
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Source Sans 3")});
        font5.setBold(true);
        pushButton->setFont(font5);
        pushButton->setAutoFillBackground(false);
        pushButton->setStyleSheet(QString::fromUtf8("#pushButton {\n"
"	background-color:rgb(9, 44, 76);\n"
"	border-radius: 8px;\n"
"	color: #fff;\n"
"	border: none;\n"
"}\n"
"\n"
"#pushButton:hover {\n"
"	background-color:rgba(9, 44, 76, 0.9);\n"
"}"));

        verticalLayout_2->addWidget(widget_10, 0, Qt::AlignVCenter);

        stackedWidget = new QStackedWidget(widget_2);
        stackedWidget->setObjectName("stackedWidget");
        page_1 = new QWidget();
        page_1->setObjectName("page_1");
        verticalLayout_3 = new QVBoxLayout(page_1);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        widget_7 = new QWidget(page_1);
        widget_7->setObjectName("widget_7");
        horizontalLayout_2 = new QHBoxLayout(widget_7);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 10);
        widget_8 = new QWidget(widget_7);
        widget_8->setObjectName("widget_8");
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(4);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(widget_8->sizePolicy().hasHeightForWidth());
        widget_8->setSizePolicy(sizePolicy2);
        widget_8->setStyleSheet(QString::fromUtf8("background-color: #fff;\n"
"border: 1px solid rgb(237, 240, 245);\n"
"border-radius: 8px;"));
        lineEdit = new QLineEdit(widget_8);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(27, 30, 301, 41));
        QFont font6;
        font6.setFamilies({QString::fromUtf8("Source Sans 3")});
        font6.setPointSize(11);
        lineEdit->setFont(font6);
        lineEdit->setStyleSheet(QString::fromUtf8("padding-left:16px;\n"
"background-color: rgb(237, 240, 245);\n"
"border-radius: 20px;"));

        horizontalLayout_2->addWidget(widget_8);

        widget_9 = new QWidget(widget_7);
        widget_9->setObjectName("widget_9");
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(8);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(widget_9->sizePolicy().hasHeightForWidth());
        widget_9->setSizePolicy(sizePolicy3);
        scrollArea = new QScrollArea(widget_9);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(0, 0, 711, 631));
        scrollArea->setStyleSheet(QString::fromUtf8("border: none;"));
        scrollArea->setWidgetResizable(true);
        roomList = new QWidget();
        roomList->setObjectName("roomList");
        roomList->setGeometry(QRect(0, 0, 711, 631));
        roomList->setStyleSheet(QString::fromUtf8(""));
        scrollArea->setWidget(roomList);

        horizontalLayout_2->addWidget(widget_9);


        verticalLayout_3->addWidget(widget_7);

        stackedWidget->addWidget(page_1);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        stackedWidget->addWidget(page_2);

        verticalLayout_2->addWidget(stackedWidget);


        horizontalLayout->addWidget(widget_2);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QString());
        emailInfoLabel->setText(QCoreApplication::translate("MainWindow", "Tien Dat", nullptr));
        nameInfoLabel->setText(QCoreApplication::translate("MainWindow", "dat@gmail.com", nullptr));
        label_4->setText(QString());
        label_5->setText(QCoreApplication::translate("MainWindow", "Exam", nullptr));
        label_8->setText(QString());
        label_9->setText(QCoreApplication::translate("MainWindow", "Practice", nullptr));
        label_12->setText(QString());
        label_13->setText(QCoreApplication::translate("MainWindow", "History", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Examination Rooms", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Create Exam", nullptr));
        lineEdit->setText(QString());
        lineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Search...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
