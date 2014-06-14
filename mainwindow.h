#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QGraphicsBlurEffect>
#include <QDebug>
#include <QSettings>
#include <QDesktopServices>
#include <QUrl>
#include <QVector>
#include <gst/gst.h>


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

    void on_buttonLogo_clicked();

    void on_buttonTopLogo_clicked();

private:
    Ui::MainWindow *ui;

    void setRadio(int which);
    void setEffects();
    void setShadow(QLabel *label, int offset, int blur);
    void setPlayButton();
    void loadSettings();
    void playRadio(bool how);

    bool playing;
    QString playUrls[2];
    QString siteUrls[2];
    int current; //current radio
    int volume;
    QSettings *settings;

    GstElement *gstream_main;
    GstBus *gstream_bus;
};

#endif // MAINWINDOW_H
