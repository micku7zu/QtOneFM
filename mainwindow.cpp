#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/images/logo-0.png"));

    setEffects();
    loadSettings();

    //initialization

    /* Initialize GStreamer */
    gst_init (NULL, NULL);

    //qt5-default
    //gstreamer0.10-plugins-good
    //gstreamer0.10-plugins-bad
    //libxcb
    //sudo apt-get install qt5-default gstreamer0.10-plugins-good gstreamer0.10-plugins-bad
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_buttonMenu_clicked()
{
}

void MainWindow::loadSettings(){
    playing = false;
    playUrls[0] = "http://80.86.106.35:8032/"; //onefm
    playUrls[1] = "http://93.113.171.27:80/"; //onefm underground
    siteUrls[0] = "http://www.onefm.ro/";
    siteUrls[1] = "http://www.oneundergroundradio.com/";

    settings = new QSettings("OneFM", "OneFM");

    volume = settings->value("volume", 50).toInt();
    current = settings->value("current", 0).toInt();
    setRadio(current);

    //Qt::WindowFlags flags = Qt::CustomizeWindowHint;
    //setWindowFlags(flags);


    ui->sliderVolume->setValue(volume);
}

void MainWindow::setEffects(){
    setShadow(ui->labelCurrentArtist, 1, 3);
}

void MainWindow::setShadow(QLabel *label, int offset, int blur){
    QGraphicsDropShadowEffect* effect = new QGraphicsDropShadowEffect();
    effect->setBlurRadius(blur);
    effect->setOffset(offset);
    label->setGraphicsEffect(effect);
}

void MainWindow::on_buttonPlay_clicked()
{
    playRadio(playing == false);
}

void MainWindow::playRadio(bool how){
    if(!how){
        playing = false;
        ui->labelCurrentArtist->setText("Apasa butonul play");
        ui->buttonPlay->setStyleSheet("QToolButton{border:none;padding:0px;margin:0px;background-image:url(:/images/play-button.png);}");

        gst_object_unref(gstream.bus);
        gst_element_set_state(gstream.pipeline, GST_STATE_NULL);
        gst_object_unref(gstream.pipeline);
    }else{
        playing = true;
        ui->labelCurrentArtist->setText("Playing");
        ui->buttonPlay->setStyleSheet("QToolButton{border:none;padding:0px;margin:0px;background-image:url(:/images/stop.png);}");

        //gstream
        QString command = QString("playbin2 uri=%1").arg(playUrls[current]);
        gstream.pipeline = gst_parse_launch (command.toStdString().c_str(), NULL);
        on_sliderVolume_valueChanged(volume);

        gstream.bus = gst_element_get_bus (gstream.pipeline);

        gst_element_set_state (gstream.pipeline, GST_STATE_PLAYING);
        GstStateChangeReturn ret = gst_element_set_state (gstream.pipeline, GST_STATE_PLAYING);
        if (ret == GST_STATE_CHANGE_FAILURE) {
            qDebug() << "Eroare la gstream.";
            gst_object_unref(gstream.pipeline);
        }

        gst_bus_add_signal_watch(gstream.bus);
        g_signal_connect (gstream.bus, "message", G_CALLBACK (gstreamSignal), ui);
    }
}

void MainWindow::on_sliderVolume_valueChanged(int value)
{
    setVolume(value);
}

void MainWindow::on_buttonLogo_clicked()
{
    current += 1;
    current %= 2;

    setRadio(current);
}

void MainWindow::setRadio(int which){
    settings->setValue("current", which);

    ui->buttonTopLogo->setStyleSheet(
                QString("padding:0px;border:0px;background:url(:/images/logo-%1.png);")
                .arg(current));
    ui->buttonLogo->setStyleSheet(
                QString("QToolButton{border: none;padding: 0px;margin: 0px;background-image:url(':/images/logo-small-%1.png');}")
                .arg((current+1)%2));

    if(playing == true){
        playRadio(false);
        playRadio(true);
    }
}

void MainWindow::on_buttonTopLogo_clicked()
{
    QDesktopServices::openUrl(siteUrls[current]);
}

void MainWindow::setVolume(int value){
    if(value < 0)
        value = 0;
    if(value > 100)
        value = 100;

    volume = value;
    settings->setValue("volume", value);
    ui->sliderVolume->setValue(value);

    double vol = value / 100.0;
    vol *= vol * vol;

    if(vol > 0.95)
        vol = 1;

    if(playing){
        g_object_set(gstream.pipeline, "volume", vol, NULL);
    }
}

void MainWindow::on_buttonVolumeDown_clicked()
{
    setVolume(volume-5);
}

void MainWindow::on_buttonVolumeUp_clicked()
{
    setVolume(volume+5);
}

void MainWindow::gstreamSignal(GstBus *bus, GstMessage *msg, Ui::MainWindow *localUi) {
    switch (GST_MESSAGE_TYPE (msg)) {
        case GST_MESSAGE_ERROR: {
            localUi->labelCurrentArtist->setText("Error.");
            break;
        }
        case GST_MESSAGE_BUFFERING: {
            gint percent = 0;

            gst_message_parse_buffering (msg, &percent);
            localUi->labelCurrentArtist->setText(QString("Buffering: %1%").arg(percent));
            break;
        }
        default:
            /* Unhandled message */
        break;
    }
}
