QT       += core gui widgets network

TARGET = OneFM
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    currentsong.cpp \
    gstreamerradio.cpp

HEADERS  += mainwindow.h \
    currentsong.h \
    radio.h \
    gstreamerradio.h

FORMS    += mainwindow.ui

RC_ICONS = images/icon.ico

RESOURCES += \
    images.qrc

unix {
    CONFIG += link_pkgconfig
    PKGCONFIG += gstreamer-0.10
}
