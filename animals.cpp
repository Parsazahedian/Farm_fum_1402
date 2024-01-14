#include "animals.h"
#include "QDebug"

QPushButton* Farmer_Pushbutton1;QPushButton* Farmer_Pushbutton2;QPushButton* Farmer_Pushbutton3;QPushButton* Farmer_Pushbutton4;
QPushButton* Farmer_Pushbutton5;QPushButton* Farmer_Pushbutton6;QPushButton* Farmer_Pushbutton7;QPushButton* Farmer_Pushbutton8;
QPushButton* Farmer_Pushbutton9;QPushButton* Farmer_Pushbutton10;QPushButton* Farmer_Pushbutton11;QPushButton* Farmer_Pushbutton12;
QPushButton* Farmer_Pushbutton13;QPushButton* Farmer_Pushbutton14;QPushButton* Farmer_Pushbutton15;QPushButton* Farmer_Pushbutton16;

Animals::Animals() : timerDelay(new QTimer(this)), timer(new QTimer(this)),  timer2(new QTimer(this)),  timer3(new QTimer(this)), timer4(new QTimer(this)), timer5(new QTimer(this)), timer6(new QTimer(this)), timer7(new QTimer(this)), timer8(new QTimer(this))
  , timer9(new QTimer(this)), timer10(new QTimer(this)), timer11(new QTimer(this)), timer12(new QTimer(this)), timer13(new QTimer(this)), timer14(new QTimer(this)), timer15(new QTimer(this)), timer16(new QTimer(this))
{
    connect(timerDelay, &QTimer::timeout, this, &Animals::Product_Collection_Delay_time_for_score);

    connect(timer, &QTimer::timeout, this, &Animals::TurnTimerOn);
    connect(timer2, &QTimer::timeout, this, &Animals::TurnTimerOn2);
    connect(timer3, &QTimer::timeout, this, &Animals::TurnTimerOn3);
    connect(timer4, &QTimer::timeout, this, &Animals::TurnTimerOn4);
    connect(timer5, &QTimer::timeout, this, &Animals::TurnTimerOn5);
    connect(timer6, &QTimer::timeout, this, &Animals::TurnTimerOn6);
    connect(timer7, &QTimer::timeout, this, &Animals::TurnTimerOn7);
    connect(timer8, &QTimer::timeout, this, &Animals::TurnTimerOn8);
    connect(timer9, &QTimer::timeout, this, &Animals::TurnTimerOn9);
    connect(timer10, &QTimer::timeout, this, &Animals::TurnTimerOn10);
    connect(timer11, &QTimer::timeout, this, &Animals::TurnTimerOn11);
    connect(timer12, &QTimer::timeout, this, &Animals::TurnTimerOn12);
    connect(timer13, &QTimer::timeout, this, &Animals::TurnTimerOn13);
    connect(timer14, &QTimer::timeout, this, &Animals::TurnTimerOn14);
    connect(timer15, &QTimer::timeout, this, &Animals::TurnTimerOn15);
    connect(timer16, &QTimer::timeout, this, &Animals::TurnTimerOn16);
}

void Animals::TurnTimerOn()
{

    if(Product_production_time == 0){

        timer->stop();
        Product_Pushbutton->show();
        Product_Collection_Delay_time_for_score();
        TimerLabel->hide();
        Label_of_timer->hide();
        Cancel_Pushbutton->hide();
        Animals_or_Seeds_Pushbutton->setEnabled(true);
        Farmer_Pushbutton1->setEnabled(true);
        Farmer_Pushbutton1->move(X2, Y2);
        number_of_Free_farmers++;
        Farmers_status_label->setText(QString::number(number_of_Free_farmers) + " / " + QString::number(number_of_farmers));

    } else {
        timer->start(1000);
        Product_production_time --;
        TimerLabel->setText(QString::number(Product_production_time));
        Product_Pushbutton->hide();

        Farmer_animation->start();

    }
}

