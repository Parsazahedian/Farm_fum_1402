#include "seeds.h"
#include "QDebug"

Seeds::Seeds() : timer(new QTimer(this))
{
    connect(timer, &QTimer::timeout, this, &Seeds::TurnTimerOn);
}

void Seeds::TurnTimerOn()
{
    if(Product_production_time == 0){
        // do somthing
        qDebug()<<"time is out = "<< Product_production_time;
        timer->stop();
    } else {
        timer->start(1000);
        Product_production_time --;
        TimerLabel->setText(QString::number(Product_production_time));
    }
}
