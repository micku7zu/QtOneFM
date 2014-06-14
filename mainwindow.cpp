#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setEffects();
    loadSettings();

    //initialization

    /* Initialize GStreamer */
    gst_init (NULL, NULL);

    //qt5-default
    //gstreamer0.10-plugins-good
    //gstreamer0.10-plugins-bad
    //sudo apt-get install qt5-default gstreamer0.10-plugins-good gstreamer0.10-plugins-bad
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_buttonMenu_clicked()
{
    QMessageBox::information(this, "Meniu", "Test :D");
}

void MainWindow::loadSettings(){

    playUrls[0] = "http://80.86.106.35:8032/"; //onefm
    playUrls[1] = "http://93.113.171.27:80/"; //onefm underground
    siteUrls[0] = "http://www.onefm.ro/";
    siteUrls[1] = "http://www.oneundergroundradio.com/";

    settings = new QSettings("OneFM", "OneFM");

    volume = settings->value("volume", 50).toInt();
    current = settings->value("current", 0).toInt();

    //Qt::WindowFlags flags = Qt::CustomizeWindowHint;
    //setWindowFlags(flags);

    playing = false;

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
    playRadio(playing == true);
}

void MainWindow::playRadio(bool how){
    if(how){
        playing = false;
        gst_element_set_state(gstream_main, GST_STATE_PAUSED);
        ui->labelCurrentArtist->setText("Apasa butonul play");
        ui->buttonPlay->setStyleSheet("QToolButton{border:none;padding:0px;margin:0px;background-image:url(:/images/play.png);}");
    }else{
        gst_element_set_state(gstream_main, GST_STATE_PAUSED);
        playing = true;
        QString command = QString("playbin2 uri=%1").arg(playUrls[current]);
        gstream_main = gst_parse_launch (command.toStdString().c_str(), NULL);
        gst_element_set_state (gstream_main, GST_STATE_PLAYING);
        on_sliderVolume_valueChanged(volume);
        ui->labelCurrentArtist->setText("Playing");
        ui->buttonPlay->setStyleSheet("QToolButton{border:none;padding:0px;margin:0px;background-image:url(:/images/stop.png);}");
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

    ui->labelCenter->setStyleSheet(QString("background-image:url(:/images/center%1.png)").arg(which));
    ui->buttonLogo->setStyleSheet(
                QString("QToolButton{border: none;padding: 0px;margin: 0px;background-image:url(':/images/logo%1.png');}")
                .arg((current+1)%2));

    if(playing == true)
        playRadio(false);
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
        qDebug() << QString("%1").arg(vol);
        g_object_set(gstream_main, "volume", vol, NULL);
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
