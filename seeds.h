#ifndef SEEDS_H
#define SEEDS_H

#include <QObject>
#include "QTimer"
#include "QLabel"
#include "QPushButton"
#include "QPropertyAnimation"

extern int number_of_farmers;
extern int number_of_Free_farmers;

class Seeds : public QObject
{
    Q_OBJECT
public:
    Seeds();

    void TurnTimerOn();
    void TurnTimerOn2();
    void TurnTimerOn3();
    void TurnTimerOn4();
    void TurnTimerOn5();
    void TurnTimerOn6();
    void TurnTimerOn7();
    void TurnTimerOn8();
    void TurnTimerOn9();
    void TurnTimerOn10();
    void TurnTimerOn11();
    void TurnTimerOn12();
    void TurnTimerOn13();
    void TurnTimerOn14();
    void TurnTimerOn15();
    void TurnTimerOn16();

    int Product_production_time;

    int Product_Collection_Point;

    int Purchase_price;

    int Product_Collection_Delay_time;

    void SetTimerLabel(QLabel* label);

    void Set_label_of_timers(QLabel* label);

    void Set_Farmer_status_Label(QLabel* label);

    void Timer_Stop();
    void Timer2_Stop();
    void Timer3_Stop();
    void Timer4_Stop();
    void Timer5_Stop();
    void Timer6_Stop();
    void Timer7_Stop();
    void Timer8_Stop();
    void Timer9_Stop();
    void Timer10_Stop();
    void Timer11_Stop();
    void Timer12_Stop();
    void Timer13_Stop();
    void Timer14_Stop();
    void Timer15_Stop();
    void Timer16_Stop();

    void Set_Product_Pushbutton(QPushButton* pushbutton);

    void Set_Cancel_Pushbutton(QPushButton* pushbutton);

    void Set_Start_Pushbutton(QPushButton* pushbutton);

    void Set_Animals_or_Seeds_Pushbutton(QPushButton* pushbutton);

    void Set_Farmer_Pushbutton(QPushButton* pushbutton);

    void Product_Collection_Delay_time_for_score();

    void TimerDelay_Stop();

    void Set_decrease_label(QLabel* label);

    void Farmer_pushbutton_setenable();
    void Farmer_pushbutton_setenable2();
    void Farmer_pushbutton_setenable3();
    void Farmer_pushbutton_setenable4();
    void Farmer_pushbutton_setenable5();
    void Farmer_pushbutton_setenable6();
    void Farmer_pushbutton_setenable7();
    void Farmer_pushbutton_setenable8();
    void Farmer_pushbutton_setenable9();
    void Farmer_pushbutton_setenable10();
    void Farmer_pushbutton_setenable11();
    void Farmer_pushbutton_setenable12();
    void Farmer_pushbutton_setenable13();
    void Farmer_pushbutton_setenable14();
    void Farmer_pushbutton_setenable15();
    void Farmer_pushbutton_setenable16();

    void decrease_label_position(int x, int y);

    void Farmer_pushbutton_position(int x, int y);

    void Set_Farmer_animation(QPropertyAnimation *animation);

private:

    QTimer* timerDelay;//on fareie
    QTimer* timer;
    QTimer* timer2;
    QTimer* timer3;
    QTimer* timer4;
    QTimer* timer5;
    QTimer* timer6;
    QTimer* timer7;
    QTimer* timer8;
    QTimer* timer9;
    QTimer* timer10;
    QTimer* timer11;
    QTimer* timer12;
    QTimer* timer13;
    QTimer* timer14;
    QTimer* timer15;
    QTimer* timer16;

    QLabel * TimerLabel;

    QLabel * TimerLabel2;

    QLabel * Label_of_timer;

    QLabel * Farmers_status_label;

    QPushButton* Product_Pushbutton;

    QPushButton* Cancel_Pushbutton;

    QPushButton* Start_Pushbutton;

    QPushButton* Animals_or_Seeds_Pushbutton;

    int x=0;

    QLabel * decrease_label;

    int X1, Y1, X2, Y2;

    QPropertyAnimation * Farmer_animation;
};

#endif // SEEDS_H
