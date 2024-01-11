#include "seeds.h"
#include "QDebug"

QPushButton* Farmer1_Pushbutton;QPushButton* Farmer2_Pushbutton;QPushButton* Farmer3_Pushbutton;QPushButton* Farmer4_Pushbutton;
QPushButton* Farmer5_Pushbutton;QPushButton* Farmer6_Pushbutton;QPushButton* Farmer7_Pushbutton;QPushButton* Farmer8_Pushbutton;
QPushButton* Farmer9_Pushbutton;QPushButton* Farmer10_Pushbutton;QPushButton* Farmer11_Pushbutton;QPushButton* Farmer12_Pushbutton;
QPushButton* Farmer13_Pushbutton;QPushButton* Farmer14_Pushbutton;QPushButton* Farmer15_Pushbutton;QPushButton* Farmer16_Pushbutton;

Seeds::Seeds() : timerDelay(new QTimer(this)), timer(new QTimer(this)),  timer2(new QTimer(this)),  timer3(new QTimer(this)), timer4(new QTimer(this)), timer5(new QTimer(this)), timer6(new QTimer(this)), timer7(new QTimer(this)), timer8(new QTimer(this))
  , timer9(new QTimer(this)), timer10(new QTimer(this)), timer11(new QTimer(this)), timer12(new QTimer(this)), timer13(new QTimer(this)), timer14(new QTimer(this)), timer15(new QTimer(this)), timer16(new QTimer(this))
{
    connect(timerDelay, &QTimer::timeout, this, &Seeds::Product_Collection_Delay_time_for_score);

    connect(timer, &QTimer::timeout, this, &Seeds::TurnTimerOn);
    connect(timer2, &QTimer::timeout, this, &Seeds::TurnTimerOn2);
    connect(timer3, &QTimer::timeout, this, &Seeds::TurnTimerOn3);
    connect(timer4, &QTimer::timeout, this, &Seeds::TurnTimerOn4);
    connect(timer5, &QTimer::timeout, this, &Seeds::TurnTimerOn5);
    connect(timer6, &QTimer::timeout, this, &Seeds::TurnTimerOn6);
    connect(timer7, &QTimer::timeout, this, &Seeds::TurnTimerOn7);
    connect(timer8, &QTimer::timeout, this, &Seeds::TurnTimerOn8);
    connect(timer9, &QTimer::timeout, this, &Seeds::TurnTimerOn9);
    connect(timer10, &QTimer::timeout, this, &Seeds::TurnTimerOn10);
    connect(timer11, &QTimer::timeout, this, &Seeds::TurnTimerOn11);
    connect(timer12, &QTimer::timeout, this, &Seeds::TurnTimerOn12);
    connect(timer13, &QTimer::timeout, this, &Seeds::TurnTimerOn13);
    connect(timer14, &QTimer::timeout, this, &Seeds::TurnTimerOn14);
    connect(timer15, &QTimer::timeout, this, &Seeds::TurnTimerOn15);
    connect(timer16, &QTimer::timeout, this, &Seeds::TurnTimerOn16);

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
        Farmer1_Pushbutton->setEnabled(true);
        Farmer1_Pushbutton->move(X2, Y2);
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

void Seeds::TurnTimerOn2()
{
    if(Product_production_time == 0){

        timer2->stop();
        Product_Pushbutton->show();
        Product_Collection_Delay_time_for_score();
        TimerLabel->hide();
        Cancel_Pushbutton->hide();
        Animals_or_Seeds_Pushbutton->setEnabled(true);
        Farmer2_Pushbutton->setEnabled(true);
        Farmer2_Pushbutton->move(X2, Y2);
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

void Seeds::TurnTimerOn3()
{
    if(Product_production_time == 0){

        timer3->stop();
        Product_Pushbutton->show();
        Product_Collection_Delay_time_for_score();
        TimerLabel->hide();
        Cancel_Pushbutton->hide();
        Animals_or_Seeds_Pushbutton->setEnabled(true);
        Farmer3_Pushbutton->setEnabled(true);
        Farmer3_Pushbutton->move(X2, Y2);
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

void Seeds::TurnTimerOn4()
{
    if(Product_production_time == 0){

        timer4->stop();
        Product_Pushbutton->show();
        Product_Collection_Delay_time_for_score();
        TimerLabel->hide();
        Cancel_Pushbutton->hide();
        Animals_or_Seeds_Pushbutton->setEnabled(true);
        Farmer4_Pushbutton->setEnabled(true);
        Farmer4_Pushbutton->move(X2, Y2);
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

void Seeds::TurnTimerOn5()
{
    if(Product_production_time == 0){

        timer5->stop();
        Product_Pushbutton->show();
        Product_Collection_Delay_time_for_score();
        TimerLabel->hide();
        Cancel_Pushbutton->hide();
        Animals_or_Seeds_Pushbutton->setEnabled(true);
        Farmer5_Pushbutton->setEnabled(true);
        Farmer5_Pushbutton->move(X2, Y2);
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

void Seeds::TurnTimerOn6()
{
    if(Product_production_time == 0){

        timer6->stop();
        Product_Pushbutton->show();
        Product_Collection_Delay_time_for_score();
        TimerLabel->hide();
        Cancel_Pushbutton->hide();
        Animals_or_Seeds_Pushbutton->setEnabled(true);
        Farmer6_Pushbutton->setEnabled(true);
        Farmer6_Pushbutton->move(X2, Y2);
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

void Seeds::TurnTimerOn7()
{
    if(Product_production_time == 0){

        timer7->stop();
        Product_Pushbutton->show();
        Product_Collection_Delay_time_for_score();
        TimerLabel->hide();
        Cancel_Pushbutton->hide();
        Animals_or_Seeds_Pushbutton->setEnabled(true);
        Farmer7_Pushbutton->setEnabled(true);
        Farmer7_Pushbutton->move(X2, Y2);
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

void Seeds::TurnTimerOn8()
{
    if(Product_production_time == 0){

        timer8->stop();
        Product_Pushbutton->show();
        Product_Collection_Delay_time_for_score();
        TimerLabel->hide();
        Cancel_Pushbutton->hide();
        Animals_or_Seeds_Pushbutton->setEnabled(true);
        Farmer8_Pushbutton->setEnabled(true);
        Farmer8_Pushbutton->move(X2, Y2);
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

void Seeds::TurnTimerOn9()
{
    if(Product_production_time == 0){

        timer9->stop();
        Product_Pushbutton->show();
        Product_Collection_Delay_time_for_score();
        TimerLabel->hide();
        Cancel_Pushbutton->hide();
        Animals_or_Seeds_Pushbutton->setEnabled(true);
        Farmer9_Pushbutton->setEnabled(true);
        Farmer9_Pushbutton->move(X2, Y2);
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

void Seeds::TurnTimerOn10()
{
    if(Product_production_time == 0){

        timer10->stop();
        Product_Pushbutton->show();
        Product_Collection_Delay_time_for_score();
        TimerLabel->hide();
        Cancel_Pushbutton->hide();
        Animals_or_Seeds_Pushbutton->setEnabled(true);
        Farmer10_Pushbutton->setEnabled(true);
        Farmer10_Pushbutton->move(X2, Y2);
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

void Seeds::TurnTimerOn11()
{
    if(Product_production_time == 0){

        timer11->stop();
        Product_Pushbutton->show();
        Product_Collection_Delay_time_for_score();
        TimerLabel->hide();
        Cancel_Pushbutton->hide();
        Animals_or_Seeds_Pushbutton->setEnabled(true);
        Farmer11_Pushbutton->setEnabled(true);
        Farmer11_Pushbutton->move(X2, Y2);
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

void Seeds::TurnTimerOn12()
{
    if(Product_production_time == 0){

        timer12->stop();
        Product_Pushbutton->show();
        Product_Collection_Delay_time_for_score();
        TimerLabel->hide();
        Cancel_Pushbutton->hide();
        Animals_or_Seeds_Pushbutton->setEnabled(true);
        Farmer12_Pushbutton->setEnabled(true);
        Farmer12_Pushbutton->move(X2, Y2);
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

void Seeds::TurnTimerOn13()
{
    if(Product_production_time == 0){

        timer13->stop();
        Product_Pushbutton->show();
        Product_Collection_Delay_time_for_score();
        TimerLabel->hide();
        Cancel_Pushbutton->hide();
        Animals_or_Seeds_Pushbutton->setEnabled(true);
        Farmer13_Pushbutton->setEnabled(true);
        Farmer13_Pushbutton->move(X2, Y2);
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

void Seeds::TurnTimerOn14()
{
    if(Product_production_time == 0){

        timer14->stop();
        Product_Pushbutton->show();
        Product_Collection_Delay_time_for_score();
        TimerLabel->hide();
        Cancel_Pushbutton->hide();
        Animals_or_Seeds_Pushbutton->setEnabled(true);
        Farmer14_Pushbutton->setEnabled(true);
        Farmer14_Pushbutton->move(X2, Y2);
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

void Seeds::TurnTimerOn15()
{
    if(Product_production_time == 0){

        timer15->stop();
        Product_Pushbutton->show();
        Product_Collection_Delay_time_for_score();
        TimerLabel->hide();
        Cancel_Pushbutton->hide();
        Animals_or_Seeds_Pushbutton->setEnabled(true);
        Farmer15_Pushbutton->setEnabled(true);
        Farmer15_Pushbutton->move(X2, Y2);
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

void Seeds::TurnTimerOn16()
{
    if(Product_production_time == 0){

        timer16->stop();
        Product_Pushbutton->show();
        Product_Collection_Delay_time_for_score();
        TimerLabel->hide();
        Cancel_Pushbutton->hide();
        Animals_or_Seeds_Pushbutton->setEnabled(true);
        Farmer16_Pushbutton->setEnabled(true);
        Farmer16_Pushbutton->move(X2, Y2);
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

void Seeds::SetTimerLabel(QLabel *label)
{
    TimerLabel = label;
}

void Seeds::Set_Farmer_status_Label(QLabel *label)
{
    Farmers_status_label = label;
}

void Seeds::Timer_Stop()
{
    timer->stop();
    TimerLabel->setText(QString::number(Product_production_time));
}

void Seeds::Timer2_Stop()
{
    timer2->stop();
    TimerLabel->setText(QString::number(Product_production_time));
}

void Seeds::Timer3_Stop()
{
    timer3->stop();
    TimerLabel->setText(QString::number(Product_production_time));
}

void Seeds::Timer4_Stop()
{
    timer4->stop();
    TimerLabel->setText(QString::number(Product_production_time));
}

void Seeds::Timer5_Stop()
{
    timer5->stop();
    TimerLabel->setText(QString::number(Product_production_time));
}

void Seeds::Timer6_Stop()
{
    timer6->stop();
    TimerLabel->setText(QString::number(Product_production_time));
}

void Seeds::Timer7_Stop()
{
    timer7->stop();
    TimerLabel->setText(QString::number(Product_production_time));
}

void Seeds::Timer8_Stop()
{
    timer8->stop();
    TimerLabel->setText(QString::number(Product_production_time));
}

void Seeds::Timer9_Stop()
{
    timer9->stop();
    TimerLabel->setText(QString::number(Product_production_time));
}

void Seeds::Timer10_Stop()
{
    timer10->stop();
    TimerLabel->setText(QString::number(Product_production_time));
}

void Seeds::Timer11_Stop()
{
    timer11->stop();
    TimerLabel->setText(QString::number(Product_production_time));
}

void Seeds::Timer12_Stop()
{
    timer12->stop();
    TimerLabel->setText(QString::number(Product_production_time));
}

void Seeds::Timer13_Stop()
{
    timer13->stop();
    TimerLabel->setText(QString::number(Product_production_time));
}

void Seeds::Timer14_Stop()
{
    timer14->stop();
    TimerLabel->setText(QString::number(Product_production_time));
}

void Seeds::Timer15_Stop()
{
    timer15->stop();
    TimerLabel->setText(QString::number(Product_production_time));
}

void Seeds::Timer16_Stop()
{
    timer16->stop();
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
    QPoint current_pos = pushbutton->pos();

    if(current_pos == QPoint(210, 160)){

        Farmer1_Pushbutton = pushbutton;

    }else if(current_pos == QPoint(600, 160)){

        Farmer2_Pushbutton = pushbutton;

    }else if(current_pos == QPoint(1320, 160)){

        Farmer3_Pushbutton = pushbutton;

    }else if(current_pos == QPoint(1710, 160)){

        Farmer4_Pushbutton = pushbutton;

    }else if(current_pos == QPoint(210, 390)){

        Farmer5_Pushbutton = pushbutton;

    }else if(current_pos == QPoint(600, 390)){

        Farmer6_Pushbutton = pushbutton;

    }else if(current_pos == QPoint(1320, 390)){

        Farmer7_Pushbutton = pushbutton;

    }else if(current_pos == QPoint(1710, 390)){

        Farmer8_Pushbutton = pushbutton;

    }else if(current_pos == QPoint(210, 620)){

        Farmer9_Pushbutton = pushbutton;

    }else if(current_pos == QPoint(600, 620)){

        Farmer10_Pushbutton = pushbutton;

    }else if(current_pos == QPoint(1320, 620)){

        Farmer11_Pushbutton = pushbutton;

    }else if(current_pos == QPoint(1710, 620)){

        Farmer12_Pushbutton = pushbutton;

    }else if(current_pos == QPoint(210, 850)){

        Farmer13_Pushbutton = pushbutton;

    }else if(current_pos == QPoint(600, 850)){

        Farmer14_Pushbutton = pushbutton;

    }else if(current_pos == QPoint(1320, 850)){

        Farmer15_Pushbutton = pushbutton;

    }else if(current_pos == QPoint(1710, 850)){

        Farmer16_Pushbutton = pushbutton;
    }

}

void Seeds::Product_Collection_Delay_time_for_score()
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

void Seeds::TimerDelay_Stop()
{
    timerDelay->stop();
}

void Seeds::Set_decrease_label(QLabel *label)
{
    decrease_label = label;
}

void Seeds::Farmer_pushbutton_setenable()
{

    Farmer1_Pushbutton->move(X2, Y2);
    Farmer1_Pushbutton->setEnabled(true);
    Farmer_animation->stop();
}

void Seeds::Farmer_pushbutton_setenable2()
{

    Farmer2_Pushbutton->move(X2, Y2);
    Farmer2_Pushbutton->setEnabled(true);
    Farmer_animation->stop();
}

void Seeds::Farmer_pushbutton_setenable3()
{

    Farmer3_Pushbutton->move(X2, Y2);
    Farmer3_Pushbutton->setEnabled(true);
    Farmer_animation->stop();
}

void Seeds::Farmer_pushbutton_setenable4()
{

    Farmer4_Pushbutton->move(X2, Y2);
    Farmer4_Pushbutton->setEnabled(true);
    Farmer_animation->stop();
}

void Seeds::Farmer_pushbutton_setenable5()
{

    Farmer5_Pushbutton->move(X2, Y2);
    Farmer5_Pushbutton->setEnabled(true);
    Farmer_animation->stop();
}

void Seeds::Farmer_pushbutton_setenable6()
{

    Farmer6_Pushbutton->move(X2, Y2);
    Farmer6_Pushbutton->setEnabled(true);
    Farmer_animation->stop();
}

void Seeds::Farmer_pushbutton_setenable7()
{

    Farmer7_Pushbutton->move(X2, Y2);
    Farmer7_Pushbutton->setEnabled(true);
    Farmer_animation->stop();
}

void Seeds::Farmer_pushbutton_setenable8()
{

    Farmer8_Pushbutton->move(X2, Y2);
    Farmer8_Pushbutton->setEnabled(true);
    Farmer_animation->stop();
}

void Seeds::Farmer_pushbutton_setenable9()
{

    Farmer9_Pushbutton->move(X2, Y2);
    Farmer9_Pushbutton->setEnabled(true);
    Farmer_animation->stop();
}

void Seeds::Farmer_pushbutton_setenable10()
{

    Farmer10_Pushbutton->move(X2, Y2);
    Farmer10_Pushbutton->setEnabled(true);
    Farmer_animation->stop();
}

void Seeds::Farmer_pushbutton_setenable11()
{

    Farmer11_Pushbutton->move(X2, Y2);
    Farmer11_Pushbutton->setEnabled(true);
    Farmer_animation->stop();
}

void Seeds::Farmer_pushbutton_setenable12()
{

    Farmer12_Pushbutton->move(X2, Y2);
    Farmer12_Pushbutton->setEnabled(true);
    Farmer_animation->stop();
}

void Seeds::Farmer_pushbutton_setenable13()
{

    Farmer13_Pushbutton->move(X2, Y2);
    Farmer13_Pushbutton->setEnabled(true);
    Farmer_animation->stop();
}

void Seeds::Farmer_pushbutton_setenable14()
{

    Farmer14_Pushbutton->move(X2, Y2);
    Farmer14_Pushbutton->setEnabled(true);
    Farmer_animation->stop();
}

void Seeds::Farmer_pushbutton_setenable15()
{

    Farmer15_Pushbutton->move(X2, Y2);
    Farmer15_Pushbutton->setEnabled(true);
    Farmer_animation->stop();
}

void Seeds::Farmer_pushbutton_setenable16()
{

    Farmer16_Pushbutton->move(X2, Y2);
    Farmer16_Pushbutton->setEnabled(true);
    Farmer_animation->stop();
}

void Seeds::Set_Farmer_animation(QPropertyAnimation *animation)
{
    Farmer_animation = animation;
}

void Seeds::decrease_label_position(int x, int y)
{
    X1 = x;
    Y1 = y;
}

void Seeds::Farmer_pushbutton_position(int x, int y)
{
    X2 = x;
    Y2 = y;
}

