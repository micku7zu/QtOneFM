#include "mainwindow.h"
#include <QApplication>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    if(qApp->arguments().contains("--help") || qApp->arguments().contains("-h")){
        qDebug() << "Options: ";
        qDebug() << "--help or -h: this menu. \n";
        qDebug() << "--qt5multimedia or -m: If you want to use qt5multimedia backend for audio playing. It has a bug with libkdecore and crashes the application on Linux. Qt5Multimedia is\ used on Windows as default because gstreamer it's too complicated. \n";
        qApp->quit();
        return 0;
    }

    MainWindow w;
    w.move(QApplication::desktop()->screen()->rect().center() - w.rect().center());
    w.show();

    return a.exec();
}
