#ifndef GSTREAMERRADIO_H
#define GSTREAMERRADIO_H

#include <QDebug>
#include "radio.h"
#include <gst/gst.h>


typedef struct _gstream {
    GstElement *pipeline;
    GstBus *bus;
} GStream;

class GstreamerRadio: public Radio
{
Q_OBJECT

public:
    GstreamerRadio();
    void init();
    void play(QString url);
    void stop();
    void setVolume(int volume);

    static void gstreamSignal(GstBus *bus, GstMessage *msg, GstreamerRadio *radio);

    GStream gstream;
};

#endif // GSTREAMERRADIO_H
