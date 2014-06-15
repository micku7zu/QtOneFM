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

typedef struct _gstream {
    GstElement *pipeline;
    GstBus *bus;
} GStream;

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

    void on_buttonVolumeDown_clicked();

    void on_buttonVolumeUp_clicked();


private:
    Ui::MainWindow *ui;

    void setRadio(int which);
    void setEffects();
    void setShadow(QLabel *label, int offset, int blur);
    void setPlayButton();
    void loadSettings();
    void playRadio(bool how);
    void setVolume(int value);
    static void gstreamSignal(GstBus *bus, GstMessage *msg, Ui::MainWindow *localUi);

    bool playing;
    QString playUrls[2];
    QString siteUrls[2];
    int current; //current radio
    int volume;
    QSettings *settings;

    GStream gstream;
};

#endif // MAINWINDOW_H
