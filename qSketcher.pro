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
    originalsketcher.cpp \
    linearsketcher.cpp \
    levelbasedsketcher.cpp \
    baseSketcher.cpp \
    smartlevelbasesketcher.cpp

HEADERS  += mainwindow.h \
    originalsketcher.h \
    linearsketcher.h \
    levelbasedsketcher.h \
    baseSketcher.h \
    smartlevelbasesketcher.h

FORMS    += mainwindow.ui

RESOURCES += \
    recources.qrc

OTHER_FILES += \
    tasks.txt
