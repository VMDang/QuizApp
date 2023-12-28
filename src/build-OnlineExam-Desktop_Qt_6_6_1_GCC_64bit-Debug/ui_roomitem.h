/********************************************************************************
** Form generated from reading UI file 'roomitem.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROOMITEM_H
#define UI_ROOMITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RoomItem
{
public:
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout;
    QWidget *widget_2;
    QLabel *label;
    QWidget *widget;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QPushButton *joinPushButton;

    void setupUi(QWidget *RoomItem)
    {
        if (RoomItem->objectName().isEmpty())
            RoomItem->setObjectName("RoomItem");
        RoomItem->resize(654, 140);
        RoomItem->setMinimumSize(QSize(654, 140));
        RoomItem->setMaximumSize(QSize(16777215, 140));
        RoomItem->setStyleSheet(QString::fromUtf8(""));
        widget_3 = new QWidget(RoomItem);
        widget_3->setObjectName("widget_3");
        widget_3->setGeometry(QRect(0, 0, 654, 140));
        widget_3->setStyleSheet(QString::fromUtf8("#widget_3  {\n"
"	border: 1px solid rgb(224, 224, 224);\n"
"}\n"
"QWidget {\n"
"	background-color: #fff;\n"
"	border-radius: 8px;\n"
"}"));
        horizontalLayout = new QHBoxLayout(widget_3);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(2, 2, 2, 2);
        widget_2 = new QWidget(widget_3);
        widget_2->setObjectName("widget_2");
        widget_2->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(5);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy);
        widget_2->setMaximumSize(QSize(16777215, 16777215));
        widget_2->setStyleSheet(QString::fromUtf8("border: none;"));
        label = new QLabel(widget_2);
        label->setObjectName("label");
        label->setGeometry(QRect(60, -10, 151, 151));
        label->setStyleSheet(QString::fromUtf8("background-color: none;"));
        label->setPixmap(QPixmap(QString::fromUtf8("../Downloads/exam.png")));
        label->setScaledContents(true);

        horizontalLayout->addWidget(widget_2);

        widget = new QWidget(widget_3);
        widget->setObjectName("widget");
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(7);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy1);
        widget->setStyleSheet(QString::fromUtf8(""));
        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 35, 341, 31));
        QFont font;
        font.setFamilies({QString::fromUtf8("Source Sans 3")});
        font.setPointSize(16);
        font.setBold(true);
        font.setKerning(false);
        font.setStyleStrategy(QFont::PreferAntialias);
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_2->setWordWrap(true);
        label_3 = new QLabel(widget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 10, 81, 24));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Source Sans 3")});
        font1.setPointSize(12);
        label_3->setFont(font1);
        label_3->setAutoFillBackground(false);
        label_3->setStyleSheet(QString::fromUtf8("border:1px solid rgb(39, 174, 96);\n"
"color: rgb(39, 174, 96);\n"
"border-radius: 8px;"));
        label_3->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(widget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 67, 28, 30));
        label_4->setPixmap(QPixmap(QString::fromUtf8("../Downloads/svgexport-10-1.svg")));
        label_4->setScaledContents(true);
        label_5 = new QLabel(widget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(85, 72, 21, 20));
        label_5->setPixmap(QPixmap(QString::fromUtf8("../Downloads/svgexport-14-1.svg")));
        label_5->setScaledContents(true);
        label_6 = new QLabel(widget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(161, 71, 20, 20));
        label_6->setPixmap(QPixmap(QString::fromUtf8("../Downloads/svgexport-11-1.svg")));
        label_6->setScaledContents(true);
        label_8 = new QLabel(widget);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(40, 67, 41, 30));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Source Sans 3")});
        font2.setPointSize(14);
        label_8->setFont(font2);
        label_9 = new QLabel(widget);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(112, 67, 41, 30));
        label_9->setFont(font2);
        label_10 = new QLabel(widget);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(188, 67, 41, 30));
        label_10->setFont(font2);
        joinPushButton = new QPushButton(widget);
        joinPushButton->setObjectName("joinPushButton");
        joinPushButton->setGeometry(QRect(267, 88, 98, 36));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Source Sans 3")});
        font3.setBold(true);
        joinPushButton->setFont(font3);
        joinPushButton->setStyleSheet(QString::fromUtf8("#joinPushButton {\n"
"	background-color: rgb(0, 191, 154);\n"
"	border-radius: 4px;\n"
"	color: #fff;\n"
"	border: none;\n"
"}\n"
"#joinPushButton:hover {\n"
"	border: 1px solid rgb(0, 191, 154);\n"
"	color: rgb(0, 191, 154);\n"
"	background: none;\n"
"}"));

        horizontalLayout->addWidget(widget);


        retranslateUi(RoomItem);

        QMetaObject::connectSlotsByName(RoomItem);
    } // setupUi

    void retranslateUi(QWidget *RoomItem)
    {
        RoomItem->setWindowTitle(QCoreApplication::translate("RoomItem", "Form", nullptr));
        label->setText(QString());
        label_2->setText(QCoreApplication::translate("RoomItem", "Introduction to Artificial Intelligence", nullptr));
        label_3->setText(QCoreApplication::translate("RoomItem", "Beginner", nullptr));
        label_4->setText(QString());
        label_5->setText(QString());
        label_6->setText(QString());
        label_8->setText(QCoreApplication::translate("RoomItem", "50", nullptr));
        label_9->setText(QCoreApplication::translate("RoomItem", "50", nullptr));
        label_10->setText(QCoreApplication::translate("RoomItem", "75m", nullptr));
        joinPushButton->setText(QCoreApplication::translate("RoomItem", "Join", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RoomItem: public Ui_RoomItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROOMITEM_H
