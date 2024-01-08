#include "animals.h"
#include "QDebug"

QPropertyAnimation *animation1;
QPushButton* Farmer_Pushbutton1;

Animals::Animals() : timer(new QTimer(this)), timer2(new QTimer(this))
{
    connect(timer, &QTimer::timeout, this, &Animals::TurnTimerOn);

    connect(timer2, &QTimer::timeout, this, &Animals::Product_Collection_Delay_time_for_score);
}

void Animals::TurnTimerOn()
{

    if(Product_production_time == 0){

        timer->stop();
        Product_Pushbutton->show();
        Product_Collection_Delay_time_for_score();
        TimerLabel->hide();
        Cancel_Pushbutton->hide();
        Animals_or_Seeds_Pushbutton->setEnabled(true);
        Farmer_Pushbutton1->setEnabled(true);
        Farmer_Pushbutton1->move(210, 160);
    } else {
        timer->start(1000);
        Product_production_time --;
        TimerLabel->setText(QString::number(Product_production_time));
        Product_Pushbutton->hide();

        animation1 = new QPropertyAnimation(Farmer_Pushbutton1, "geometry", this);
        animation1->setStartValue(QRect(210, 160, Farmer_Pushbutton1->geometry().width(), Farmer_Pushbutton1->geometry().height()));
        animation1->setEndValue(QRect(330, 160, Farmer_Pushbutton1->geometry().width(), Farmer_Pushbutton1->geometry().height()));
        animation1->setEasingCurve(QEasingCurve::Type::Linear);
        animation1->setDuration(950);
        animation1->start();
    }
}

void Animals::SetTimerLabel(QLabel *label)
{
    TimerLabel = label;
}

void Animals::Timer_Stop()
{
    timer->stop();
    TimerLabel->setText(QString::number(Product_production_time));
}

void Animals::Set_Product_Pushbutton(QPushButton *pushbutton)
{
    Product_Pushbutton = pushbutton;
}

void Animals::Set_Cancel_Pushbutton(QPushButton *pushbutton)
{
    Cancel_Pushbutton = pushbutton;
}

void Animals::Set_Start_Pushbutton(QPushButton *pushbutton)
{
    Start_Pushbutton = pushbutton;
}

void Animals::Set_Animals_or_Seeds_Pushbutton(QPushButton *pushbutton)
{
    Animals_or_Seeds_Pushbutton = pushbutton;
}

void Animals::Set_Farmer_Pushbutton(QPushButton *pushbutton)
{
    Farmer_Pushbutton1 = pushbutton;
}

void Animals::Product_Collection_Delay_time_for_score()
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

void Animals::Timer2_Stop()
{
    timer2->stop();
}

void Animals::SetTimerLabel2(QLabel *label)
{
    TimerLabel2 = label;
}

void Animals::Set_decrease_label(QLabel *label)
{
    decrease_label = label;
}

void Animals::Stop_animation()
{
    animation1->stop();
    delete animation1;
    animation1 = nullptr;
    Farmer_Pushbutton1->move(210, 160);
    Farmer_Pushbutton1->setEnabled(true);
}