void Animals::TurnTimerOn2()
{
    if(Product_production_time == 0){

        timer2->stop();
        Product_Pushbutton->show();
        Product_Collection_Delay_time_for_score();
        TimerLabel->hide();
        Label_of_timer->hide();
        Cancel_Pushbutton->hide();
        Animals_or_Seeds_Pushbutton->setEnabled(true);
        Farmer_Pushbutton2->setEnabled(true);
        Farmer_Pushbutton2->move(X2, Y2);
        number_of_Free_farmers++;
        Farmers_status_label->setText(QString::number(number_of_Free_farmers) + " / " + QString::number(number_of_farmers));

    } else {
        timer2->start(1000);
        Product_production_time --;
        TimerLabel->setText(QString::number(Product_production_time));
        Product_Pushbutton->hide();

        Farmer_animation->start();
    }
}

void Animals::TurnTimerOn3()
{
    if(Product_production_time == 0){

        timer3->stop();
        Product_Pushbutton->show();
        Product_Collection_Delay_time_for_score();
        TimerLabel->hide();
        Label_of_timer->hide();
        Cancel_Pushbutton->hide();
        Animals_or_Seeds_Pushbutton->setEnabled(true);
        Farmer_Pushbutton3->setEnabled(true);
        Farmer_Pushbutton3->move(X2, Y2);
        number_of_Free_farmers++;
        Farmers_status_label->setText(QString::number(number_of_Free_farmers) + " / " + QString::number(number_of_farmers));

    } else {
        timer3->start(1000);
        Product_production_time --;
        TimerLabel->setText(QString::number(Product_production_time));
        Product_Pushbutton->hide();

        Farmer_animation->start();
    }
}

void Animals::TurnTimerOn4()
{
    if(Product_production_time == 0){

        timer4->stop();
        Product_Pushbutton->show();
        Product_Collection_Delay_time_for_score();
        TimerLabel->hide();
        Label_of_timer->hide();
        Cancel_Pushbutton->hide();
        Animals_or_Seeds_Pushbutton->setEnabled(true);
        Farmer_Pushbutton4->setEnabled(true);
        Farmer_Pushbutton4->move(X2, Y2);
        number_of_Free_farmers++;
        Farmers_status_label->setText(QString::number(number_of_Free_farmers) + " / " + QString::number(number_of_farmers));

    } else {
        timer4->start(1000);
        Product_production_time --;
        TimerLabel->setText(QString::number(Product_production_time));
        Product_Pushbutton->hide();

        Farmer_animation->start();
    }
}

void Animals::TurnTimerOn5()
{
    if(Product_production_time == 0){

        timer5->stop();
        Product_Pushbutton->show();
        Product_Collection_Delay_time_for_score();
        TimerLabel->hide();
        Label_of_timer->hide();
        Cancel_Pushbutton->hide();
        Animals_or_Seeds_Pushbutton->setEnabled(true);
        Farmer_Pushbutton5->setEnabled(true);
        Farmer_Pushbutton5->move(X2, Y2);
        number_of_Free_farmers++;
        Farmers_status_label->setText(QString::number(number_of_Free_farmers) + " / " + QString::number(number_of_farmers));

    } else {
        timer5->start(1000);
        Product_production_time --;
        TimerLabel->setText(QString::number(Product_production_time));
        Product_Pushbutton->hide();

        Farmer_animation->start();
    }
}

void Animals::TurnTimerOn6()
{
    if(Product_production_time == 0){

        timer6->stop();
        Product_Pushbutton->show();
        Product_Collection_Delay_time_for_score();
        TimerLabel->hide();
        Label_of_timer->hide();
        Cancel_Pushbutton->hide();
        Animals_or_Seeds_Pushbutton->setEnabled(true);
        Farmer_Pushbutton6->setEnabled(true);
        Farmer_Pushbutton6->move(X2, Y2);
        number_of_Free_farmers++;
        Farmers_status_label->setText(QString::number(number_of_Free_farmers) + " / " + QString::number(number_of_farmers));

    } else {
        timer6->start(1000);
        Product_production_time --;
        TimerLabel->setText(QString::number(Product_production_time));
        Product_Pushbutton->hide();

        Farmer_animation->start();
    }
}

void Animals::TurnTimerOn7()
{
    if(Product_production_time == 0){

        timer7->stop();
        Product_Pushbutton->show();
        Product_Collection_Delay_time_for_score();
        TimerLabel->hide();
        Label_of_timer->hide();
        Cancel_Pushbutton->hide();
        Animals_or_Seeds_Pushbutton->setEnabled(true);
        Farmer_Pushbutton7->setEnabled(true);
        Farmer_Pushbutton7->move(X2, Y2);
        number_of_Free_farmers++;
        Farmers_status_label->setText(QString::number(number_of_Free_farmers) + " / " + QString::number(number_of_farmers));

    } else {
        timer7->start(1000);
        Product_production_time --;
        TimerLabel->setText(QString::number(Product_production_time));
        Product_Pushbutton->hide();

        Farmer_animation->start();
    }
}

void Animals::TurnTimerOn8()
{
    if(Product_production_time == 0){

        timer8->stop();
        Product_Pushbutton->show();
        Product_Collection_Delay_time_for_score();
        TimerLabel->hide();
        Label_of_timer->hide();
        Cancel_Pushbutton->hide();
        Animals_or_Seeds_Pushbutton->setEnabled(true);
        Farmer_Pushbutton8->setEnabled(true);
        Farmer_Pushbutton8->move(X2, Y2);
        number_of_Free_farmers++;
        Farmers_status_label->setText(QString::number(number_of_Free_farmers) + " / " + QString::number(number_of_farmers));

    } else {
        timer8->start(1000);
        Product_production_time --;
        TimerLabel->setText(QString::number(Product_production_time));
        Product_Pushbutton->hide();

        Farmer_animation->start();
    }
}

void Animals::TurnTimerOn9()
{
    if(Product_production_time == 0){

        timer9->stop();
        Product_Pushbutton->show();
        Product_Collection_Delay_time_for_score();
        TimerLabel->hide();
        Label_of_timer->hide();
        Cancel_Pushbutton->hide();
        Animals_or_Seeds_Pushbutton->setEnabled(true);
        Farmer_Pushbutton9->setEnabled(true);
        Farmer_Pushbutton9->move(X2, Y2);
        number_of_Free_farmers++;
        Farmers_status_label->setText(QString::number(number_of_Free_farmers) + " / " + QString::number(number_of_farmers));

    } else {
        timer9->start(1000);
        Product_production_time --;
        TimerLabel->setText(QString::number(Product_production_time));
        Product_Pushbutton->hide();

        Farmer_animation->start();
    }
}

void Animals::TurnTimerOn10()
{
    if(Product_production_time == 0){

        timer10->stop();
        Product_Pushbutton->show();
        Product_Collection_Delay_time_for_score();
        TimerLabel->hide();
        Label_of_timer->hide();
        Cancel_Pushbutton->hide();
        Animals_or_Seeds_Pushbutton->setEnabled(true);
        Farmer_Pushbutton10->setEnabled(true);
        Farmer_Pushbutton10->move(X2, Y2);
        number_of_Free_farmers++;
        Farmers_status_label->setText(QString::number(number_of_Free_farmers) + " / " + QString::number(number_of_farmers));

    } else {
        timer10->start(1000);
        Product_production_time --;
        TimerLabel->setText(QString::number(Product_production_time));
        Product_Pushbutton->hide();

        Farmer_animation->start();
    }
}

void Animals::TurnTimerOn11()
{
    if(Product_production_time == 0){

        timer11->stop();
        Product_Pushbutton->show();
        Product_Collection_Delay_time_for_score();
        TimerLabel->hide();
        Label_of_timer->hide();
        Cancel_Pushbutton->hide();
        Animals_or_Seeds_Pushbutton->setEnabled(true);
        Farmer_Pushbutton11->setEnabled(true);
        Farmer_Pushbutton11->move(X2, Y2);
        number_of_Free_farmers++;
        Farmers_status_label->setText(QString::number(number_of_Free_farmers) + " / " + QString::number(number_of_farmers));

    } else {
        timer11->start(1000);
        Product_production_time --;
        TimerLabel->setText(QString::number(Product_production_time));
        Product_Pushbutton->hide();

        Farmer_animation->start();
    }
}

void Animals::TurnTimerOn12()
{
    if(Product_production_time == 0){

        timer12->stop();
        Product_Pushbutton->show();
        Product_Collection_Delay_time_for_score();
        TimerLabel->hide();
        Label_of_timer->hide();
        Cancel_Pushbutton->hide();
        Animals_or_Seeds_Pushbutton->setEnabled(true);
        Farmer_Pushbutton12->setEnabled(true);
        Farmer_Pushbutton12->move(X2, Y2);
        number_of_Free_farmers++;
        Farmers_status_label->setText(QString::number(number_of_Free_farmers) + " / " + QString::number(number_of_farmers));

    } else {
        timer12->start(1000);
        Product_production_time --;
        TimerLabel->setText(QString::number(Product_production_time));
        Product_Pushbutton->hide();

        Farmer_animation->start();
    }
}

