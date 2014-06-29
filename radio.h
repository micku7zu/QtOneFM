#ifndef RADIO_H
#define RADIO_H

#include <QObject>
#include <QString>
#include <QDebug>

class Radio : public QObject
{
Q_OBJECT
public:
    Radio(){};

    virtual void init(){};
    virtual void play(QString url){};
    virtual void stop(){};
    virtual void setVolume(int volume){};

signals:
    void bufferChanged(int value);
};

#endif // RADIO_H
