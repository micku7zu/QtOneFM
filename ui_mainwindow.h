/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
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
    QAction *actionClose;
    QWidget *centralWidget;
    QToolButton *buttonMenu;
    QToolButton *buttonLogo;
    QToolButton *buttonVolumeUp;
    QToolButton *buttonVolumeDown;
    QSlider *sliderVolume;
    QLabel *labelCenter;
    QToolButton *buttonPlay;
    QLabel *labelHand;
    QLabel *labelCurrentArtist;
    QToolButton *buttonStar;
    QPushButton *buttonTopLogo;
    QLabel *labelLive;
    QLabel *labelHearth;
    QLabel *labelCurrentSong;
    QWidget *widgetMenu;
    QCheckBox *checkBoxTitleBar;
    QCheckBox *checkboxTest;
    QToolButton *buttonClose;
    QToolButton *buttonMinimize;
    QToolButton *buttonLinux;
    QToolButton *topLogoTip;
    QToolButton *changeRadioTip;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(354, 530);
        MainWindow->setMinimumSize(QSize(354, 530));
        MainWindow->setMaximumSize(QSize(354, 530));
        MainWindow->setStyleSheet(QStringLiteral(""));
        actionClose = new QAction(MainWindow);
        actionClose->setObjectName(QStringLiteral("actionClose"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setMinimumSize(QSize(354, 530));
        centralWidget->setMaximumSize(QSize(354, 530));
        centralWidget->setBaseSize(QSize(0, 0));
        centralWidget->setMouseTracking(false);
        centralWidget->setFocusPolicy(Qt::StrongFocus);
        centralWidget->setStyleSheet(QStringLiteral("background-image:url(\":/images/background.png\");"));
        buttonMenu = new QToolButton(centralWidget);
        buttonMenu->setObjectName(QStringLiteral("buttonMenu"));
        buttonMenu->setEnabled(true);
        buttonMenu->setGeometry(QRect(314, 10, 33, 27));
        buttonMenu->setMinimumSize(QSize(33, 27));
        buttonMenu->setMaximumSize(QSize(33, 27));
        buttonMenu->setCursor(QCursor(Qt::PointingHandCursor));
        buttonMenu->setFocusPolicy(Qt::NoFocus);
        buttonMenu->setStyleSheet(QLatin1String("QToolButton{\n"
"border: none;\n"
"margin: 0px;\n"
"padding: 0px;\n"
"background-image: url(:/images/menu-icon.png)\n"
"}\n"
"\n"
"QToolButton:hover{\n"
"\n"
"}"));
        buttonLogo = new QToolButton(centralWidget);
        buttonLogo->setObjectName(QStringLiteral("buttonLogo"));
        buttonLogo->setGeometry(QRect(7, 208, 91, 91));
        buttonLogo->setCursor(QCursor(Qt::PointingHandCursor));
        buttonLogo->setFocusPolicy(Qt::NoFocus);
        buttonLogo->setStyleSheet(QLatin1String("QToolButton{\n"
"border: none;\n"
"padding: 0px;\n"
"margin: 0px;\n"
"background-image:url(\":/images/logo-small-1.png\");\n"
"}"));
        buttonVolumeUp = new QToolButton(centralWidget);
        buttonVolumeUp->setObjectName(QStringLiteral("buttonVolumeUp"));
        buttonVolumeUp->setGeometry(QRect(292, 124, 31, 21));
        buttonVolumeUp->setMinimumSize(QSize(0, 21));
        buttonVolumeUp->setMaximumSize(QSize(34, 16777215));
        buttonVolumeUp->setCursor(QCursor(Qt::PointingHandCursor));
        buttonVolumeUp->setFocusPolicy(Qt::NoFocus);
        buttonVolumeUp->setStyleSheet(QLatin1String("QToolButton{\n"
"border: none;\n"
"margin: 0px;\n"
"padding: 0px;\n"
"background-image:url(:/images/volume-icon-up.png);\n"
"}"));
        buttonVolumeDown = new QToolButton(centralWidget);
        buttonVolumeDown->setObjectName(QStringLiteral("buttonVolumeDown"));
        buttonVolumeDown->setGeometry(QRect(296, 426, 21, 21));
        buttonVolumeDown->setMinimumSize(QSize(0, 21));
        buttonVolumeDown->setMaximumSize(QSize(28, 16777215));
        buttonVolumeDown->setCursor(QCursor(Qt::PointingHandCursor));
        buttonVolumeDown->setFocusPolicy(Qt::NoFocus);
        buttonVolumeDown->setStyleSheet(QLatin1String("QToolButton{\n"
"border: none;\n"
"margin: 0px;\n"
"padding: 0px;\n"
"background-image:url(\":/images/volume-icon-down.png\");\n"
"}"));
        sliderVolume = new QSlider(centralWidget);
        sliderVolume->setObjectName(QStringLiteral("sliderVolume"));
        sliderVolume->setGeometry(QRect(285, 150, 60, 272));
        sliderVolume->setMinimumSize(QSize(0, 0));
        sliderVolume->setMaximumSize(QSize(60, 272));
        sliderVolume->setCursor(QCursor(Qt::ArrowCursor));
        sliderVolume->setStyleSheet(QLatin1String("QSlider{\n"
"background-image:url(\":/images/volume-grid.png\");\n"
"background-repeat:no-repeat;\n"
"background-position:center center;\n"
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
"background-image:url(\":/images/volume-controller.png\");\n"
"background-repeat:no-repeat;\n"
"width: 40px;\n"
"height: 32px;\n"
"margin:13px 0 11px -1px;\n"
"}\n"
"QSlider::handle:vertical:pressed{\n"
"background-image:url(\":/images/volume-controller-pressed.png\");\n"
"}\n"
""));
        sliderVolume->setMinimum(1);
        sliderVolume->setMaximum(99);
        sliderVolume->setSingleStep(1);
        sliderVolume->setValue(1);
        sliderVolume->setSliderPosition(1);
        sliderVolume->setTracking(true);
        sliderVolume->setOrientation(Qt::Vertical);
        labelCenter = new QLabel(centralWidget);
        labelCenter->setObjectName(QStringLiteral("labelCenter"));
        labelCenter->setGeometry(QRect(97, 10, 160, 510));
        labelCenter->setStyleSheet(QStringLiteral("background-image:url(:/images/center-bg.png)"));
        buttonPlay = new QToolButton(centralWidget);
        buttonPlay->setObjectName(QStringLiteral("buttonPlay"));
        buttonPlay->setGeometry(QRect(128, 386, 98, 98));
        buttonPlay->setBaseSize(QSize(98, 98));
        buttonPlay->setCursor(QCursor(Qt::PointingHandCursor));
        buttonPlay->setFocusPolicy(Qt::NoFocus);
        buttonPlay->setStyleSheet(QLatin1String("QToolButton{\n"
"border: none;\n"
"padding:0px;\n"
"margin:0px;\n"
"background-image:url(:/images/play-button.png) no-repeat center center;\n"
"}"));
        labelHand = new QLabel(centralWidget);
        labelHand->setObjectName(QStringLiteral("labelHand"));
        labelHand->setEnabled(true);
        labelHand->setGeometry(QRect(143, 300, 61, 61));
        labelHand->setMouseTracking(false);
        labelHand->setStyleSheet(QLatin1String("QLabel{\n"
"border:none;\n"
"padding:0px;\n"
"margin:0px;\n"
"background-image:url(:/images/hand.png)\n"
"}"));
        labelHand->setFrameShape(QFrame::NoFrame);
        labelCurrentArtist = new QLabel(centralWidget);
        labelCurrentArtist->setObjectName(QStringLiteral("labelCurrentArtist"));
        labelCurrentArtist->setGeometry(QRect(106, 230, 140, 63));
        QFont font;
        font.setFamily(QStringLiteral("URW Gothic L"));
        font.setPointSize(11);
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
        buttonStar->setEnabled(true);
        buttonStar->setGeometry(QRect(161, 160, 31, 31));
        buttonStar->setFocusPolicy(Qt::NoFocus);
        buttonStar->setStyleSheet(QLatin1String("QToolButton{\n"
"border:none;\n"
"margin:0px;\n"
"padding:0px;\n"
"background-image:url(:/images/star.png)\n"
"}"));
        buttonTopLogo = new QPushButton(centralWidget);
        buttonTopLogo->setObjectName(QStringLiteral("buttonTopLogo"));
        buttonTopLogo->setGeometry(QRect(106, 14, 140, 140));
        buttonTopLogo->setCursor(QCursor(Qt::PointingHandCursor));
        buttonTopLogo->setFocusPolicy(Qt::NoFocus);
        buttonTopLogo->setToolTipDuration(-1);
        buttonTopLogo->setStyleSheet(QLatin1String("QPushButton{\n"
"padding:0px;\n"
"border:0px;\n"
"background-image:url(:/images/logo-0.png);\n"
"background-repeat:no-repeat;\n"
"background-position:center center;\n"
"}\n"
"\n"
""));
        labelLive = new QLabel(centralWidget);
        labelLive->setObjectName(QStringLiteral("labelLive"));
        labelLive->setGeometry(QRect(110, 200, 131, 31));
        labelLive->setStyleSheet(QStringLiteral("background:url(:/images/acum-live.png)"));
        labelHearth = new QLabel(centralWidget);
        labelHearth->setObjectName(QStringLiteral("labelHearth"));
        labelHearth->setGeometry(QRect(220, 370, 13, 13));
        labelHearth->setStyleSheet(QStringLiteral("background:url(:/images/hearth.png)"));
        labelCurrentSong = new QLabel(centralWidget);
        labelCurrentSong->setObjectName(QStringLiteral("labelCurrentSong"));
        labelCurrentSong->setGeometry(QRect(106, 294, 140, 51));
        labelCurrentSong->setFont(font);
        labelCurrentSong->setStyleSheet(QLatin1String("QLabel{\n"
"border:none;\n"
"background:none;\n"
"color:white;\n"
"}"));
        labelCurrentSong->setTextFormat(Qt::RichText);
        labelCurrentSong->setScaledContents(true);
        labelCurrentSong->setAlignment(Qt::AlignCenter);
        labelCurrentSong->setWordWrap(true);
        widgetMenu = new QWidget(centralWidget);
        widgetMenu->setObjectName(QStringLiteral("widgetMenu"));
        widgetMenu->setGeometry(QRect(38, 20, 311, 441));
        widgetMenu->setMinimumSize(QSize(311, 441));
        widgetMenu->setMaximumSize(QSize(311, 441));
        widgetMenu->setStyleSheet(QLatin1String("border: none;\n"
"margin: 0px;\n"
"padding: 0px;\n"
"background-image: url(:/images/menu-bg.png);\n"
"background-position:top left;"));
        checkBoxTitleBar = new QCheckBox(widgetMenu);
        checkBoxTitleBar->setObjectName(QStringLiteral("checkBoxTitleBar"));
        checkBoxTitleBar->setGeometry(QRect(20, 50, 281, 35));
        QFont font1;
        font1.setFamily(QStringLiteral("URW Gothic L"));
        font1.setPointSize(11);
        checkBoxTitleBar->setFont(font1);
        checkBoxTitleBar->setCursor(QCursor(Qt::PointingHandCursor));
        checkBoxTitleBar->setFocusPolicy(Qt::NoFocus);
        checkBoxTitleBar->setLayoutDirection(Qt::RightToLeft);
        checkBoxTitleBar->setStyleSheet(QLatin1String(" QCheckBox {\n"
"     spacing: 5px;\n"
" }\n"
"\n"
" QCheckBox::indicator {\n"
"     width: 53px;\n"
"     height: 35px;\n"
"	 margin:9px 5px 3px 3px;\n"
" }\n"
"\n"
" QCheckBox::indicator:unchecked {\n"
"     background-image: url(:/images/checkbox.png);\n"
"     background-position:right center;\n"
" }\n"
"\n"
" QCheckBox::indicator:checked {\n"
"     background-image: url(:/images/checkbox.png);\n"
"     background-position:left center;\n"
" }\n"
""));
        checkboxTest = new QCheckBox(widgetMenu);
        checkboxTest->setObjectName(QStringLiteral("checkboxTest"));
        checkboxTest->setGeometry(QRect(20, 90, 281, 35));
        checkboxTest->setFont(font1);
        checkboxTest->setCursor(QCursor(Qt::PointingHandCursor));
        checkboxTest->setFocusPolicy(Qt::NoFocus);
        checkboxTest->setLayoutDirection(Qt::RightToLeft);
        checkboxTest->setStyleSheet(QLatin1String(" QCheckBox {\n"
"     spacing: 5px;\n"
" }\n"
"\n"
" QCheckBox::indicator {\n"
"     width: 53px;\n"
"     height: 35px;\n"
"	 margin:9px 5px 3px 3px;\n"
" }\n"
"\n"
" QCheckBox::indicator:unchecked {\n"
"     background-image: url(:/images/checkbox.png);\n"
"     background-position:right center;\n"
" }\n"
"\n"
" QCheckBox::indicator:checked {\n"
"     background-image: url(:/images/checkbox.png);\n"
"     background-position:left center;\n"
" }\n"
"\n"
""));
        buttonClose = new QToolButton(centralWidget);
        buttonClose->setObjectName(QStringLiteral("buttonClose"));
        buttonClose->setGeometry(QRect(0, 0, 26, 26));
        buttonClose->setMinimumSize(QSize(26, 26));
        buttonClose->setMaximumSize(QSize(26, 26));
        buttonClose->setCursor(QCursor(Qt::ArrowCursor));
        buttonClose->setFocusPolicy(Qt::NoFocus);
        buttonClose->setStyleSheet(QLatin1String("QToolButton{\n"
"border: none;\n"
"width:26px;\n"
"height:26px;\n"
"margin: 0px;\n"
"padding: 0px;\n"
"background-image: url(:/images/close-icon.png)\n"
"}\n"
"\n"
"QToolButton:hover{\n"
"background-image: url(:/images/close-icon-hover.png)\n"
"}"));
        buttonMinimize = new QToolButton(centralWidget);
        buttonMinimize->setObjectName(QStringLiteral("buttonMinimize"));
        buttonMinimize->setGeometry(QRect(26, 0, 26, 26));
        buttonMinimize->setCursor(QCursor(Qt::ArrowCursor));
        buttonMinimize->setFocusPolicy(Qt::NoFocus);
        buttonMinimize->setStyleSheet(QLatin1String("QToolButton{\n"
"border: none;\n"
"width:26px;\n"
"height:26px;\n"
"margin: 0px;\n"
"padding: 0px;\n"
"background-image: url(:/images/minimize-icon.png)\n"
"}\n"
"\n"
"QToolButton:hover{\n"
"background-image: url(:/images/minimize-icon-hover.png)\n"
"}"));
        buttonLinux = new QToolButton(centralWidget);
        buttonLinux->setObjectName(QStringLiteral("buttonLinux"));
        buttonLinux->setGeometry(QRect(10, 480, 85, 42));
        buttonLinux->setCursor(QCursor(Qt::PointingHandCursor));
        buttonLinux->setStyleSheet(QLatin1String("border:0px;\n"
"margin:0px;\n"
"padding:0px;\n"
"background:url(:/images/tux.png)"));
        topLogoTip = new QToolButton(centralWidget);
        topLogoTip->setObjectName(QStringLiteral("topLogoTip"));
        topLogoTip->setEnabled(false);
        topLogoTip->setGeometry(QRect(125, 6, 103, 38));
        topLogoTip->setMinimumSize(QSize(103, 38));
        topLogoTip->setMaximumSize(QSize(103, 38));
        QFont font2;
        font2.setPointSize(8);
        topLogoTip->setFont(font2);
        topLogoTip->setStyleSheet(QLatin1String("background:none;\n"
"background-image:url(:/images/onefmro.png) top center;\n"
"border:0;\n"
"margin:0;\n"
"padding:0;"));
        changeRadioTip = new QToolButton(centralWidget);
        changeRadioTip->setObjectName(QStringLiteral("changeRadioTip"));
        changeRadioTip->setGeometry(QRect(5, 184, 97, 35));
        changeRadioTip->setMinimumSize(QSize(97, 35));
        changeRadioTip->setMaximumSize(QSize(97, 35));
        changeRadioTip->setStyleSheet(QLatin1String("background:none;\n"
"background-image:url(:/images/change-radio.png) top center;\n"
"border:0;\n"
"margin:0;\n"
"padding:0;\n"
""));
        MainWindow->setCentralWidget(centralWidget);
        buttonLogo->raise();
        buttonVolumeUp->raise();
        buttonVolumeDown->raise();
        sliderVolume->raise();
        labelCenter->raise();
        buttonPlay->raise();
        labelHand->raise();
        labelCurrentArtist->raise();
        buttonStar->raise();
        buttonTopLogo->raise();
        labelLive->raise();
        labelHearth->raise();
        labelCurrentSong->raise();
        widgetMenu->raise();
        buttonClose->raise();
        buttonMinimize->raise();
        buttonMenu->raise();
        buttonLinux->raise();
        topLogoTip->raise();
        changeRadioTip->raise();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionClose->setText(QApplication::translate("MainWindow", "Close", 0));
#ifndef QT_NO_TOOLTIP
        actionClose->setToolTip(QApplication::translate("MainWindow", "Close", 0));
#endif // QT_NO_TOOLTIP
        buttonMenu->setText(QString());
        buttonLogo->setText(QString());
        buttonVolumeUp->setText(QString());
        buttonVolumeDown->setText(QString());
        labelCenter->setText(QString());
        buttonPlay->setText(QString());
        labelHand->setText(QString());
        labelCurrentArtist->setText(QApplication::translate("MainWindow", "Apasa butonul play", 0));
        buttonStar->setText(QString());
#ifndef QT_NO_TOOLTIP
        buttonTopLogo->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        buttonTopLogo->setText(QString());
        labelLive->setText(QString());
        labelHearth->setText(QString());
        labelCurrentSong->setText(QString());
        checkBoxTitleBar->setText(QApplication::translate("MainWindow", "Use system title bar", 0));
        checkboxTest->setText(QApplication::translate("MainWindow", "Another checkbox to test", 0));
        buttonClose->setText(QString());
        buttonMinimize->setText(QString());
        buttonLinux->setText(QString());
        topLogoTip->setText(QString());
        changeRadioTip->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
