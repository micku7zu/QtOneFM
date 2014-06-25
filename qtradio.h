#ifndef QTRADIO_H
#define QTRADIO_H

#include "radio.h"
#include <QMediaPlayer>
#include <QDebug>

class QtRadio : public Radio
{
    Q_OBJECT
private:
    QMediaPlayer radio;

private slots:
    void qtBufferChanged(int value);

public:
    QtRadio();
    void init();

    void play(QString url);
    void stop();
    void setVolume(int volume);

};

#endif // QTRADIO_H
