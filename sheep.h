#ifndef SHEEP_H
#define SHEEP_H

#include <QObject>
#include "animals.h"
#include "QVBoxLayout"
#include "QPushButton"

class Sheep : public Animals
{
    Q_OBJECT
public:
    Sheep(QVBoxLayout* BaseLayout);

    QPushButton* pushButton;
};

#endif // SHEEP_H
