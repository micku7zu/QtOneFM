#include "mainwindow.h"



bool MainWindow::eventFilter(QObject* obj, QEvent* event)
{

    if(obj == ui->buttonTopLogo)
    {

        if(event->type() == QEvent::Enter)
        {

            ui->topLogoTip->setVisible(true);
            ui->topLogoTip->graphicsEffect()->setProperty("opacity", 1);

        }
        if(event->type() == QEvent::Leave)
        {

            topLogoTipFade->start();

        }

    }

    if(obj == ui->buttonLogo)
    {

        if(event->type() == QEvent::Enter)
        {

            ui->changeRadioTip->setVisible(true);
            ui->changeRadioTip->graphicsEffect()->setProperty("opacity", 1);

        }
        if(event->type() == QEvent::Leave)
        {

           changeRadioTipFade->start();

        }

    }

    return false;

}


void MainWindow::setEffects()
{
    setShadow(ui->labelCurrentArtist, 1, 3);
    setShadow(ui->labelCurrentSong, 1, 3);
    ui->labelHand->setAttribute(Qt::WA_TransparentForMouseEvents);

    QGraphicsOpacityEffect *menuOpacity = new QGraphicsOpacityEffect;
    menuFade = new QPropertyAnimation(menuOpacity, "opacity");
    menuOpacity->setOpacity(0);
    ui->widgetMenu->setAttribute(Qt::WA_TransparentForMouseEvents);
    ui->widgetMenu->setGraphicsEffect(menuOpacity);
    menuFade->setDuration(400);
    menuFade->setStartValue(0);
    menuFade->setEndValue(1);
    menuFade->setEasingCurve(QEasingCurve::InCubic);

    //handMove
    handMove = new QPropertyAnimation(ui->labelHand, "geometry");
    handMove->setDuration(1300);
    handMove->setKeyValueAt(0, QRect(170, 360, 73, 73));
    handMove->setKeyValueAt(1, QRect(170, 390, 73, 73));
    handMove->setEasingCurve(QEasingCurve::OutBounce);
    handMove->setLoopCount(-1);
    handMove->start();

    //hand fade
    QGraphicsOpacityEffect *handOpacity = new QGraphicsOpacityEffect;
    handFade = new QPropertyAnimation(handOpacity, "opacity");
    ui->labelHand->setGraphicsEffect(handOpacity);
    handFade->setDuration(400);
    handFade->setStartValue(1);
    handFade->setEndValue(0);
    handFade->setEasingCurve(QEasingCurve::InCubic);

    //Top logo ToolTip
    QGraphicsOpacityEffect *topLogoTipOpacity = new QGraphicsOpacityEffect;
    topLogoTipFade = new QPropertyAnimation(topLogoTipOpacity, "opacity");
    ui->topLogoTip->setGraphicsEffect(topLogoTipOpacity);
    topLogoTipFade->setDuration(400);
    topLogoTipFade->setStartValue(1);
    topLogoTipFade->setEndValue(0);
    topLogoTipFade->setEasingCurve(QEasingCurve::InCubic);

    //Change Radio ToolTip
    QGraphicsOpacityEffect *changeRadioTipOpacity = new QGraphicsOpacityEffect;
    changeRadioTipFade = new QPropertyAnimation(changeRadioTipOpacity, "opacity");
    ui->changeRadioTip->setGraphicsEffect(changeRadioTipOpacity);
    changeRadioTipFade->setDuration(400);
    changeRadioTipFade->setStartValue(1);
    changeRadioTipFade->setEndValue(0);
    changeRadioTipFade->setEasingCurve(QEasingCurve::InCubic);
}

void MainWindow::setShadow(QLabel *label, int offset, int blur)
{
    QGraphicsDropShadowEffect* effect = new QGraphicsDropShadowEffect();
    effect->setBlurRadius(blur);
    effect->setOffset(offset);
    label->setGraphicsEffect(effect);
}
