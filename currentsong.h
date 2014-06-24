#ifndef CURRENTSONG_H
#define CURRENTSONG_H

#include <QString>
#include <QUrl>
#include <QTimer>
#include <QDebug>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QEventLoop>
#include <QDebug>
#include <QObject>

class CurrentSong : public QObject
{
    Q_OBJECT

private slots:
    void getCurrent();

signals:
    void songChanged();

public:
    explicit CurrentSong();
    ~CurrentSong();

    void start(int which, int seconds);
    void stop();
    QString getPage(QString site);

    QString artist;
    QString song;

private:
    QTimer *timer;
    int which;

};

#endif // CURRENTSONG_H
