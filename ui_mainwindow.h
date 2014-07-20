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
        MainWindow->setWindowModality(Qt::NonModal);
        MainWindow->setEnabled(true);
        MainWindow->resize(427, 640);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(427, 640));
        MainWindow->setMaximumSize(QSize(427, 640));
        MainWindow->setSizeIncrement(QSize(1, 1));
        MainWindow->setMouseTracking(false);
        MainWindow->setFocusPolicy(Qt::StrongFocus);
        MainWindow->setContextMenuPolicy(Qt::DefaultContextMenu);
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/logo-0.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QStringLiteral(""));
        actionClose = new QAction(MainWindow);
        actionClose->setObjectName(QStringLiteral("actionClose"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setEnabled(true);
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        centralWidget->setMaximumSize(QSize(427, 640));
        centralWidget->setBaseSize(QSize(427, 640));
        centralWidget->setMouseTracking(false);
        centralWidget->setFocusPolicy(Qt::StrongFocus);
        centralWidget->setStyleSheet(QStringLiteral("background-image:url(\":/images/background.png\");"));
        buttonMenu = new QToolButton(centralWidget);
        buttonMenu->setObjectName(QStringLiteral("buttonMenu"));
        buttonMenu->setEnabled(true);
        buttonMenu->setGeometry(QRect(380, 10, 37, 30));
        buttonMenu->setMinimumSize(QSize(37, 0));
        buttonMenu->setMaximumSize(QSize(37, 16777215));
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
        buttonLogo->setGeometry(QRect(10, 270, 100, 100));
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
        buttonVolumeUp->setGeometry(QRect(342, 135, 34, 29));
        buttonVolumeUp->setMinimumSize(QSize(0, 21));
        buttonVolumeUp->setMaximumSize(QSize(34, 16777215));
        buttonVolumeUp->setCursor(QCursor(Qt::PointingHandCursor));
        buttonVolumeUp->setFocusPolicy(Qt::NoFocus);
        buttonVolumeUp->setStyleSheet(QLatin1String("QToolButton{\n"
"border: none;\n"
"margin: 0px;\n"
"padding: 0px;\n"
"background-image:url(\":/images/volume-icon-up.png\");\n"
"}"));
        buttonVolumeDown = new QToolButton(centralWidget);
        buttonVolumeDown->setObjectName(QStringLiteral("buttonVolumeDown"));
        buttonVolumeDown->setGeometry(QRect(345, 490, 27, 27));
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
        sliderVolume->setGeometry(QRect(330, 170, 60, 312));
        sliderVolume->setMinimumSize(QSize(60, 312));
        sliderVolume->setMaximumSize(QSize(62, 16777215));
        sliderVolume->setCursor(QCursor(Qt::ArrowCursor));
        sliderVolume->setStyleSheet(QLatin1String("QSlider{\n"
"background-image:url(\":/images/volume-grid.png\");\n"
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
"background-image:url(\":/images/volume-controller.png\");\n"
"width: 38px;\n"
"height: 39px;\n"
"}\n"
"QSlider::handle:vertical:pressed{\n"
"background-image:url(\":/images/volume-controller-pressed.png\");\n"
"}\n"
""));
        sliderVolume->setOrientation(Qt::Vertical);
        labelCenter = new QLabel(centralWidget);
        labelCenter->setObjectName(QStringLiteral("labelCenter"));
        labelCenter->setGeometry(QRect(110, 10, 192, 616));
        labelCenter->setStyleSheet(QStringLiteral("background-image:url(:/images/center-bg.png)"));
        buttonPlay = new QToolButton(centralWidget);
        buttonPlay->setObjectName(QStringLiteral("buttonPlay"));
        buttonPlay->setGeometry(QRect(146, 460, 120, 120));
        buttonPlay->setCursor(QCursor(Qt::PointingHandCursor));
        buttonPlay->setFocusPolicy(Qt::NoFocus);
        buttonPlay->setStyleSheet(QLatin1String("QToolButton{\n"
"border: none;\n"
"padding:0px;\n"
"margin:0px;\n"
"background-image:url(:/images/play-button.png)\n"
"}"));
        labelHand = new QLabel(centralWidget);
        labelHand->setObjectName(QStringLiteral("labelHand"));
        labelHand->setEnabled(true);
        labelHand->setGeometry(QRect(170, 360, 73, 73));
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
        labelCurrentArtist->setGeometry(QRect(136, 280, 140, 63));
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
        buttonStar->setEnabled(true);
        buttonStar->setGeometry(QRect(190, 185, 35, 37));
        buttonStar->setFocusPolicy(Qt::NoFocus);
        buttonStar->setStyleSheet(QLatin1String("QToolButton{\n"
"border:none;\n"
"margin:0px;\n"
"padding:0px;\n"
"background-image:url(:/images/star.png)\n"
"}"));
        buttonTopLogo = new QPushButton(centralWidget);
        buttonTopLogo->setObjectName(QStringLiteral("buttonTopLogo"));
        buttonTopLogo->setGeometry(QRect(116, 10, 180, 180));
        buttonTopLogo->setCursor(QCursor(Qt::PointingHandCursor));
        buttonTopLogo->setFocusPolicy(Qt::NoFocus);
        buttonTopLogo->setToolTipDuration(-1);
        buttonTopLogo->setStyleSheet(QLatin1String("QPushButton{\n"
"padding:0px;\n"
"border:0px;\n"
"background:url(:/images/logo-0.png);\n"
"}\n"
"\n"
""));
        labelLive = new QLabel(centralWidget);
        labelLive->setObjectName(QStringLiteral("labelLive"));
        labelLive->setGeometry(QRect(124, 240, 164, 40));
        labelLive->setStyleSheet(QStringLiteral("background:url(:/images/acum-live.png)"));
        labelHearth = new QLabel(centralWidget);
        labelHearth->setObjectName(QStringLiteral("labelHearth"));
        labelHearth->setGeometry(QRect(255, 465, 16, 16));
        labelHearth->setStyleSheet(QStringLiteral("background:url(:/images/hearth.png)"));
        labelCurrentSong = new QLabel(centralWidget);
        labelCurrentSong->setObjectName(QStringLiteral("labelCurrentSong"));
        labelCurrentSong->setGeometry(QRect(136, 352, 140, 51));
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
        widgetMenu->setGeometry(QRect(107, 20, 311, 441));
        widgetMenu->setStyleSheet(QLatin1String("border: none;\n"
"margin: 0px;\n"
"padding: 0px;\n"
"background-image: url(:/images/menu-bg.png);\n"
"background-position:top left;"));
        checkBoxTitleBar = new QCheckBox(widgetMenu);
        checkBoxTitleBar->setObjectName(QStringLiteral("checkBoxTitleBar"));
        checkBoxTitleBar->setGeometry(QRect(20, 50, 281, 30));
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
"     width: 67px;\n"
"     height: 30px;\n"
" }\n"
"\n"
" QCheckBox::indicator:unchecked {\n"
"     image: url(:/images/checkbox_unchecked.png);\n"
" }\n"
"\n"
" QCheckBox::indicator:checked {\n"
"     image: url(:/images/checkbox_checked.png);\n"
" }\n"
""));
        checkboxTest = new QCheckBox(widgetMenu);
        checkboxTest->setObjectName(QStringLiteral("checkboxTest"));
        checkboxTest->setGeometry(QRect(20, 90, 281, 30));
        checkboxTest->setFont(font1);
        checkboxTest->setCursor(QCursor(Qt::PointingHandCursor));
        checkboxTest->setFocusPolicy(Qt::NoFocus);
        checkboxTest->setLayoutDirection(Qt::RightToLeft);
        checkboxTest->setStyleSheet(QLatin1String(" QCheckBox {\n"
"     spacing: 5px;\n"
" }\n"
"\n"
" QCheckBox::indicator {\n"
"     width: 67px;\n"
"     height: 30px;\n"
" }\n"
"\n"
" QCheckBox::indicator:unchecked {\n"
"     image: url(:/images/checkbox_unchecked.png);\n"
" }\n"
"\n"
" QCheckBox::indicator:checked {\n"
"     image: url(:/images/checkbox_checked.png);\n"
" }\n"
"\n"
""));
        buttonClose = new QToolButton(centralWidget);
        buttonClose->setObjectName(QStringLiteral("buttonClose"));
        buttonClose->setGeometry(QRect(0, 0, 24, 24));
        buttonClose->setCursor(QCursor(Qt::ArrowCursor));
        buttonClose->setFocusPolicy(Qt::NoFocus);
        buttonClose->setStyleSheet(QLatin1String("QToolButton{\n"
"border: none;\n"
"width:24px;\n"
"height:24px;\n"
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
        buttonMinimize->setGeometry(QRect(24, 0, 24, 24));
        buttonMinimize->setCursor(QCursor(Qt::ArrowCursor));
        buttonMinimize->setFocusPolicy(Qt::NoFocus);
        buttonMinimize->setStyleSheet(QLatin1String("QToolButton{\n"
"border: none;\n"
"width:24px;\n"
"height:24px;\n"
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
        buttonLinux->setGeometry(QRect(10, 580, 105, 52));
        buttonLinux->setCursor(QCursor(Qt::PointingHandCursor));
        buttonLinux->setStyleSheet(QLatin1String("border:0px;\n"
"margin:0px;\n"
"padding:0px;\n"
"background:url(:/images/tux.png)"));
        topLogoTip = new QToolButton(centralWidget);
        topLogoTip->setObjectName(QStringLiteral("topLogoTip"));
        topLogoTip->setGeometry(QRect(156, 5, 103, 38));
        topLogoTip->setMinimumSize(QSize(103, 38));
        topLogoTip->setMaximumSize(QSize(103, 38));
        topLogoTip->setStyleSheet(QLatin1String("background:none;\n"
"background-image:url(:/images/onefmro.png) top center;\n"
"border:0;\n"
"margin:0;\n"
"padding:0;\n"
""));
        changeRadioTip = new QToolButton(centralWidget);
        changeRadioTip->setObjectName(QStringLiteral("changeRadioTip"));
        changeRadioTip->setGeometry(QRect(11, 252, 97, 35));
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
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "OneFM", 0));
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
