#-------------------------------------------------
#
# Project created by QtCreator 2019-02-07T12:02:43
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Deliverable_1
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    animal.cpp \
    storagedatabase.cpp \
    loginpage.cpp \
    mainwindowclient.cpp \
    cuacsmainwindow.cpp \
    viewanimalwindow.cpp \
    viewclientwindow.cpp \
    cuacsviewwindow.cpp \
    cuacsmatchingalgorithm.cpp

HEADERS += \
        mainwindow.h \
    animal.h \
    storagedatabase.h \
    loginpage.h \
    mainwindowclient.h \
    cuacsmainwindow.h \
    viewanimalwindow.h \
    viewclientwindow.h \
    cuacsviewwindow.h \
    cuacsmatchingalgorithm.h

FORMS += \
        mainwindow.ui \
    loginpage.ui \
    mainwindowclient.ui \
    cuacsmainwindow.ui \
    viewanimalwindow.ui \
    viewclientwindow.ui \
    cuacsviewwindow.ui

RESOURCES += \
    textfiles.qrc

DISTFILES +=
