QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

SOURCES += \
    ../app/comunicate/client.cpp \
    answerhandler.cpp \
    categoryhandler.cpp \
    clientmanager.cpp \
    resulthandler.cpp \
    roomhandler.cpp \
    examwindow.cpp \
    lobbywindow.cpp \
    loginwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    roomitem.cpp

HEADERS += \
    answerhandler.h \
    categoryhandler.h \
    clientmanager.h \
    resulthandler.h \
    roomhandler.h \
    examwindow.h \
    lobbywindow.h \
    loginwindow.h \
    mainwindow.h \
    roomitem.h

FORMS += \
    examwindow.ui \
    lobbywindow.ui \
    loginwindow.ui \
    mainwindow.ui \
    roomitem.ui

RESOURCES +=
