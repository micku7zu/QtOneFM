QtOneFM
=======

Cross-platform QT Radio applicaton for http://onefm.ro


Compile on Linux
=================

You must have the required packages for Qt5 development and gstreamer 0.10, for Ubuntu and other distros based on Ubuntu:

    sudo apt-get install qt5-default gstreamer0.10-plugins-good gstreamer0.10-plugins-bad
    
for Arch:
    sudo pacman -S qt5-base gstreamer0.10-good-plugins gstreamer0.10-bad-plugins

then execute the following:

    git clone https://github.com/micku7zu/QtOneFM
    cd QtOneFM
    qmake
    make

then run the application:

    ./OneFM


Compile on Windows
==================

Coming soon... Use Linux :) 
