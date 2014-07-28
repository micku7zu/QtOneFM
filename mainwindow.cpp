#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "efects.cpp"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/images/logo-0.png"));

    radio = new GstreamerRadio();

    radio->init();
    connect(radio, SIGNAL(bufferChanged(int)), this, SLOT(bufferChanged(int)));
    connect(&currentSong, SIGNAL(songChanged()), this, SLOT(songChanged()));

    loadSettings();
    setEffects();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadSettings(){

    isMouseDown = false;
    iXdeffarace = -1;
    iYdeffarance = -1;

    playing = false;
    playUrls[0] = "http://80.86.106.35:8032/"; //onefm
    playUrls[1] = "http://93.113.171.27:80/"; //onefm underground
    siteUrls[0] = "http://www.onefm.ro/";
    siteUrls[1] = "http://www.oneundergroundradio.com/";

    settings = new QSettings("OneFM", "OneFM");

    systemTitle = settings->value("systemTitle", true).toBool();
    ui->checkBoxTitleBar->setChecked(systemTitle);

    if(!systemTitle){
         this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinimizeButtonHint);
         ui->topLogoTip->setVisible(true);
         ui->changeRadioTip->setVisible(true);

    }else{
        this->setWindowFlags(Qt::Window | Qt::WindowCloseButtonHint | Qt::WindowMinimizeButtonHint );
        ui->buttonMinimize->setVisible(false);
        ui->buttonClose->setVisible(false);
    }

    volume = settings->value("volume", 50).toInt();
    current = settings->value("current", 0).toInt();
    setRadio(current);

    ui->sliderVolume->setValue(volume);
    ui->buttonTopLogo->installEventFilter(this);
    ui->buttonLogo->installEventFilter(this);

    ui->topLogoTip->setVisible(false);
    ui->changeRadioTip->setVisible(false);
}

void MainWindow::on_buttonMenu_clicked()
{
    int val = menuFade->currentValue().toInt();

    if(val == 0){
        ui->widgetMenu->setAttribute(Qt::WA_TransparentForMouseEvents, false);
    }else{
        ui->widgetMenu->setAttribute(Qt::WA_TransparentForMouseEvents);
    }

    menuFade->setStartValue(val);
    menuFade->setEndValue((val+1)%2);
    menuFade->start();

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
        ui->labelHand->setVisible(true);
        ui->labelCurrentSong->setText("");
        ui->labelHand->graphicsEffect()->setProperty("opacity", 1);
        handMove->start();

        currentSong.stop();
        radio->stop();
    }else{

        playing = true;
        ui->labelCurrentArtist->setText("Playing");
        ui->buttonPlay->setStyleSheet("QToolButton{border:none;padding:0px;margin:0px;background-image:url(:/images/stop.png);}");
        //ui->labelHand->setVisible(false);
        handMove->stop();
        handFade->start();

        radio->play(playUrls[current]);
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

void MainWindow::setRadio(int which)
{
    settings->setValue("current", which);

    ui->buttonTopLogo->setStyleSheet(
                QString("padding:0px;border:0px;background-image:url(:/images/logo-%1.png); background-position:center center; background-repeat:no-repeat;")
                .arg(current));
    ui->buttonLogo->setStyleSheet(
                QString("QToolButton{border: none;padding: 0px;margin: 0px;background-image:url(':/images/logo-small-%1.png'); background-position:center center; background-repeat:no-repeat;}")
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

void MainWindow::setVolume(int value)
{
    if(value < 0)
        value = 0;
    if(value > 100)
        value = 100;

    volume = value;
    settings->setValue("volume", value);
    ui->sliderVolume->setValue(value);

    if(playing){
        radio->setVolume(volume);
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


void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        isMouseDown = true;
        QPoint qpMousePressedPoint = QCursor::pos();
        QPoint qpApploc = this->pos();
        iXdeffarace = qpMousePressedPoint.x() - qpApploc.x();
        iYdeffarance = qpMousePressedPoint.y() - qpApploc.y();
    }

}


void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    isMouseDown = false;
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if(isMouseDown == true){
        this->setProperty("pos", QPoint((QCursor::pos().x() - iXdeffarace) , (QCursor::pos().y() - iYdeffarance)));
    }
}


void MainWindow::on_checkBoxTitleBar_toggled(bool checked)
{
    settings->setValue("systemTitle", checked);
    ui->buttonMinimize->setVisible(!checked);
    ui->buttonClose->setVisible(!checked);


    if(!checked){
        this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinimizeButtonHint );

    }else{
        this->setWindowFlags(Qt::Window | Qt::WindowCloseButtonHint | Qt::WindowMinimizeButtonHint );


    }

    //detect compiz
    FILE *in;
    char buff[512];

    QString buf;

    if((in = popen("ps cax | grep compiz | wc -l", "r"))){
        fgets(buff, sizeof(buff), in);
        buf = QString(buff);
    }

    pclose(in);

    if(buf.toInt() != 0){
        qDebug() << "Compiz detected.";
        this->showNormal();
        this->setWindowState(Qt::WindowMinimized);
        this->setWindowState(Qt::WindowActive);
    }

    this->showNormal();


}

void MainWindow::on_buttonClose_clicked()
{
    qApp->quit();
}

void MainWindow::on_buttonMinimize_clicked()
{
    this->setWindowState(Qt::WindowMinimized);
    this->showNormal();
}

void MainWindow::on_buttonLinux_clicked()
{
    QDesktopServices::openUrl(QUrl("http://www.ubuntu.com/desktop"));
}

void MainWindow::songChanged()
{
    ui->labelCurrentArtist->setText(currentSong.artist);
    ui->labelCurrentSong->setText(currentSong.song);
}

void MainWindow::bufferChanged(int value){
    if(value == -1){
        ui->labelCurrentArtist->setText("Error!");
    }else
        ui->labelCurrentArtist->setText(QString("Buffering: %1").arg(value));


    if(value == 100){
        currentSong.start(current, 30);
    }
}

