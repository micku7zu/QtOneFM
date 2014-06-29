#include "mainwindow.h"
#include <QApplication>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    if(qApp->arguments().contains("--help") || qApp->arguments().contains("-h")){
        qDebug() << "Options: ";
        qDebug() << "--help or -h: this menu. \n";
        qDebug() << "--vlc or -v: If you want to use libVLC backend for audio playing. This is the default (and only) on Windows. Default in Linux is gstreamer.\n";
        qApp->quit();
        return 0;
    }

    MainWindow w;
    w.move(QApplication::desktop()->screen()->rect().center() - w.rect().center());
    w.show();

    return a.exec();
}
