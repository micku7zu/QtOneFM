/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QToolButton *buttonMenu;
    QToolButton *buttonLogo;
    QToolButton *buttonVolumeUp;
    QToolButton *buttonVolumeDown;
    QSlider *sliderVolume;
    QLabel *labelCenter;
    QToolButton *buttonRefresh;
    QToolButton *buttonPlay;
    QLabel *labelHand;
    QLabel *labelCurrentArtist;
    QToolButton *buttonStar;
    QPushButton *buttonTopLogo;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(427, 640);
        MainWindow->setMinimumSize(QSize(427, 640));
        MainWindow->setMaximumSize(QSize(427, 640));
        MainWindow->setSizeIncrement(QSize(1, 1));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QStringLiteral(""));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setStyleSheet(QStringLiteral("background-image:url(\":/images/background.png\");"));
        buttonMenu = new QToolButton(centralWidget);
        buttonMenu->setObjectName(QStringLiteral("buttonMenu"));
        buttonMenu->setEnabled(true);
        buttonMenu->setGeometry(QRect(380, 10, 37, 30));
        buttonMenu->setMinimumSize(QSize(37, 0));
        buttonMenu->setMaximumSize(QSize(37, 16777215));
        buttonMenu->setCursor(QCursor(Qt::PointingHandCursor));
        buttonMenu->setStyleSheet(QLatin1String("QToolButton{\n"
"border: none;\n"
"margin: 0px;\n"
"padding: 0px;\n"
"background-image: url(:/images/menu.png)\n"
"}\n"
"\n"
"QToolButton:hover{\n"
"\n"
"}"));
        buttonLogo = new QToolButton(centralWidget);
        buttonLogo->setObjectName(QStringLiteral("buttonLogo"));
        buttonLogo->setGeometry(QRect(10, 530, 96, 96));
        buttonLogo->setCursor(QCursor(Qt::PointingHandCursor));
        buttonLogo->setStyleSheet(QLatin1String("QToolButton{\n"
"border: none;\n"
"padding: 0px;\n"
"margin: 0px;\n"
"background-image:url(\":/images/logo1.png\");\n"
"}"));
        buttonVolumeUp = new QToolButton(centralWidget);
        buttonVolumeUp->setObjectName(QStringLiteral("buttonVolumeUp"));
        buttonVolumeUp->setGeometry(QRect(351, 138, 28, 23));
        buttonVolumeUp->setMinimumSize(QSize(0, 21));
        buttonVolumeUp->setMaximumSize(QSize(28, 16777215));
        buttonVolumeUp->setCursor(QCursor(Qt::PointingHandCursor));
        buttonVolumeUp->setStyleSheet(QLatin1String("QToolButton{\n"
"border: none;\n"
"margin: 0px;\n"
"padding: 0px;\n"
"background-image:url(\":/images/up.png\");\n"
"}"));
        buttonVolumeDown = new QToolButton(centralWidget);
        buttonVolumeDown->setObjectName(QStringLiteral("buttonVolumeDown"));
        buttonVolumeDown->setGeometry(QRect(353, 492, 20, 21));
        buttonVolumeDown->setMinimumSize(QSize(0, 21));
        buttonVolumeDown->setMaximumSize(QSize(28, 16777215));
        buttonVolumeDown->setCursor(QCursor(Qt::PointingHandCursor));
        buttonVolumeDown->setStyleSheet(QLatin1String("QToolButton{\n"
"border: none;\n"
"margin: 0px;\n"
"padding: 0px;\n"
"background-image:url(\":/images/down.png\");\n"
"}"));
        sliderVolume = new QSlider(centralWidget);
        sliderVolume->setObjectName(QStringLiteral("sliderVolume"));
        sliderVolume->setGeometry(QRect(330, 170, 62, 312));
        sliderVolume->setMinimumSize(QSize(62, 312));
        sliderVolume->setMaximumSize(QSize(62, 16777215));
        sliderVolume->setCursor(QCursor(Qt::ArrowCursor));
        sliderVolume->setStyleSheet(QLatin1String("QSlider{\n"
"background-image:url(\":/images/slide.png\");\n"
"background-repeat:no-repeat;\n"
"}\n"
"\n"
"QSlider::groove:vertical{\n"
"border: none;\n"
"padding:0px;\n"
"margin:0px;\n"
"}\n"
"\n"
"QSlider::sub-page:vertical {\n"
"border: none;\n"
"padding:0px;\n"
"margin:0px;\n"
"}\n"
"\n"
"QSlider::add-page:vertical {\n"
"border: none;\n"
"padding:0px;\n"
"margin:0px;\n"
"}\n"
"\n"
"QSlider::handle:vertical{\n"
"background-image:url(\":/images/volume.png\");\n"
"width: 59px;\n"
"height: 39px;\n"
"}\n"
""));
        sliderVolume->setOrientation(Qt::Vertical);
        labelCenter = new QLabel(centralWidget);
        labelCenter->setObjectName(QStringLiteral("labelCenter"));
        labelCenter->setGeometry(QRect(110, 10, 200, 629));
        labelCenter->setStyleSheet(QStringLiteral("background-image:url(:/images/center0.png)"));
        buttonRefresh = new QToolButton(centralWidget);
        buttonRefresh->setObjectName(QStringLiteral("buttonRefresh"));
        buttonRefresh->setGeometry(QRect(10, 280, 37, 30));
        buttonRefresh->setStyleSheet(QLatin1String("background-image:url(:/images/refresh.png);\n"
"border:none;\n"
"padding:0px;\n"
"margin:0px;"));
        buttonPlay = new QToolButton(centralWidget);
        buttonPlay->setObjectName(QStringLiteral("buttonPlay"));
        buttonPlay->setGeometry(QRect(145, 475, 130, 129));
        buttonPlay->setCursor(QCursor(Qt::PointingHandCursor));
        buttonPlay->setStyleSheet(QLatin1String("QToolButton{\n"
"border: none;\n"
"padding:0px;\n"
"margin:0px;\n"
"background-image:url(:/images/play.png)\n"
"}"));
        labelHand = new QLabel(centralWidget);
        labelHand->setObjectName(QStringLiteral("labelHand"));
        labelHand->setGeometry(QRect(190, 390, 35, 63));
        labelHand->setStyleSheet(QLatin1String("QLabel{\n"
"border:none;\n"
"padding:0px;\n"
"margin:0px;\n"
"background-image:url(:/images/hand.png)\n"
"}"));
        labelHand->setFrameShape(QFrame::NoFrame);
        labelCurrentArtist = new QLabel(centralWidget);
        labelCurrentArtist->setObjectName(QStringLiteral("labelCurrentArtist"));
        labelCurrentArtist->setGeometry(QRect(140, 310, 141, 51));
        QFont font;
        font.setFamily(QStringLiteral("URW Gothic L"));
        font.setPointSize(12);
        font.setBold(false);
        font.setWeight(50);
        labelCurrentArtist->setFont(font);
        labelCurrentArtist->setStyleSheet(QLatin1String("QLabel{\n"
"border:none;\n"
"background:none;\n"
"color:white;\n"
"}"));
        labelCurrentArtist->setTextFormat(Qt::RichText);
        labelCurrentArtist->setScaledContents(true);
        labelCurrentArtist->setAlignment(Qt::AlignCenter);
        labelCurrentArtist->setWordWrap(true);
        buttonStar = new QToolButton(centralWidget);
        buttonStar->setObjectName(QStringLiteral("buttonStar"));
        buttonStar->setGeometry(QRect(190, 200, 35, 37));
        buttonStar->setStyleSheet(QLatin1String("QToolButton{\n"
"border:none;\n"
"margin:0px;\n"
"padding:0px;\n"
"background-image:url(:/images/star.png)\n"
"}"));
        buttonTopLogo = new QPushButton(centralWidget);
        buttonTopLogo->setObjectName(QStringLiteral("buttonTopLogo"));
        buttonTopLogo->setGeometry(QRect(140, 40, 141, 141));
        buttonTopLogo->setCursor(QCursor(Qt::PointingHandCursor));
        buttonTopLogo->setStyleSheet(QLatin1String("padding:0px;\n"
"border:0px;\n"
"background:none;\n"
""));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "OneFM", 0));
        buttonMenu->setText(QString());
        buttonLogo->setText(QString());
        buttonVolumeUp->setText(QString());
        buttonVolumeDown->setText(QString());
        labelCenter->setText(QString());
        buttonRefresh->setText(QString());
        buttonPlay->setText(QString());
        labelHand->setText(QString());
        labelCurrentArtist->setText(QApplication::translate("MainWindow", "Apasa butonul play", 0));
        buttonStar->setText(QString());
        buttonTopLogo->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