void Animals::TurnTimerOn13()
{
    if(Product_production_time == 0){

        timer13->stop();
        Product_Pushbutton->show();
        Product_Collection_Delay_time_for_score();
        TimerLabel->hide();
        Label_of_timer->hide();
        Cancel_Pushbutton->hide();
        Animals_or_Seeds_Pushbutton->setEnabled(true);
        Farmer_Pushbutton13->setEnabled(true);
        Farmer_Pushbutton13->move(X2, Y2);
        number_of_Free_farmers++;
        Farmers_status_label->setText(QString::number(number_of_Free_farmers) + " / " + QString::number(number_of_farmers));

    } else {
        timer13->start(1000);
        Product_production_time --;
        TimerLabel->setText(QString::number(Product_production_time));
        Product_Pushbutton->hide();

        Farmer_animation->start();
    }
}

void Animals::TurnTimerOn14()
{
    if(Product_production_time == 0){

        timer14->stop();
        Product_Pushbutton->show();
        Product_Collection_Delay_time_for_score();
        TimerLabel->hide();
        Label_of_timer->hide();
        Cancel_Pushbutton->hide();
        Animals_or_Seeds_Pushbutton->setEnabled(true);
        Farmer_Pushbutton14->setEnabled(true);
        Farmer_Pushbutton14->move(X2, Y2);
        number_of_Free_farmers++;
        Farmers_status_label->setText(QString::number(number_of_Free_farmers) + " / " + QString::number(number_of_farmers));

    } else {
        timer14->start(1000);
        Product_production_time --;
        TimerLabel->setText(QString::number(Product_production_time));
        Product_Pushbutton->hide();

        Farmer_animation->start();
    }
}

void Animals::TurnTimerOn15()
{
    if(Product_production_time == 0){

        timer15->stop();
        Product_Pushbutton->show();
        Product_Collection_Delay_time_for_score();
        TimerLabel->hide();
        Label_of_timer->hide();
        Cancel_Pushbutton->hide();
        Animals_or_Seeds_Pushbutton->setEnabled(true);
        Farmer_Pushbutton15->setEnabled(true);
        Farmer_Pushbutton15->move(X2, Y2);
        number_of_Free_farmers++;
        Farmers_status_label->setText(QString::number(number_of_Free_farmers) + " / " + QString::number(number_of_farmers));

    } else {
        timer15->start(1000);
        Product_production_time --;
        TimerLabel->setText(QString::number(Product_production_time));
        Product_Pushbutton->hide();

        Farmer_animation->start();
    }
}

void Animals::TurnTimerOn16()
{
    if(Product_production_time == 0){

        timer16->stop();
        Product_Pushbutton->show();
        Product_Collection_Delay_time_for_score();
        TimerLabel->hide();
        Label_of_timer->hide();
        Cancel_Pushbutton->hide();
        Animals_or_Seeds_Pushbutton->setEnabled(true);
        Farmer_Pushbutton16->setEnabled(true);
        Farmer_Pushbutton16->move(X2, Y2);
        number_of_Free_farmers++;
        Farmers_status_label->setText(QString::number(number_of_Free_farmers) + " / " + QString::number(number_of_farmers));

    } else {
        timer16->start(1000);
        Product_production_time --;
        TimerLabel->setText(QString::number(Product_production_time));
        Product_Pushbutton->hide();

        Farmer_animation->start();
    }
}

void Animals::SetTimerLabel(QLabel *label)
{
    TimerLabel = label;
}

void Animals::Set_label_of_timers(QLabel *label)
{
    Label_of_timer = label;
}

void Animals::Set_Farmer_status_Label(QLabel *label)
{
    Farmers_status_label = label;
}

void Animals::Timer_Stop()
{
    timer->stop();
    TimerLabel->setText(QString::number(Product_production_time));
}

void Animals::Timer2_Stop()
{
    timer2->stop();
    TimerLabel->setText(QString::number(Product_production_time));
}

