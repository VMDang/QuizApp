/********************************************************************************
** Form generated from reading UI file 'lobbywindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOBBYWINDOW_H
#define UI_LOBBYWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LobbyWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QWidget *widget;
    QPushButton *pushButton;
    QWidget *widget_10;
    QWidget *widget_3;
    QLabel *label;
    QLabel *examNameLabel;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLabel *label_4;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_9;
    QLabel *label_10;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QWidget *widget_7;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_15;
    QLabel *label_16;
    QWidget *widget_8;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_19;
    QLabel *label_20;
    QWidget *widget_9;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_21;
    QLabel *label_22;
    QPushButton *pushButton_2;
    QWidget *widget_2;
    QTableWidget *tableWidget;

    void setupUi(QMainWindow *LobbyWindow)
    {
        if (LobbyWindow->objectName().isEmpty())
            LobbyWindow->setObjectName("LobbyWindow");
        LobbyWindow->resize(1280, 712);
        LobbyWindow->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: rgb(9, 44, 76);\n"
"}\n"
"QMainWindow {\n"
"	background-color: rgb(224,224,224);\n"
"}"));
        centralwidget = new QWidget(LobbyWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setSpacing(30);
        horizontalLayout->setObjectName("horizontalLayout");
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(7);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        pushButton = new QPushButton(widget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(10, 10, 121, 31));
        QFont font;
        font.setFamilies({QString::fromUtf8("Source Sans 3")});
        font.setBold(true);
        font.setItalic(false);
        pushButton->setFont(font);
        pushButton->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton->setStyleSheet(QString::fromUtf8("#pushButton {\n"
"	background-color: rgb(230, 65, 65);\n"
"	border: none;\n"
"	border-radius: 4px;\n"
"	color: #fff;\n"
"}\n"
"#pushButton:hover {\n"
"	background-color: rgba(230, 65, 65, 0.9);\n"
"}\n"
""));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../Downloads/svgexport-9-1.svg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);
        widget_10 = new QWidget(widget);
        widget_10->setObjectName("widget_10");
        widget_10->setGeometry(QRect(9, 60, 711, 631));
        widget_10->setStyleSheet(QString::fromUtf8("background-color: #fff;\n"
"border-radius: 8px;"));
        widget_3 = new QWidget(widget_10);
        widget_3->setObjectName("widget_3");
        widget_3->setGeometry(QRect(10, 10, 691, 421));
        label = new QLabel(widget_3);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 60, 181, 22));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Source Sans 3")});
        font1.setPointSize(16);
        label->setFont(font1);
        examNameLabel = new QLabel(widget_3);
        examNameLabel->setObjectName("examNameLabel");
        examNameLabel->setGeometry(QRect(10, 10, 381, 41));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Source Sans 3")});
        font2.setPointSize(24);
        font2.setBold(true);
        examNameLabel->setFont(font2);
        examNameLabel->setStyleSheet(QString::fromUtf8("color: rgb(9, 44, 76)"));
        widget_4 = new QWidget(widget_3);
        widget_4->setObjectName("widget_4");
        widget_4->setGeometry(QRect(20, 80, 211, 43));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Source Sans 3")});
        widget_4->setFont(font3);
        horizontalLayout_2 = new QHBoxLayout(widget_4);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_2 = new QLabel(widget_4);
        label_2->setObjectName("label_2");
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Source Sans 3")});
        font4.setPointSize(14);
        label_2->setFont(font4);

        horizontalLayout_2->addWidget(label_2);

        label_4 = new QLabel(widget_4);
        label_4->setObjectName("label_4");
        label_4->setFont(font4);

        horizontalLayout_2->addWidget(label_4);

        widget_5 = new QWidget(widget_3);
        widget_5->setObjectName("widget_5");
        widget_5->setGeometry(QRect(20, 120, 187, 40));
        widget_5->setFont(font3);
        horizontalLayout_3 = new QHBoxLayout(widget_5);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(9, 4, -1, 4);
        label_9 = new QLabel(widget_5);
        label_9->setObjectName("label_9");
        label_9->setFont(font4);

        horizontalLayout_3->addWidget(label_9);

        label_10 = new QLabel(widget_5);
        label_10->setObjectName("label_10");
        label_10->setFont(font4);

        horizontalLayout_3->addWidget(label_10);

        widget_6 = new QWidget(widget_3);
        widget_6->setObjectName("widget_6");
        widget_6->setGeometry(QRect(20, 160, 201, 40));
        widget_6->setFont(font3);
        horizontalLayout_4 = new QHBoxLayout(widget_6);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(-1, 4, -1, 4);
        label_11 = new QLabel(widget_6);
        label_11->setObjectName("label_11");
        label_11->setFont(font4);

        horizontalLayout_4->addWidget(label_11);

        label_12 = new QLabel(widget_6);
        label_12->setObjectName("label_12");
        label_12->setFont(font4);

        horizontalLayout_4->addWidget(label_12);

        label_13 = new QLabel(widget_3);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(30, 200, 431, 40));
        label_13->setFont(font4);
        label_13->setWordWrap(true);
        label_14 = new QLabel(widget_3);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(10, 260, 171, 22));
        label_14->setFont(font1);
        widget_7 = new QWidget(widget_3);
        widget_7->setObjectName("widget_7");
        widget_7->setGeometry(QRect(30, 290, 183, 42));
        widget_7->setFont(font3);
        horizontalLayout_5 = new QHBoxLayout(widget_7);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_15 = new QLabel(widget_7);
        label_15->setObjectName("label_15");
        label_15->setFont(font4);

        horizontalLayout_5->addWidget(label_15);

        label_16 = new QLabel(widget_7);
        label_16->setObjectName("label_16");
        label_16->setFont(font4);

        horizontalLayout_5->addWidget(label_16);

        widget_8 = new QWidget(widget_3);
        widget_8->setObjectName("widget_8");
        widget_8->setGeometry(QRect(30, 330, 198, 42));
        widget_8->setFont(font4);
        horizontalLayout_6 = new QHBoxLayout(widget_8);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        label_19 = new QLabel(widget_8);
        label_19->setObjectName("label_19");
        label_19->setFont(font4);

        horizontalLayout_6->addWidget(label_19);

        label_20 = new QLabel(widget_8);
        label_20->setObjectName("label_20");
        label_20->setFont(font3);

        horizontalLayout_6->addWidget(label_20);

        widget_9 = new QWidget(widget_3);
        widget_9->setObjectName("widget_9");
        widget_9->setGeometry(QRect(30, 370, 166, 40));
        widget_9->setFont(font4);
        horizontalLayout_7 = new QHBoxLayout(widget_9);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        label_21 = new QLabel(widget_9);
        label_21->setObjectName("label_21");
        label_21->setFont(font3);

        horizontalLayout_7->addWidget(label_21);

        label_22 = new QLabel(widget_9);
        label_22->setObjectName("label_22");
        label_22->setFont(font3);

        horizontalLayout_7->addWidget(label_22);

        pushButton_2 = new QPushButton(widget_10);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(240, 480, 261, 50));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Source Sans 3")});
        font5.setBold(true);
        pushButton_2->setFont(font5);
        pushButton_2->setStyleSheet(QString::fromUtf8("#pushButton_2 {\n"
"	background-color: rgb(9, 44, 76);\n"
"	border: none;\n"
"	color: #fff;\n"
"	border-radius: 25px;\n"
"}\n"
"\n"
"#pushButton_2:hover {\n"
"	background-color: rgba(9, 44, 76, 0.9);\n"
"}"));

        horizontalLayout->addWidget(widget);

        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName("widget_2");
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(5);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy1);
        tableWidget = new QTableWidget(widget_2);
        if (tableWidget->columnCount() < 3)
            tableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        if (tableWidget->rowCount() < 3)
            tableWidget->setRowCount(3);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setItem(0, 0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setItem(0, 1, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setItem(0, 2, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setItem(1, 0, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setItem(2, 0, __qtablewidgetitem10);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(0, 0, 511, 691));
        tableWidget->setFont(font3);
        tableWidget->setStyleSheet(QString::fromUtf8("QHeaderView::section { \n"
"	background-color: rgb(9, 44, 76);\n"
"	border-radius: 20px;\n"
"	color: #fff;\n"
"}"));
        tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget->setGridStyle(Qt::SolidLine);
        tableWidget->horizontalHeader()->setDefaultSectionSize(170);
        tableWidget->horizontalHeader()->setStretchLastSection(false);
        tableWidget->verticalHeader()->setVisible(false);
        tableWidget->verticalHeader()->setMinimumSectionSize(30);
        tableWidget->verticalHeader()->setDefaultSectionSize(50);

        horizontalLayout->addWidget(widget_2);

        LobbyWindow->setCentralWidget(centralwidget);

        retranslateUi(LobbyWindow);

        QMetaObject::connectSlotsByName(LobbyWindow);
    } // setupUi

    void retranslateUi(QMainWindow *LobbyWindow)
    {
        LobbyWindow->setWindowTitle(QCoreApplication::translate("LobbyWindow", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("LobbyWindow", "Leave", nullptr));
        label->setText(QCoreApplication::translate("LobbyWindow", "General information: ", nullptr));
        examNameLabel->setText(QCoreApplication::translate("LobbyWindow", "C Programing for beginner ", nullptr));
        label_2->setText(QCoreApplication::translate("LobbyWindow", "Time limit: ", nullptr));
        label_4->setText(QCoreApplication::translate("LobbyWindow", "75 minutes", nullptr));
        label_9->setText(QCoreApplication::translate("LobbyWindow", "Questions: ", nullptr));
        label_10->setText(QCoreApplication::translate("LobbyWindow", "45", nullptr));
        label_11->setText(QCoreApplication::translate("LobbyWindow", "Maximum score: ", nullptr));
        label_12->setText(QCoreApplication::translate("LobbyWindow", "100", nullptr));
        label_13->setText(QCoreApplication::translate("LobbyWindow", "All questions are in single-choice question type.", nullptr));
        label_14->setText(QCoreApplication::translate("LobbyWindow", "Exam structure: ", nullptr));
        label_15->setText(QCoreApplication::translate("LobbyWindow", "Easy:", nullptr));
        label_16->setText(QCoreApplication::translate("LobbyWindow", "20 questions", nullptr));
        label_19->setText(QCoreApplication::translate("LobbyWindow", "Medium:", nullptr));
        label_20->setText(QCoreApplication::translate("LobbyWindow", "15 questions", nullptr));
        label_21->setText(QCoreApplication::translate("LobbyWindow", "Hard:", nullptr));
        label_22->setText(QCoreApplication::translate("LobbyWindow", "10 questions", nullptr));
        pushButton_2->setText(QCoreApplication::translate("LobbyWindow", "START EXAM", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("LobbyWindow", "#", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("LobbyWindow", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("LobbyWindow", "Point", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("LobbyWindow", "New Row", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("LobbyWindow", "New Row", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("LobbyWindow", "New Row", nullptr));

        const bool __sortingEnabled = tableWidget->isSortingEnabled();
        tableWidget->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->item(0, 0);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("LobbyWindow", "1", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->item(0, 1);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("LobbyWindow", "Nguyen Tien Dat", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->item(0, 2);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("LobbyWindow", "1440", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->item(1, 0);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("LobbyWindow", "2", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->item(2, 0);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("LobbyWindow", "3", nullptr));
        tableWidget->setSortingEnabled(__sortingEnabled);

    } // retranslateUi

};

namespace Ui {
    class LobbyWindow: public Ui_LobbyWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOBBYWINDOW_H
