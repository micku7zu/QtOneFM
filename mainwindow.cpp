#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/images/logo-0.png"));

    radio.init();
    connect(&radio, SIGNAL(bufferChanged(int)), this, SLOT(bufferChanged(int)));
    connect(&currentSong, SIGNAL(songChanged()), this, SLOT(songChanged()));

    loadSettings();
    setEffects();
}

MainWindow::~MainWindow()
{
    delete ui;
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
        this->setWindowFlags(Qt::CustomizeWindowHint);
    }else{
        ui->buttonMinimize->setVisible(false);
        ui->buttonClose->setVisible(false);
    }

    volume = settings->value("volume", 50).toInt();
    current = settings->value("current", 0).toInt();
    setRadio(current);

    ui->sliderVolume->setValue(volume);
}

void MainWindow::setEffects()
{
    setShadow(ui->labelCurrentArtist, 1, 3);
    setShadow(ui->labelCurrentSong, 1, 3);
    ui->labelHand->setAttribute(Qt::WA_TransparentForMouseEvents);

    QGraphicsOpacityEffect *menuOpacity = new QGraphicsOpacityEffect;
    menuFade = new QPropertyAnimation(menuOpacity, "opacity");
    menuOpacity->setOpacity(0);
    ui->widgetMenu->setAttribute(Qt::WA_TransparentForMouseEvents);
    ui->widgetMenu->setGraphicsEffect(menuOpacity);
    menuFade->setDuration(400);
    menuFade->setStartValue(0);
    menuFade->setEndValue(1);
    menuFade->setEasingCurve(QEasingCurve::InCubic);

    //handMove
    handMove = new QPropertyAnimation(ui->labelHand, "geometry");
    handMove->setDuration(1300);
    handMove->setKeyValueAt(0, QRect(170, 360, 73, 73));
    handMove->setKeyValueAt(1, QRect(170, 390, 73, 73));
    handMove->setEasingCurve(QEasingCurve::OutBounce);
    handMove->setLoopCount(-1);
    handMove->start();

    //hand fade
    QGraphicsOpacityEffect *handOpacity = new QGraphicsOpacityEffect;
    handFade = new QPropertyAnimation(handOpacity, "opacity");
    ui->labelHand->setGraphicsEffect(handOpacity);
    handFade->setDuration(400);
    handFade->setStartValue(1);
    handFade->setEndValue(0);
    handFade->setEasingCurve(QEasingCurve::InCubic);
}

void MainWindow::setShadow(QLabel *label, int offset, int blur)
{
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
        ui->labelHand->setVisible(true);
        ui->labelCurrentSong->setText("");
        ui->labelHand->graphicsEffect()->setProperty("opacity", 1);
        handMove->start();

        currentSong.stop();
        radio.stop();
    }else{

        playing = true;
        ui->labelCurrentArtist->setText("Playing");
        ui->buttonPlay->setStyleSheet("QToolButton{border:none;padding:0px;margin:0px;background-image:url(:/images/stop.png);}");
        //ui->labelHand->setVisible(false);
        handMove->stop();
        handFade->start();

        radio.play(playUrls[current]);
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
        radio.setVolume(volume);
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
        this->setWindowFlags(Qt::Window | Qt::CustomizeWindowHint );
    }else{
        this->setWindowFlags(Qt::Window | Qt::WindowTitleHint | Qt::WindowCloseButtonHint | Qt::WindowMinimizeButtonHint);
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
