#ifndef VLCRADIO_H
#define VLCRADIO_H

#include "radio.h"
#include <vlc/vlc.h>



class VlcRadio: public Radio
{
public:
    VlcRadio();
    ~VlcRadio();
    void init();
    void play(QString url);
    void stop();
    void setVolume(int volume);

private:
    libvlc_instance_t *instance;
    libvlc_media_player_t *mediaPlayer;
    libvlc_media_t *media;
    libvlc_event_manager_t *eventManager;
    static void vlcEvent(const libvlc_event_t* event, void* vlcvideo_object);

};

#endif // VLCRADIO_H
