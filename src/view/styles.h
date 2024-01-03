#ifndef STYLES_H
#define STYLES_H


#include <QPushButton>
#include <QLabel>

class Styles
{
public:
    Styles();
    static void questionButtonActive(QPushButton *button);
    static void questionButtonDisable(QPushButton *button);
    static void questionButtonStyle(QPushButton *button);
    static void activeSidebarItem(QPushButton *button);
    static void disableSidebarItem(QPushButton *button);
    static void unReadyButton(QPushButton *button);
    static void readyButton(QPushButton *button);
    static void tableHead(QLabel *thead, int hStretch);
};

#endif // STYLES_H
