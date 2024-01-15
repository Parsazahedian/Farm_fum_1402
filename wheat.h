#ifndef WHEAT_H
#define WHEAT_H

#include <QObject>
#include "seeds.h"
#include "QVBoxLayout"
#include "QPushButton"

class Wheat : public Seeds
{
    Q_OBJECT
public:
    Wheat(QVBoxLayout* BaseLayout);

    QPushButton* pushButton;
};

#endif // WHEAT_H
