#include "farmer.h"

Farmer::Farmer(QVBoxLayout* BaseLayout)
{
    pushButton = new QPushButton();
    QSize buttonSize(50, 70);
    pushButton->setFixedSize(buttonSize);
    pushButton->setStyleSheet("border-image: url(C:/Users/i/Downloads/farmer.png);");
    Farmer_Status = false;
    Purchase_price = 5;
    BaseLayout->addWidget(pushButton);
}
