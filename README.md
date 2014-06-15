QtOneFM
=======

Cross-platform QT Radio applicaton for http://onefm.ro

Early preview: https://drive.google.com/file/d/0BxktHhMrAobWYTY2NFFiUzFKZGc/edit?usp=sharing

Compiled 64 bit preview: https://github.com/micku7zu/QtOneFM/releases

## Compile on Linux

(you can use QT Creator)

You must have the required packages for Qt5 development and gstreamer 0.10, for Ubuntu and other distros based on Ubuntu:

```sh
sudo apt-get install build-essential git qt5-default gstreamer0.10-plugins-good gstreamer0.10-plugins-bad
```

for Arch:

```sh
sudo pacman -S git qt5-base gstreamer0.10-good-plugins gstreamer0.10-bad-plugins
```

then execute the following:

```sh
git clone https://github.com/micku7zu/QtOneFM
cd QtOneFM
qmake
make
```

then run the application:

```sh
./OneFM
```

## Compile on Windows

Coming soon... Use Linux :smile:
