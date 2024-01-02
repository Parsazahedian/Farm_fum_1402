#ifndef SEEDS_H
#define SEEDS_H

#include <QObject>
#include "QTimer"
#include "QLabel"

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

    QLabel * TimerLabel;

private:

    QTimer* timer;
};

#endif // SEEDS_H
