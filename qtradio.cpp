#include "qtradio.h"

#include <QAudioOutput>


QtRadio::QtRadio()
{
}

void QtRadio::init(){
    connect(&radio, SIGNAL(bufferStatusChanged(int)), this, SLOT(qtBufferChanged(int)));
}

void QtRadio::play(QString url){
    radio.setMedia(QUrl(url));
    radio.play();
}


void QtRadio::stop(){
    radio.stop();
}

void QtRadio::setVolume(int volume){
    radio.setVolume(volume);
}

void QtRadio::qtBufferChanged(int value){
    emit bufferChanged(value);
}
