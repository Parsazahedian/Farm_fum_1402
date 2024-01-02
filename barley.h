#ifndef BARLEY_H
#define BARLEY_H

#include <QObject>
#include "seeds.h"
#include "QVBoxLayout"
#include "QPushButton"

class Barley : public Seeds
{
    Q_OBJECT
public:
    Barley(QVBoxLayout* BaseLayout);

    QPushButton* pushButton;
};

#endif // BARLEY_H
