QT       += core gui widgets network

TARGET = OneFM
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    currentsong.cpp \
<<<<<<< HEAD
    gstreamerradio.cpp

HEADERS  += mainwindow.h \
    currentsong.h \
    gstreamerradio.h \
    radio.h
=======
    qtradio.cpp

HEADERS  += mainwindow.h \
    currentsong.h \
    radio.h \
    qtradio.h
>>>>>>> 825a3e8cd3033840f0d7ba53b7f1b5d9f8394942

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
