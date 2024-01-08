#include "seeds.h"
#include "QDebug"

QPushButton* Farmer_Pushbutton;
QPropertyAnimation *animation;

Seeds::Seeds() : timer(new QTimer(this)), timer2(new QTimer(this))
{
    connect(timer, &QTimer::timeout, this, &Seeds::TurnTimerOn);

    connect(timer2, &QTimer::timeout, this, &Seeds::Product_Collection_Delay_time_for_score);
}

void Seeds::TurnTimerOn()
{

    if(Product_production_time == 0){

        timer->stop();
        Product_Pushbutton->show();
        Product_Collection_Delay_time_for_score();
        TimerLabel->hide();
        Cancel_Pushbutton->hide();
        Animals_or_Seeds_Pushbutton->setEnabled(true);
        Farmer_Pushbutton->setEnabled(true);
        Farmer_Pushbutton->move(210, 160);
    } else {
        timer->start(1000);
        Product_production_time --;
        TimerLabel->setText(QString::number(Product_production_time));
        Product_Pushbutton->hide();

        animation = new QPropertyAnimation(Farmer_Pushbutton, "geometry", this);
        animation->setStartValue(QRect(210, 160, Farmer_Pushbutton->geometry().width(), Farmer_Pushbutton->geometry().height()));
        animation->setEndValue(QRect(330, 160, Farmer_Pushbutton->geometry().width(), Farmer_Pushbutton->geometry().height()));
        animation->setEasingCurve(QEasingCurve::Type::Linear);
        animation->setDuration(950);
        animation->start();
    }
}

void Seeds::SetTimerLabel(QLabel *label)
{
    TimerLabel = label;
}

void Seeds::Timer_Stop()
{
    timer->stop();
    TimerLabel->setText(QString::number(Product_production_time));
}

void Seeds::Set_Product_Pushbutton(QPushButton *pushbutton)
{
    Product_Pushbutton = pushbutton;
}

void Seeds::Set_Cancel_Pushbutton(QPushButton *pushbutton)
{
    Cancel_Pushbutton = pushbutton;
}

void Seeds::Set_Start_Pushbutton(QPushButton *pushbutton)
{
    Start_Pushbutton = pushbutton;
}

void Seeds::Set_Animals_or_Seeds_Pushbutton(QPushButton *pushbutton)
{
    Animals_or_Seeds_Pushbutton = pushbutton;
}

void Seeds::Set_Farmer_Pushbutton(QPushButton *pushbutton)
{
    Farmer_Pushbutton = pushbutton;
}

void Seeds::Product_Collection_Delay_time_for_score()
{

    timer2->start(1000);
    x ++;
    TimerLabel->setText(QString::number(x));

    if((x != 0) && (x % Product_Collection_Delay_time == 0)){

        Product_Collection_Point--;
        decrease_label->show();
        QPropertyAnimation *animation1 = new QPropertyAnimation(decrease_label, "geometry", this);
        animation1->setStartValue(QRect(160, 120, decrease_label->geometry().width(), decrease_label->geometry().height()));
        animation1->setEndValue(QRect(160, 50, decrease_label->geometry().width(), decrease_label->geometry().height()));
        animation1->setEasingCurve(QEasingCurve::Type::Linear);
        animation1->setDuration(500);
        animation1->start();

    }
    QPoint current_pos = decrease_label->pos();
    if(current_pos == QPoint(160, 50)){

        decrease_label->hide();
    }
}

void Seeds::Timer2_Stop()
{
    timer2->stop();
}

void Seeds::SetTimerLabel2(QLabel *label)
{
    TimerLabel2 = label;
}

void Seeds::Set_decrease_label(QLabel *label)
{
    decrease_label = label;
}

void Seeds::Stop_animation()
{
    animation->stop();
    delete animation;
    animation = nullptr;
    Farmer_Pushbutton->move(210, 160);
    Farmer_Pushbutton->setEnabled(true);
}
