#ifndef RADIO_H
#define RADIO_H

#include <QObject>
#include <QString>

class Radio : public QObject
{
Q_OBJECT
public:
    Radio(){};

    virtual void play(QString url) = 0;
    virtual void stop() = 0;
    virtual void setVolume(int volume) = 0;

signals:
    void bufferChanged(int value);
};

#endif // RADIO_H