void Animals::Timer3_Stop()
{
    timer3->stop();
    TimerLabel->setText(QString::number(Product_production_time));
}

void Animals::Timer4_Stop()
{
    timer4->stop();
    TimerLabel->setText(QString::number(Product_production_time));
}

void Animals::Timer5_Stop()
{
    timer5->stop();
    TimerLabel->setText(QString::number(Product_production_time));
}

void Animals::Timer6_Stop()
{
    timer6->stop();
    TimerLabel->setText(QString::number(Product_production_time));
}

void Animals::Timer7_Stop()
{
    timer7->stop();
    TimerLabel->setText(QString::number(Product_production_time));
}

void Animals::Timer8_Stop()
{
    timer8->stop();
    TimerLabel->setText(QString::number(Product_production_time));
}

void Animals::Timer9_Stop()
{
    timer9->stop();
    TimerLabel->setText(QString::number(Product_production_time));
}

void Animals::Timer10_Stop()
{
    timer10->stop();
    TimerLabel->setText(QString::number(Product_production_time));
}

void Animals::Timer11_Stop()
{
    timer11->stop();
    TimerLabel->setText(QString::number(Product_production_time));
}

void Animals::Timer12_Stop()
{
    timer12->stop();
    TimerLabel->setText(QString::number(Product_production_time));
}

void Animals::Timer13_Stop()
{
    timer13->stop();
    TimerLabel->setText(QString::number(Product_production_time));
}

void Animals::Timer14_Stop()
{
    timer14->stop();
    TimerLabel->setText(QString::number(Product_production_time));
}

void Animals::Timer15_Stop()
{
    timer15->stop();
    TimerLabel->setText(QString::number(Product_production_time));
}

void Animals::Timer16_Stop()
{
    timer16->stop();
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
    QPoint current_pos = pushbutton->pos();

    if(current_pos == QPoint(210, 160)){

        Farmer_Pushbutton1 = pushbutton;

    }else if(current_pos == QPoint(600, 160)){

        Farmer_Pushbutton2 = pushbutton;

    }else if(current_pos == QPoint(1320, 160)){

        Farmer_Pushbutton3 = pushbutton;

    }else if(current_pos == QPoint(1710, 160)){

        Farmer_Pushbutton4 = pushbutton;

    }else if(current_pos == QPoint(210, 390)){

        Farmer_Pushbutton5 = pushbutton;

    }else if(current_pos == QPoint(600, 390)){

        Farmer_Pushbutton6 = pushbutton;

    }else if(current_pos == QPoint(1320, 390)){

        Farmer_Pushbutton7 = pushbutton;

    }else if(current_pos == QPoint(1710, 390)){

        Farmer_Pushbutton8 = pushbutton;

    }else if(current_pos == QPoint(210, 620)){

        Farmer_Pushbutton9 = pushbutton;

    }else if(current_pos == QPoint(600, 620)){

        Farmer_Pushbutton10 = pushbutton;

    }else if(current_pos == QPoint(1320, 620)){

        Farmer_Pushbutton11 = pushbutton;

    }else if(current_pos == QPoint(1710, 620)){

        Farmer_Pushbutton12 = pushbutton;

    }else if(current_pos == QPoint(210, 850)){

        Farmer_Pushbutton13 = pushbutton;

    }else if(current_pos == QPoint(600, 850)){

        Farmer_Pushbutton14 = pushbutton;

    }else if(current_pos == QPoint(1320, 850)){

        Farmer_Pushbutton15 = pushbutton;

    }else if(current_pos == QPoint(1710, 850)){

        Farmer_Pushbutton16 = pushbutton;
    }

}

void Animals::Product_Collection_Delay_time_for_score()
{

    timerDelay->start(1000);
    x ++;
    TimerLabel->setText(QString::number(x));

    if((x != 0) && (x % Product_Collection_Delay_time == 0)){

        Product_Collection_Point--;
        decrease_label->show();
        QPropertyAnimation *animation1 = new QPropertyAnimation(decrease_label, "geometry", this);
        animation1->setStartValue(QRect(X1, Y1, decrease_label->geometry().width(), decrease_label->geometry().height()));
        animation1->setEndValue(QRect(X1, Y1-70, decrease_label->geometry().width(), decrease_label->geometry().height()));
        animation1->setEasingCurve(QEasingCurve::Type::Linear);
        animation1->setDuration(500);
        animation1->start();

    }
    QPoint current_pos = decrease_label->pos();
    if(current_pos == QPoint(X1, Y1-70)){

        decrease_label->hide();
    }

}

