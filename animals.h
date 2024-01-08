#ifndef ANIMALS_H
#define ANIMALS_H

#include <QObject>
#include "QTimer"
#include "QLabel"
#include "QPushButton"
#include "QPropertyAnimation"

extern int score;

class Animals : public QObject
{
    Q_OBJECT
public:
    Animals();

    void TurnTimerOn();

    int Product_production_time;

    int Price_of_meat;

    int Product_Collection_Point;

    int Purchase_price;

    int Product_Collection_Delay_time;

    void SetTimerLabel(QLabel* label);

    void Timer_Stop();

    void Set_Product_Pushbutton(QPushButton* pushbutton);

    void Set_Cancel_Pushbutton(QPushButton* pushbutton);

    void Set_Start_Pushbutton(QPushButton* pushbutton);

    void Set_Animals_or_Seeds_Pushbutton(QPushButton* pushbutton);

    void Set_Farmer_Pushbutton(QPushButton* pushbutton);

    void Product_Collection_Delay_time_for_score();

    void Timer2_Stop();

    void SetTimerLabel2(QLabel* label);

    void Set_decrease_label(QLabel* label);

    void Stop_animation();

private:

    QTimer* timer;

    QTimer* timer2;

    QLabel * TimerLabel;

    QLabel * TimerLabel2;

    QPushButton* Product_Pushbutton;

    QPushButton* Cancel_Pushbutton;

    QPushButton* Start_Pushbutton;

    QPushButton* Animals_or_Seeds_Pushbutton;

    int x=0;

    QLabel * decrease_label;

};

#endif // ANIMALS_H
