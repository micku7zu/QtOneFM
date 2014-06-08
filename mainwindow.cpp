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
    player = new QMediaPlayer;
    connect(player, SIGNAL(bufferStatusChanged(int)), this, SLOT(on_buffer_change(int)));

}

void MainWindow::on_buffer_change(int value){
    QString text;
    text = QString("Incarc: %1%").arg(value);

    if(value == 100)
        text = "Playing";

    if(playing)
        ui->labelCurrentArtist->setText(text);
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
        player->stop();
        ui->labelCurrentArtist->setText("Apasa butonul play");
        ui->buttonPlay->setStyleSheet("QToolButton{border:none;padding:0px;margin:0px;background-image:url(:/images/play.png);}");
    }else{
        playing = true;
        player->setMedia(QUrl("http://80.86.106.35:8032/"));
        player->setVolume(settings->value("volume", 50).toInt());
        player->play();
        ui->buttonPlay->setStyleSheet("QToolButton{border:none;padding:0px;margin:0px;background-image:url(:/images/stop.png);}");
    }
}

void MainWindow::on_sliderVolume_valueChanged(int value)
{
    settings->setValue("volume", value);
    if(playing)
        player->setVolume(value);
}

void MainWindow::on_buttonLogo_clicked()
{
    QDesktopServices::openUrl(QUrl("http://onefm.ro"));
}
