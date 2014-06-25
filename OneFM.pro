QT       += core gui widgets network multimedia


TARGET = OneFM
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    currentsong.cpp \
    qtradio.cpp

HEADERS  += mainwindow.h \
    currentsong.h \
    radio.h \
    qtradio.h

unix {
    HEADERS += gstreamerradio.h
    SOURCES += gstreamerradio.cpp
}

FORMS    += mainwindow.ui

RC_ICONS = images/icon.ico

RESOURCES += \
    images.qrc

unix {
    CONFIG += link_pkgconfig
    PKGCONFIG += gstreamer-0.10
}
