#include "animals.h"
#include "QDebug"

//extern int Score;


Animals::Animals() : timer(new QTimer(this)), timer2(new QTimer(this))
{
    connect(timer, &QTimer::timeout, this, &Animals::TurnTimerOn);

    connect(timer2, &QTimer::timeout, this, &Animals::Product_Collection_Delay_time_for_score);
}

void Animals::TurnTimerOn()
{

    if(Product_production_time == 0){
        // do somthing
        qDebug()<<"time is out = "<< Product_production_time;
        timer->stop();
        Product_Pushbutton->show();
        Product_Collection_Delay_time_for_score();
        TimerLabel->hide();
        Cancel_Pushbutton->hide();
        Animals_or_Seeds_Pushbutton->setEnabled(true);
        Farmer_Pushbutton->setEnabled(true);
    } else {
        timer->start(1000);
        Product_production_time --;
        TimerLabel->setText(QString::number(Product_production_time));
        Product_Pushbutton->hide();
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
    Farmer_Pushbutton = pushbutton;
}

void Animals::Product_Collection_Delay_time_for_score()
{

    timer2->start(1000);
    x ++;
    TimerLabel->setText(QString::number(x));

    if((x != 0) && (x % Product_Collection_Delay_time == 0)){

        qDebug()<<"Product_Collection_Delay_time ="<<Product_Collection_Delay_time;
        Product_Collection_Point--;
       // TimerLabel2->setText( "Score :" + QString::number(Product_Collection_Point));
    }

}

void Animals::Timer2_Stop()
{
    timer2->stop();
  //  TimerLabel->setText(QString::number(Product_Collection_Delay_time));

}

void Animals::SetTimerLabel2(QLabel *label)
{
    TimerLabel2 = label;
}




















