#include "vlcradio.h"

VlcRadio::VlcRadio()
{
}

VlcRadio::~VlcRadio(){
    libvlc_media_player_stop(mediaPlayer);
    libvlc_media_player_release(mediaPlayer);
    libvlc_release (instance);
}

void VlcRadio::setVolume(int volume){
    libvlc_audio_set_volume(mediaPlayer, volume);
}

void VlcRadio::init(){
    instance = libvlc_new(0, NULL);
    mediaPlayer = libvlc_media_player_new(instance);

    eventManager = libvlc_media_player_event_manager(mediaPlayer);
    libvlc_event_attach(eventManager, libvlc_MediaPlayerBuffering, vlcEvent, this);
}

void VlcRadio::stop(){
    libvlc_media_player_pause(mediaPlayer);
}

void VlcRadio::play(QString url){
    media = libvlc_media_new_location (instance, url.toStdString().c_str());

    libvlc_media_player_set_media(mediaPlayer, media);
    libvlc_media_release(media);

    libvlc_media_player_play(mediaPlayer);
}

void VlcRadio::vlcEvent(const libvlc_event_t* event, void* vlcvideo_object)
{
    emit ((VlcRadio*)vlcvideo_object)->bufferChanged(event->u.media_player_buffering.new_cache);
}

