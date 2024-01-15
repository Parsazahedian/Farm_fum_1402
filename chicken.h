#ifndef CHICKEN_H
#define CHICKEN_H

#include <QObject>
#include "animals.h"
#include "QVBoxLayout"
#include "QPushButton"

class Chicken : public Animals
{
    Q_OBJECT
public:
    Chicken(QVBoxLayout* BaseLayout);

    QPushButton* pushButton;
};

#endif // CHICKEN_H
