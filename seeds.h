#ifndef SEEDS_H
#define SEEDS_H

#include <QObject>
#include "QTimer"
#include "QLabel"
#include "QPushButton"

class Seeds : public QObject
{
    Q_OBJECT
public:
    Seeds();

    void TurnTimerOn();

    int Product_production_time;

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


private:

    QTimer* timer;

    QTimer* timer2;

    QLabel * TimerLabel;

    QLabel * TimerLabel2;

    QPushButton* Product_Pushbutton;

    QPushButton* Cancel_Pushbutton;

    QPushButton* Start_Pushbutton;

    QPushButton* Animals_or_Seeds_Pushbutton;

    QPushButton* Farmer_Pushbutton;

    int x=0;
};

#endif // SEEDS_H
