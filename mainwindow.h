#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QSettings>
#include <QPropertyAnimation>
#include <QUrl>
#include <QGraphicsOpacityEffect>
#include <QDesktopServices>
#include <QMouseEvent>
#include <QApplication>
#include <QObject>

#include "currentsong.h"


#ifndef Q_OS_WIN32
    #include "gstreamerradio.h"
#endif

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_buttonMenu_clicked();

    void on_buttonPlay_clicked();

    void on_sliderVolume_valueChanged(int value);

    void on_buttonVolumeDown_clicked();

    void on_buttonVolumeUp_clicked();

    void on_buttonLogo_clicked();

    void on_buttonTopLogo_clicked();

    void on_checkBoxTitleBar_toggled(bool checked);

    void on_buttonClose_clicked();

    void on_buttonMinimize_clicked();

    void on_buttonLinux_clicked();

    void songChanged();

    void bufferChanged(int value);

private:
    Ui::MainWindow *ui;

    void setRadio(int which);
    void setEffects();
    void setShadow(QLabel *label, int offset, int blur);
    void setPlayButton();
    void loadSettings();
    void playRadio(bool how);
    void setVolume(int value);
    QString getPage(QString url);

    bool playing;
    int current; //current radio
    int volume;
    bool systemTitle;
    QSettings *settings;
    bool isMouseDown;
    int iXdeffarace;
    int iYdeffarance;
    bool slidingMenu;

    QPropertyAnimation *handMove;
    QPropertyAnimation *handFade;
    QPropertyAnimation *menuFade;
    QPropertyAnimation *topLogoTipFade;
    QPropertyAnimation *changeRadioTipFade;

    Radio *radio;

    CurrentSong currentSong;

    QString playUrls[2];
    QString siteUrls[2];
protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    QPoint mousePoint;
    bool eventFilter(QObject*, QEvent* event);
};

#endif // MAINWINDOW_H
