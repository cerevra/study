TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    rect.cpp \
    areamanager.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    rect.h \
    areamanager.h

QMAKE_CXXFLAGS += -std=c++0x
