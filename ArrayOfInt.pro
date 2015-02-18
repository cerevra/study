#-------------------------------------------------
#
# Project created by QtCreator 2015-02-18T10:56:42
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = ArrayOfInt
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    cli.cpp \
    array.cpp

HEADERS += \
    cli.h \
    array.h

QMAKE_CXXFLAGS += -std=c++0x
