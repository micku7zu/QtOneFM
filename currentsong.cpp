#include "currentsong.h"

CurrentSong::CurrentSong()
{
    timer = new QTimer(this);
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(getCurrent()));
}

CurrentSong::~CurrentSong()
{
    timer->stop();
    delete timer;
}

void CurrentSong::start(int which, int seconds)
{
    this->which = which;
    getCurrent();
    timer->start(1000 * seconds);
}

void CurrentSong::stop()
{
    timer->stop();
}

void CurrentSong::getCurrent()
{
    song = QString("Unknown");
    artist = QString("Unknown");
    emit songChanged();

    if(which == 0){

        QString page = getPage("http://www.onefm.ro/nowplaying.php");

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

        song = list.at(1);
        song.chop(2);

        list = song.split(" - ");

        if(list.size() < 2){
            song = list.at(0);
        }else{
            song = list.at(1);
        }

    }

    emit songChanged();
}

QString CurrentSong::getPage(QString site)
{
    QEventLoop eventLoop;

    QNetworkAccessManager mgr;
    QObject::connect(&mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));

    QNetworkRequest req( QUrl( QString(site.toStdString().c_str()) ) );

    QNetworkReply *reply = mgr.get(req);
    eventLoop.exec();

    if (reply->error() == QNetworkReply::NoError) {
        QString ret = QString(reply->readAll());
        delete reply;
        return ret;
    }else {
        QString ret = QString(reply->errorString());
        delete reply;
        return ret;
    }
}
