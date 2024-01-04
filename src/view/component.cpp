#include "component.h"
#include "styles.h"

#include <QHBoxLayout>
#include <QWidget>
#include <QSizePolicy>

Component::Component()
{

}

QWidget* Component::userInRoomItem()
{
    QWidget* container = new QWidget;

    QHBoxLayout* userLayout = new QHBoxLayout(container);
    QLabel* idLabel = new QLabel("1");
    Styles::tableHead(idLabel, 1);

    QLabel* nameLabel = new QLabel(QString("Nguyen Tien Dat"));
    Styles::tableHead(nameLabel, 9);

    QLabel* pointLabel = new QLabel(QString("1200"));
    Styles::tableHead(pointLabel, 2);

    userLayout->addWidget(idLabel);
    userLayout->addWidget(nameLabel);
    userLayout->addWidget(pointLabel);

    container->setLayout(userLayout);
    container->setStyleSheet("background-color: #fff; "
                             "border-radius: 4px; ");
    return container;
}

// tạo useritem trong danh sách user của màn thống kê kết quả
QWidget* Component::userResultItem(QString id)
{
    QWidget* container = new QWidget;

    QHBoxLayout* resultLayout = new QHBoxLayout(container);
    QLabel* idLabel = new QLabel(id);
    Styles::tableHead(idLabel, 1);

    QLabel* nameLabel = new QLabel(QString("Nguyen Tien Dat"));
    Styles::tableHead(nameLabel, 3);

    QLabel* emailLabel = new QLabel(QString("dat@gmail.com"));
    Styles::tableHead(emailLabel, 3);

    QLabel* timeLabel = new QLabel(QString("1m37s"));
    Styles::tableHead(timeLabel, 2);

    QLabel* correctLabel = new QLabel(QString("40/50"));
    Styles::tableHead(correctLabel, 2);

    QLabel* scoreLabel = new QLabel(QString("60/70"));
    Styles::tableHead(scoreLabel, 1);

    resultLayout->addWidget(idLabel);
    resultLayout->addWidget(nameLabel);
    resultLayout->addWidget(emailLabel);
    resultLayout->addWidget(timeLabel);
    resultLayout->addWidget(correctLabel);
    resultLayout->addWidget(scoreLabel);

    container->setLayout(resultLayout);

    container->setStyleSheet("background-color: #fff; "
                             "border-radius: 4px; ");
    return container;
}
