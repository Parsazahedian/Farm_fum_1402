#ifndef COW_H
#define COW_H

#include <QObject>
#include "animals.h"
#include "QVBoxLayout"
#include "QPushButton"

class Cow : public Animals
{
    Q_OBJECT
public:
    Cow(QVBoxLayout* BaseLayout);

    QPushButton* pushButton;
};

#endif // COW_H
