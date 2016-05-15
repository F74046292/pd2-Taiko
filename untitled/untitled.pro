#-------------------------------------------------
#
# Project created by QtCreator 2016-04-29T16:41:42
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    scene.cpp \
    btn.cpp \
    drum.cpp \
    rail.cpp

HEADERS  += mainwindow.h \
    scene.h \
    btn.h \
    drum.h \
    rail.h

FORMS    += mainwindow.ui

RESOURCES += \
    picture.qrc \
    playing.qrc
