#include "farmer.h"

Farmer::Farmer(QVBoxLayout* BaseLayout)
{
    pushButton = new QPushButton("Farmer");
    QSize buttonSize(50, 50);
    pushButton->setFixedSize(buttonSize);
    Farmer_Status = false;
    BaseLayout->addWidget(pushButton);
}
