#-------------------------------------------------
#
# Project created by QtCreator 2015-03-20T20:18:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += c++11

TARGET = qSketcher
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    BaseSketcher.cpp \
    originalsketcher.cpp \
    linearsketcher.cpp

HEADERS  += mainwindow.h \
    originalsketcher.h \
    BaseSketcher.h \
    linearsketcher.h

FORMS    += mainwindow.ui

RESOURCES += \
    recources.qrc
