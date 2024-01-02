#include "chicken.h"

Chicken::Chicken(QVBoxLayout* BaseLayout)
{
    pushButton = new QPushButton("Chicken");
    QSize buttonSize(50, 50);
    pushButton->setFixedSize(buttonSize);
    Product_production_time = 20;
    Price_of_meat = 2;
    Product_Collection_Point = 3;
    Purchase_price = 3;
    Product_Collection_Delay_time = 5;
    BaseLayout->addWidget(pushButton);
}
