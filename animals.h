#ifndef ANIMALS_H
#define ANIMALS_H

#include <QObject>
#include "QTimer"
#include "QLabel"

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

    QLabel * TimerLabel;

private:

    QTimer* timer;
};

#endif // ANIMALS_H
