#-------------------------------------------------
#
# Project created by QtCreator 2017-03-07T20:05:28
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = usbspeedtest
TEMPLATE = app
# include(/usr/src/linux-headers-4.8.0-22/include/linux/usb.h)

LIBS += -lusb -ludev


SOURCES += main.cpp\
        mainw.cpp \
    usbworker.cpp \
    usblistenerlowlevel.cpp

HEADERS  += mainw.h \
    usbworker.h

FORMS    += mainw.ui
