#include "gstreamerradio.h"

GstreamerRadio::GstreamerRadio()
{
}

void GstreamerRadio::init()
{
    gst_init (NULL, NULL);
}

void GstreamerRadio::stop()
{
    gst_object_unref(gstream.bus);
    gst_element_set_state(gstream.pipeline, GST_STATE_NULL);
    gst_object_unref(gstream.pipeline);
}

void GstreamerRadio::play(QString url)
{
    QString command = QString("playbin2 uri=%1").arg(url);
    gstream.pipeline = gst_parse_launch (command.toStdString().c_str(), NULL);

    gstream.bus = gst_element_get_bus (gstream.pipeline);

    gst_element_set_state (gstream.pipeline, GST_STATE_PLAYING);
    GstStateChangeReturn ret = gst_element_set_state (gstream.pipeline, GST_STATE_PLAYING);
    if (ret == GST_STATE_CHANGE_FAILURE) {
        emit this->bufferChanged(-1);
        gst_object_unref(gstream.pipeline);
    }

    gst_bus_add_signal_watch(gstream.bus);
    g_signal_connect (gstream.bus, "message", G_CALLBACK (gstreamSignal), this);
}

void GstreamerRadio::setVolume(int volume)
{
    double vol = volume / 100.0;
    vol *= vol * vol;

    if(vol > 0.95)
        vol = 1;

    g_object_set(gstream.pipeline, "volume", vol, NULL);
}

void GstreamerRadio::gstreamSignal(GstBus *bus, GstMessage *msg, GstreamerRadio *radio)
{
    switch (GST_MESSAGE_TYPE (msg)) {
        case GST_MESSAGE_ERROR: {
            emit radio->bufferChanged(-1);
            break;
        }
        case GST_MESSAGE_BUFFERING: {
            int percent = 0;
            gst_message_parse_buffering (msg, &percent);
            emit radio->bufferChanged(percent);
            break;
        }
        default:
            /* Unhandled message */
        break;
    }
}
