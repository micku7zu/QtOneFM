#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QGraphicsBlurEffect>
#include <QDebug>
#include <QSettings>
#include <QDesktopServices>
#include <QUrl>
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

private:
    Ui::MainWindow *ui;
    void setEffects();
    void setShadow(QLabel *label, int offset, int blur);
    void setPlayButton();
    void loadSettings();
    void playRadio(bool how);

    bool playing;
    QString URL = "http://80.86.106.35:8032/";
    int volume;
    QSettings *settings;

    GstElement *gstream_main;
    GstBus *gstream_bus;
};

#endif // MAINWINDOW_H
