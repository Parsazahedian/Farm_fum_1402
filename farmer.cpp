#include "farmer.h"

Farmer::Farmer(QVBoxLayout* BaseLayout)
{
    pushButton = new QPushButton("Farmer");
    QSize buttonSize(50, 70);
    pushButton->setFixedSize(buttonSize);
    Farmer_Status = false;
    Purchase_price = 5;
    BaseLayout->addWidget(pushButton);
}
