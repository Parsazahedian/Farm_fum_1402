#include "sheep.h"

Sheep::Sheep(QVBoxLayout* BaseLayout)
{
    pushButton = new QPushButton();
    QSize buttonSize(50, 50);
    pushButton->setFixedSize(buttonSize);
    pushButton->setStyleSheet("border-image: url(C:/Users/i/Downloads/sheep.png);");
    Product_production_time = 15;
    Price_of_meat = 4;
    Product_Collection_Point = 3;
    Purchase_price= 5;
    Product_Collection_Delay_time = 4;
    BaseLayout->addWidget(pushButton);
}
