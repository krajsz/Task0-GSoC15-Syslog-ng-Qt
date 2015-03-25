QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TEMPLATE = app

CONFIG += C++11
TARGET = Task0

LIBS += `pkg-config --libs --cflags yaml-cpp`

SOURCES += main.cpp \
    yaml_handler.cpp \
    mainwindow.cpp \
    shape.cpp


HEADERS += \
    yaml_handler.h \
    mainwindow.h \
    shape.h

