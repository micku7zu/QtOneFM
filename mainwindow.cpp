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

    settings = new QSettings("OneFM", "OneFM");

    volume = settings->value("volume", 50).toInt();

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
        playing = true;

        gstream_main = gst_parse_launch ("playbin2 uri=http://80.86.106.35/", NULL);
        gst_element_set_state (gstream_main, GST_STATE_PLAYING);
        on_sliderVolume_valueChanged(volume);
        ui->labelCurrentArtist->setText("Playing");
        ui->buttonPlay->setStyleSheet("QToolButton{border:none;padding:0px;margin:0px;background-image:url(:/images/stop.png);}");
    }
}

void MainWindow::on_sliderVolume_valueChanged(int value)
{
    settings->setValue("volume", value);

    double vol = value / 100.0;
    vol *= vol * vol;

    if(vol > 0.95)
        vol = 1;

    if(playing){
        qDebug() << QString("%1").arg(vol);
        g_object_set(gstream_main, "volume", vol, NULL);
    }
}

void MainWindow::on_buttonLogo_clicked()
{
    QDesktopServices::openUrl(QUrl("http://onefm.ro"));
}
