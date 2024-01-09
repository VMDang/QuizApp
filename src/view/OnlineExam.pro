QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

SOURCES += \
    ../app/comunicate/client.cpp \
    animations.cpp \
    answerhandler.cpp \
    categoryhandler.cpp \
    clientmanager.cpp \
    component.cpp \
    createroomdialog.cpp \
    examwindow.cpp \
    loginwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    passworddialog.cpp \
    practicehandler.cpp \
    questionbutton.cpp \
    questionclient.cpp \
    questionhandler.cpp \
    resulthandler.cpp \
    roomhandler.cpp \
    roomitem.cpp \
    styles.cpp \
    userhandler.cpp \
    utils.cpp

HEADERS += \
    animations.h \
    answerhandler.h \
    categoryhandler.h \
    clientmanager.h \
    component.h \
    createroomdialog.h \
    examwindow.h \
    loginwindow.h \
    mainwindow.h \
    passworddialog.h \
    practicehandler.h \
    questionbutton.h \
    questionclient.h \
    questionhandler.h \
    resulthandler.h \
    roomhandler.h \
    roomitem.h \
    styles.h \
    userhandler.h \
    utils.h

FORMS += \
    createroomdialog.ui \
    examwindow.ui \
    loginwindow.ui \
    mainwindow.ui \
    passworddialog.ui \
    roomitem.ui

RESOURCES += \
    resource.qrc
