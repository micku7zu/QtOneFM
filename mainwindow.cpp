#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QSystemTrayIcon>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/images/logo-0.png"));

    loadSettings();
    setEffects();

    //initialization
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateArtist()));

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

void MainWindow::updateArtist()
{
    qDebug() << "Timer function: ";

    QString fullSong = QString("Unknown");
    QString artist = QString("Unknown");

    ui->labelCurrentArtist->setText(artist);
    ui->labelCurrentSong->setText(fullSong);

    if(current == 0){

        QString page = getPage(siteUrls[0]);

        QStringList list = page.split("(");

        if(list.size() < 2)
            return;

        page = list.at(1);
        list = page.split(")");
        page = list.at(0);
        page.replace("				", "");

        list = page.split("artist : '");
        if(list.size() < 2)
            return;

        artist = list.at(1);
        list = artist.split("theTitle :");
        artist = list.at(0);
        artist.chop(3);

        list = page.split("theTitle : '");

        if(list.size() < 2)
            return;

        fullSong = list.at(1);
        fullSong.chop(3);

        list = fullSong.split(" - ");

        if(list.size() < 2)
            return;
        fullSong = list.at(1);

        qDebug() << QString("Page: %1").arg(page);
        qDebug() << QString("Artist: %1").arg(artist);
        qDebug() << QString("Song: %1").arg(fullSong);

        if(fullSong.length() <= 2)
            return;


        ui->labelCurrentArtist->setText(artist);
        ui->labelCurrentSong->setText(fullSong);
    }
}

QString MainWindow::getPage(QString site)
{
    QEventLoop eventLoop;

    QNetworkAccessManager mgr;
    QObject::connect(&mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));

   // QNetworkRequest req( QUrl( QString(site.toStdString().c_str()) ) );
    QNetworkRequest req(QUrl(QString("http://www.onefm.ro/nowplaying.php")));

    QNetworkReply *reply = mgr.get(req);
    eventLoop.exec();

    if (reply->error() == QNetworkReply::NoError) {
        QString ret = QString(reply->readAll());
        delete reply;
        return ret;
    }
    else {
        QString ret = QString(reply->errorString());
        delete reply;
        return ret;
    }
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

void MainWindow::setEffects(){
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
        ui->labelHand->setVisible(true);
        handMove->start();
        ui->labelHand->graphicsEffect()->setProperty("opacity", 1);

        ui->labelCurrentSong->setText("");

        timer->stop();

        gst_object_unref(gstream.bus);
        gst_element_set_state(gstream.pipeline, GST_STATE_NULL);
        gst_object_unref(gstream.pipeline);
    }else{
        playing = true;
        ui->labelCurrentArtist->setText("Playing");
        ui->buttonPlay->setStyleSheet("QToolButton{border:none;padding:0px;margin:0px;background-image:url(:/images/stop.png);}");
        //ui->labelHand->setVisible(false);
        handMove->stop();
        handFade->start();

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
        g_signal_connect (gstream.bus, "message", G_CALLBACK (gstreamSignal), this);
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

void MainWindow::gstreamSignal(GstBus *bus, GstMessage *msg, MainWindow *w) {
    switch (GST_MESSAGE_TYPE (msg)) {
        case GST_MESSAGE_ERROR: {
            w->ui->labelCurrentArtist->setText("Error.");
            break;
        }
        case GST_MESSAGE_BUFFERING: {
            gint percent = 0;

            gst_message_parse_buffering (msg, &percent);
            w->ui->labelCurrentArtist->setText(QString("Buffering: %1%").arg(percent));

            if(percent == 100){
                w->updateArtist();
                w->timer->start(1000 * 30);
            }
            break;
        }
        default:
            /* Unhandled message */
        break;
    }
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
        QPoint qpAppNewLoc( (QCursor::pos().x() - iXdeffarace) , (QCursor::pos().y() - iYdeffarance) );
        this->setProperty("pos", qpAppNewLoc);
    }
}


void MainWindow::on_checkBoxTitleBar_toggled(bool checked)
{
    settings->setValue("systemTitle", checked);
    ui->buttonMinimize->setVisible(!checked);
    ui->buttonClose->setVisible(!checked);

    if(!checked){
        this->setWindowFlags(Qt::CustomizeWindowHint);
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

