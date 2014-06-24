#-------------------------------------------------
#
# Project created by QtCreator 2014-05-29T17:02:06
#
#-------------------------------------------------

QT       += core gui widgets network

TARGET = OneFM
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    currentsong.cpp

HEADERS  += mainwindow.h \
    currentsong.h

FORMS    += mainwindow.ui

RC_ICONS = images/icon.ico

RESOURCES += \
    images.qrc

unix {
    CONFIG += link_pkgconfig
    PKGCONFIG += gstreamer-0.10
}
