#ifndef FARMER_H
#define FARMER_H

#include <QObject>
#include "QVBoxLayout"
#include "QPushButton"

class Farmer : public QObject
{
    Q_OBJECT
public:
    Farmer(QVBoxLayout* BaseLayout);

    QPushButton* pushButton;

    bool Farmer_Status;

    int Purchase_price;
};

#endif // FARMER_H