void Animals::TimerDelay_Stop()
{
    timerDelay->stop();
}

void Animals::Set_decrease_label(QLabel *label)
{
    decrease_label = label;
}

void Animals::Farmer_pushbutton_setenable()
{

    Farmer_Pushbutton1->move(X2, Y2);
    Farmer_Pushbutton1->setEnabled(true);
    Farmer_animation->stop();
}

void Animals::Farmer_pushbutton_setenable2()
{

    Farmer_Pushbutton2->move(X2, Y2);
    Farmer_Pushbutton2->setEnabled(true);
    Farmer_animation->stop();
}

void Animals::Farmer_pushbutton_setenable3()
{

    Farmer_Pushbutton3->move(X2, Y2);
    Farmer_Pushbutton3->setEnabled(true);
    Farmer_animation->stop();
}

void Animals::Farmer_pushbutton_setenable4()
{

    Farmer_Pushbutton4->move(X2, Y2);
    Farmer_Pushbutton4->setEnabled(true);
    Farmer_animation->stop();
}

void Animals::Farmer_pushbutton_setenable5()
{

    Farmer_Pushbutton5->move(X2, Y2);
    Farmer_Pushbutton5->setEnabled(true);
    Farmer_animation->stop();
}

void Animals::Farmer_pushbutton_setenable6()
{

    Farmer_Pushbutton6->move(X2, Y2);
    Farmer_Pushbutton6->setEnabled(true);
    Farmer_animation->stop();
}

void Animals::Farmer_pushbutton_setenable7()
{

    Farmer_Pushbutton7->move(X2, Y2);
    Farmer_Pushbutton7->setEnabled(true);
    Farmer_animation->stop();
}

void Animals::Farmer_pushbutton_setenable8()
{

    Farmer_Pushbutton8->move(X2, Y2);
    Farmer_Pushbutton8->setEnabled(true);
    Farmer_animation->stop();
}

void Animals::Farmer_pushbutton_setenable9()
{

    Farmer_Pushbutton9->move(X2, Y2);
    Farmer_Pushbutton9->setEnabled(true);
    Farmer_animation->stop();
}

void Animals::Farmer_pushbutton_setenable10()
{

    Farmer_Pushbutton10->move(X2, Y2);
    Farmer_Pushbutton10->setEnabled(true);
    Farmer_animation->stop();
}

void Animals::Farmer_pushbutton_setenable11()
{

    Farmer_Pushbutton11->move(X2, Y2);
    Farmer_Pushbutton11->setEnabled(true);
    Farmer_animation->stop();
}

void Animals::Farmer_pushbutton_setenable12()
{

    Farmer_Pushbutton12->move(X2, Y2);
    Farmer_Pushbutton12->setEnabled(true);
    Farmer_animation->stop();
}

void Animals::Farmer_pushbutton_setenable13()
{

    Farmer_Pushbutton13->move(X2, Y2);
    Farmer_Pushbutton13->setEnabled(true);
    Farmer_animation->stop();
}

void Animals::Farmer_pushbutton_setenable14()
{

    Farmer_Pushbutton14->move(X2, Y2);
    Farmer_Pushbutton14->setEnabled(true);
    Farmer_animation->stop();
}

void Animals::Farmer_pushbutton_setenable15()
{

    Farmer_Pushbutton15->move(X2, Y2);
    Farmer_Pushbutton15->setEnabled(true);
    Farmer_animation->stop();
}

void Animals::Farmer_pushbutton_setenable16()
{

    Farmer_Pushbutton16->move(X2, Y2);
    Farmer_Pushbutton16->setEnabled(true);
    Farmer_animation->stop();
}

void Animals::decrease_label_position(int x, int y)
{
    X1 = x;
    Y1 = y;
}

void Animals::Set_Farmer_animation(QPropertyAnimation *animation)
{
    Farmer_animation = animation;
}

void Animals::Farmer_pushbutton_position(int x, int y)
{
    X2 = x;
    Y2 = y;
}






