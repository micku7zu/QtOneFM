#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QGraphicsBlurEffect>
#include <QtMultimedia/QMediaPlayer>
#include <QDebug>
#include <QSettings>
#include <QDesktopServices>


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

    void on_buffer_change(int value);

    void on_buttonLogo_clicked();

private:
    Ui::MainWindow *ui;
    void setEffects();
    void setShadow(QLabel *label, int offset, int blur);
    void setPlayButton();
    void loadSettings();
    void playRadio(bool how);

    QMediaPlayer *player;
    bool playing;
    QString URL = "http://80.86.106.35:8032/";
    int volume;
    QSettings *settings;
};

#endif // MAINWINDOW_H
