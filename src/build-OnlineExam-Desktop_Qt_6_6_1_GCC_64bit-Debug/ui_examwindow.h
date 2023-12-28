/********************************************************************************
** Form generated from reading UI file 'examwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXAMWINDOW_H
#define UI_EXAMWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ExamWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QWidget *widget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QWidget *widget_3;
    QLabel *label;
    QLabel *label_2;
    QWidget *widget_2;
    QWidget *widget_4;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;

    void setupUi(QMainWindow *ExamWindow)
    {
        if (ExamWindow->objectName().isEmpty())
            ExamWindow->setObjectName("ExamWindow");
        ExamWindow->resize(1280, 712);
        ExamWindow->setStyleSheet(QString::fromUtf8("QMainWindow {\n"
"	background-color: rgb(224,224,224);\n"
"}"));
        centralwidget = new QWidget(ExamWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(4);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        widget->setStyleSheet(QString::fromUtf8("#widget {\n"
"	background-color: #fff;\n"
"	border-right: 1px solid #e2e8f0;\n"
"}"));
        gridLayoutWidget = new QWidget(widget);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(10, 120, 401, 561));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        widget_3 = new QWidget(widget);
        widget_3->setObjectName("widget_3");
        widget_3->setGeometry(QRect(10, 30, 401, 61));
        widget_3->setStyleSheet(QString::fromUtf8("border-bottom: 1px solid #e2e8f0;"));
        label = new QLabel(widget_3);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 20, 151, 22));
        QFont font;
        font.setFamilies({QString::fromUtf8("Source Sans 3 SemiBold")});
        font.setPointSize(18);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("border: none;"));
        label_2 = new QLabel(widget_3);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(240, 20, 151, 22));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Source Sans 3")});
        font1.setPointSize(22);
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("border: none;"));

        horizontalLayout->addWidget(widget);

        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName("widget_2");
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(8);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy1);
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Source Sans 3")});
        font2.setPointSize(12);
        widget_2->setFont(font2);
        widget_2->setStyleSheet(QString::fromUtf8("background-color: #fff;"));
        widget_4 = new QWidget(widget_2);
        widget_4->setObjectName("widget_4");
        widget_4->setGeometry(QRect(10, 10, 811, 151));
        widget_4->setStyleSheet(QString::fromUtf8("#widget_4{\n"
"	border-bottom: 1px solid #e2e8f0;\n"
"}"));
        label_3 = new QLabel(widget_4);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 30, 161, 31));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Source Sans 3")});
        font3.setPointSize(24);
        font3.setBold(true);
        font3.setItalic(false);
        label_3->setFont(font3);
        label_4 = new QLabel(widget_4);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(20, 80, 771, 61));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Source Sans 3")});
        label_4->setFont(font4);
        label_4->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_4->setWordWrap(true);
        label_5 = new QLabel(widget_2);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(30, 180, 281, 22));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Source Sans 3")});
        font5.setPointSize(12);
        font5.setBold(false);
        label_5->setFont(font5);

        horizontalLayout->addWidget(widget_2);

        ExamWindow->setCentralWidget(centralwidget);

        retranslateUi(ExamWindow);

        QMetaObject::connectSlotsByName(ExamWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ExamWindow)
    {
        ExamWindow->setWindowTitle(QCoreApplication::translate("ExamWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("ExamWindow", "Question List", nullptr));
        label_2->setText(QCoreApplication::translate("ExamWindow", "1h 47m 13s", nullptr));
        label_3->setText(QCoreApplication::translate("ExamWindow", "Question 1", nullptr));
        label_4->setText(QCoreApplication::translate("ExamWindow", "Which of the following is appropriate as the characteristic of single sign-on?", nullptr));
        label_5->setText(QCoreApplication::translate("ExamWindow", "Choose the correct answer:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ExamWindow: public Ui_ExamWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXAMWINDOW_H
